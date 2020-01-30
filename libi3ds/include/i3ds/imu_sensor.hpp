///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_IMU_HPP
#define __I3DS_IMU_HPP

#include <i3ds_asn1/IMU.hpp>

#include <i3ds/topic.hpp>
#include <i3ds/sensor.hpp>
#include <i3ds/service.hpp>
#include <i3ds/codec.hpp>

namespace i3ds
{

CODEC(IMUMeasurement20);

class IMU : public Sensor
{
public:

  typedef Topic<128, IMUMeasurement20Codec> MeasurementTopic;

  // Shared pointer for IMU interfaces.
  typedef std::shared_ptr<IMU> Ptr;

  // Constructor and destructor.
  IMU(i3ds_asn1::NodeID node) : Sensor(node) {};
  virtual ~IMU() {};

};

} // namespace i3ds

#endif
