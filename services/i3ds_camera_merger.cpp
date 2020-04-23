///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2020 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <csignal>
#include <iostream>
#include <unistd.h>
#include <atomic>

#include <i3ds/camera_merger.hpp>
#include <i3ds/configurator.hpp>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

std::atomic<bool> running;

void signal_handler(int)
{
  running = false;
}

int main(int argc, char *argv[])
{
  int merger_node, cam_1_node, cam_2_node;

  po::options_description desc("Service for merging two camera streams into one stereo image stream\n  Available options");
  i3ds::Configurator configurator;

  configurator.add_common_options(desc);
  desc.add_options()
  ("node,n", po::value<int>(&merger_node)->required(), "NodeID of camera_merger")
  ("cam_1_node", po::value<int>(&cam_1_node)->required(), "NodeID of left input camera")
  ("cam_2_node", po::value<int>(&cam_2_node)->required(), "NodeID of right input camera")
  ;

  po::variables_map vm = configurator.parse_common_options(desc, argc, argv);

  running = true;
  signal(SIGINT, signal_handler);

  i3ds::Context::Ptr context = i3ds::Context::Create();;
  i3ds::Server server(context);
  i3ds::CameraMerger merger(context, merger_node, cam_1_node, cam_2_node);
  merger.Attach(server);

  server.Start();
  while(running)
    {
      sleep(1);
    }
  //TODO: stop merger, join thread
  server.Stop();

  return 0;
}
