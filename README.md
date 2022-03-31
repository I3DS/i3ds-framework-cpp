# I3DS C++ framework

This is the I3DS sensor suite C++ framework for creating sensor
interfaces with the ASN.1 message formats and the ZMQ communication
library. The framework also contains sensor emulators, and services
and tools for interfacing with the sensor suite. Bindings to the
Python programming language for the sensor clients are also provided.

## libi3ds

This is the library containing the functionality of the I3DS C++
framework, including the ASN.1 encoders and decoders that are
generated using ASN1CC. It is organized in a standard way with headers
under `include/i3ds`, source code under `src` and unit tests under
`tests` using the Boost unit test framework. Emulators used in testing
and partial setups can be found under `emulators/`.

The details of ZMQ are hidden in `communication.hpp`. This package
also specifies the address consisting of a node and endpoint ID.
Addresses are used for identifying messages so that they can reach the
correct receiver. Generic communication patterns such as publish /
subscribe and request / response are found in files `publisher.hpp`,
`subscriber.hpp`, `client.hpp` and `server.hpp` respectively.  The
encoding and decoding of messages with the ASN.1 uPER message format
is handled by `codec.hpp` that defines thin C++ wrappers around the C
code generated by the ASN.1 compiler. For simplicity the endpoint ID
and message format are bound together in C++ structs as either a
service with input/output data in `service.hpp` or as a publish /
subscribe topic in `topic.hpp`.

Basic sensor functionality with the state machine is defined in
`sensor.hpp`. More specific sensor interfaces such as a camera in
`camera_sensor.hpp` inherit from this class, and the concrete device
interfaces inherit from these again and override the service methods
they support. The corresponding client classes (like `camera_client.hpp`
can be used by client applications to send commands to the sensors.
Emulated sensor are defined for all main classes and is found under
`emulators`. These allow for testing of commands and queries, but are
not guaranteed to produce meaningful sensor data as of now. The emulated
camera can be given a file path to a directory containing image files,
and will send these images on loop.

## Services

The following services are provided:

* The I3DS address server that is used by the communication parts of
  the library to translate a node ID and pattern to a ZMQ address with
  IP and port. The service reads in a simple CSV file in memory at
  startup. The format of the file is `323,pub,b,tcp://127.0.0.1:7000`,
  where the first integer is the node ID, then the ZMQ pattern (pub,
  sub, req, rep), then whether to bind (b) or connect (c), and then
  finally the ZMQ address specifying protocol, IP and port.

* The sensor suite emulator that creates one of each of the supported
  sensors of the I3DS sensor suites from the provided base address.

Use the `--help` argument to get the detailed usage.

## Tools

The following tools are provided:

* `i3ds_camera_capture`: A camera capture tool for capturing
image frames.
* `i3ds_codec_performance_test`: A test suite to check the
encoding and decoding times of different message types.
* `i3ds_configure_camera`: Configuration tool for camera sensors.
* `i3ds_configure_sensor`: Configuration tool for a generic sensor.
* `i3ds_delay_recorder`: Tool for recording transport delays in
a CSV file.
* `i3ds_record`: Tool for recording measurements and writing them
to a log file.
* `i3ds_replay`: Tool for replaying measurement logs created with
`i3ds_record`.

Use the `--help` argument to get the detailed usage.

## Building and installing

### Downloading source and picking the right branch

All the source code is contained in a git repository, and there
are 2 branches of particular interest. For a more stable release-cycle,
look there are a few tagged releases on the type "v1.1", "v1.2-rc0" and
so on.

* Tagged releases: these are releases that we have tested and run
  through different scenarios and they should be stable. An -rc-release
  will see a few updates before a final (non-rc) release is tagged. Once
  released, new development will be pushed to the next dot-release.

* master: this is the stable branch, a bit more live than a tagged
  release, but it should be fairly safe to use.

* next: this is our main integration branch. It should be stable, but
  please note that this may break on occasions.

Any other branches must be considered development branches and they may,
at the owner's discretion be rebased, deleted or otherwise (temporarily)
broken. Please do not use these for anything but bleeding edge
development.



### Building using docker for x86-64 systems

A dockerized build environment is provided to make it easier to build
and test the library. The only requirement is to have docker-io
installed locally. The first invokation will take some time as a
complete docker-image must be created. Once this is done, subsequent
calls should only be delayed by the time it takes to compile the
projcet.

On a debian/ubuntu host, install docker as per the official documentation
and then build with
``` shell
./do_docker.s -c -t all
```

To install the compiled library and header, invoke do_docker with the
archiving option:

``` shell
./do_docker.sh -A
```

this will yield an archive called i3ds-2019-10-98a0d601488b.tar on the
format 'i3ds-YYYY-MM-<sha1>.tar' to help distinguish between different
archives. This can then be extracted like any normal archive:

``` shell
tar xvf i3ds-2019-10-98a0d601488b.tar -C /
```

Note that some of the apt packages mentioned below are needed as runtime
dependencies.

### Building natively on host

The framework has the following build dependencies:

* cmake
* C++11 compiler (only tested with GCC)
* ZMQ libraries
* Boost framework (program options and unit test)
* SWIG and Python development files for optional Python binding
* OpenCV development files for some of the tools

On Ubuntu 20.04, the packages you should need are installed by:
```
sudo apt update
sudo apt install build-essential cmake libboost-dev libboost-program-options-dev libboost-test-dev libboost-log-dev swig python3-dev swig libzmq3-dev
sudo apt install libopencv-dev # Only required if tools, emulator and tests for camera or tof are needed
```

To build and install the framework with CMake do the following:

```
mkdir build/
cd build/
cmake -DI3DS_ASN1_ALT=external ..
make
make test
sudo make install
sudo ldconfig
```

This will install the headers under `/usr/local/include/i3ds`,
`libi3ds.so`, `libi3ds_clients.so` and `libi3ds_emulators.so`
under `/usr/local/lib`, and the tools and services under
`/usr/local/bin`. The Python bindings are put in the local install
directory that can vary among distributions.

### Getting the ASN.1 bindings
  
Note that the ASN.1-bindings will not be installed. They are 
included in this repository under the `external` directory for
building, but will have to be installed either by manual copying
from the `external` directory or from the `i3ds-interfaces`
git repository. See the README file in that repo for details.
