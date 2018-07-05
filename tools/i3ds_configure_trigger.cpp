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
#include <cstdlib>

#include <i3ds/trigger_client.hpp>
#include <i3ds/sensor_configurator.hpp>

#include <boost/program_options.hpp>

#define BOOST_LOG_DYN_LINK

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace po = boost::program_options;
namespace logging = boost::log;

int main(int argc, char *argv[])
{
  i3ds::SensorConfigurator configurator;
  int generator;
  int trigger;
  uint32_t period;
  uint32_t width;
  uint32_t delay;
  bool inverted;
  bool enable;

  po::options_description desc("Allowed trigger control options");

  //configurator.add_common_options(desc);
  desc.add_options()
  ("print", "Print the trigger configuration")

  ("node", po::value(&configurator.node_id), "NodeID")
  ("generator", po::value(&generator), "Generator ID")
  ("trigger", po::value(&trigger), "Trigger ID")
  ("period", po::value(&period), "Time between triggers")
  ("width", po::value(&width), "Width of the pulse")
  ("delay", po::value(&delay)->default_value(0), "Phase of the trigger")
  ("inverted", po::value(&inverted)->default_value(false), "Invert the trigger")
  ("enable", po::value(&enable)->default_value(true), "Enable the trigger")
  ;

  po::variables_map vm = configurator.parse_common_options(desc, argc, argv);

  i3ds::Context::Ptr context(i3ds::Context::Create());

  BOOST_LOG_TRIVIAL(info) << "Connecting to trigger with node ID: " << configurator.node_id << " context " << context;
  i3ds::TriggerClient trigger_client(context, configurator.node_id);
  BOOST_LOG_TRIVIAL(trace) << "---> [OK]";

  // Configure region.
  if (vm.count("period") && vm.count("generator"))
  {
    BOOST_LOG_TRIVIAL(info) << "Sending generator message: " << generator << " @ " << period << "[µs]";

    TriggerGenerator gen = generator;
    TriggerPeriod per = period;
    trigger_client.set_generator(gen, per);
      
    BOOST_LOG_TRIVIAL(trace) << "---> [OK]";
  }
  if (vm.count("trigger") && vm.count("generator") && vm.count("width"))
  {
    BOOST_LOG_TRIVIAL(info) << "Sending channel message: " << trigger << " @ " << generator << " - " << width << " + " << delay;
    trigger_client.set_interal_channel(trigger, generator, delay, width);
    BOOST_LOG_TRIVIAL(trace) << "---> [OK]";
  }
  if (vm.count("trigger") && vm.count("enable")) {
    TriggerMask channels = {false};
    for(int i=0; i<8; i++) {
      channels.arr[i]  = false;
    }
    channels.arr[trigger] = true;
    if (enable) {
      BOOST_LOG_TRIVIAL(info) << "Enabling: " << trigger;
      trigger_client.enable_channels(channels);
    } else {
      BOOST_LOG_TRIVIAL(info) << "Disabling: " << trigger;
      trigger_client.disable_channels(channels);
    }
  }

  return 0;
}
