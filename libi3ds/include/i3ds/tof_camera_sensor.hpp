///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_TOF_CAMERA_HPP
#define __I3DS_TOF_CAMERA_HPP

#include <i3ds/ToFCamera.h>

#include <i3ds/sensor.hpp>
#include <i3ds/service.hpp>
#include <i3ds/codec.hpp>
#include <i3ds/topic.hpp>

namespace i3ds
{

CODEC(ToFRegion);
CODEC(ToFConfiguration);

CODEC(ToFMeasurement250K);
CODEC(ToFMeasurement500K);
CODEC(ToFMeasurement1M);
CODEC(ToFMeasurement2M);

class ToFCamera : public Sensor
{
public:

  // Shared pointer for ToF camera interfaces.
  typedef std::shared_ptr<ToFCamera> Ptr;

  // ToFCamera services.
  typedef Command<16, ToFRegionCodec>        RegionService;
  typedef Query  <17, ToFConfigurationCodec> ConfigurationService;

  // ToFCamera topics.
  typedef Topic<128, ToFMeasurement250KCodec> Measurement250KTopic;
  typedef Topic<129, ToFMeasurement500KCodec> Measurement500KTopic;
  typedef Topic<130, ToFMeasurement1MCodec> Measurement1MTopic;
  typedef Topic<131, ToFMeasurement2MCodec> Measurement2MTopic;

  // Constructor and destructor.
  ToFCamera(NodeID node) : Sensor(node) {};
  virtual ~ToFCamera() {};

  // Get the region of interest enabled for ToF-camera.
  virtual bool region_enabled() const {return false;}

  // Get the region of interest for the ToF-camera.
  virtual PlanarRegion region() const {return {0,0,0,0};}

  // Attach handlers to the server.
  virtual void Attach(Server& server);

protected:

  // Handler for ToF-camera region of interest command.
  virtual void handle_region(RegionService::Data& command);

  // Handler for camera configuration query.
  virtual void handle_configuration(ConfigurationService::Data& config) const;
};

} // namespace i3ds

#endif
