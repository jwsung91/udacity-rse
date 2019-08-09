#include <ros/ros.h>
#include <cmath>

#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
//#include "geometry_msgs/Pose2D.h"

#define REACH_DIST 0.1

//geometry_msgs::Pose2D current_pose;

float current_pose_x = 0.0;
float current_pose_y = 0.0;

void odomCallback(const nav_msgs::Odometry::ConstPtr msg)
{
  current_pose_x = msg->pose.pose.position.x;
  current_pose_y = msg->pose.pose.position.y;
  ROS_INFO("x: %f, y: %f", current_pose_x, current_pose_y);
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  bool reach_goal = false;
  float dist_x = 0;
  float dist_y = 0;

  // add odom subscriber
  ros::Subscriber odom_sub = n.subscribe("/odom", 1000, odomCallback);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  // Set Phase (modified)
  uint8_t phase = 0;

  float goals[2][3] = {{5,5,0},{1,-3,0}};

  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "cube_marker";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;


    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;

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

    while(1)
    {
      if(phase==0)
      {
        phase=1;
        break;
      }
      dist_x = fabs(current_pose_x-goals[phase-1][0]);
      dist_y = fabs(current_pose_x-goals[phase-1][1]);

      if(dist_x<=REACH_DIST&&dist_y<=REACH_DIST)
      {
        reach_goal=true;
        phase++;
      }
    }
    switch (phase)
    {
        case 1:
            ROS_INFO("phase 1 : Publish the marker at the pickup zone and wait 5 seconds");
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = goals[0][0];
            marker.pose.position.y = goals[0][1];
            marker.pose.position.z = goals[0][2];
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            marker.pose.orientation.w = 1.0;
        break;
        
        case 2:
            ROS_INFO("phase 2 : Hide the marker and wait 5 seconds");
            marker.action = visualization_msgs::Marker::DELETE;
        break;
        
        case 3:
            ROS_INFO("phase 3 : Publish the marker at the drop off zone");
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = goals[1][0];
            marker.pose.position.y = goals[1][1];
            marker.pose.position.z = goals[1][2];
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            marker.pose.orientation.w = 1.0;
            break;
    }

    marker_pub.publish(marker);

    if(phase>3)
        while(1)
        {}
    r.sleep();
  }
}
