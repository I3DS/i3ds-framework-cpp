///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2020 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_MODULE camera_merger_test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <chrono>

#include <cstring>
#include <cstdlib>

#include <i3ds/subscriber.hpp>

#include <i3ds/emulated_camera.hpp>
#include <i3ds/camera_merger.hpp>

#include <i3ds/camera_client.hpp>
#include <i3ds/common_tests.hpp>

#include <i3ds/frame.hpp>

using namespace i3ds;
using namespace i3ds_asn1;

////////////////////////////////////////////////////////////////////////////////

struct F
{
  F()
   :

     context(Context::Create()),
     cam_1_server(context),
     cam_2_server(context),
     cam_merger_server(context),
     cam_merger(context, cam_merger_node, cam_1_node, cam_2_node),
     client(context, cam_merger_node),
     cam_1_buffer(nullptr),
     cam_2_buffer(nullptr),
     cam_1_merged_buffer(nullptr),
     cam_2_merged_buffer(nullptr),
     cam_1_buffer_valid(false),
     cam_2_buffer_valid(false),
     cam_merger_buffer_valid(false),
     received(0)
    {
      BOOST_TEST_MESSAGE("setup fixture");

      cam_1_param.camera_name = "cam_1";
      cam_1_param.image_count = 1;
      cam_1_param.external_trigger = false;
      cam_1_param.support_flash = false;
      cam_1_param.support_pattern = false;

      cam_1_param.frame_mode  = Frame_mode_t_mode_mono;
      cam_1_param.data_depth  = 8;
      cam_1_param.pixel_size  = 1;

      cam_1_param.width = 10;
      cam_1_param.height = 10;

      cam_1_param.sample_dir = "";

      cam_2_param = cam_1_param;
      cam_2_param.camera_name = "cam_2";

      cam_1 = EmulatedCamera::Create(context, cam_1_node, cam_1_param);
      cam_1->Attach(cam_1_server);
      cam_1_server.Start();
      cam_2 = EmulatedCamera::Create(context, cam_2_node, cam_2_param);
      cam_2->Attach(cam_2_server);
      cam_2_server.Start();

      cam_merger.Attach(cam_merger_server);
      cam_merger_server.Start();

      client.set_timeout(1000000);

    }

  ~F()
    {
      BOOST_TEST_MESSAGE("teardown fixture");
      cam_1_server.Stop();
      cam_2_server.Stop();
      cam_merger_server.Stop();
      free(cam_1_buffer);
      free(cam_2_buffer);
      free(cam_1_merged_buffer);
      free(cam_2_merged_buffer);
    }

  void put_frame_in_buffer(Camera::FrameTopic::Data& data, byte** buffer, int image);
  void handle_measurement(Camera::FrameTopic::Data& data, NodeID id);

  static constexpr NodeID cam_1_node = 1;
  static constexpr NodeID cam_2_node = 2;
  static constexpr NodeID cam_merger_node = 3;

  Context::Ptr context;

  EmulatedCamera::Parameters cam_1_param;
  EmulatedCamera::Parameters cam_2_param;

  Server cam_1_server;
  Server cam_2_server;
  Server cam_merger_server;

  EmulatedCamera::Ptr cam_1;
  EmulatedCamera::Ptr cam_2;
  CameraMerger cam_merger;

  SensorClient client;

  byte* cam_1_buffer;
  byte* cam_2_buffer;
  byte* cam_1_merged_buffer;
  byte* cam_2_merged_buffer;

  bool cam_1_buffer_valid;
  bool cam_2_buffer_valid;
  bool cam_merger_buffer_valid;

  unsigned int received;
};

void
F::put_frame_in_buffer(Camera::FrameTopic::Data& data, byte** buffer, int image)
{
  if (*buffer == nullptr)
    {
      *buffer = static_cast<byte*>(malloc(data.image_size(image)));
    }
  memcpy(*buffer, data.image_data(image), data.image_size(image));
}

void
F::handle_measurement(Camera::FrameTopic::Data& data, NodeID id)
{
  switch(id)
    {
    case cam_1_node:
      put_frame_in_buffer(data, &cam_1_buffer, 0);
      cam_1_buffer_valid = true;
      break;
    case cam_2_node:
      put_frame_in_buffer(data, &cam_2_buffer, 0);
      cam_2_buffer_valid = true;
      break;
    case cam_merger_node:
      put_frame_in_buffer(data, &cam_1_merged_buffer, 0);
      put_frame_in_buffer(data, &cam_2_merged_buffer, 1);
      cam_merger_buffer_valid = true;
      break;
    }

  if (cam_1_buffer_valid && cam_2_buffer_valid && cam_merger_buffer_valid)
    {
      received++;
      size_t img_size = image_size(data.descriptor);
      for (unsigned int i = 0; i < img_size; ++i)
        {
          BOOST_CHECK_EQUAL(cam_1_buffer[i], cam_1_merged_buffer[i]);
          BOOST_CHECK_EQUAL(cam_2_buffer[i], cam_2_merged_buffer[i]);
        }
      cam_1_buffer_valid = false;
      cam_2_buffer_valid = false;
      cam_merger_buffer_valid = false;
    }
}

