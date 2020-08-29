#!/bin/sh
xterm  -e  "source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/HSR/src/world/my_world.world" &
sleep 10
xterm  -e  "source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/HSR/src/world/map.yaml" & 
sleep 5
xterm  -e  "source devel/setup.bash; rosrun rviz rviz -d /home/workspace/HSR/home_service.rviz" &
sleep 10
xterm  -e  "source devel/setup.bash; rosrun add_markers add_markers_hsr" &
sleep 1
xterm  -e  "source devel/setup.bash; rosrun pick_objects pick_objects" 
