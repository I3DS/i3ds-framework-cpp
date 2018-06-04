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

i3ds::Sensor::Sensor(NodeID node)
  : node_(node)
{
  state_ = inactive;
  period_ = 0.0;
  batch_size_ = 1;
  batch_count_ = 0;
}

i3ds::Sensor::~Sensor()
{
}

void
i3ds::Sensor::check_inactive() const
{
  if (!is_inactive())
    {
      throw CommandError(error_state, "Sensor is not in inactive state");
    }
}

void
i3ds::Sensor::check_active() const
{
  if (!is_active())
    {
      throw CommandError(error_state, "Sensor is not in active state");
    }
}

void
i3ds::Sensor::check_standby() const
{
  if (!is_standby())
    {
      throw CommandError(error_state, "Sensor is not in standby state");
    }
}

void
i3ds::Sensor::check_operational() const
{
  if (!is_operational())
    {
      throw CommandError(error_state, "Sensor is not in operational state");
    }
}

void
i3ds::Sensor::check_failure() const
{
  if (!is_failure())
    {
      throw CommandError(error_state, "Sensor is not in failure state");
    }
}

void
i3ds::Sensor::check_sampling_supported(SampleCommand sample)
{
  if (!is_sampling_supported(sample))
    {
      throw CommandError(error_value, "Sample configuration not supported");
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
i3ds::Sensor::handle_state(StateService::Data& command)
{
  ResultCode result = error_state;

  switch(state_)
    {
    case inactive:
      if (command.request == activate)
        {
          do_activate();
          state_ = standby;
          result = success;
        }
      break;

    case standby:
      if (command.request == deactivate)
        {
          do_deactivate();
          state_ = inactive;
          result = success;
        }
      else if (command.request == start)
        {
          do_start();
          state_ = operational;
          result = success;
        }
      break;

    case operational:
      if (command.request == stop)
        {
          do_stop();
          state_ = standby;
          result = success;
        }
      break;

    default:
      break;
    }

  command.response.result = result;
}

void
i3ds::Sensor::handle_sample(SampleService::Data& sample)
{
  check_standby();
  check_sampling_supported(sample.request);

  period_ = sample.request.period;
  batch_size_ = sample.request.batch_size;
  batch_count_ = sample.request.batch_count;
}

void
i3ds::Sensor::handle_status(StatusService::Data& status) const
{
  status.response.state = state();
  status.response.temperature.kelvin = temperature();
}

void
i3ds::Sensor::handle_configuration(ConfigurationService::Data& config) const
{
  config.response.period = period();
  config.response.batch_size = batch_size();
  config.response.batch_count = batch_count();
}
