#include <boost/test/tools/old/interface.hpp>
#include <cstdlib>
#define BOOST_TEST_MODULE depthmap_test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <chrono>
#include <random>

#include <i3ds/depthmap.hpp>

using namespace i3ds;

BOOST_AUTO_TEST_CASE(depthmap_encdec)
{
  std::random_device r;
  std::default_random_engine gen(r());
  std::uniform_real_distribution<> dis_real(0.0, 1.0);

  size_t n_nums = 1000;

  DepthMap map;

  DepthMapCodec::Initialize(map);
  
  map.depths.reserve(n_nums);

  for (size_t i=0; i < n_nums; i++)
    {
      map.depths.push_back(dis_real(gen));
    }

  BOOST_CHECK_EQUAL(map.depths.size(), 1000);

  Message message;
  Encode<DepthMapCodec>(message, map);
  BOOST_CHECK_EQUAL(message.payloads(), 2);

  DepthMap map2;
  Decode<DepthMapCodec>(message, map2);

  BOOST_CHECK_EQUAL(map.depths.size(), map2.depths.size());

  for (size_t i = 0; i < n_nums; i++)
    {
      const auto d = map.depths[i];
      const auto d2 = map2.depths[i];
      
      BOOST_CHECK_EQUAL(d, d2);
    }
}

BOOST_AUTO_TEST_CASE(depthmap_with_frame_encdec)
{
  std::random_device r;
  std::default_random_engine gen(r());
  std::uniform_real_distribution<> dis_real(0.0, 1.0);

  size_t n_nums = 1000;

  DepthMap map;

  DepthMapCodec::Initialize(map);
  
  map.depths.reserve(n_nums);

  for (size_t i=0; i < n_nums; i++)
    {
      map.depths.push_back(dis_real(gen));
    }

  BOOST_CHECK_EQUAL(map.depths.size(), 1000);

  const unsigned int frame_height = 480;
  const unsigned int frame_width = 640;

  map.frame.descriptor.image_count = 1;
  map.frame.descriptor.frame_mode  = i3ds_asn1::Frame_mode_t_mode_mono;
  map.frame.descriptor.data_depth  = 16;
  map.frame.descriptor.pixel_size  = 2;
  map.frame.descriptor.region.size_x = frame_width;
  map.frame.descriptor.region.size_y = frame_height;

  size_t image_data_size = frame_width * frame_height * map.frame.descriptor.pixel_size;
  i3ds_asn1::byte *image_data = static_cast<i3ds_asn1::byte *>(malloc(image_data_size));

  std::uniform_int_distribution<> dis_int(0, 255);

  for (size_t i = 0; i < image_data_size; i++)
    {
      image_data[i] = dis_int(gen);
    }

  map.frame.append_image(image_data, image_data_size);
  map.has_frame = true;

  Message message;
  Encode<DepthMapCodec>(message, map);
  BOOST_CHECK_EQUAL(message.payloads(), 4);

  DepthMap map2;
  Decode<DepthMapCodec>(message, map2);

  BOOST_CHECK_EQUAL(map.depths.size(), map2.depths.size());

  for (size_t i = 0; i < n_nums; i++)
    {
      const auto d = map.depths[i];
      const auto d2 = map2.depths[i];
      
      BOOST_CHECK_EQUAL(d, d2);
    }

  BOOST_CHECK_EQUAL(map2.has_frame, true);

  BOOST_CHECK_EQUAL(map.frame.descriptor.image_count, map2.frame.descriptor.image_count);
  BOOST_CHECK_EQUAL(map.frame.descriptor.frame_mode, map2.frame.descriptor.frame_mode);
  BOOST_CHECK_EQUAL(map.frame.descriptor.data_depth, map2.frame.descriptor.data_depth);
  BOOST_CHECK_EQUAL(map.frame.descriptor.pixel_size, map2.frame.descriptor.pixel_size);
  BOOST_CHECK_EQUAL(map.frame.descriptor.region.size_x, map2.frame.descriptor.region.size_x);
  BOOST_CHECK_EQUAL(map.frame.descriptor.region.size_y, map2.frame.descriptor.region.size_y);
  
  BOOST_CHECK_EQUAL(map.frame.image_size(0), map2.frame.image_size(0));

  for (size_t i = 0; i < image_data_size; i++)
    {
      BOOST_CHECK_EQUAL(map.frame.image_data(0)[i], map2.frame.image_data(0)[i]);
    }

  free(image_data);
}