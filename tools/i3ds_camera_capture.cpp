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
#include <fstream>
#include <csignal>
#include <cmath>
#include <cstring>
#include <atomic>

#include <i3ds/configurator.hpp>
#include <i3ds/subscriber.hpp>
#include <i3ds/camera_sensor.hpp>
#include <i3ds/tof_camera_sensor.hpp>
#include <i3ds/frame.hpp>
#include <i3ds/depthmap.hpp>
#include <i3ds/time.hpp>

#include <i3ds/opencv_convertion.hpp>

#include <boost/program_options.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/version.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <chrono>
#include <iomanip>

namespace po = boost::program_options;

std::atomic<bool> running;

std::chrono::time_point<std::chrono::high_resolution_clock>previous_time;
float scale = 100;
int width = -1;
bool headless_mode = false;
std::string output = "", format;
bool do_output = false, do_scale = false, do_size = false;
long long prev_time = 0;

unsigned int img_index = 0;

std::ofstream logfile;

void
signal_handler(int)
{
  running = false;
}

void
draw_center_value(cv::Mat image, i3ds::DepthMap dm)
{
  int line_length = dm.descriptor.height/10;
  int x_mid = dm.descriptor.width / 2;
  int y_mid = (dm.descriptor.height / 2) + (image.size().height-dm.descriptor.height); // Account for header
  cv::line(image, cv::Point(x_mid-line_length, y_mid), cv::Point(x_mid+line_length, y_mid), cv::Scalar(100000));
  cv::line(image, cv::Point(x_mid, y_mid-line_length), cv::Point(x_mid, y_mid+line_length), cv::Scalar(100000));
  float center_value = dm.depths[(dm.descriptor.width/2)*(dm.descriptor.height+1)];
  cv::putText(image, std::to_string(center_value), cv::Point(x_mid+5, y_mid-5), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(100000), 1, cv::LINE_AA);
}

void
draw_center_value(cv::Mat, i3ds::Frame f)
{
  // Do nothing for normal images
}

template <typename T>
void
handle_image(std::string window_name, const T& frame, int image_number, std::string fps_text)
{
  cv::Mat mat = i3ds::frame_to_cv_mat(frame, image_number);

  long long current_time = i3ds::get_timestamp();
  long long sent_time = frame.descriptor.attributes.timestamp;
  long long delay = current_time - sent_time;
  long long period = sent_time - prev_time;

  prev_time = sent_time;

  if (do_output) {

    std::ostringstream path;
    path <<  output << "_";
    path << std::setw(5) << std::setfill('0') << img_index;
    path << "_" << image_number << "." << format;

    logfile << path.str() << ","
	    << current_time << ","
	    << sent_time << ","
	    << delay << ","
	    << period << std::endl;

    cv::imwrite(path.str(), mat);
  }

  if (headless_mode) {
    return;
  }

  cv::Mat mat2, mat3;

  if(do_size){
    cv::Size size = mat.size();
    float height = (size.height * width)/size.width;
    cv::resize(mat, mat2, cv::Size(width, height), 0, 0, cv::INTER_AREA);
  } else if (do_scale) {
    cv::resize(mat, mat2, cv::Size(0, 0), scale/100, scale/100, cv::INTER_AREA);
  } else {
    mat2 = mat;
  }
#if CV_MAJOR_VERSION == 3 || CV_MAJOR_VERSION == 4
  cv::setWindowTitle (window_name, window_name + " " + fps_text);
#endif

  cv::Scalar value(0);

  cv::copyMakeBorder(mat2, mat3, 40, 0, 0, 0, cv::BORDER_CONSTANT, value);

  std::ostringstream display;

  display << std::fixed << std::setprecision(9);
  display << "Delay: " << delay * 1.0e-3 << " ms, Period: " << period * 1.0e-6 << " s";

  cv::putText(mat3, display.str(), cv::Point(20, 30), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(100000), 1, cv::LINE_AA);

  draw_center_value(mat3, frame);

  cv::imshow(window_name, mat3);
}

