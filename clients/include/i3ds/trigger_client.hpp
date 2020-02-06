///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_TRIGGER_CLIENT_HPP
#define __I3DS_TRIGGER_CLIENT_HPP

#include <i3ds/client.hpp>
#include <i3ds/trigger.hpp>

#include <set>

namespace i3ds
{

typedef std::set<i3ds_asn1::TriggerOutput> TriggerOutputSet;

class TriggerClient : public Client
{
public:

  typedef std::shared_ptr<TriggerClient> Ptr;

  TriggerClient(Context::Ptr context, i3ds_asn1::NodeID node);

  void set_generator(i3ds_asn1::TriggerGenerator generator, i3ds_asn1::TriggerPeriod period);

  void set_internal_channel(i3ds_asn1::TriggerOutput channel, i3ds_asn1::TriggerGenerator source, i3ds_asn1::TriggerOffset offset,
                            i3ds_asn1::TriggerDuration duration, bool invert);

  void set_external_channel(i3ds_asn1::TriggerOutput channel, i3ds_asn1::TriggerInput source, 
                            i3ds_asn1::TriggerOffset offset, i3ds_asn1::TriggerDuration duration,
                            bool bypass, bool invert);

  void enable_channels(const TriggerOutputSet& channels);
  void disable_channels(const TriggerOutputSet& channels);
};

} // namespace i3ds

#endif
