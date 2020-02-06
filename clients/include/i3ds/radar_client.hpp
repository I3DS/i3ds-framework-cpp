///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_RADAR_CLIENT_HPP
#define __I3DS_RADAR_CLIENT_HPP

#include <i3ds/sensor_client.hpp>
#include <i3ds/radar_sensor.hpp>

namespace i3ds
{

class RadarClient : public SensorClient
{
public:

  typedef std::shared_ptr<RadarClient> Ptr;
  static Ptr Create(Context::Ptr context, i3ds_asn1::NodeID id)
  {
    return std::make_shared<RadarClient>(context, id);
  }

  RadarClient(Context::Ptr context, i3ds_asn1::NodeID sensor);
  void set_region(bool enable, i3ds_asn1::PlanarRegion region);

  bool region_enabled() const {return config_.response.region_enabled;}
  i3ds_asn1::PlanarRegion region() const {return config_.response.region;}

  virtual void load_config();

private:

  Radar::ConfigurationService::Data config_;
};

} // namespace i3ds

#endif
