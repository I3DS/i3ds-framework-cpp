///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_MODULE pose_estimator_test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <chrono>

#include <i3ds/subscriber.hpp>
#include <i3ds/emulated_pose_estimator.hpp>
#include <i3ds/pose_estimator_client.hpp>
#include <i3ds/common_tests.hpp>

using namespace i3ds;

////////////////////////////////////////////////////////////////////////////////

struct F
{
  F()
    : node(1),
      context(Context::Create()),
      server(context),
      pe(EmulatedPoseEstimator::Create(context, node)),
      client(PoseEstimatorClient::Create(context, node))
  {
    BOOST_TEST_MESSAGE("setup fixture");
    pe->Attach(server);
    server.Start();
    client->set_timeout(1000);
  }

  ~F()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );
    server.Stop();
  }

  const NodeID node;

  Context::Ptr context;
  Server server;
  EmulatedPoseEstimator::Ptr pe;
  PoseEstimatorClient::Ptr client;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(star_tracker_creation)
{
  test_sensor_creation(pe, node);
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(star_tracker_sample_settings)
{
  test_sample_settings(client);
}

////////////////////////////////////////////////////////////////////////////////

int received;

void
handle_measurement(PoseEstimator::MeasurementTopic::Data& data)
{
  BOOST_TEST_MESSAGE("Recv: " << data.attributes.timestamp);

  BOOST_CHECK_EQUAL(data.estimated_pose.position.data.nCount, 3);
  BOOST_CHECK_EQUAL(data.estimated_pose.position.data.arr[0], 1.0);
  BOOST_CHECK_EQUAL(data.estimated_pose.position.data.arr[1], 2.0);
  BOOST_CHECK_EQUAL(data.estimated_pose.position.data.arr[2], 3.0);

  BOOST_CHECK_EQUAL(data.estimated_pose.orientation.im.nCount,  3);
  BOOST_CHECK_EQUAL(data.estimated_pose.orientation.im.arr[0], 1.0);
  BOOST_CHECK_EQUAL(data.estimated_pose.orientation.im.arr[1], 2.0);
  BOOST_CHECK_EQUAL(data.estimated_pose.orientation.im.arr[2], 3.0);
  BOOST_CHECK_EQUAL(data.estimated_pose.orientation.re, 4.0);

  received++;
}

BOOST_AUTO_TEST_CASE(pose_estimator_sampling)
{
  received = 0;
  Subscriber subscriber(context);

  subscriber.Attach<PoseEstimator::MeasurementTopic>(client->node(), &handle_measurement);


  SamplePeriod period = 100000;

  client->set_state(activate);
  client->set_sampling(period);
  client->set_state(start);

  subscriber.Start();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 5));

  client->set_state(stop);

  subscriber.Stop();

  BOOST_CHECK_GT(received, 0);
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()