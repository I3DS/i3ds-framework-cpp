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
#include <sstream>

namespace logging = boost::log;

i3ds::GigECamera::GigECamera(Context::Ptr context, i3ds_asn1::NodeID node, Parameters param)
  : Camera(node),
    param_(param),
    data_depth_(param.data_depth),
    pixel_size_(param.pixel_size),
    publisher_(context, node)
{
  flash_enabled_ = false;
  flash_strength_ = 0.0;

  pattern_enabled_ = false;
  pattern_sequence_ = 0;

  if (param_.external_trigger && param_.trigger_node != 0)
    {
      BOOST_LOG_TRIVIAL(info) << "Using external trigger service with node ID: " << param_.trigger_node;

      // Create trigger client.
      trigger_ = std::make_shared<i3ds::TriggerClient>(context, param_.trigger_node);

      // Wait up to 500 ms for trigger service.
      trigger_->set_timeout(500);
    }

  if (param_.support_flash)
    {
      BOOST_LOG_TRIVIAL(info) << "Using flash service with node ID: " << param_.flash_node;

      // Create flash client.
      flash_ = std::make_shared<i3ds::FlashClient>(context, param_.flash_node);

      // Wait up to 500 ms for flash service.
      flash_->set_timeout(500);
    }
}

i3ds::GigECamera::~GigECamera()
{
}

i3ds_asn1::ShutterTime
i3ds::GigECamera::shutter() const
{
  return (i3ds_asn1::ShutterTime) getShutter();
}

i3ds_asn1::SensorGain
i3ds::GigECamera::gain() const
{
  return (i3ds_asn1::SensorGain) getGain();
}

bool
i3ds::GigECamera::auto_exposure_enabled() const
{
  return getAutoShutterEnabled() || getAutoGainEnabled();
}

i3ds_asn1::ShutterTime
i3ds::GigECamera::max_shutter() const
{
  return (i3ds_asn1::ShutterTime) getAutoShutterLimit();
}

