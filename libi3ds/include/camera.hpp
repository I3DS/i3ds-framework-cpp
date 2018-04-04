///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_CAMERA_HPP
#define __I3DS_CAMERA_HPP

#include "Camera.h"

#include "sensor.hpp"
#include "service.hpp"
#include "codec.hpp"

namespace i3ds
{

CODEC(CameraCommand);
CODEC(CameraConfiguration);

class Camera : public Sensor
{
public:

  // Camera services.
  typedef Service<CameraCommandCodec, SensorResponseCodec> CommandService;
  typedef Service<NullCodec, CameraConfigurationCodec> ConfigurationService;

  // Constructor and destructor.
  Camera(Context::Ptr context, NodeID id);
  virtual ~Camera();

  // Get the X (horizontal) resolution of sensor.
  virtual int resolution_x() const = 0;

  // Get the Y (vertical) resolution of sensor.
  virtual int resolution_y() const = 0;

  // Get exposure time for camera.
  virtual ExposureTime exposure() const = 0;

  // Get gain for camera.
  virtual SensorGain gain() const = 0;

  // Get auto exposure for camera.
  virtual bool auto_exposure() const {return false;}

  // Get exposure time limit for camera with auto exposure.
  virtual ExposureTime exposure_limit() const {return 0.0;}

  // Get gain limit for camera with auto exposure.
  virtual SensorGain gain_limit() const {return 0.0;}

  // Get the region of interest for the camera.
  virtual PlanarRegion region() const;

  // Get the flash illumination for the camera.
  virtual bool flash_enabled() const {return false;}

  // Get the flash strength for the camera.
  virtual FlashStrength flash_strength() const {return 0;}

  // Get the pattern illumination for the camera.
  virtual bool pattern_enabled() const {return false;}

  // Get the pattern for the camera.
  virtual IlluminationPattern illumination_pattern() const {return 0;}

protected:

  // Set default handler for endpoints.
  void set_command_handler();
  void set_configuration_handler();

  // Get camera status.
  void get_camera_configuration(CameraConfiguration& config) const;

  // Execute camera command.
  ResultCode execute_camera_command(CameraCommand& command);

  // Set exposure time for camera.
  virtual ResultCode set_exposure(ExposureTime exposure) {return error_unsupported;}

  // Set gain for camera.
  virtual ResultCode set_gain(SensorGain gain) {return error_unsupported;}

  // Set auto exposure for camera.
  virtual ResultCode set_auto_exposure(bool auto_exposure) {return error_unsupported;}

  // Set exposure time limit for camera with auto exposure.
  virtual ResultCode set_exposure_limit(ExposureTime exposure_limit) {return error_unsupported;}

  // Set gain limit for camera with auto exposure.
  virtual ResultCode set_gain_limit(SensorGain gain_limit) {return error_unsupported;}

  // Set the region of interest for the camera.
  virtual ResultCode set_region(PlanarRegion region) {return error_unsupported;}

  // Set the flash illumination for the camera.
  virtual ResultCode set_flash_enabled(bool flash_enabled) {return error_unsupported;}

  // Set the flash strength for the camera.
  virtual ResultCode set_flash_strength(FlashStrength flash_strength) {return error_unsupported;}

  // Set the pattern illumination for the camera.
  virtual ResultCode set_pattern_enabled(bool pattern_enabled) {return error_unsupported;}

  // Set the next pattern for the camera.
  virtual ResultCode set_illumination_pattern(IlluminationPattern pattern) {return error_unsupported;}

private:

  // Handler for camera configuration query.
  void handle_configuration_query(ConfigurationService::Data& config) const;

  // Handler for camera command.
  void handle_command(CommandService::Data& command);

};

} // namespace i3ds

#endif