///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <i3ds/sensor_client.hpp>

i3ds::SensorClient::SensorClient(Context::Ptr context, i3ds_asn1::NodeID sensor)
  : Client(context, sensor)
{
  Sensor::StatusService::Initialize(status_);
  Sensor::ConfigurationService::Initialize(config_);
}

void
i3ds::SensorClient::load_status()
{
  Call<Sensor::StatusService>(status_);
}

void
i3ds::SensorClient::load_config()
{
  Call<Sensor::ConfigurationService>(config_);
}
void
i3ds::SensorClient::load_all()
{
  load_status();

  if (is_active())
    {
      load_config();
    }
}

void
i3ds::SensorClient::set_state(i3ds_asn1::StateCommand state)
{
  Sensor::StateService::Data command;
  Sensor::StateService::Initialize(command);

  command.request = state;

  Call<Sensor::StateService>(command);
}

void
i3ds::SensorClient::set_sampling(i3ds_asn1::SamplePeriod period, i3ds_asn1::BatchSize batch_size, i3ds_asn1::BatchCount batch_count)
{
  Sensor::SampleService::Data command;
  Sensor::SampleService::Initialize(command);

  command.request.period = period;
  command.request.batch_size = batch_size;
  command.request.batch_count = batch_count;

  Call<Sensor::SampleService>(command);
}
