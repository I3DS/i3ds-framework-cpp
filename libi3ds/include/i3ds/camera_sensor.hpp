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

#include <i3ds_asn1/Camera.hpp>

#include <i3ds/frame.hpp>
#include <i3ds/sensor.hpp>
#include <i3ds/service.hpp>
#include <i3ds/codec.hpp>
#include <i3ds/topic.hpp>

namespace i3ds
{

CODEC(CameraExposure);
CODEC(CameraAutoExposure);
CODEC(CameraRegion);
CODEC(CameraFlash);
CODEC(CameraPattern);
CODEC(CameraImgSequence);
CODEC(CameraConfiguration);

class Camera : public Sensor
{
public:

  // Shared pointer for camera interfaces.
  typedef std::shared_ptr<Camera> Ptr;

  // Camera services.
  typedef Command<16, CameraExposureCodec>      ExposureService;
  typedef Command<17, CameraAutoExposureCodec>  AutoExposureService;
  typedef Command<18, CameraRegionCodec>        RegionService;
  typedef Command<19, CameraFlashCodec>         FlashService;
  typedef Command<20, CameraPatternCodec>       PatternService;
  typedef Query  <21, CameraConfigurationCodec> ConfigurationService;
  typedef Command<22, CameraImgSequenceCodec>   SequenceService;

  // Camera topics
  typedef Topic<128, FrameCodec> FrameTopic;

  // Constructor for camera.
  Camera(i3ds_asn1::NodeID node) : Sensor(node) {};

  // Destructor for camera.
  virtual ~Camera() {};

  // Get shutter time for camera in microseconds.
  virtual i3ds_asn1::ShutterTime shutter() const = 0;

  // Get gain for camera in decibel.
  virtual i3ds_asn1::SensorGain gain() const = 0;

  // Get auto exposure for camera.
  virtual bool auto_exposure_enabled() const {return false;}

  // Get shutter time limit for camera with auto exposure in microseconds.
  virtual i3ds_asn1::ShutterTime max_shutter() const {return 0;}

  // Get gain limit for camera with auto exposure in decibel.
  virtual i3ds_asn1::SensorGain max_gain() const {return 0.0;}

  // Get the region of interest enabled for camera.
  virtual bool region_enabled() const {return false;}

  // Get the region of interest for the camera.
  virtual i3ds_asn1::PlanarRegion region() const {return {0,0,0,0};}

  // Get the flash illumination for the camera.
  virtual bool flash_enabled() const {return false;}

  // Get the flash strength for the camera.
  virtual i3ds_asn1::FlashStrength flash_strength() const {return 0;}

  // Get the pattern illumination for the camera.
  virtual bool pattern_enabled() const {return false;}

  // Get the pattern sequence for the camera.
  virtual i3ds_asn1::PatternSequence pattern_sequence() const {return 0;}

  // sequence stream is enabled
  virtual bool image_sequence_enabled() const { return false; }

  // Get the current position in the image sequence
  virtual i3ds_asn1::ImageSequence image_sequence() const { return 0; }
  virtual i3ds_asn1::ImageSequence image_max_sequence() const { return 0; }

  // Ready sensor for next image in sequence, will return false if
  // no more images should be added to sequence
  virtual bool image_sequence_ready_next() { return false; }
  virtual void image_sequence_reset() {};

  // Attach handlers to the server.
  virtual void Attach(Server& server);

protected:

  // Handler for camera exposure command, must be overloaded.
  virtual void handle_exposure(ExposureService::Data& command) = 0;

  // Handler for camera auto exposure command.
  virtual void handle_auto_exposure(AutoExposureService::Data& command);

  // Handler for camera region command.
  virtual void handle_region(RegionService::Data& command);

  // Handler for camera flash command.
  virtual void handle_flash(FlashService::Data& command);

  // Handler for camera pattern command.
  virtual void handle_pattern(PatternService::Data& command);

  // handler for camera sequence command
  virtual void handle_sequence(SequenceService::Data& command);

  // Handler for camera configuration query.
  virtual void handle_configuration(ConfigurationService::Data& config);
};

} // namespace i3ds

#endif
