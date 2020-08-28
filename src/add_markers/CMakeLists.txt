cmake_minimum_required(VERSION 2.8.3)
project(add_markers)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pick_objects
#  CATKIN_DEPENDS actionlib move_base_msgs roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(add_markers src/add_markers.cpp)

target_link_libraries(add_markers ${catkin_LIBRARIES})


