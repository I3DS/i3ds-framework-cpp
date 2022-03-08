///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_MODULE sensor_test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <thread>
#include <string>
#include <vector>
#include <iostream>

#include <i3ds/codec.hpp>
#include <i3ds/sensor.hpp>
#include <i3ds/sensor_client.hpp>
#include <i3ds/topic.hpp>
#include <i3ds/publisher.hpp>
#include <i3ds/subscriber.hpp>
#include <i3ds/periodic.hpp>

using namespace i3ds;
using namespace i3ds_asn1;

CODEC(T_UInt8);

class TestSensor : public Sensor
{
public:

  typedef Topic<128, T_UInt8Codec> MeasurementTopic;

  typedef std::shared_ptr<TestSensor> Ptr;

  TestSensor(Context::Ptr context, NodeID node);
  virtual ~TestSensor() = default;

  void test_callback_and_clear(std::string callback);
  void test_no_callback();

  virtual double temperature() const {return 300.0;}

  virtual bool is_sampling_supported(SampleCommand sample);

  bool send_sample(unsigned int timestamp_us);

protected:

  std::vector<std::string> callbacks;

  void log(std::string callback) {callbacks.push_back(callback);}

  virtual void do_activate() {log("do_activate");}
  virtual void do_start() {log("do_start"); sampler_.Start(period());}
  virtual void do_stop() {log("do_stop"); sampler_.Stop();}
  virtual void do_deactivate() {log("do_deactivate");}

private:
  Publisher publisher_;
  Sampler sampler_;
};

class TestClient : public SensorClient
{
public:

  typedef std::shared_ptr<TestClient> Ptr;

  TestClient(Context::Ptr context, NodeID sensor);

  ResultCode issue_state_command(StateCommand cmd);

  void test_legal_state_command(StateCommand cmd);
  void test_illegal_state_command(StateCommand cmd);

  ResultCode issue_sample_command(SamplePeriod period, BatchSize batch_size);

  void test_legal_sample_command(SamplePeriod period, BatchSize batch_size);
  void test_illegal_sample_command(SamplePeriod period, BatchSize batch_size, ResultCode error);
  void test_unsupported_sample_command(SamplePeriod period, BatchSize batch_size, ResultCode error);
};

TestSensor::TestSensor(Context::Ptr context, NodeID node) :
    Sensor(node),
    publisher_(context, node),
    sampler_([this](unsigned int ts){return send_sample(ts);})
{
  set_device_name("Test sensor");
}

void TestSensor::test_callback_and_clear(std::string callback)
{
  BOOST_CHECK_EQUAL(callbacks.size(), 1);
  BOOST_CHECK_EQUAL(callbacks[0], callback);

  callbacks.clear();
}

void TestSensor::test_no_callback()
{
  BOOST_CHECK_EQUAL(callbacks.size(), 0);
}

bool TestSensor::is_sampling_supported(SampleCommand sample)
{
  log("is_sampling_supported");

  return (1 <= sample.batch_size && sample.batch_size <= 10) &&
         (1000 <= sample.period && sample.period <= 1000000) &&
         (sample.batch_count <= 1000000);
}


bool TestSensor::send_sample(unsigned int timestamp_us)
{
  BOOST_TEST_MESSAGE("Sending message at " + timestamp_us);
  publisher_.Send<MeasurementTopic>(1);
  update_and_check_batch_count();
  return true;
}

TestClient::TestClient(Context::Ptr context, NodeID sensor)
  : SensorClient(context, sensor)
{
}

ResultCode TestClient::issue_state_command(StateCommand sc)
{
  Sensor::StateService::Data command;
  Sensor::StateService::Initialize(command);

  command.request = sc;

  Call<Sensor::StateService>(command);

  return command.response.result;
}

void TestClient::test_legal_state_command(StateCommand sc)
{
  ResultCode r = issue_state_command(sc);

  BOOST_CHECK_EQUAL(r, ResultCode_success);
}

void TestClient::test_illegal_state_command(StateCommand sc)
{
  try
    {
      issue_state_command(sc);
      BOOST_CHECK(false);
    }
  catch (CommandError& e)
    {
      BOOST_CHECK_EQUAL(e.result(), ResultCode_error_state);
    }
}

ResultCode TestClient::issue_sample_command(SamplePeriod period, BatchSize batch_size)
{
  Sensor::SampleService::Data command;
  Sensor::SampleService::Initialize(command);

  command.request.period = period;
  command.request.batch_size = batch_size;
  command.request.batch_count = 0;

  Call<Sensor::SampleService>(command);

  return command.response.result;
}

void TestClient::test_legal_sample_command(SamplePeriod period, BatchSize batch_size)
{
  ResultCode r = issue_sample_command(period, batch_size);

  BOOST_CHECK_EQUAL(r, ResultCode_success);
}

void TestClient::test_illegal_sample_command(SamplePeriod period, BatchSize batch_size, ResultCode error)
{
  try
    {
      issue_sample_command(period, batch_size);
      BOOST_CHECK(false);
    }
  catch (CommandError& e)
    {
      BOOST_CHECK_EQUAL(e.result(), error);
    }
}

////////////////////////////////////////////////////////////////////////////////

struct F
{
  F()
    : id(1),
      context(Context::Create()),
      server(context)
  {
    BOOST_TEST_MESSAGE("setup fixture");

    sensor = std::make_shared<TestSensor>(context, id);
    client = std::make_shared<TestClient>(context, id);

    sensor->Attach(server);
    client->set_timeout(2000);

    server.Start();
  }

