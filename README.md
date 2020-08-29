# Udacity-RoboND-Home-Service-Robot
<img src="image/home_service.gif" width = "800"/>

This project was developed on Ubuntu 16.04 LTS with ROS Kinetic, Gazebo and catkin installed.

## Dependencies
* xterm  
``sudo apt-get install xterm``  
  
## Preliminary Steps
1. clone this project  
2. submodule initialization  
  ``git submodule init``  
3. submodule update  
  ``git submodule update``
4. open ``Udacity-RoboND-Home-Service-Robot`` with Terminal   
  ``catkin_make``  
5. switch pkg``slam_gmapping`` branch to ``hydro-devel``
  ``git checkout -b hydro-devel origin/hydro-devel`` 

### Mapping
<img src="image/slam_test.gif" width = "600"/>

1. Open ``Udacity-RoboND-Home-Service-Robot/Shell`` in Terminal  

2. give it ``execute`` pemission by ``chmod +x test_slam.sh``  

3. ``./test_slam.sh``  

4. generated pgm file:  

<img src="image/slam_pgm.png" width = "300"/>

### Localization and Navigation
<img src="image/pickup.gif" width = "600"/>  

1. Open ``Udacity-RoboND-Home-Service-Robot/Shell`` in Terminal  

2. give it ``execute`` pemission by ``chmod +x pick_object.sh``  

3. ``./pick_object.sh``  

### Home Service Functions
#### Add Markers 
<img src="image/add_markers.gif" width = "300"/>  

1. Open ``Udacity-RoboND-Home-Service-Robot/Shell`` in Terminal  

2. give it ``execute`` pemission by ``chmod +x add_markers.sh``  

3. ``./add_markers.sh``  

#### Home Service  
<img src="image/cover_hsr.gif" width = "300"/>  

1. give it ``execute`` pemission by ``chmod +x home_service.sh``  
2. ``./home_servicem.sh``  
* ``home_servicem.sh`` launches ``turtlebot``, ``AMCL``, ``rviz``, ``pcik_objects`` and ``add_markers_hsr`` nodes  
* rviz config file: ``home_service.rviz`` modifiy it path in ``/shell/home_service.sh`` line 6  

