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

#include <i3ds/tof_camera_client.hpp>
#include <i3ds/configurator.hpp>

#include <boost/program_options.hpp>

#ifndef BOOST_LOG_DYN_LINK
#define BOOST_LOG_DYN_LINK
#endif


#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace po = boost::program_options;
namespace logging = boost::log;

void
print_tof_settings(i3ds::ToFCameraClient& tof)
{
  tof.load_all();
  std::cout << "\"region-enabled\" : " << tof.region_enabled() << "," << std::endl;
  std::cout << "\"region\" : [" << tof.region().size_x;
  std::cout << "," << tof.region().size_y;
  std::cout << "," << tof.region().offset_x;
  std::cout << "," << tof.region().offset_y << "]" << "," << std::endl;
  std::cout << "\"min_depth\" : " << tof.min_depth() << "," << std::endl;
  std::cout << "\"max_depth\" : " << tof.max_depth() << std::endl;
  std::cout << "}" << std::endl;
}

int main(int argc, char *argv[])
{
  i3ds::SensorConfigurator configurator;
  bool enable_region;
  i3ds_asn1::PlanarRegion region;
  double min_depth, max_depth;

  po::options_description desc("Allowed ToF camera control options");

  configurator.add_common_options(desc);
  desc.add_options()
  ("print,p", "Print the ToF camera configuration")

  ("region", po::value(&enable_region), "Enable region of interest (ROI). Region sizes must be greater than 0.")
  ("region-size-x,X", po::value(&region.size_x)->default_value(640), "ROI horisontal size")
  ("region-size-y,Y", po::value(&region.size_y)->default_value(480), "ROI vertical size")
  ("region-offset-x,x", po::value(&region.offset_x)->default_value(0), "ROI horisontal offset from left")
  ("region-offset-y,y", po::value(&region.offset_y)->default_value(0), "ROI vertical offset from top")

  ("min-depth,d", po::value(&min_depth)->default_value(0.0), "Min depth range for ToF")
  ("max-depth,D", po::value(&max_depth)->default_value(13.32), "Max depth range for ToF")
  ;

  po::variables_map vm = configurator.parse_common_options(desc, argc, argv);

  i3ds::Context::Ptr context(i3ds::Context::Create());

  BOOST_LOG_TRIVIAL(info) << "Connecting to ToF camera with node ID: " << configurator.node_id;
  i3ds::ToFCameraClient tof(context, configurator.node_id);
  BOOST_LOG_TRIVIAL(trace) << "---> [OK]";

  configurator.handle_sensor_commands(vm, tof);

  // Configure region.
  if (vm.count("region"))
    {
      if (enable_region)
        {
          if (region.size_x == 0 || region.size_y == 0)
            {
              BOOST_LOG_TRIVIAL(error) << "Must set region sizes larger than 0!";
              return -1;
            }
          if( (vm["region-size-x"].defaulted()) ||
              (vm["region-size-y"].defaulted()) ||
	      (vm["region-offset-x"].defaulted()) ||
	      (vm["region-offset-y"].defaulted())
	      )
	      {
		BOOST_LOG_TRIVIAL(error) << "All 4 parameters for region must be set! (region-size-x, region-size-y, region-offset-x, region-offset-y)";
		return -1;
	      }

          BOOST_LOG_TRIVIAL(info) << "Enable region: ("
                                  << region.offset_x << ","
                                  << region.offset_y << ","
                                  << region.size_x << ","
                                  << region.size_y << ")";
        }
      else
        {
          BOOST_LOG_TRIVIAL(info) << "Disable region";
        }

      tof.set_region(enable_region, region);

      BOOST_LOG_TRIVIAL(trace) << "---> [OK]";
    }

  if (vm.count("min-depth") || vm.count("max-depth")){
    if (! (vm["min-depth"].defaulted() && vm["max-depth"].defaulted()))
      {
	 if ( (vm["min-depth"].defaulted() ^ vm["max-depth"].defaulted()))
	   {
	     BOOST_LOG_TRIVIAL(info) << "REMARK: Only one depth parameter set. Then the other parameter will use the default value!";
	   }

	  BOOST_LOG_TRIVIAL(info) << "Set range: "
				  << min_depth << " [m],"
				  << max_depth << " [m]";

	  tof.set_range(min_depth, max_depth);

	  BOOST_LOG_TRIVIAL(info) << "---> [OK]";

      }
    }

  // Print config.
  if (vm.count("print"))
    {
      configurator.print_sensor_status(tof);
      print_tof_settings(tof);
    }

  return 0;
}
