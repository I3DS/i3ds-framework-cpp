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

#include <i3ds/emulated_tof_camera.hpp>

i3ds::EmulatedToFCamera::Ptr
i3ds::EmulatedToFCamera::Create(Context::Ptr context, i3ds_asn1::NodeID node)
{
  return std::make_shared<EmulatedToFCamera>(context, node);
}

i3ds::EmulatedToFCamera::EmulatedToFCamera(Context::Ptr context, i3ds_asn1::NodeID node)
  : ToFCamera(node),
    sampler_(std::bind(&i3ds::EmulatedToFCamera::send_sample, this, std::placeholders::_1)),
    publisher_(context, node)
{
  BOOST_LOG_TRIVIAL(info) << "Create emulated ToF camera with NodeID: " << node;

  min_depth_ = 10;
  max_depth_ = 1e4;

  region_.size_x = 640;
  region_.size_y = 480;
  region_.offset_x = 0;
  region_.offset_y = 0;

  MeasurementTopic::Codec::Initialize(frame_);

  frame_.descriptor.width = region_.size_x;
  frame_.descriptor.height = region_.size_y;

  set_device_name("Emulated ToF camera");
}

i3ds::EmulatedToFCamera::~EmulatedToFCamera()
{
  BOOST_LOG_TRIVIAL(info) << "Destroy emulated ToF camera with NodeID: " << node();
}

void
i3ds::EmulatedToFCamera::do_activate()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " do_activate()";
}

void
i3ds::EmulatedToFCamera::do_start()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " do_start()";
  sampler_.Start(period());
}

void
i3ds::EmulatedToFCamera::do_stop()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " do_stop()";
  sampler_.Stop();
}

void
i3ds::EmulatedToFCamera::do_deactivate()
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " do_deactivate()";
}

bool
i3ds::EmulatedToFCamera::is_sampling_supported(i3ds_asn1::SampleCommand sample)
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " is_period_supported()";
  return sample.batch_size == 1 && (0 < sample.period && sample.period <= 10000000);
}

void
i3ds::EmulatedToFCamera::handle_region(RegionService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " handle_region()";
  region_enabled_ = command.request.enable;

  if (command.request.enable)
    {
      region_ = command.request.region;
    }
}

void
i3ds::EmulatedToFCamera::handle_range(RangeService::Data& command)
{
  BOOST_LOG_TRIVIAL(info) << "Emulated ToF camera with NodeID: " << node() << " handle_range()";

  check_standby();

  min_depth_ = std::max(command.request.min_depth, 0.0);
  max_depth_ = command.request.max_depth;
}

bool
i3ds::EmulatedToFCamera::send_sample(unsigned long timestamp_us)
{
  BOOST_LOG_TRIVIAL(trace) << "Emulated ToF camera with NodeID: " << node() << " sends sample at " << timestamp_us;

  frame_.descriptor.attributes.timestamp = timestamp_us;
  frame_.descriptor.attributes.validity = i3ds_asn1::SampleValidity_sample_valid;

  std::uniform_real_distribution<float> d(min_depth_, max_depth_);

  for (unsigned int i = 0; i < frame_.descriptor.width; i++)
    {
      for (unsigned int j = 0; j < frame_.descriptor.height; j++)
	{
	  frame_.depths.push_back(d(generator_));
	}
    }

  publisher_.Send<MeasurementTopic>(frame_);

  frame_.depths.clear();

  return true;
}