BOOST_FIXTURE_TEST_SUITE(s, F)

    ////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(state_transitions)
{
  BOOST_CHECK_EQUAL(cam_1->state(), SensorState_inactive);
  BOOST_CHECK_EQUAL(cam_2->state(), SensorState_inactive);

  client.set_state(StateCommand_activate);
  BOOST_CHECK_EQUAL(cam_1->state(), SensorState_standby);
  BOOST_CHECK_EQUAL(cam_2->state(), SensorState_standby);

  client.set_state(StateCommand_start);
  BOOST_CHECK_EQUAL(cam_1->state(), SensorState_operational);
  BOOST_CHECK_EQUAL(cam_2->state(), SensorState_operational);

  client.set_state(StateCommand_stop);
  BOOST_CHECK_EQUAL(cam_1->state(), SensorState_standby);
  BOOST_CHECK_EQUAL(cam_2->state(), SensorState_standby);

  client.set_state(StateCommand_deactivate);
  BOOST_CHECK_EQUAL(cam_1->state(), SensorState_inactive);
  BOOST_CHECK_EQUAL(cam_2->state(), SensorState_inactive);
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(configure_period)
{
  SamplePeriod period = 100000;
  BatchSize batch_size = 2;
  BatchCount batch_count = 8;

  client.set_state(StateCommand_activate);
  client.set_sampling(period, batch_size, batch_count);

  BOOST_CHECK_EQUAL(cam_1->period(), period);
  BOOST_CHECK_EQUAL(cam_2->period(), period);
  BOOST_CHECK_EQUAL(cam_merger.period(), period);
  BOOST_CHECK_EQUAL(cam_merger.batch_size(), batch_size);
  BOOST_CHECK_EQUAL(cam_merger.batch_count(), batch_count);
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(measurements)
{
  Subscriber subscriber(context);

  subscriber.Attach<Camera::FrameTopic>(cam_1_node,
                                        [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_1_node);});
  subscriber.Attach<Camera::FrameTopic>(cam_2_node,
                                        [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_2_node);});
  subscriber.Attach<CameraMerger::FrameTopic>(cam_merger_node,
                                              [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_merger_node);});

  SamplePeriod period = 200000;

  client.set_state(StateCommand_activate);
  client.set_sampling(period);
  client.set_state(StateCommand_start);

  subscriber.Start();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));

  client.set_state(StateCommand_stop);

  subscriber.Stop();

  BOOST_CHECK_GT(received, 0);

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(single_measurement)
{
  received = 0;
  Subscriber subscriber(context);

  subscriber.Attach<Camera::FrameTopic>(cam_1_node,
                                        [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_1_node);});
  subscriber.Attach<Camera::FrameTopic>(cam_2_node,
                                        [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_2_node);});
  subscriber.Attach<CameraMerger::FrameTopic>(cam_merger_node,
                                              [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_merger_node);});

  SamplePeriod period = 200000;
  BatchSize batch_size = 1;
  BatchCount batch_count = 1;

  client.set_state(StateCommand_activate);
  client.set_sampling(period, batch_size, batch_count);
  client.set_state(StateCommand_start);

  subscriber.Start();

  // Warmup
  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));

  try {
    client.set_state(StateCommand_stop);
  } catch (CommandError& e) {
    // Ignore if already stopped
  }
  std::this_thread::sleep_for(std::chrono::microseconds(period));

  received = 0;
  client.set_state(StateCommand_start);

  // Wait for measurements
  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));

  try {
    client.set_state(StateCommand_stop);
  } catch (CommandError& e) {
    // Ignore if already stopped
  }

  subscriber.Stop();

  BOOST_CHECK_EQUAL(received, batch_count);

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(synchronizing_measurements)
{
  Subscriber subscriber(context);

  subscriber.Attach<Camera::FrameTopic>(cam_1_node,
                                        [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_1_node);});
  subscriber.Attach<Camera::FrameTopic>(cam_2_node,
                                        [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_2_node);});
  subscriber.Attach<CameraMerger::FrameTopic>(cam_merger_node,
                                              [this](Camera::FrameTopic::Data& data){handle_measurement(data, cam_merger_node);});

  SamplePeriod period = 200000;

  client.set_state(StateCommand_activate);
  client.set_sampling(period);
  client.set_state(StateCommand_start);

  subscriber.Start();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));

  BOOST_CHECK_GT(received, 0);
  received = 0;

  SensorClient cam_1_client(context, cam_1_node);
  cam_1_client.set_state(StateCommand_stop);
  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));
  cam_1_client.set_state(StateCommand_start);
  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));

  client.set_state(StateCommand_stop);

  subscriber.Stop();

  BOOST_CHECK_GT(received, 0);

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