i3ds_asn1::SensorGain
i3ds::GigECamera::max_gain() const
{
  return (i3ds_asn1::SensorGain) getAutoGainLimit();
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

i3ds_asn1::PlanarRegion
i3ds::GigECamera::region() const
{
  i3ds_asn1::PlanarRegion region;

  region.size_x   = (i3ds_asn1::T_UInt16) getRegionWidth();
  region.size_y   = (i3ds_asn1::T_UInt16) getRegionHeight() / param_.image_count;
  region.offset_x = (i3ds_asn1::T_UInt16) getRegionOffsetX();
  region.offset_y = (i3ds_asn1::T_UInt16) getRegionOffsetY();

  return region;
}

void
i3ds::GigECamera::signal_lost_camera()
{
  // Called when connection to camera is supected lost.
  const std::string error_string = "Probably lost connection with camera. Going to failure mode.";

  BOOST_LOG_TRIVIAL(error) <<  error_string;
  set_failure();

  throw CommandError(i3ds_asn1::error_other, error_string);
}

void
i3ds::GigECamera::do_activate()
{
  BOOST_LOG_TRIVIAL(info) << "do_activate()";

  if (param_.external_trigger && param_.trigger_node != 0)
    {
      set_trigger(param_.camera_output, param_.camera_offset);
    }

  Open();
}

void
i3ds::GigECamera::do_start()
{
  BOOST_LOG_TRIVIAL(info) << "do_start()";

  Start();

  if (param_.external_trigger && param_.trigger_node != 0)
    {
      trigger_->set_generator(param_.trigger_source, period());
      trigger_->enable_channels(trigger_outputs_);
    }
}

void
i3ds::GigECamera::do_stop()
{
  BOOST_LOG_TRIVIAL(info) << "do_stop()";

  if (param_.external_trigger && param_.trigger_node != 0)
    {
      trigger_->disable_channels(trigger_outputs_);
    }

  Stop();
}

void
i3ds::GigECamera::do_deactivate()
{
  BOOST_LOG_TRIVIAL(info) << "do_activate()";

  Close();

  flash_enabled_ = false;
  flash_strength_ = 0.0;

  pattern_enabled_ = false;
  pattern_sequence_ = 0;

  trigger_outputs_.clear();
}

bool
i3ds::GigECamera::is_sampling_supported(i3ds_asn1::SampleCommand sample)
{
  BOOST_LOG_TRIVIAL(info) << "is_rate_supported() " << sample.period;
  try
    {
      if (param_.external_trigger && param_.trigger_node != 0)
        {
          // Minimal period 50 ms (= 20 Hz) and maximal 16.7 seconds for external trigger.
          return 50000 <= sample.period && sample.period <= 16777215;
        }
      else
        {
          return setInternalTrigger(sample.period);
        }
    }
  catch (i3ds::CommandError& e)
    {
      // This is for rethrowing out of range values etc. found by software.
      BOOST_LOG_TRIVIAL(warning) <<  "Value exception in is_sampling_supported(): " + std::string(e.what());
      throw;
    }
  catch (...)
    {
      // Catch unknown exceptions thrown by device interface.
      signal_lost_camera();
    }

  return false; // To remove compiler warning. Never executed.
}

void
i3ds::GigECamera::handle_exposure(ExposureService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_exposure()";

  check_active();

  try
    {
      // Cannot set manual exposure when auto exposure is enabled.
      if (auto_exposure_enabled())
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "In auto-exposure mode");
        }

      // Check that shutter is within limits.
      const int shutter = command.request.shutter;
      const int shutter_max = getMaxShutter();
      const int64_t shutter_min = getMinShutter();

      if (shutter > (int64_t) period())
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Shutter time longer than period: " + std::to_string(period()) );
        }

      if (shutter > shutter_max)
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Shutter time longer than max " + std::to_string(shutter_max));
        }

      if (shutter < shutter_min)
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Shutter time shorter than min " + std::to_string(shutter_min));
        }

      // Check that gain is within limits.
      const double gain = command.request.gain;
      const double gain_max = getMaxGain();
      const double gain_min = getMinGain();

      if (gain > gain_max)
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Gain higher than max value: " + std::to_string(gain_max));
        }

      if (gain < gain_min)
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Gain lower than min value: " + std::to_string(gain_min));
        }

      // Update gain and shutter.
      setShutter(shutter);
      setGain(gain);

      // Update flash duration corresponding to shutter if enabled.
      if (flash_enabled_)
        {
          flash_->set_flash(shutter, flash_strength_);
        }
    }
  catch (CommandError& e)
    {
      // This is for rethrowing out of range values found by software etc.
      BOOST_LOG_TRIVIAL(error) <<  "Value exception in handle_exposure: "+ std::string(e.what());
      throw;
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::error_other, e.what());
    }
  catch (...)
    {
      signal_lost_camera();
    }
}

void
i3ds::GigECamera::handle_auto_exposure(AutoExposureService::Data& command)
{

  BOOST_LOG_TRIVIAL(info) << "handle_auto_exposure";

  check_standby();

  try
    {
      // Check that auto shutter or auto gain is supported.
      const bool support_shutter = isAutoShutterSupported();
      const bool support_gain = isAutoGainSupported();

      if (!(support_shutter || support_gain))
        {
          throw i3ds::CommandError(i3ds_asn1::error_unsupported, "Auto exposure is not supported");
        }

      if (!command.request.enable)
        {
          if (support_gain)
            {
              setAutoGainEnabled(false);
            }

          if (support_shutter)
            {
              setAutoShutterEnabled(false);
            }

          return;
        }

      if (support_shutter)
        {
          const int limit = command.request.max_shutter;
          const int limit_max = getMaxAutoShutterLimit();
          const int limit_min = getMinAutoShutterLimit();

          if (limit > limit_max)
            {
              throw i3ds::CommandError(i3ds_asn1::error_value, "Shutter limit longer than max " + std::to_string(limit_max));
            }

          if (limit < limit_min)
            {
              throw i3ds::CommandError(i3ds_asn1::error_value, "Shutter limit shorter than min " + std::to_string(limit_min));
            }

          if (limit > (period() / 2.0))
            {
              throw i3ds::CommandError(i3ds_asn1::error_value, "Shutter limit longer than (period/2) " + std::to_string(period() / 2.) );
            }

          setAutoShutterEnabled(true);
          setAutoShutterLimit(limit);

          if (flash_enabled_)
            {
              // TODO: Is this a smart way of doing it?
              const int shutter_duration = (limit_max + limit_min) / 2.0;

              BOOST_LOG_TRIVIAL(trace) << "Setting flash strength to " << flash_strength_;
              BOOST_LOG_TRIVIAL(trace) << "Setting flash duration to " << shutter_duration;

              // Send flash command.
              flash_->set_flash(shutter_duration, flash_strength_);

	      BOOST_LOG_TRIVIAL(trace) << "Setting flash OK";
            }
        }

      if (support_gain)
        {
          const int limit = command.request.max_gain;
          const int limit_max = getMaxAutoGainLimit();
          const int limit_min = getMinAutoGainLimit();

          if (limit > limit_max)
            {
              throw i3ds::CommandError(i3ds_asn1::error_value, "Gain limit larger than max " + std::to_string(limit_max));
            }

          if (limit < limit_min)
            {
              throw i3ds::CommandError(i3ds_asn1::error_value, "Gain limit smaller than min " + std::to_string(limit_min));
            }

          setAutoGainEnabled(true);
          setAutoGainLimit(limit);
        }
    }
  catch (i3ds::CommandError& e)
    {
      // This is for rethrowing wrong values such that catch(...) does not get it. .
      BOOST_LOG_TRIVIAL(error) <<  "Value exception in handle_auto_exposure: " << e.what();
      throw;
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::error_other, e.what());
    }
  catch (...)
    {
      signal_lost_camera();
    }
}

