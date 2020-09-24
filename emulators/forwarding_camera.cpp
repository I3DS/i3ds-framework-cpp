///////////////////////////////////////////////////////////////////////////\file
///
///   Copyright 2020 SINTEF AS
///
///   This Source Code Form is subject to the terms of the Mozilla
///   Public License, v. 2.0. If a copy of the MPL was not distributed
///   with this file, You can obtain one at https://mozilla.org/MPL/2.0/
///
////////////////////////////////////////////////////////////////////////////////

#include <i3ds/forwarding_camera.hpp>
#include <i3ds/opencv_convertion.hpp>


i3ds::ForwardingCamera::ForwardingCamera(Context::Ptr context, i3ds_asn1::NodeID id, Parameters param) :
    GigECamera(context, id, param)
{
    set_device_name("Forwarding camera");
}
bool
i3ds::ForwardingCamera::send_image(cv::Mat img)
{
    BOOST_LOG_TRIVIAL(trace) << "Forwarding Image: "
                           << img.cols << " cols, "
                           << img.rows << " rows, "
                           << img.channels() << " chan, "
                           << img.depth() << " depth";
    if (img.cols == 0 || img.rows == 0) {
        BOOST_LOG_TRIVIAL(error) << "Invalid size of image, you sure you provided right ref?";
        return false;
    }
    send_sample(img.data, img.cols, img.rows);
    return true;
}

// Emtpy functions, or bare minimum needed for all abstract methods
// inherited from gige-sensor

void i3ds::ForwardingCamera::Open()
{
    ;
}
void i3ds::ForwardingCamera::Close()
{
    ;
}
void i3ds::ForwardingCamera::Start()
{
    ;
}
void i3ds::ForwardingCamera::Stop()
{
    ;
}

bool i3ds::ForwardingCamera::setInternalTrigger(int64_t)
{
    //period_us;
    return true;
}

int64_t i3ds::ForwardingCamera::getSensorWidth() const
{
    return 2048;
}

int64_t i3ds::ForwardingCamera::getSensorHeight() const
{
    return 2048;
}

bool i3ds::ForwardingCamera::isRegionSupported() const
{
    return false;
}

int64_t i3ds::ForwardingCamera::getRegionWidth() const
{
    return 2048;
}

int64_t i3ds::ForwardingCamera::getRegionHeight() const
{
    return 2048;
}

int64_t i3ds::ForwardingCamera::getRegionOffsetX() const
{
    return 0;
}

int64_t i3ds::ForwardingCamera::getRegionOffsetY() const
{
    return 0;
}

void i3ds::ForwardingCamera::setRegionWidth(int64_t)
{
    //width;
}

void i3ds::ForwardingCamera::setRegionHeight(int64_t)
{
    //height;
}

void i3ds::ForwardingCamera::setRegionOffsetX(int64_t)
{
    //offset_x;
}

void i3ds::ForwardingCamera::setRegionOffsetY(int64_t)
{
    //offset_y;
}

int64_t i3ds::ForwardingCamera::getShutter() const
{
    return 2000;
}

int64_t i3ds::ForwardingCamera::getMaxShutter() const
{
    return 10000000;
}

int64_t i3ds::ForwardingCamera::getMinShutter() const
{
    return 10;
}

void i3ds::ForwardingCamera::setShutter(int64_t)
{
    //shutter_us;
}

bool i3ds::ForwardingCamera::isAutoShutterSupported() const
{
    return false;
}

bool i3ds::ForwardingCamera::getAutoShutterEnabled() const
{
    return false;
}

void i3ds::ForwardingCamera::setAutoShutterEnabled(bool)
{
    //enable;
}

int64_t i3ds::ForwardingCamera::getAutoShutterLimit() const
{
    return getMaxShutter();
}

int64_t i3ds::ForwardingCamera::getMaxAutoShutterLimit() const
{
    return getMaxShutter();
}

int64_t i3ds::ForwardingCamera::getMinAutoShutterLimit() const
{
    return getMinShutter();
}

void i3ds::ForwardingCamera::setAutoShutterLimit(int64_t)
{
    //shutter_limit;
}

double i3ds::ForwardingCamera::getGain() const
{
    return 1.0;
}

double i3ds::ForwardingCamera::getMaxGain() const
{
    return 30.0;
}

double i3ds::ForwardingCamera::getMinGain() const
{
    return 0.0;
}

void i3ds::ForwardingCamera::setGain(double)
{
    //gain;
}

bool i3ds::ForwardingCamera::isAutoGainSupported() const
{
    return false;
}

bool i3ds::ForwardingCamera::getAutoGainEnabled() const
{
    return false;
}

void i3ds::ForwardingCamera::setAutoGainEnabled(bool)
{
    //enable;
}

double i3ds::ForwardingCamera::getAutoGainLimit() const
{
    return getMaxGain();
}

double i3ds::ForwardingCamera::getMaxAutoGainLimit() const
{
    return getMaxGain();
}

double i3ds::ForwardingCamera::getMinAutoGainLimit() const
{
    return getMinGain();
}

void i3ds::ForwardingCamera::setAutoGainLimit(double)
{
    //gain_limit;
}
