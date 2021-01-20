///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018-2019 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_POINTCLOUD_HPP
#define __I3DS_POINTCLOUD_HPP


#include <i3ds_asn1/PointCloud.hpp>
#include <i3ds_asn1/taste-types.hpp>
#include <i3ds/codec.hpp>

#include <vector>

namespace i3ds
{

CODEC(PointCloudDescriptor);

struct PointXYZ
{
  float x;
  float y;
  float z;
};

struct PointCloud
{
  i3ds_asn1::PointCloudDescriptor descriptor;
  std::vector<PointXYZ> points;
};

struct PointCloudCodec
{
  typedef PointCloud Data;

  static inline void Initialize(Data& val)
  {
    PointCloudDescriptorCodec::Initialize(val.descriptor);
    val.descriptor.point_format = i3ds_asn1::Point_format_t_fields_xyz_f;
    val.descriptor.point_size = sizeof(PointXYZ);
    val.points.clear();
  };

  static inline i3ds_asn1::flag Encode(const Data* val, i3ds_asn1::BitStream* pBitStrm, int* pErrCode,
                                       i3ds_asn1::flag bCheckConstraints)
  {
    return PointCloudDescriptorCodec::Encode(&(val->descriptor), pBitStrm, pErrCode, bCheckConstraints);
  }

  static inline i3ds_asn1::flag Decode(Data* pVal, i3ds_asn1::BitStream* pBitStrm, int* pErrCode)
  {
    return PointCloudDescriptorCodec::Decode(&pVal->descriptor, pBitStrm, pErrCode);
  }

};

////////////////////////////////////////////////////////////////////////////////
/// Template specialization for frame codec, sets multipart message
////////////////////////////////////////////////////////////////////////////////

template<>
inline void Encode<PointCloudCodec>(Message& message, const PointCloudCodec::Data& data)
{
  Encode<PointCloudDescriptorCodec>(message, data.descriptor);

  const i3ds_asn1::byte* d = reinterpret_cast<const i3ds_asn1::byte*>(data.points.data());
  const size_t s = data.points.size() * sizeof(PointXYZ);

  message.append_payload(d, s);
}

////////////////////////////////////////////////////////////////////////////////
/// Template specialization for frame codes, reads multipart message
////////////////////////////////////////////////////////////////////////////////

template<>
inline void Decode<PointCloudCodec>(const Message& message, PointCloudCodec::Data& data)
{
  Decode<PointCloudDescriptorCodec>(message, data.descriptor);

  const PointXYZ* d = reinterpret_cast<const PointXYZ*>(message.data(1));
  const size_t s = message.size(1) / sizeof(PointXYZ);

  data.points.assign(d, d + s);
}

} // namespace i3ds

#endif // __I3DS_POINTCLOUD_HPP
