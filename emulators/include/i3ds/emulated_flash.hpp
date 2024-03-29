///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_EMULATED_FLASH_HPP
#define __I3DS__EMULATED_FLASH_HPP

#include <i3ds/flash.hpp>

#ifndef BOOST_LOG_DYN_LINK
#define BOOST_LOG_DYN_LINK
#endif


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;

namespace i3ds
{

class EmulatedFlash : public Flash
{
public:

  // Shared pointer for flash interfaces.
  typedef std::shared_ptr<EmulatedFlash> Ptr;

  static Ptr Create(i3ds_asn1::NodeID id)
  {
    return std::make_shared<EmulatedFlash>(id);
  }

  // Constructor for flash.
  EmulatedFlash(i3ds_asn1::NodeID node);

  // Destructor for flash.
  virtual ~EmulatedFlash();

  i3ds_asn1::ShutterTime duration() const {return duration_;}

  i3ds_asn1::FlashStrength strength() const {return strength_;}

protected:

  // Handler for flash setup command, must be overloaded.
  virtual void handle_flash(FlashService::Data& command);

private:

  i3ds_asn1::ShutterTime duration_;
  i3ds_asn1::FlashStrength strength_;
};

} // namespace i3ds

#endif
