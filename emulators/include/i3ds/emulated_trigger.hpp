///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_EMULATED_TRIGGER_HPP
#define __I3DS_EMULATED_TRIGGER_HPP

#include <memory>
#include <vector>

#include <i3ds/trigger.hpp>

#ifndef BOOST_LOG_DYN_LINK
#define BOOST_LOG_DYN_LINK
#endif


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;

namespace i3ds
{

class EmulatedTrigger : public Trigger
{
public:

  typedef std::shared_ptr<EmulatedTrigger> Ptr;

  static Ptr Create(i3ds_asn1::NodeID id)
  {
    return std::make_shared<EmulatedTrigger>(id);
  }

  EmulatedTrigger(i3ds_asn1::NodeID id);
  ~EmulatedTrigger();

  i3ds_asn1::TriggerPeriod period(i3ds_asn1::TriggerGenerator generator) const;
  i3ds_asn1::TriggerGenerator source(i3ds_asn1::TriggerOutput channel) const;
  i3ds_asn1::TriggerDuration duration(i3ds_asn1::TriggerOutput channel) const;
  i3ds_asn1::TriggerOffset offset(i3ds_asn1::TriggerOutput channel) const;
  bool inverted(i3ds_asn1::TriggerOutput channel) const;
  bool enabled(i3ds_asn1::TriggerOutput channel) const;

protected:

  // Handler for trigger generator command, must be overloaded.
  virtual void handle_generator(GeneratorService::Data& command);

  // Handler for trigger internal channel command, must be overloaded.
  virtual void handle_internal_channel(InternalChannelService::Data& command);

  // Handler for trigger external channel command, must be overloaded.
  virtual void handle_external_channel(ExternalChannelService::Data& command);

  // Handler for channel enable command, must be overloaded.
  virtual void handle_enable_channel(ChannelEnableService::Data& command);

  // Handler for channel disable command, must be overloaded.
  virtual void handle_disable_channel(ChannelDisableService::Data& command);

private:

  std::vector<i3ds_asn1::TriggerPeriod> generators_;
  std::vector<i3ds_asn1::ChannelInternal> channels_;
  std::vector<bool> enabled_;
};

} // namespace i3ds

#endif
