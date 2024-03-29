///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_FRAME_HPP
#define __I3DS_FRAME_HPP

#include <cstdlib>
#include <cstring>
#include <i3ds_asn1/Frame.hpp>
#include <i3ds/codec.hpp>
#include <i3ds_asn1/asn1crt.hpp>
#include <vector>

namespace i3ds
{

CODEC(FrameDescriptor);

struct FrameCodec;

inline size_t image_size(const i3ds_asn1::FrameDescriptor& desc)
{
  return desc.region.size_x  * desc.region.size_y * desc.pixel_size;
}

class Frame
{
public:

  Frame() : copied_(false) {};
  
  ~Frame()
  {
    if (copied_)
      {
        for (Image image : image_)
          {
            free((void*)(image.data));
          }
      }
  }

  Frame(const Frame& other)
  {
    descriptor = other.descriptor;
    for (Image image : other.image_)
      {
        i3ds_asn1::byte* data_copy = static_cast<i3ds_asn1::byte*>(malloc(image.size));
        memcpy(data_copy, image.data, image.size);
        image_.push_back({data_copy, image.size});
      }
    copied_ = true;
  }

  Frame& operator=(const Frame& other)
  {
    this->descriptor = other.descriptor;
    if (this->image_.size() == other.image_.size() &&
        this->image_.size() > 0 &&
        this->image_size(0) == other.image_size(0))
      {
        for (int i = 0; i < other.images(); ++i)
          {
            i3ds_asn1::byte* non_const_ptr = const_cast<i3ds_asn1::byte*>(this->image_data(i));
            memcpy(non_const_ptr, other.image_data(i), this->image_size(i));
          }
      }
    else
      {
        this->image_.clear();
        for (Image image : other.image_)
          {
            i3ds_asn1::byte* data_copy = static_cast<i3ds_asn1::byte*>(malloc(image.size));
            memcpy(data_copy, image.data, image.size);
            image_.push_back({data_copy, image.size});
          }
      }
    copied_ = true;
    return *this;
  }

  i3ds_asn1::FrameDescriptor descriptor;

  inline int images() const {return image_.size();}

  inline size_t image_size(int i) const {return image_.at(i).size;}
  inline const i3ds_asn1::byte* image_data(int i) const {return image_.at(i).data;}

  inline void append_image(const i3ds_asn1::byte* data, size_t size) {image_.push_back({data, size});}
  inline void clear_images() {image_.clear();}

private:

  struct Image
  {
    const i3ds_asn1::byte* data;
    size_t size;
  };

  std::vector<Image> image_;
  bool copied_;
};

struct FrameCodec
{
  typedef Frame Data;

  static const int max_size = FrameDescriptorCodec::max_size;

  static inline void Initialize(Data& val)
  {
    FrameDescriptorCodec::Initialize(val.descriptor);
    val.clear_images();
  };

  static inline i3ds_asn1::flag Encode(const Data* val, i3ds_asn1::BitStream* pBitStrm, int* pErrCode, i3ds_asn1::flag bCheckConstraints)
  {
    return FrameDescriptorCodec::Encode(&(val->descriptor), pBitStrm, pErrCode, bCheckConstraints);
  }

  static inline i3ds_asn1::flag Decode(Data* pVal, i3ds_asn1::BitStream* pBitStrm, int* pErrCode)
  {
    return FrameDescriptorCodec::Decode(&pVal->descriptor, pBitStrm, pErrCode);
  }
};

////////////////////////////////////////////////////////////////////////////////
/// Template specialization for frame codec, sets multipart message
////////////////////////////////////////////////////////////////////////////////

template<>
inline void Encode<FrameCodec>(Message& message, const FrameCodec::Data& data)
{
  Encode<FrameDescriptorCodec>(message, data.descriptor);

  for (int i = 0; i < data.images(); i++)
    {
      message.append_payload(data.image_data(i), data.image_size(i));
    }
}

////////////////////////////////////////////////////////////////////////////////
/// Template specialization for frame codes, reads multipart message
////////////////////////////////////////////////////////////////////////////////

template<>
inline void Decode<FrameCodec>(const Message& message, FrameCodec::Data& data)
{
  Decode<FrameDescriptorCodec>(message, data.descriptor);

  data.clear_images();

  for (int i = 1; i < data.descriptor.image_count+1; i++)
    {
      data.append_image(message.data(i), message.size(i));
    }
}

} // namespace i3ds

#endif
