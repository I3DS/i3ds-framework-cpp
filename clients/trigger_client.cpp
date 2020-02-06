///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <i3ds/trigger_client.hpp>

i3ds::TriggerClient::TriggerClient(Context::Ptr context, i3ds_asn1::NodeID node)
  : Client(context, node)
{
}

void
i3ds::TriggerClient::set_generator(i3ds_asn1::TriggerGenerator generator, i3ds_asn1::TriggerPeriod period)
{
  Trigger::GeneratorService::Data command;

  command.request.source = generator;
  command.request.period = period;

  Call<Trigger::GeneratorService>(command);
}

void
i3ds::TriggerClient::set_internal_channel(i3ds_asn1::TriggerOutput channel, i3ds_asn1::TriggerGenerator source, 
                                          i3ds_asn1::TriggerOffset offset,  i3ds_asn1::TriggerDuration duration, bool invert)
{
  Trigger::InternalChannelService::Data command;

  Trigger::InternalChannelService::Initialize(command);

  command.request.output_channel = channel;
  command.request.source = source;
  command.request.offset = offset;
  command.request.duration = duration;
  command.request.invert = invert;

  Call<Trigger::InternalChannelService>(command);
}

void
i3ds::TriggerClient::set_external_channel(i3ds_asn1::TriggerOutput channel, i3ds_asn1::TriggerInput source, i3ds_asn1::TriggerOffset offset,
    i3ds_asn1::TriggerDuration duration,
    bool bypass, bool invert)
{
  Trigger::ExternalChannelService::Data command;

  Trigger::ExternalChannelService::Initialize(command);

  command.request.output_channel = channel;
  command.request.source = source;
  command.request.offset = offset;
  command.request.duration = duration;
  command.request.bypass = bypass;
  command.request.invert = invert;

  Call<Trigger::ExternalChannelService>(command);
}

void
i3ds::TriggerClient::enable_channels(const TriggerOutputSet& channels)
{
  Trigger::ChannelEnableService::Data command;

  Trigger::ChannelEnableService::Initialize(command);

  int code = 0;

  for (i3ds_asn1::TriggerOutput c : channels)
    {
      if (i3ds_asn1::TriggerOutput_IsConstraintValid(&c, &code))
        {
          command.request.arr[c - 1] = true;
        }
      else
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Invalid output channel " + std::to_string(c));
        }
    }

  Call<Trigger::ChannelEnableService>(command);
}

void
i3ds::TriggerClient::disable_channels(const TriggerOutputSet& channels)
{
  Trigger::ChannelDisableService::Data command;

  Trigger::ChannelDisableService::Initialize(command);

  int code = 0;

  for (i3ds_asn1::TriggerOutput c : channels)
    {
      if (i3ds_asn1::TriggerOutput_IsConstraintValid(&c, &code))
        {
          command.request.arr[c - 1] = true;
        }
      else
        {
          throw i3ds::CommandError(i3ds_asn1::error_value, "Invalid output channel " + std::to_string(c));
        }
    }

  Call<Trigger::ChannelDisableService>(command);
}

