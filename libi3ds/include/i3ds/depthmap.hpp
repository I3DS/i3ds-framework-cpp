///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018-2019 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_DEPTHMAP_HPP
#define __I3DS_DEPTHMAP_HPP

#include <i3ds_asn1/DepthMap.hpp>
#include <i3ds_asn1/taste-types.hpp>

#include <i3ds/codec.hpp>
#include <i3ds/frame.hpp>
#include <vector>

namespace i3ds
{

CODEC(DepthMapDescriptor);

struct DepthMap
{
  i3ds_asn1::DepthMapDescriptor descriptor;
  std::vector<float> depths;
  Frame frame;
  bool has_frame = false;
};

struct DepthMapCodec
{
  typedef DepthMap Data;

  static inline void Initialize(Data& val)
  {
    DepthMapDescriptorCodec::Initialize(val.descriptor);
    val.descriptor.depth_format = i3ds_asn1::Depth_format_t_depth_f;
    val.descriptor.depth_size = sizeof(float);
    val.depths.clear();
    FrameCodec::Initialize(val.frame);
  };

  static inline i3ds_asn1::flag Encode(const Data* val, i3ds_asn1::BitStream* pBitStrm, int* pErrCode,
                                       i3ds_asn1::flag bCheckConstraints)
  {
    return DepthMapDescriptorCodec::Encode(&(val->descriptor), pBitStrm, pErrCode, bCheckConstraints);
  }

  static inline i3ds_asn1::flag Decode(Data* pVal, i3ds_asn1::BitStream* pBitStrm, int* pErrCode)
  {
    return DepthMapDescriptorCodec::Decode(&pVal->descriptor, pBitStrm, pErrCode);
  }

};

////////////////////////////////////////////////////////////////////////////////
/// Template specialization for frame codec, sets multipart message
////////////////////////////////////////////////////////////////////////////////

template<>
inline void Encode<DepthMapCodec>(Message& message, const DepthMapCodec::Data& data)
{
  Encode<DepthMapDescriptorCodec>(message, data.descriptor);

  const i3ds_asn1::byte* d = reinterpret_cast<const i3ds_asn1::byte*>(data.depths.data());
  const size_t s = data.depths.size() * sizeof(float);

  message.append_payload(d, s);

  if (data.has_frame)
    {
      Encode<FrameCodec>(message, data.frame);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Template specialization for frame codes, reads multipart message
////////////////////////////////////////////////////////////////////////////////

template<>
inline void Decode<DepthMapCodec>(const Message& message, DepthMapCodec::Data& data)
{
  Decode<DepthMapDescriptorCodec>(message, data.descriptor);

  const float* d = reinterpret_cast<const float*>(message.data(1));
  const size_t s = message.size(1) / sizeof(float);

  data.depths.assign(d, d + s);
  
  if (message.payloads() > 2)
    {
      // Decode message.data(2) as FrameDescriptor frame.descriptor
      i3ds_asn1::BitStream bs;
      i3ds_asn1::BitStream_AttachBuffer(&bs, (unsigned char*) message.data(2), message.size(2));
 
      int errcode = 0;

      if (!FrameDescriptorCodec::Decode(&data.frame.descriptor, &bs, &errcode))
        {
          throw CodecError("Cannot decode: Bad data " + std::to_string(errcode));
        }

      // Decode message.data(3) as Frame::Image.
      data.frame.clear_images();
      data.frame.append_image(message.data(3), message.size(3));
      data.has_frame = true;
    }
  else
    {
      data.has_frame = false;
    }
}

} // namespace i3ds

#endif // __I3DS_DEPTHMAP_HPP
