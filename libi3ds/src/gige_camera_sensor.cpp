///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <i3ds/gige_camera_sensor.hpp>
#include <i3ds/time.hpp>

#define BOOST_LOG_DYN_LINK

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <cmath>

namespace logging = boost::log;

i3ds::GigECamera::GigECamera(Context::Ptr context, NodeID node, Parameters param)
  : Camera(node),
    param_(param),
    publisher_(context, node)
{
  flash_enabled_ = false;
  flash_strength_ = 0.0;

  pattern_enabled_ = false;
  pattern_sequence_ = 0;

  if (param_.external_trigger)
    {
      // Create trigger client.
      trigger_ = std::make_shared<i3ds::TriggerClient>(context, param_.trigger_node);

      // Only wait 100 ms for trigger service.
      trigger_->set_timeout(100);
    }

  if (param_.support_flash)
    {
      // Create flash client.
      flash_ = std::make_shared<i3ds::FlashClient>(context, param_.flash_node);

      // Only wait 100 ms for flash service.
      flash_->set_timeout(100);
    }
}

i3ds::GigECamera::~GigECamera()
{
}

ShutterTime
i3ds::GigECamera::shutter() const
{
  return (ShutterTime) getShutter();
}

SensorGain
i3ds::GigECamera::gain() const
{
  return (SensorGain) getGain();
}

bool
i3ds::GigECamera::auto_exposure_enabled() const
{
  return getAutoShutterEnabled() || getAutoGainEnabled();
}

ShutterTime
i3ds::GigECamera::max_shutter() const
{
  return (ShutterTime) getMaxAutoShutterLimit();
}

SensorGain
i3ds::GigECamera::max_gain() const
{
  return (SensorGain) getMaxAutoGainLimit();
}

bool
i3ds::GigECamera::region_enabled() const
{
  if (!isRegionSupported())
    {
      return false;
    }
  else
    {
      return (getRegionWidth() != getSensorWidth()) ||
             (getRegionHeight() != getSensorHeight());
    }
}

PlanarRegion
i3ds::GigECamera::region() const
{
  PlanarRegion region;

  region.size_x   = (T_UInt16) getRegionWidth();
  region.size_y   = (T_UInt16) getRegionHeight();
  region.offset_x = (T_UInt16) getRegionOffsetX();
  region.offset_y = (T_UInt16) getRegionOffsetY();

  return region;
}

void
i3ds::GigECamera::do_activate()
{
  BOOST_LOG_TRIVIAL(info) << "do_activate()";

  Open();
}

void
i3ds::GigECamera::do_start()
{
  BOOST_LOG_TRIVIAL(info) << "do_start()";

  Start();

  if (param_.external_trigger)
    {
      trigger_->enable_channels(trigger_outputs_);
    }
}

void
i3ds::GigECamera::do_stop()
{
  BOOST_LOG_TRIVIAL(info) << "do_stop()";

  if (param_.external_trigger)
    {
      trigger_->disable_channels(trigger_outputs_);
    }

  Stop();
}

void
i3ds::GigECamera::do_deactivate()
{
  Close();

  flash_enabled_ = false;
  flash_strength_ = 0.0;

  pattern_enabled_ = false;
  pattern_sequence_ = 0;

  trigger_outputs_.clear();
}

bool
i3ds::GigECamera::is_sampling_supported(SampleCommand sample)
{
  BOOST_LOG_TRIVIAL(info) << "is_rate_supported() " << sample.period;

  if (param_.external_trigger)
    {
      // Minimal period 50 ms (= 20 Hz) and maximal 16.7 seconds for external trigger.
      return 50000 <= sample.period && sample.period <= 16777215;
    }
  else
    {
      return setInternalTrigger(sample.period);
    }
}

