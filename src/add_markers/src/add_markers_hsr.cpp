#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>   /*odom msg */
#include <math.h>

using std::fabs;

#define EPSILON 0.1f

typedef struct 
{
  float x;
  float y;
}pos;

/* set pickup and dropoff position */
static pos pick{3.0, -4.0};
static pos drop{-5.0, 3.5};

static bool reach_pickup;
static bool reach_dropoff;

void robot_pos_check(const nav_msgs::Odometry::ConstPtr &odom);

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers_hsr");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
   ros::Subscriber odom = n.subscribe("/odom", 1000, robot_pos_check);  

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  
  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pick.x;
    marker.pose.position.y = pick.y;
    
    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    while (reach_dropoff != true)
    { 
      ros::spinOnce();
      /* Publish the first marker at the pickup zone */
      ROS_INFO("Pick up the object");
      marker_pub.publish(marker);
    
      if(reach_pickup == true)
      {
      /* Delete marker */
      ROS_INFO("Object picked");
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
      /* set the second marker at the dropoff zone */
      marker.pose.position.x = drop.x;
      marker.pose.position.y = drop.y;
      ROS_INFO("Transporting");
      }

      if(reach_dropoff == true)
      {
          marker.action = visualization_msgs::Marker::ADD;
          marker_pub.publish(marker);
          ROS_INFO("Object delivered"); 
      }    
    }
    return 0;
  }
}

void robot_pos_check(const nav_msgs::Odometry::ConstPtr &odom)
{
    float robot_x =  pose.pose.position.x;
    float robot_y =  pose.pose.position.y;

    float diff_x_pick = fabs(robot_x - pick.x);
    float diff_y_ pick = fabs(robot_y - pick.y);
    float diff_x_drop = fabs(robot_x - drop.x);
    float diff_y_ drop = fabs(robot_y - drop.y);

    if( diff_x_pick  < = EPSILON && diff_y_pick  < = EPSILON )
    {
      reach_pickup = true;
      reach_dropoff = false;
    }
    else if( diff_x_drop  < = EPSILON && diff_y_drop  < = EPSILON )
    {
      reach_pickup = false;
      reach_dropoff = true;
    }
     else
     {
        reach_pickup = false;
        reach_dropoff = false;
     }    
}
