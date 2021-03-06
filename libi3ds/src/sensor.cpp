///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include <i3ds/sensor.hpp>

i3ds::Sensor::Sensor(i3ds_asn1::NodeID node)
  : Node(node)
{
  // Sensors are initially inactive.
  state_ = i3ds_asn1::inactive;

  // Default setting one sample at 1 Hz.
  period_ = 1000000;
  batch_size_ = 1;
  batch_count_ = 0;

  T_String_Initialize(&device_name_);
}

i3ds::Sensor::~Sensor()
{
}

void
i3ds::Sensor::check_inactive() const
{
  if (!is_inactive())
    {
      throw CommandError(i3ds_asn1::error_state, "Sensor is not in inactive state");
    }
}

void
i3ds::Sensor::check_active() const
{
  if (!is_active())
    {
      throw CommandError(i3ds_asn1::error_state, "Sensor is not in active state");
    }
}

void
i3ds::Sensor::check_standby() const
{
  if (!is_standby())
    {
      throw CommandError(i3ds_asn1::error_state, "Sensor is not in standby state");
    }
}

void
i3ds::Sensor::check_operational() const
{
  if (!is_operational())
    {
      throw CommandError(i3ds_asn1::error_state, "Sensor is not in operational state");
    }
}

void
i3ds::Sensor::check_failure() const
{
  if (!is_failure())
    {
      throw CommandError(i3ds_asn1::error_state, "Sensor is not in failure state");
    }
}

void
i3ds::Sensor::check_sampling_supported(i3ds_asn1::SampleCommand sample)
{
  if (!is_sampling_supported(sample))
    {
      throw CommandError(i3ds_asn1::error_value, "Sample configuration not supported");
    }
}

void
i3ds::Sensor::Attach(Server& server)
{
  using std::placeholders::_1;

  server.Attach<StateService>(node(), std::bind(&i3ds::Sensor::handle_state, this, _1));
  server.Attach<SampleService>(node(), std::bind(&i3ds::Sensor::handle_sample, this, _1));
  server.Attach<StatusService>(node(), std::bind(&i3ds::Sensor::handle_status, this, _1));
  server.Attach<ConfigurationService>(node(), std::bind(&i3ds::Sensor::handle_configuration, this, _1));
}

void
i3ds::Sensor::set_failure()
{
  if (state_ != i3ds_asn1::failure)
    {
      do_failure();
      state_ = i3ds_asn1::failure;
    }
}

void
i3ds::Sensor::handle_state(StateService::Data& command)
{
  i3ds_asn1::ResultCode result = i3ds_asn1::error_state;

  try
    {
      switch(state_)
        {
        case i3ds_asn1::inactive:
          if (command.request == i3ds_asn1::activate)
            {
              do_activate();
              state_ = i3ds_asn1::standby;
              result = i3ds_asn1::success;
            }
          else if (command.request == i3ds_asn1::deactivate)
            {
              set_string(command.response.message, "Already in inactivate state, ignoring command.");
            }
          else
            {
              set_string(command.response.message, "Command not allowed for inactive state.");
            }

          break;

        case i3ds_asn1::standby:
          if (command.request == i3ds_asn1::deactivate)
            {
              do_deactivate();
              state_ = i3ds_asn1::inactive;
              result = i3ds_asn1::success;
            }
          else if (command.request == i3ds_asn1::start)
            {
              do_start();
              state_ = i3ds_asn1::operational;
              result = i3ds_asn1::success;
            }
          else if (command.request == i3ds_asn1::activate)
            {
              set_string(command.response.message, "Already in standby state, ignoring command");
            }
          else if (command.request == i3ds_asn1::stop)
            {
              set_string(command.response.message, "Command not allowed for standby state.");
            }

          break;

        case i3ds_asn1::operational:
          if (command.request == i3ds_asn1::stop)
            {
              do_stop();
              state_ = i3ds_asn1::standby;
              result = i3ds_asn1::success;
            }
          else if (command.request == i3ds_asn1::start)
            {
              set_string(command.response.message,"Already in operational state, ignoring command.");
            }
          else
            {
              set_string(command.response.message,"Command not allowed for operational state");
            }
          break;

        case i3ds_asn1::failure:
          if (command.request == i3ds_asn1::deactivate)
            {
              do_deactivate();
              state_ = i3ds_asn1::inactive;
              result = i3ds_asn1::success;
            }
          else
            {
              set_string(command.response.message, "In failure state, only deactivate command is allowed.");
            }
          break;

        default:
          break;
        }

      command.response.result = result;
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::error_other, e.what());
    }
}

void
i3ds::Sensor::handle_sample(SampleService::Data& sample)
{
  check_standby();

  try
    {
      check_sampling_supported(sample.request);

      period_ = sample.request.period;
      batch_size_ = sample.request.batch_size;
      batch_count_ = sample.request.batch_count;
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::error_other, e.what());
    }
}

void
i3ds::Sensor::handle_status(StatusService::Data& status)
{
  try
    {
      status.response.current_state = state();
      status.response.device_temperature.kelvin = temperature();
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::error_other, e.what());
    }
}

void
i3ds::Sensor::handle_configuration(ConfigurationService::Data& config)
{
  check_active();

  try
    {
      config.response.device_name = device_name();
      config.response.period = period();
      config.response.batch_size = batch_size();
      config.response.batch_count = batch_count();
    }
  catch (DeviceError& e)
    {
      set_failure();
      throw CommandError(i3ds_asn1::error_other, e.what());
    }
}

void
i3ds::Sensor::set_device_name(std::string device_name)
{
  strncpy((char*)device_name_.arr, device_name.c_str(), 40);
  device_name_.nCount = strlen((const char*)device_name_.arr);
}