void
i3ds::GigECamera::handle_exposure(ExposureService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_exposure()";

  check_active();

  // Cannot set manual exposure when auto exposure is enabled.
  if (auto_exposure_enabled())
    {
      throw i3ds::CommandError(error_value, "In auto-exposure mode");
    }

  // Check that shutter is within limits.
  const int shutter = command.request.shutter;
  const int shutter_max = getMaxShutter();
  const int64_t shutter_min = getMinShutter();

  if (shutter > (int64_t) period())
    {
      throw i3ds::CommandError(error_value, "Shutter time longer than period!");
    }

  if (shutter > shutter_max)
    {
      throw i3ds::CommandError(error_value, "Shutter time longer than max " + std::to_string(shutter_max));
    }

  if (shutter < shutter_min)
    {
      throw i3ds::CommandError(error_value, "Shutter time shorter than min " + std::to_string(shutter_min));
    }

  // Check that gain is within limits.
  const double gain = command.request.gain;
  const double gain_max = getMaxGain();
  const double gain_min = getMinGain();

  if (gain > gain_max)
    {
      throw i3ds::CommandError(error_value, "Gain higher than " + std::to_string(gain_max));
    }

  if (gain < gain_min)
    {
      throw i3ds::CommandError(error_value, "Gain lower than " + std::to_string(gain_min));
    }

  // Update gain and shutter.
  try
    {
      setShutter(shutter);
      setGain(gain);
    }
  catch (std::exception& e)
    {
      BOOST_LOG_TRIVIAL(warning) << e.what();
    }

  // Update flash duration corresponding to shutter if enabled.
  if (flash_enabled_)
    {
      flash_->set_flash(shutter, flash_strength_);
    }
}

void
i3ds::GigECamera::handle_auto_exposure(AutoExposureService::Data& command)
{

  BOOST_LOG_TRIVIAL(info) << "handle_auto_exposure";

  check_active();

  if (!command.request.enable)
    {
      setAutoShutterEnabled(false);
      setAutoGainEnabled(false);

      return;
    }

  // Check that auto shutter or auto gain is supported.
  const bool support_shutter = isAutoShutterSupported();
  const bool support_gain = isAutoGainSupported();

  if (!(support_shutter || support_gain))
    {
      throw i3ds::CommandError(error_unsupported, "Auto exposure is not supported");
    }

  if (support_shutter)
    {
      const int limit = command.request.max_shutter;
      const int limit_max = getMaxAutoShutterLimit();
      const int limit_min = getMinAutoShutterLimit();

      if (limit > limit_max)
        {
          throw i3ds::CommandError(error_value, "Shutter limit longer than max " + std::to_string(limit_max));
        }

      if (limit < limit_min)
        {
          throw i3ds::CommandError(error_value, "Shutter limit shorter than min " + std::to_string(limit_min));
        }

      setAutoShutterLimit(limit);
      setAutoShutterEnabled(true);
    }

  if (support_gain)
    {
      const int limit = command.request.max_gain;
      const int limit_max = getMaxAutoGainLimit();
      const int limit_min = getMinAutoGainLimit();

      if (limit > limit_max)
        {
          throw i3ds::CommandError(error_value, "Gain limit larger than max " + std::to_string(limit_max));
        }

      if (limit < limit_min)
        {
          throw i3ds::CommandError(error_value, "Gain limit smaller than min " + std::to_string(limit_min));
        }

      setAutoGainLimit(limit);
      setAutoGainEnabled(true);
    }
}

void
i3ds::GigECamera::handle_region(RegionService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_region()";

  check_standby();

  if (command.request.enable)
    {
      BOOST_LOG_TRIVIAL(info) << "handle_region()";

      const int sx = command.request.region.size_x;
      const int sy = command.request.region.size_y;
      const int ox = command.request.region.offset_x;
      const int oy = command.request.region.offset_y;

      if ((sx + ox) > getSensorWidth())
        {
          throw i3ds::CommandError(error_value, std::string("Region width and offset outside sensor width for camera"));
        }

      if ((sy + oy) > getSensorHeight())
        {
          throw i3ds::CommandError(error_value, std::string("Region height and offset outside sensor height for camera"));
        }

      // Have to do resizing in correct order.(Reduse parameter first, increase later)
      if (sx > getRegionWidth())
        {
          setRegionOffsetX(ox);
          setRegionWidth(sx);
        }
      else
        {
          setRegionWidth(sx);
          setRegionOffsetX(ox);
        }

      if (sy > getRegionHeight())
        {
          setRegionOffsetY(oy);
          setRegionHeight(sy);
        }
      else
        {
          setRegionHeight(sy);
          setRegionOffsetY(oy);
        }
    }
  else
    {
      setRegionOffsetX(0);
      setRegionOffsetY(0);
      setRegionWidth(getSensorWidth());
      setRegionHeight(getSensorHeight());
    }
}

