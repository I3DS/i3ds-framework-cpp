///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <i3ds/flash_client.hpp>

i3ds::FlashClient::FlashClient(Context::Ptr context, i3ds_asn1::NodeID node)
  : Client(context, node)
{
}

void
i3ds::FlashClient::set_flash(i3ds_asn1::ShutterTime duration, i3ds_asn1::FlashStrength strength)
{
  Flash::FlashService::Data command;
  Flash::FlashService::Initialize(command);

  command.request.duration = duration;
  command.request.strength = strength;

  Call<Flash::FlashService>(command);
}
