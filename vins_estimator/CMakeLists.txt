cmake_minimum_required(VERSION 3.5)
project(vins_estimator)

set(vins_estimator_MAJOR_VERSION 0)
set(vins_estimator_MINOR_VERSION 0)
set(vins_estimator_PATCH_VERSION 0)
set(vins_estimator_VERSION
  ${vins_estimator_MAJOR_VERSION}.${vins_estimator_MINOR_VERSION}.${vins_estimator_PATCH_VERSION})

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(image_transport REQUIRED)

include_directories(include)

add_executable(node src/Opencv_example.cpp)

target_link_libraries(node ${OpenCV_LIBS})

ament_target_dependencies(node 
  "rclcpp" 
  "sensor_msgs"
  "OpenCV"
  "image_transport"
  "cv_bridge")

install(TARGETS node
DESTINATION bin/${PROJECT_NAME})

ament_package()

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