  ~F()
  {
    BOOST_TEST_MESSAGE( "teardown fixture" );

    server.Stop();
  }

  const NodeID id;
  Context::Ptr context;
  Server server;

  TestSensor::Ptr sensor;
  TestClient::Ptr client;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(sensor_creation)
{
  BOOST_CHECK_EQUAL(sensor->node(), id);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_inactive);
  BOOST_CHECK_EQUAL(sensor->period(), 1000000);
  BOOST_CHECK_EQUAL(sensor->batch_size(), 1);
  BOOST_CHECK_EQUAL(sensor->batch_count(), 0);
  BOOST_CHECK_CLOSE(sensor->temperature(), 300.0, 0.01);
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(sensor_state_command)
{
  // Test commands from INACTIVE.
  client->test_illegal_state_command(StateCommand_start);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_inactive);
  sensor->test_no_callback();

  client->test_illegal_state_command(StateCommand_stop);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_inactive);
  sensor->test_no_callback();

  client->test_illegal_state_command(StateCommand_deactivate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_inactive);
  sensor->test_no_callback();

  client->test_legal_state_command(StateCommand_activate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  sensor->test_callback_and_clear("do_activate");

  // Test commands from STANDBY.
  client->test_illegal_state_command(StateCommand_activate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  sensor->test_no_callback();

  client->test_legal_state_command(StateCommand_deactivate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_inactive);
  sensor->test_callback_and_clear("do_deactivate");

  client->test_legal_state_command(StateCommand_activate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  sensor->test_callback_and_clear("do_activate");

  client->test_legal_state_command(StateCommand_start);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_operational);
  sensor->test_callback_and_clear("do_start");

  // Test commands from OPERATIONAL.
  client->test_illegal_state_command(StateCommand_start);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_operational);
  sensor->test_no_callback();

  client->test_illegal_state_command(StateCommand_deactivate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_operational);
  sensor->test_no_callback();

  client->test_illegal_state_command(StateCommand_activate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_operational);
  sensor->test_no_callback();

  client->test_legal_state_command(StateCommand_stop);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  sensor->test_callback_and_clear("do_stop");
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(sensor_sample_command)
{
  // Test from INACTIVE (illegal).
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_inactive);

  client->test_illegal_sample_command(10000, 1, ResultCode_error_state);
  sensor->test_no_callback();

  // Test from STANDBY (legal).
  client->test_legal_state_command(StateCommand_activate);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);

  client->test_legal_sample_command(1000, 2);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  BOOST_CHECK_EQUAL(sensor->period(), 1000);
  BOOST_CHECK_EQUAL(sensor->batch_size(), 2);

  client->load_all();
  BOOST_CHECK_EQUAL(client->period(), 1000);
  BOOST_CHECK_EQUAL(client->batch_size(), 2);

  client->test_illegal_sample_command(2000000, 1, ResultCode_error_value);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  BOOST_CHECK_EQUAL(sensor->period(), 1000);
  BOOST_CHECK_EQUAL(sensor->batch_size(), 2);

  client->test_legal_sample_command(2000, 3);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);
  BOOST_CHECK_EQUAL(sensor->period(), 2000);
  BOOST_CHECK_EQUAL(sensor->batch_size(), 3);

  client->test_illegal_sample_command(10, 1, ResultCode_error_value);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);

  client->test_illegal_sample_command(2000000, 1, ResultCode_error_value);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);

  client->test_illegal_sample_command(1000, 0, ResultCode_error_value);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);

  client->test_illegal_sample_command(1000, 100, ResultCode_error_value);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_standby);

  // Test from OPERATIONAL (illegal).
  client->test_legal_state_command(StateCommand_start);
  BOOST_CHECK_EQUAL(sensor->state(), SensorState_operational);

  client->test_illegal_sample_command(10000, 1, ResultCode_error_state);

}

////////////////////////////////////////////////////////////////////////////////

int received;

void
handle_measurement(TestSensor::MeasurementTopic::Data& data)
{
  received++;
  BOOST_CHECK_EQUAL(data, 1);
  BOOST_TEST_MESSAGE("Received measurement: " + data);
}

BOOST_AUTO_TEST_CASE(test_batch_count)
{
  received = 0;
  Subscriber subscriber(context);

  subscriber.Attach<TestSensor::MeasurementTopic>(client->node(), &handle_measurement);
  subscriber.Start();

  SamplePeriod period = 100000;
  BatchSize batch_size = 1;
  BatchCount batch_count = 5;

  client->set_state(StateCommand_activate);
  client->set_sampling(period, batch_size, batch_count);
  client->set_state(StateCommand_start);

  // Warmup
  std::this_thread::sleep_for(std::chrono::microseconds(period * 10));

  try {
    client->set_state(StateCommand_stop);
  } catch (CommandError& e) {
    // Ignore if already stopped
  }
  std::this_thread::sleep_for(std::chrono::microseconds(period * 10));

  received = 0;

  client->set_state(StateCommand_start);

  // Wait for measurements
  std::this_thread::sleep_for(std::chrono::microseconds(period * 10));

  try {
    client->set_state(StateCommand_stop);
  } catch (CommandError& e) {
    // Ignore if already stopped
  }

  subscriber.Stop();

  BOOST_CHECK_EQUAL(received, batch_count);
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(test_device_name)
{
  client->test_legal_state_command(StateCommand_activate);
  client->load_all();
  BOOST_CHECK_EQUAL(client->device_name(), "Test sensor");
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
