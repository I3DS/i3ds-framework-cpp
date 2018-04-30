///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2018 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#ifndef __I3DS_EMULATED_RADAR_HPP
#define __I3DS_EMULATED_RADAR_HPP

#include <memory>

#include "topic.hpp"
#include "publisher.hpp"
#include "periodic.hpp"

#include "radar_sensor.hpp"

namespace i3ds
{

class EmulatedRadar : public Radar
{
public:

  typedef Topic<128, RadarMeasurement400KCodec> RadarMeasurement;

  typedef std::shared_ptr<EmulatedRadar> Ptr;

  static Ptr Create(Context::Ptr context, NodeID node);

  EmulatedRadar(Context::Ptr context, NodeID node);
  virtual ~EmulatedRadar();

  // Getters.
  virtual bool region_enabled() const {return region_enabled_;}
  virtual PlanarRegion region() const {return region_;}

  // Supported rate.
  virtual bool is_rate_supported(SampleRate rate);

protected:

  // Actions.
  virtual void do_activate();
  virtual void do_start();
  virtual void do_stop();
  virtual void do_deactivate();

  // Handlers.
  virtual void handle_region(RegionService::Data& command);

private:

  bool send_sample(unsigned long timestamp_us);

  bool region_enabled_;
  PlanarRegion region_;

  Sampler sampler_;

  Publisher publisher_;
  RadarMeasurement400K frame_;
};

} // namespace i3ds

#endif