void
i3ds::GigECamera::handle_flash(FlashService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_flash()";

  check_standby();

  if (!param_.support_flash)
    {
      throw i3ds::CommandError(error_unsupported, "Flash not supported");
    }

  flash_enabled_ = command.request.enable;

  if (flash_enabled_)
    {
      flash_strength_ = command.request.strength;

      ShutterTime flash_duration;

      if (getAutoShutterEnabled())
        {
          flash_duration = getAutoShutterLimit();
        }
      else
        {
          flash_duration = getShutter();
        }

      // Send flash command.
      flash_->set_flash(flash_duration, flash_strength_);

      // Enable trigger for flash.
      set_trigger(param_.flash_output, param_.flash_offset);
    }
  else
    {
      // Clear trigger, not enabled when operational.
      clear_trigger(param_.flash_output);
    }
}

void
i3ds::GigECamera::handle_pattern(PatternService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_pattern()";

  check_standby();

  if (!trigger_)
    {
      throw i3ds::CommandError(error_other, "Pattern not supported in free-running mode");
    }

  pattern_enabled_ = command.request.enable;

  if (command.request.enable)
    {
      // Only support one pattern sequence, not controllable as of now.
      if (command.request.sequence != 1)
        {
          throw i3ds::CommandError(error_value, "Unsupported pattern sequence");
        }

      pattern_sequence_ = command.request.sequence;

      // Enable trigger for flash.
      set_trigger(param_.pattern_output, param_.pattern_offset);
    }
  else
    {
      // Reset pattern sequence to disabled.
      pattern_sequence_ = 0;

      // Clear trigger, not enabled when operational.
      clear_trigger(param_.pattern_output);
    }
}

void
i3ds::GigECamera::set_trigger(TriggerOutput channel, TriggerOffset offset)
{
  // Set the channel to fire at offset with 100 us pulse.
  trigger_->set_internal_channel(channel, param_.trigger_source, offset, 100, false);

  // Enable the trigger on do_start.
  trigger_outputs_.insert(channel);
}

void
i3ds::GigECamera::clear_trigger(TriggerOutput channel)
{
  // Do not enable the trigger on do_start.
  trigger_outputs_.erase(channel);
}

bool
i3ds::GigECamera::send_sample(const byte* image, int width, int height)
{
  BOOST_LOG_TRIVIAL(trace) << "GigECamera::send_sample() (" << width << "x" << height << ")" ;

  const PlanarRegion r = region();

  Camera::FrameTopic::Data frame;

  Camera::FrameTopic::Codec::Initialize(frame);

  // Set metadata of the frame.
  frame.descriptor.attributes.timestamp = get_timestamp();
  frame.descriptor.attributes.validity = sample_valid;

  frame.descriptor.region.size_x = r.size_x;
  frame.descriptor.region.size_y = r.size_y;
  frame.descriptor.region.offset_x = r.offset_x;
  frame.descriptor.region.offset_y = r.offset_y;

  frame.descriptor.frame_mode = param_.frame_mode;
  frame.descriptor.data_depth = param_.data_depth;
  frame.descriptor.pixel_size = param_.pixel_size;
  frame.descriptor.image_count = param_.image_count;

  // Check if region matches the image width and height.
  if (((int) r.size_x == width) && ((int) r.size_y == (height / param_.image_count)))
    {
      const size_t size = image_size(frame.descriptor);

      for (int i = 0; i < param_.image_count; i++)
        {
          frame.append_image(image + size * i, size);
        }

      publisher_.Send<Camera::FrameTopic>(frame);
    }
  else
    {
      // TODO: Send an empty frame with negative validity flag?
      BOOST_LOG_TRIVIAL(error) << "Error in image format going to be sent";
      BOOST_LOG_TRIVIAL(error) << "size check x: " << width << " " << r.size_x;
      BOOST_LOG_TRIVIAL(error) << "size check y: " << height << " " << r.size_y;
      BOOST_LOG_TRIVIAL(error) << "image count:  " << param_.image_count;
    }

  return true;
}