void
i3ds::GigECamera::handle_region(RegionService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_region()";

  check_standby();

  if (!isRegionSupported())
    {
      throw CommandError(i3ds_asn1::error_unsupported, "ROI not supported for camera");
    }

  try
    {
      if (command.request.enable)
        {
          const int sx = command.request.region.size_x;
          const int sy = command.request.region.size_y;
          const int ox = command.request.region.offset_x;
          const int oy = command.request.region.offset_y;

          BOOST_LOG_TRIVIAL(trace) << "Enable region: " << sx << " " << sy << " " << ox << " " << oy;

          if ((sx + ox) > getSensorWidth())
            {
              std::stringstream ss;

              ss << "Region width + offset larger than sensor width: (" <<  sx << "+" << ox << ") > " << getSensorWidth();

              throw i3ds::CommandError(i3ds_asn1::error_value, ss.str());
            }

          if ((sy + oy) > getSensorHeight())
            {
              std::stringstream ss;

              ss << "Region height + offset larger than sensor height: (" <<  sy << "+" << oy << ") > " << getSensorHeight();

              throw i3ds::CommandError(i3ds_asn1::error_value, ss.str());
            }

          // Do resize in correct order
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
          BOOST_LOG_TRIVIAL(trace) << "Disable region";

          setRegionOffsetX(0);
          setRegionOffsetY(0);
          setRegionWidth(getSensorWidth());
          setRegionHeight(getSensorHeight());
        }
    }
  catch (i3ds::CommandError& e)
    {
      // This is for rethrowing soft value errors etc such that it is not regarded as camera error.
      BOOST_LOG_TRIVIAL(warning) <<  "Value exception in handle_region: " << e.what();
      throw;
    }
  catch (DeviceError& e)
    {
      signal_lost_camera();
    }
  catch (...)
    {
      signal_lost_camera();
    }
}

void
i3ds::GigECamera::handle_flash(FlashService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_flash()";

  check_standby();

  try
    {
      if (!param_.support_flash)
        {
          throw i3ds::CommandError(i3ds_asn1::error_unsupported, "Flash not supported without starting camera in triggered mode");
        }

      flash_enabled_ = command.request.enable;

      if (flash_enabled_)
        {
          flash_strength_ = command.request.strength;

          i3ds_asn1::ShutterTime shutter_duration;

          if (getAutoShutterEnabled())
            {
              shutter_duration = getAutoShutterLimit();
            }
          else
            {
              shutter_duration = getShutter();
            }

          BOOST_LOG_TRIVIAL(trace) << "Setting flash strength to " << flash_strength_;
          BOOST_LOG_TRIVIAL(trace) << "Setting flash duration to " << shutter_duration;

          // Send flash command.
          flash_->set_flash(shutter_duration, flash_strength_);

	  BOOST_LOG_TRIVIAL(trace) << "Setting flash OK";

          // Enable trigger for flash.
          set_trigger(param_.flash_output, param_.flash_offset);
        }
      else
        {
          // Disable flash.
          flash_strength_ = 0;

          // Clear trigger for flash.
          clear_trigger(param_.flash_output);
        }
    }
  catch (i3ds::CommandError& e)
    {
      // This is for rethrowing soft value errors etc such that it is not regarded as camera error.
      BOOST_LOG_TRIVIAL(warning) <<  "Value exception in handle_flash: " << e.what();
      throw;
    }
  catch (DeviceError& e)
    {
      BOOST_LOG_TRIVIAL(warning) << "DeviceError catch";
      signal_lost_camera();
    }
  catch (...)
    {
      signal_lost_camera();
    }

}

