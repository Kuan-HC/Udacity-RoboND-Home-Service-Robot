#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 3.0;
  goal.target_pose.pose.position.y = -4.0;
  goal.target_pose.pose.orientation.w = -1.5707;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup zone info, buffer 3 seconds");
  ros::Duration(5.0).sleep();
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Robot reached pickup zone");
    ROS_INFO("Pause 5 seconds!");
    ros::Duration(5.0).sleep();
    ROS_INFO("Sending dropoff zone info");
    goal.target_pose.pose.position.x = -5.0;
    goal.target_pose.pose.position.y = 3.5;
    goal.target_pose.pose.orientation.w = 1.5707;
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Robot reached dropoff zone");
    else
      ROS_INFO("Robot failed to reach dropoff zone for some reason");
  }
  else
    ROS_INFO("Robot failed to reach pickup zone for some reason");

  return 0;
}