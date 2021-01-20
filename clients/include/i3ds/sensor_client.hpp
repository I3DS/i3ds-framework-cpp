///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_SENSOR_CLIENT_HPP
#define __I3DS_SENSOR_CLIENT_HPP

#include <i3ds/client.hpp>
#include <i3ds/sensor.hpp>

namespace i3ds
{

class SensorClient : public Client
{
public:

  typedef std::shared_ptr<SensorClient> Ptr;

  SensorClient(Context::Ptr context, i3ds_asn1::NodeID sensor);

  // Returns true if sensor is in inactive state.
  inline bool is_inactive() const {return state() == i3ds_asn1::SensorState_inactive;}

  // Returns true if sensor is in active state.
  inline bool is_active() const {return state() == i3ds_asn1::SensorState_standby || state() == i3ds_asn1::SensorState_operational;}

  // Returns true if sensor is in standby state.
  inline bool is_standby() const {return state() == i3ds_asn1::SensorState_standby;}

  // Returns true if sensor is in operational state.
  inline bool is_operational() const {return state() == i3ds_asn1::SensorState_operational;}

  // Returns true if sensor is in failure state.
  inline bool is_failure() const {return state() == i3ds_asn1::SensorState_failure;}

  // State helper functions.
  inline void Activate()   {set_state(i3ds_asn1::StateCommand_activate);}
  inline void Deactivate() {set_state(i3ds_asn1::StateCommand_deactivate);}
  inline void Start()      {set_state(i3ds_asn1::StateCommand_start);}
  inline void Stop()       {set_state(i3ds_asn1::StateCommand_stop);}

  void set_state(i3ds_asn1::StateCommand state);
  void set_sampling(i3ds_asn1::SamplePeriod period, i3ds_asn1::BatchSize batch_size = 1, i3ds_asn1::BatchCount batch_count = 0);

  i3ds_asn1::SensorState state() const {return status_.response.current_state;}
  i3ds_asn1::Base_Temperature temperature() const {return status_.response.device_temperature;}
  i3ds_asn1::SamplePeriod period() const {return config_.response.period;}
  i3ds_asn1::BatchSize batch_size() const {return config_.response.batch_size;}
  i3ds_asn1::BatchCount batch_count() const {return config_.response.batch_count;}

  std::string device_name() const {return std::string((const char*)config_.response.device_name.arr, config_.response.device_name.nCount);}

  void load_status();
  virtual void load_config();
  virtual void load_all();

private:

  Sensor::StatusService::Data status_;
  Sensor::ConfigurationService::Data config_;
};

} // namespace i3ds

#endif
