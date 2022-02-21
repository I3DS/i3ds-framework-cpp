///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_SENSOR_HPP
#define __I3DS_SENSOR_HPP

#include <memory>
#include <mutex>
#include <atomic>

#include <i3ds_asn1/Common.hpp>
#include <i3ds_asn1/Sensor.hpp>

#include <i3ds/node.hpp>
#include <i3ds/communication.hpp>
#include <i3ds/service.hpp>
#include <i3ds/server.hpp>
#include <i3ds/codec.hpp>
#include <i3ds/exception.hpp>

namespace i3ds
{

CODEC(StateCommand);
CODEC(SampleCommand);
CODEC(SensorStatus);
CODEC(SensorConfiguration);

class Sensor : public Node
{
public:

  // Shared pointer for sensor interfaces.
  typedef std::shared_ptr<Sensor> Ptr;

  // Service definitions for basic sensor.
  typedef Command<1, StateCommandCodec>        StateService;
  typedef Command<2, SampleCommandCodec>       SampleService;
  typedef Query  <3, SensorStatusCodec>        StatusService;
  typedef Query  <4, SensorConfigurationCodec> ConfigurationService;

  // Constructor.
  Sensor(i3ds_asn1::NodeID node);

  // Virtual destructor.
  virtual ~Sensor();

  // Throws exception if sensor is not in inactive state.
  void check_inactive() const;

  // Throws exception if sensor is not in active state.
  void check_active() const;

  // Throws exception if sensor is not in standby state.
  void check_standby() const;

  // Throws exception if sensor is not in operational state.
  void check_operational() const;

  // Throws exception if sensor is not in failure state.
  void check_failure() const;

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

  // Get sensor state.
  inline i3ds_asn1::SensorState state() const {return state_;}

  // Get sensor period in microseconds between samples.
  inline i3ds_asn1::SamplePeriod period() const {return period_;}

  // Get number of samples per batch.
  inline i3ds_asn1::BatchSize batch_size() const {return batch_size_;}

  // Get number of batches to acquire when operational (0 is infinite).
  inline i3ds_asn1::BatchCount batch_count() const {return batch_count_;}

  // Get name of sensor implementation
  virtual i3ds_asn1::T_String device_name() const {return device_name_;}

  // Get temperature in Kelvin (defaults to 0.0).
  virtual double temperature() const {return 0.0;}

  // Throws exception if sample configuration is not supported.
  void check_sampling_supported(i3ds_asn1::SampleCommand sample);

  // Returns true if sample configuration is supported.
  virtual bool is_sampling_supported(i3ds_asn1::SampleCommand sample) = 0;

  // Attach handlers to the server.
  virtual void Attach(Server& server);

protected:

  // Sensor action when activated.
  virtual void do_activate() = 0;

  // Sensor action when started.
  virtual void do_start() = 0;

  // Sensor action when activated.
  virtual void do_stop() = 0;

  // Sensor action when activated.
  virtual void do_deactivate() = 0;

  // Sensor action on failure.
  virtual void do_failure() {};

  // Set sensor in failure state.
  void set_failure();

  // Set the name of the sensor implementation
  void set_device_name(std::string device_name);

  // Set the state of the sensor
  // Only use this if the default state handling needs to be overridden
  // and never inside the other state change methods: do_*
  void set_state(i3ds_asn1::SensorState new_state);

private:

  // Handler for state command.
  void handle_state(StateService::Data& command);

  // Handler for sample configuration.
  virtual void handle_sample(SampleService::Data& sample);

  // Handler for sensor status query.
  void handle_status(StatusService::Data& status);

  // Handler for sensor configuration query.
  void handle_configuration(ConfigurationService::Data& config);

  std::atomic<i3ds_asn1::SensorState> state_;
  i3ds_asn1::SamplePeriod period_;
  i3ds_asn1::BatchSize batch_size_;
  i3ds_asn1::BatchCount batch_count_;
  i3ds_asn1::T_String device_name_;

  std::mutex state_change_mutex;
};

} // namespace i3ds

#endif
