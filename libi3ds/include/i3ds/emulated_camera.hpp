///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_EMULATED_CAMERA_HPP
#define __I3DS_EMULATED_CAMERA_HPP

#include <memory>

#include <i3ds/topic.hpp>
#include <i3ds/publisher.hpp>
#include <i3ds/periodic.hpp>

#include <i3ds/camera_sensor.hpp>

#define BOOST_LOG_DYN_LINK

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace logging = boost::log;

namespace i3ds
{

struct FrameProperties
{
  Frame_mode_t mode;
  int data_depth;
  int pixel_size;
  int width;
  int height;
};

class EmulatedCamera : public Camera
{
public:

  EmulatedCamera(Context::Ptr context, NodeID id, FrameProperties prop, std::string sample_dir = "");
  virtual ~EmulatedCamera();

  // Getters.
  virtual ShutterTime shutter() const {return shutter_;}
  virtual SensorGain gain() const {return gain_;}
  virtual bool auto_exposure_enabled() const {return auto_exposure_enabled_;}
  virtual ShutterTime max_shutter() const {return max_shutter_;}
  virtual SensorGain max_gain() const {return max_gain_;}
  virtual bool region_enabled() const {return region_enabled_;}
  virtual PlanarRegion region() const {return region_;}
  virtual bool flash_enabled() const {return flash_enabled_;}
  virtual FlashStrength flash_strength() const {return flash_strength_;}
  virtual bool pattern_enabled() const {return pattern_enabled_;}
  virtual PatternSequence pattern_sequence() const {return pattern_sequence_;}

  // Supported period.
  virtual bool is_sampling_supported(SampleCommand sample);

protected:

  // Actions.
  virtual void do_activate();
  virtual void do_start();
  virtual void do_stop();
  virtual void do_deactivate();

  // Handlers.
  virtual void handle_exposure(ExposureService::Data& command);
  virtual void handle_region(RegionService::Data& command);
  virtual void handle_auto_exposure(AutoExposureService::Data& command);
  virtual void handle_flash(FlashService::Data& command);
  virtual void handle_pattern(PatternService::Data& command);

  virtual bool send_sample(unsigned long timestamp_us) = 0;

  void fetch_next_image();

  template<typename FrameTopic>
  void set_meta(typename FrameTopic::Data& frame, unsigned long timestamp_us)
  {
    frame.attributes.timestamp.microseconds = timestamp_us;
    frame.attributes.validity = sample_valid;
    if (!sample_images_.empty())
      {
        fetch_next_image();
        cv::Mat current_image = sample_images_[current_image_index_];
        frame.region.size_x = current_image.cols;
        frame.region.size_y = current_image.rows;
        if (current_image.depth() == CV_16U)
          {
            frame.pixel_size = current_image.channels() * 2;
          }
        else
          {
            frame.pixel_size = current_image.channels();
          }
        frame.frame_mode = mode_rgb;
      }
    else
      {
        frame.frame_mode = prop_.mode;
        frame.data_depth = prop_.data_depth;
        frame.pixel_size = prop_.pixel_size;
        frame.region = region_;
      }
  }

  ShutterTime shutter_;
  SensorGain gain_;
  bool auto_exposure_enabled_;
  ShutterTime max_shutter_;
  SensorGain max_gain_;
  bool region_enabled_;
  PlanarRegion region_;
  bool flash_enabled_;
  FlashStrength flash_strength_;
  bool pattern_enabled_;
  PatternSequence pattern_sequence_;

  FrameProperties prop_;

  Sampler sampler_;

  Publisher publisher_;

  std::vector<cv::Mat> sample_images_;
  unsigned int current_image_index_;

};

template<typename FrameTopic>
class EmulatedMonoCamera : public EmulatedCamera
{
public:


  typedef std::shared_ptr<EmulatedMonoCamera<FrameTopic>> Ptr;

  static Ptr Create(Context::Ptr context, NodeID id, FrameProperties prop, std::string sample_dir = "")
  {
    return std::make_shared<EmulatedMonoCamera<FrameTopic>>(context, id, prop, sample_dir);
  }

  EmulatedMonoCamera(Context::Ptr context, NodeID id, FrameProperties prop, std::string sample_dir = "")
    : EmulatedCamera(context, id, prop, sample_dir)
  {
    FrameTopic::Codec::Initialize(frame_);
  }

  virtual ~EmulatedMonoCamera() {};

protected:

  virtual bool send_sample(unsigned long timestamp_us)
  {
    set_meta<FrameTopic>(frame_, timestamp_us);
    frame_.image.nCount = frame_.region.size_x  * frame_.region.size_y * frame_.pixel_size;
    if (!sample_images_.empty())
      {
        memcpy(frame_.image.arr, sample_images_[current_image_index_].data, frame_.image.nCount);
      }

    BOOST_LOG_TRIVIAL(trace) << "Send mono frame: "
                             << timestamp_us << " "
                             << frame_.image.nCount / 1024.0 << "KiB";

    publisher_.Send<FrameTopic>(frame_);

    return true;
  }

  typename FrameTopic::Data frame_;
};


template<typename FrameTopic>
class EmulatedStereoCamera : public EmulatedCamera
{
public:

  typedef std::shared_ptr<EmulatedMonoCamera<FrameTopic>> Ptr;

  static Ptr Create(Context::Ptr context, NodeID id, FrameProperties prop, std::string sample_dir = "")
  {
    return std::make_shared<EmulatedStereoCamera<FrameTopic>>(context, id, prop, sample_dir);
  }

  EmulatedStereoCamera(Context::Ptr context, NodeID id, FrameProperties prop, std::string sample_dir = "")
    : EmulatedCamera(context, id, prop, sample_dir)
  {
    FrameTopic::Codec::Initialize(frame_);
  }

  virtual ~EmulatedStereoCamera() {};

protected:

  virtual bool send_sample(unsigned long timestamp_us)
  {
    set_meta<FrameTopic>(frame_, timestamp_us);
    frame_.region.size_x *= 2;
    int size = frame_.region.size_x  * frame_.region.size_y * frame_.pixel_size;
    frame_.image_left.nCount = size;
    frame_.image_right.nCount = size;

    if (!sample_images_.empty())
      {
        memcpy(frame_.image_left.arr, sample_images_[current_image_index_].data, frame_.image_left.nCount);
        memcpy(frame_.image_right.arr, sample_images_[current_image_index_].data, frame_.image_right.nCount);
      }

    BOOST_LOG_TRIVIAL(trace) << "Send stereo frame: "
                             << timestamp_us << " "
                             << size / 512.0 << "KiB";

    publisher_.Send<FrameTopic>(frame_);

    return true;
  }

  typename FrameTopic::Data frame_;
};

} // namespace i3ds

#endif
