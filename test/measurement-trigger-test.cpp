///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2022 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#define BOOST_TEST_MODULE measurement_trigger_test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <chrono>
#include <stdexcept>

#include <i3ds/measurement_trigger.hpp>
#include <i3ds/address_server.hpp>
#include <i3ds/subscriber.hpp>
#include <i3ds/emulated_imu.hpp>
#include <i3ds/imu_client.hpp>

using namespace i3ds;
using namespace i3ds_asn1;

////////////////////////////////////////////////////////////////////////////////

struct F
{
  F()
    : node(20),
      context(Context::Create()),
      imu(EmulatedIMU::Create(context, node)),
      imu_command_server(context),
      client(context, node)
  {
    imu->Attach(imu_command_server);
    imu_command_server.Start();
    client.set_timeout(1000);
  }

  ~F()
  {
    imu_command_server.Stop();
  }

  const NodeID node;
  Context::Ptr context;
  EmulatedIMU::Ptr imu;
  Server imu_command_server;
  IMUClient client;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

////////////////////////////////////////////////////////////////////////////////

int received_count;

void
check_measurement(IMU::MeasurementTopic::Data& data)
{
  BOOST_CHECK_EQUAL(data.samples.nCount, 1);
  BOOST_CHECK_EQUAL(data.samples.arr[0].axis_x_rate, 1.0);
  BOOST_CHECK_EQUAL(data.samples.arr[0].axis_x_acceleration, 2.0);
  BOOST_CHECK_EQUAL(data.samples.arr[0].axis_y_rate, 3.0);
  BOOST_CHECK_EQUAL(data.samples.arr[0].axis_y_acceleration, 4.0);
  BOOST_CHECK_EQUAL(data.samples.arr[0].axis_z_rate, 5.0);
  BOOST_CHECK_EQUAL(data.samples.arr[0].axis_z_acceleration, 6.0);
}

void
handle_measurement(IMU::MeasurementTopic::Data& data)
{
  BOOST_TEST_MESSAGE("Subscriber received msg at: " << data.attributes.timestamp);
  check_measurement(data);
  received_count++;
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(trigger_from_active)
{
  MeasurementTrigger<IMU::MeasurementTopic> trigger(context, node, true);
  received_count = 0;

  Subscriber subscriber(context);

  subscriber.Attach<IMU::MeasurementTopic>(client.node(), &handle_measurement);
  SamplePeriod period = 1000000;

  client.set_state(StateCommand_activate);
  client.set_sampling(period);
  subscriber.Start();

  trigger.trigger();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 2));

  BOOST_CHECK_GE(received_count, 1);

  check_measurement(trigger.fetch());
  trigger.trigger();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 2));

  BOOST_CHECK_GE(received_count, 2);
  subscriber.Stop();
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(trigger_from_operational)
{
  MeasurementTrigger<IMU::MeasurementTopic> trigger(context, node, true);
  received_count = 0;

  Subscriber subscriber(context);

  subscriber.Attach<IMU::MeasurementTopic>(client.node(), &handle_measurement);
  SamplePeriod period = 1000000;

  client.set_state(StateCommand_activate);
  client.set_sampling(period);
  client.set_state(StateCommand_start);
  subscriber.Start();

  trigger.trigger();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 2));

  BOOST_CHECK_GE(received_count, 1);

  check_measurement(trigger.fetch());
  trigger.trigger();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 2));

  BOOST_CHECK_GE(received_count, 2);
  subscriber.Stop();
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(fetch_exception)
{
  MeasurementTrigger<IMU::MeasurementTopic> trigger(context, node);
  received_count = 0;

  Subscriber subscriber(context);

  subscriber.Attach<IMU::MeasurementTopic>(client.node(), &handle_measurement);
  SamplePeriod period = 1000000;

  client.set_state(StateCommand_activate);
  client.set_sampling(period);
  subscriber.Start();

  IMU::MeasurementTopic::Data data;
  BOOST_CHECK_THROW(data = trigger.fetch(), std::logic_error);

  trigger.trigger();

  std::this_thread::sleep_for(std::chrono::microseconds(period * 2));

  BOOST_CHECK_GE(received_count, 1);
  BOOST_CHECK_THROW(data = trigger.fetch(), std::logic_error);
  subscriber.Stop();
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
