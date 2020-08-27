# HSR

This project was developed on Ubuntu 18.04 LTS with ROS Melodic, Gazebo and catkin installed.

## Dependencies
* xterm
``sudo apt-get install xterm``  
  
## Preliminary Steps
1. Clone this project  
2. Submodule initialization  
  ``git submodule init``  
3. Submodule update  
  ``git submodule update``
4. open Terminal with ``Home_Service_Robot``  
  ``catkin_make``  
5. switch ``slam_gmapping`` branch to ``hydro-devel``

### SLAM Testing
Open Home_Service_Robot/Shell in Terminal  
1. give it ``execute`` pemission by ``chmod +x test_slam.sh``  
2. ``source devel/setup.bash``  
3. ``./test_slam.sh``  

### SLAM Testing
Open Home_Service_Robot/Shell in Terminal  
1. give it ``execute`` pemission by ``chmod +x test_navigation.sh``  
2. ``source devel/setup.bash``  
3. ``./test_navigation.sh``  


