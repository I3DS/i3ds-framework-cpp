///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_TOPIC_HPP
#define __I3DS_TOPIC_HPP

#include <functional>

#include <i3ds/communication.hpp>
#include <i3ds/codec.hpp>

namespace i3ds
{

template<i3ds_asn1::EndpointID E, typename T>
struct Topic
{
  static const i3ds_asn1::EndpointID endpoint = E;

  typedef T Codec;
  typedef typename T::Data Data;

  static void Initialize(Data& data)
  {
    Codec::Initialize(data);
  }
};

} // namespace i3ds

#endif
