///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <csignal>
#include <cmath>
#include <cstring>
#include <atomic>

#include <i3ds/subscriber.hpp>
#include <i3ds/lidar_sensor.hpp>
#include <i3ds/configurator.hpp>

#ifndef BOOST_LOG_DYN_LINK
#define BOOST_LOG_DYN_LINK
#endif

#include <boost/log/trivial.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

std::atomic<bool> running;

void
signal_handler(int)
{
  running = false;
}

void
handle_frame(i3ds::LIDAR::MeasurementTopic::Data& data)
{
  const int n = data.points.size();

  double d_max = 0.0;
  double d_min = 1.0e10;
  double d_sum = 0.0;

  for (int i = 0; i < n; i++)
    {
      const double x = data.points[i].x;
      const double y = data.points[i].y;
      const double z = data.points[i].z;

      const double d = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

      if (d > d_max) { d_max = d; }
      if (d < d_min) { d_min = d; }

      d_sum += d;
    }

  BOOST_LOG_TRIVIAL(info) << "***********************************************";
  BOOST_LOG_TRIVIAL(info) << "LIDAR point-cloud size: " << n;
  BOOST_LOG_TRIVIAL(info) << "LIDAR max distance:     " << d_max;
  BOOST_LOG_TRIVIAL(info) << "LIDAR min distance:     " << d_min;
  BOOST_LOG_TRIVIAL(info) << "LIDAR avg distance:     " << d_sum / n;
}

int main(int argc, char *argv[])
{
  int node;
  po::options_description desc("Displays data about LIDAR stream");
  i3ds::Configurator configurator;
  configurator.add_common_options(desc);
  desc.add_options()
  ("node,n", po::value<int>(&node)->default_value(10), "Node ID of camera")
  ;

  po::variables_map vm = configurator.parse_common_options(desc, argc, argv);

  i3ds::Context::Ptr context = i3ds::Context::Create();
  i3ds::Subscriber subscriber(context);

  running = true;
  signal(SIGINT, signal_handler);

  subscriber.Attach<i3ds::LIDAR::MeasurementTopic>(node, &handle_frame);
  subscriber.Start();

  while(running)
    {
      sleep(1);
    }

  subscriber.Stop();

  return 0;
}