bool is_tof_camera(i3ds::DepthMap&) {
  return true;
}

bool is_tof_camera(i3ds::Frame&) {
  return false;
}

int image_count(i3ds::DepthMap&) {
  return 1;
}

int image_count(i3ds::Frame& data) {
  return data.descriptor.image_count;
}

void handle_extra_tof_frame(i3ds::DepthMap& dm, std::string fps_text) {
  if (dm.has_frame) {
    handle_image("ToF Image", dm.frame, 1, fps_text);
  }
}

void handle_extra_tof_frame(i3ds::Frame& dm, std::string fps_text) {
  // Do nothing for normal Frames
}

template <typename T>
void
handle_frame(T& data, int node)
{
  auto time_now = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = time_now - previous_time;

  std::stringstream buffer;
  buffer <<  "(node: " << node << " fps: "  << std::setprecision(1) << std::fixed << 1000. / (std::chrono::duration <double, std::milli> (diff).count()) << ")" << std::endl;;
  std::cout << "fps: "<< buffer.str();

  previous_time = time_now;
  img_index++;

  if ( is_tof_camera(data) )
    {
      handle_image("ToF Depthmap", data, 0, buffer.str());
      handle_extra_tof_frame(data, buffer.str());
    }
  else // Normal camera
    {
      switch (image_count(data))
      {
      case 1:
	handle_image("Camera feed", data, 0, buffer.str());
	break;

      case 2:
	handle_image("Left camera feed", data, 0, buffer.str());
	handle_image("Right camera feed", data, 1, buffer.str());
	break;
      }
    }
  if (!headless_mode)
    {
      cv::waitKey(5); // Apparently needed to render image properly
    }
}

int main(int argc, char *argv[])
{
  int node;
  bool tof_version = false;
  i3ds::Configurator configurator;
  po::options_description desc("Displays mono or stereo video stream\n  Available options");

  configurator.add_common_options(desc);
  desc.add_options()
  ("node,n", po::value<int>(&node)->default_value(10), "Node ID of camera")
  ("scale,x", po::value(&scale), "Camera scale [%]")
  ("width,w", po::value(&width), "Maximal image width [px]")
  ("output,o", po::value(&output), "Output path template")
  ("format,f", po::value(&format)->default_value("tiff"), "Output format")
  ("tof", po::bool_switch(&tof_version), "TOF version")
  ("nogui,g", po::bool_switch(&headless_mode), "Headless mode")
  ;

  po::variables_map vm = configurator.parse_common_options(desc, argc, argv);

  if (vm.count("width")) {
    do_size = true;
    std::cout << "Scaling width to: " << width << " [px]" << std::endl;
  } else if (vm.count("scale")) {
    do_scale = true;
    std::cout << "Scale: " << scale << "%" << std::endl;
  }

  if (vm.count("output")) {
    do_output = true;
    std::cout << "Storing data to: " << output << "_XXXXX." << format << std::endl
	      << "Logging time to: " << output << ".csv"  << std::endl;

    logfile.open (output + ".csv", std::ofstream::out);

    logfile << "# FILE,RECEIVED,SENT,DELAY,PERIOD" << std::endl;
  }

  std::cout << "Connecting to Node with ID: " << node << std::endl;

  i3ds::Context::Ptr context = i3ds::Context::Create();
  i3ds::Subscriber subscriber(context);

  running = true;
  signal(SIGINT, signal_handler);

  if (tof_version) {
    subscriber.Attach<i3ds::ToFCamera::MeasurementTopic>(node, [node](i3ds::ToFCamera::MeasurementTopic::Data d){handle_frame(d, node);});
  } else {
    subscriber.Attach<i3ds::Camera::FrameTopic>(node, [node](i3ds::Camera::FrameTopic::Data d){handle_frame(d, node);});
  }
  subscriber.Start();

  while(running)
    {
      sleep(1);
    }

  subscriber.Stop();

  return 0;
}
