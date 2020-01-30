///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_ANALOG_HPP
#define __I3DS_ANALOG_HPP

#include <i3ds_asn1/Analog.hpp>

#include <i3ds/topic.hpp>
#include <i3ds/sensor.hpp>
#include <i3ds/service.hpp>
#include <i3ds/codec.hpp>
#include <i3ds/analogseries.hpp>

namespace i3ds
{

class Analog : public Sensor
{
public:

  // Topic definitions.
  typedef Topic<128, AnalogSeriesCodec> MeasurementTopic;

  // Shared pointer for Analog interfaces.
  typedef std::shared_ptr<Analog> Ptr;

  // Constructor and destructor.
  Analog(i3ds_asn1::NodeID node, i3ds_asn1::SeriesCount series_count) : Sensor(node), series_count_(series_count) {};
  virtual ~Analog() {};

  // Get the number of series per measurement (number of channels)
  i3ds_asn1::SeriesCount series_count() const {return series_count_;}

private:

  const i3ds_asn1::SeriesCount series_count_;

};

} // namespace i3ds

#endif
