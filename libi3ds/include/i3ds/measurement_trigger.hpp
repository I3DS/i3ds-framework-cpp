///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2022 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_MEASUREMENT_FETCHER_HPP
#define __I3DS_MEASUREMENT_FETCHER_HPP

#include<boost/log/trivial.hpp>

#ifndef BOOST_LOG_DYN_LINK
#define BOOST_LOG_DYN_LINK
#endif

#include <boost/log/trivial.hpp>

#include <i3ds/subscriber.hpp>
#include <i3ds/sensor_client.hpp>

#include <mutex>
#include <stdexcept>

namespace i3ds
{

////////////////////////////////////////////////////////////////////////////////
/// Utility function for fetching single measurements instead of subscribing
////////////////////////////////////////////////////////////////////////////////

template<typename Topic>
class MeasurementTrigger
{
public:

  MeasurementTrigger(Context::Ptr context, i3ds_asn1::NodeID node, bool capture_measurement = false) :
      capture_measurement_(capture_measurement),
      subscriber_(context),
      client_(context, node),
      valid_measurement_(false),
      waiting_(false),
      started_by_trigger_(false)
    {
      subscriber_.Attach<Topic>(node, [this](typename Topic::Data& msg){handle_measurement(msg);});
      subscriber_.Start();
    };
  virtual ~MeasurementTrigger()
    {
      subscriber_.Stop();
    }

  // Trigger a single measurement
  void trigger()
    {
      std::lock_guard<std::mutex> guard(mutex);
      BOOST_LOG_TRIVIAL(trace) << "[MeasurementTrigger] trigger()";
      client_.load_status();
      if (client_.is_standby())
        {
          BOOST_LOG_TRIVIAL(trace) << "[MeasurementTrigger] starting sensor";
          client_.set_state(i3ds_asn1::StateCommand_start);
          started_by_trigger_ = true;
        }
      else
        {
          started_by_trigger_ = false;
        }
      waiting_ = true;
    }

  // Will return the latest measurement sent by the sensor
  // Throws logic_error if the no measurement is available
  typename Topic::Data& fetch()
    {
      std::lock_guard<std::mutex> guard(mutex);
      if (!valid_measurement_)
        {
           throw std::logic_error("No valid measurement to fetch");
        }
      return measurement_;
    }

  bool valid_measurement()
    {
      std::lock_guard<std::mutex> guard(mutex);
      return valid_measurement_;
    }
  
private:

  void handle_measurement(typename Topic::Data& measurement)
    {
      std::lock_guard<std::mutex> guard(mutex);
      BOOST_LOG_TRIVIAL(trace) << "[MeasurementTrigger] handle_measurement";
      if (started_by_trigger_)
        {
          BOOST_LOG_TRIVIAL(trace) << "[MeasurementTrigger] stopping sensor";
          client_.set_state(i3ds_asn1::StateCommand_stop);
        }
      if (capture_measurement_)
        {
          measurement_ = measurement;
          valid_measurement_ = true;
        }
      waiting_ = false;
    }

  // Should the message body be kept for fetching
  bool capture_measurement_;

  // Subscriber for fetching measurements
  Subscriber subscriber_;

  // Client for starting the sensor
  SensorClient client_;

  // Last measurement received
  typename Topic::Data measurement_;

  // Is the measurement valid?
  bool valid_measurement_;

  // Is the fetcher waiting for a measurement?
  bool waiting_;

  // Did the trigger start the sensor?
  bool started_by_trigger_;

  // Mutual exclusion
  std::mutex mutex;
};

}

#endif
