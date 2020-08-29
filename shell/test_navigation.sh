#!/bin/sh

xterm  -e  "source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/Udacity-RoboND-Home-Service-Robot/src/world/my_world.world" &
sleep 5 
xterm  -e  "source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/Udacity-RoboND-Home-Service-Robot/src/world/map.yaml" & 
sleep 5
xterm  -e  "source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch"

