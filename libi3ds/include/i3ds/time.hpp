///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_TIME_HPP
#define __I3DS_TIME_HPP

#include <i3ds_asn1/Common.hpp>
#include <i3ds_asn1/Sensor.hpp>

#include <chrono>

namespace i3ds
{

typedef std::chrono::high_resolution_clock clock;

inline i3ds_asn1::Timepoint to_timestamp(clock::time_point t)
{
  using namespace std::chrono;
  return (i3ds_asn1::Timepoint) duration_cast<microseconds>(t.time_since_epoch()).count();
}

inline i3ds_asn1::Timepoint get_timestamp()
{
  return to_timestamp(clock::now());
}

inline clock::duration to_duration(i3ds_asn1::SamplePeriod period)
{
  return std::chrono::microseconds(period);
}

}

#endif
