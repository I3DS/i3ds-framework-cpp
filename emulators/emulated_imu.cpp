///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_LOG_DYN_LINK
#define BOOST_LOG_DYN_LINK
#endif

#include <boost/log/trivial.hpp>

#include <i3ds/emulated_imu.hpp>

i3ds::EmulatedIMU::EmulatedIMU(Context::Ptr context, i3ds_asn1::NodeID node)
  : IMU(node),
    sampler_(std::bind(&i3ds::EmulatedIMU::send_sample, this, std::placeholders::_1)),
    publisher_(context, node)
{
  BOOST_LOG_TRIVIAL(info) << "Create emulated IMU with NodeID: " << node;
  IMUMeasurement20Codec::Initialize(frame_);
  set_device_name("Emulated IMU");
}

i3ds::EmulatedIMU::~EmulatedIMU()
{
  BOOST_LOG_TRIVIAL(info) << "Destroy emulated IMU with NodeID: " << node();
}

void
i3ds::EmulatedIMU::do_activate()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated IMU with NodeID: " << node() << " do_activate()";
}

void
i3ds::EmulatedIMU::do_start()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated IMU with NodeID: " << node() << " do_start()";
  sampler_.Start(period());
}

void
i3ds::EmulatedIMU::do_stop()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated IMU with NodeID: " << node() << " do_stop()";
  sampler_.Stop();
}

void
i3ds::EmulatedIMU::do_deactivate()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated IMU with NodeID: " << node() << " do_deactivate()";
}

bool
i3ds::EmulatedIMU::is_sampling_supported(i3ds_asn1::SampleCommand sample)
{
  BOOST_LOG_TRIVIAL(info) << "Emulated IMU with NodeID: " << node() << " is_period_supported()";
  return sample.batch_size == 1 && (0 < sample.period && sample.period <= 10000000);
}

bool
i3ds::EmulatedIMU::send_sample(unsigned long timestamp_us)
{
  BOOST_LOG_TRIVIAL(trace) << "Emulated IMU with NodeID: " << node() << " sends sample at " << timestamp_us;

  frame_.attributes.timestamp = timestamp_us;
  frame_.attributes.validity = i3ds_asn1::SampleValidity_sample_valid;

  frame_.batch_size = 1;
  frame_.samples.nCount = 1;

  frame_.samples.arr[0].axis_x_rate = 1.0;
  frame_.samples.arr[0].axis_x_acceleration = 2.0;
  frame_.samples.arr[0].axis_y_rate = 3.0;
  frame_.samples.arr[0].axis_y_acceleration = 4.0;
  frame_.samples.arr[0].axis_z_rate = 5.0;
  frame_.samples.arr[0].axis_z_acceleration = 6.0;


  publisher_.Send<MeasurementTopic>(frame_);

  return true;
}