void
i3ds::GigECamera::handle_pattern(PatternService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "handle_pattern()";

  if(!param_.support_pattern)
    {
      throw i3ds::CommandError(i3ds_asn1::error_unsupported, "Pattern not activated when started camera server");
    }

  check_standby();

  if (!trigger_)
    {
      throw i3ds::CommandError(i3ds_asn1::error_unsupported, "Pattern only supported in triggered mode");
    }

  pattern_enabled_ = command.request.enable;

  if (command.request.enable)
    {
      // Only support one pattern sequence, not controllable as of now.
      if (command.request.pattern_sequence != 1)
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Unsupported pattern sequence");
        }

      pattern_sequence_ = command.request.pattern_sequence;

      // Enable trigger for pattern projector.
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
i3ds::GigECamera::set_trigger(i3ds_asn1::TriggerOutput channel, i3ds_asn1::TriggerOffset offset)
{
  BOOST_LOG_TRIVIAL(trace) << "Set trigger " << channel << " offset " << offset;

  // Set the channel to fire at offset with 100 us pulse.
  try
    {
      trigger_->set_internal_channel(channel, param_.trigger_source, offset, 100, false);
    }
  catch (Timeout& e)
    {
      const std::string error = "TIMEOUT for setting trigger";

      BOOST_LOG_TRIVIAL(error) << error;

      throw CommandError(i3ds_asn1::error_other, error);
    }

  // Enable the trigger on do_start.
  trigger_outputs_.insert(channel);
}

void
i3ds::GigECamera::clear_trigger(i3ds_asn1::TriggerOutput channel)
{
  // Do not enable the trigger on do_start.
  trigger_outputs_.erase(channel);
}

bool
i3ds::GigECamera::send_sample(const i3ds_asn1::byte* image, int width, int height)
{
  BOOST_LOG_TRIVIAL(trace) << "GigECamera::send_sample() (" << width << "x" << height << ")" ;

  const i3ds_asn1::PlanarRegion r = region();

  Camera::FrameTopic::Data frame;

  Camera::FrameTopic::Codec::Initialize(frame);

  int split_height = height / param_.image_count;

  // Set metadata of the frame.
  frame.descriptor.attributes.timestamp = get_timestamp();
  frame.descriptor.attributes.validity = i3ds_asn1::sample_valid;

  frame.descriptor.region.size_x = r.size_x;
  frame.descriptor.region.size_y = r.size_y;
  frame.descriptor.region.offset_x = r.offset_x;
  frame.descriptor.region.offset_y = r.offset_y;

  frame.descriptor.frame_mode = param_.frame_mode;
  frame.descriptor.data_depth = data_depth_;
  frame.descriptor.pixel_size = pixel_size_;
  frame.descriptor.image_count = param_.image_count;

  // Check if region matches the image width and height.
  if (((int) r.size_x == width) && ((int) r.size_y == split_height))
    {
      const size_t size = image_size(frame.descriptor);

      for (int i = 0; i < param_.image_count; i++)
        {
          frame.append_image(image + size * i, size);
        }

      publisher_.Send<Camera::FrameTopic>(frame);

      BOOST_LOG_TRIVIAL(trace) << "Send frame OK";
    }
  else
    {
      // TODO: Send an empty frame with negative validity flag?
      BOOST_LOG_TRIVIAL(error) << "Error in image format going to be sent";
      BOOST_LOG_TRIVIAL(error) << "size check x: " << width << " " << r.size_x;
      BOOST_LOG_TRIVIAL(error) << "size check y: " << split_height << " " << r.size_y;
      BOOST_LOG_TRIVIAL(error) << "image count:  " << param_.image_count;
    }

  return true;
}
