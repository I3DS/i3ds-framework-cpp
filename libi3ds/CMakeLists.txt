# Need to have unit_test_framework available here for ../test/ to link properly..
if (BUILD_TESTS OR BUILD_TOOLS)
  find_package (Boost COMPONENTS program_options unit_test_framework log REQUIRED)
endif (BUILD_TESTS OR BUILD_TOOLS)

################################################################################
# libi3ds
################################################################################

set (SRCS
  src/communication.cpp
  src/address_server.cpp
  src/receiver.cpp
  src/server.cpp
  src/publisher.cpp
  src/subscriber.cpp
  src/periodic.cpp
  src/sensor.cpp
  src/camera_sensor.cpp
  src/gige_camera_sensor.cpp
  src/tof_camera_sensor.cpp
  src/radar_sensor.cpp
  src/lidar_sensor.cpp
  src/trigger.cpp
  src/power.cpp
  src/flash.cpp
  src/measurement_proxy.cpp
  src/configurator.cpp
  src/message_recording.cpp
  src/pose_estimator_sensor.cpp
  src/camera_merger.cpp
  )

set (LIBS
  zmq
  pthread
  ${Boost_LIBRARIES}
  i3ds_asn1
  )

add_library (i3ds SHARED ${SRCS})

target_link_libraries (i3ds ${LIBS})

set_target_properties (
  i3ds PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION})

install (TARGETS i3ds DESTINATION lib)
install (DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
