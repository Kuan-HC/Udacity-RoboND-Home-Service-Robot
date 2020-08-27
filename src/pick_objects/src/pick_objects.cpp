#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
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
  goal.target_pose.pose.position.x = 5.0;
  goal.target_pose.pose.orientation.w = 1.0;
  goal.target_pose.pose.orientation.w = 0.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup zone");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Robot reached the pickup zone");
    ros::Duration(5.0).sleep();

    // Define a drop off zone position and orientation for the robot to reach
    goal.target_pose.pose.position.x = -7.0;
    goal.target_pose.pose.orientation.w = 1.0;
    goal.target_pose.pose.orientation.w = 1.5707;

    // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending drop off zone");
    ac.sendGoal(goal);
    // Wait an infinite time for the results
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        ROS_INFO("Robot reached the drop off zone");
        ros::Duration(5.0).sleep();
    }
  else
  {
     ROS_INFO("Robot failed to reach Drop off location for some reason");
  }
   }
}
  else
    ROS_INFO("Robot failed to reached pickup zone  for some reason");

  return 0;
}