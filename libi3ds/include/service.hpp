///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_SERVICE_HPP
#define __I3DS_SERVICE_HPP

#include <functional>

#include "communication.hpp"

namespace i3ds
{

template<typename T1, typename T2>
struct Service
{
  typedef T1 RequestCodec;
  typedef T2 ResponseCodec;
  
  struct Data
  {
    typename RequestCodec::Data request;
    typename ResponseCodec::Data response;
  };
};

} // namespace i3ds

#endif