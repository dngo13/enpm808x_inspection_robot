
#include <iostream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/String.h"
#include "../include/robot.hpp"

// #include "../include/PressureDetection.hpp"
#include "enpm808x_inspection_robot/location.h"
#include "enpm808x_inspection_robot/array.h"

void flaggedCallback(const enpm808x_inspection_robot::array::ConstPtr &msg) {
  ROS_INFO("STREAMMMMMM");
  ROS_INFO("%s", msg->id[0].check.c_str());
}

int main(int argc, char **argv) {
  // create a node for running the subscriber
  ros::init(argc, argv, "subscriber_node");
  ros::NodeHandle nh;
  // create the subscriber
  ros::Subscriber sub_sub = nh.subscribe("flag", 1000, flaggedCallback);

  // Run the subscriber until someone stops the program with Ctrl + C
  ros::spin();

  return 0;
}
