///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <i3ds/camera_sensor.hpp>
#include <i3ds/exception.hpp>

void
i3ds::Camera::Attach(Server& server)
{
  using std::placeholders::_1;

  Sensor::Attach(server);

  server.Attach<ExposureService>(node(), std::bind(&i3ds::Camera::handle_exposure, this, _1));
  server.Attach<AutoExposureService>(node(), std::bind(&i3ds::Camera::handle_auto_exposure, this, _1));
  server.Attach<RegionService>(node(), std::bind(&i3ds::Camera::handle_region, this, _1));
  server.Attach<PatternService>(node(), std::bind(&i3ds::Camera::handle_pattern, this, _1));
  server.Attach<FlashService>(node(), std::bind(&i3ds::Camera::handle_flash, this, _1));
  server.Attach<ConfigurationService>(node(), std::bind(&i3ds::Camera::handle_configuration, this, _1));
  server.Attach<SequenceService>(node(), std::bind(&i3ds::Camera::handle_sequence, this, _1));
}

void
i3ds::Camera::handle_auto_exposure(AutoExposureService::Data&)
{
  throw CommandError(i3ds_asn1::ResultCode_error_unsupported, "Auto exposure not supported");
}

void
i3ds::Camera::handle_region(RegionService::Data&)
{
  throw CommandError(i3ds_asn1::ResultCode_error_unsupported, "Region of interest not supported");
}

void
i3ds::Camera::handle_flash(FlashService::Data&)
{
  throw CommandError(i3ds_asn1::ResultCode_error_unsupported, "Region of interest not supported");
}

void
i3ds::Camera::handle_pattern(PatternService::Data&)
{
  throw CommandError(i3ds_asn1::ResultCode_error_unsupported, "Pattern illumination not supported");
}

void
i3ds::Camera::handle_sequence(SequenceService::Data&)
{
  throw CommandError(i3ds_asn1::ResultCode_error_unsupported, "Camera image-sequence modifier not supported");
}

void
i3ds::Camera::handle_configuration(ConfigurationService::Data& config)
{
  check_active();

  try
    {
      config.response.shutter = shutter();
      config.response.gain = gain();
      config.response.auto_exposure_enabled = auto_exposure_enabled();
      config.response.max_shutter = max_shutter();
      config.response.max_gain = max_gain();
      config.response.region_enabled = region_enabled();
      config.response.region = region();
      config.response.flash_enabled = flash_enabled();
      config.response.flash_strength = flash_strength();
      config.response.pattern_enabled = pattern_enabled();
      config.response.pattern_sequence = pattern_sequence();
      config.response.image_sequence_enabled = image_sequence_enabled();
      config.response.image_sequence = image_sequence();
      config.response.image_max_sequence = image_max_sequence();
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::ResultCode_error_other, e.what());
    }
  catch (...)
    {
      /// \todo This forces it into failure state, but the first error message give wrong message on client side.
      set_failure();
      throw CommandError(i3ds_asn1::ResultCode_error_other, "Probably lost connection with camera. Going to failure mode.");
    }
}
