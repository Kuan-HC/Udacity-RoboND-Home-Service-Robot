#!/bin/sh
xterm  -e  "source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/Udacity-RoboND-Home-Service-Robot/src/world/my_world.world" &
sleep 10
xterm  -e  "source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/Udacity-RoboND-Home-Service-Robot/src/world/map.yaml" & 
sleep 5
xterm  -e  "source devel/setup.bash; rosrun rviz rviz -d /home/workspace/Udacity-RoboND-Home-Service-Robot/home_service.rviz" &
sleep 10
xterm  -e  "source devel/setup.bash; rosrun add_markers add_markers_hsr" &
sleep 1
xterm  -e  "source devel/setup.bash; rosrun pick_objects pick_objects" 
