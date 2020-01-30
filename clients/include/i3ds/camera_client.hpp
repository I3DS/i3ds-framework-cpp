///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_CAMERA_CLIENT_HPP
#define __I3DS_CAMERA_CLIENT_HPP

#include <i3ds/sensor_client.hpp>
#include <i3ds/camera_sensor.hpp>

namespace i3ds
{

class CameraClient : public SensorClient
{
public:

  typedef std::shared_ptr<CameraClient> Ptr;
  static Ptr Create(Context::Ptr context, i3ds_asn1::NodeID id)
  {
    return std::make_shared<CameraClient>(context, id);
  }

  CameraClient(Context::Ptr context, i3ds_asn1::NodeID sensor);

  void set_exposure(i3ds_asn1::ShutterTime shutter, i3ds_asn1::SensorGain gain);
  void set_auto_exposure(bool enable, i3ds_asn1::ShutterTime max_shutter, i3ds_asn1::SensorGain max_gain);
  void set_region(bool enable, i3ds_asn1::PlanarRegion region);
  void set_flash(bool enable, i3ds_asn1::FlashStrength strength);
  void set_pattern(bool enable, i3ds_asn1::PatternSequence sequence);

  i3ds_asn1::ShutterTime shutter() const {return config_.response.shutter;}
  i3ds_asn1::SensorGain gain() const {return config_.response.gain;}
  bool auto_exposure_enabled() const {return config_.response.auto_exposure_enabled;}
  i3ds_asn1::ShutterTime max_shutter() const {return config_.response.max_shutter;}
  i3ds_asn1::SensorGain max_gain() const {return config_.response.max_gain;}
  bool region_enabled() const {return config_.response.region_enabled;}
  i3ds_asn1::PlanarRegion region() const {return config_.response.region;}
  bool flash_enabled() const {return config_.response.flash_enabled;}
  i3ds_asn1::FlashStrength flash_strength() const {return config_.response.flash_strength;}
  bool pattern_enabled() const {return config_.response.pattern_enabled;}
  i3ds_asn1::PatternSequence pattern_sequence() const {return config_.response.pattern_sequence;}

  virtual void load_config();

private:

  Camera::ConfigurationService::Data config_;

};

} // namespace i3ds

#endif
