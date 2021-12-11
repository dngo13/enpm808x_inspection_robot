/* 
MIT License

Copyright (c) 2021 Diane Ngo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. 
*/
#pragma once

#ifndef INCLUDE_ROBOT_HPP_
#define ROBOT_HPP_

#include <sstream>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

class Robot {
 private:
    // Declaring the front speed of the turtlebot
    double front_speed = 0.2;
    // Declaring the turning speed of the turtlebot
    double turn_speed = 0.5;
    // Sleep duration so that stop doesn't keep getting called
    double sleep_duration = 0.4;
    // Declaring a minimum distance the robot can stay away from the obstacle
    double collision_threshold = 0.35;
    // Subscriber for the LIDAR Data
    ros::Subscriber lidar_data;

    // boolean for making sure the robot can move ahead
    bool path_clear = true;

 public:
    // boolean for obstacle detection
    bool obstacle_detected = false;
    // Declaring the new constructor
    explicit Robot(ros::NodeHandle);
    // Function to start the turtlebot motion in the environment
    void initiateRobot(ros::NodeHandle, ros::Publisher, ros::Rate, bool obstacle_detected);
    // Function to keep turning while the robot is clear of any obstacles
    void turnRobot(ros::NodeHandle, ros::Publisher, ros::Rate,  bool obstacle_detected);
    // Function to stop the robot
    void stopRobot(ros::Publisher, ros::Rate);
    // Function to get LIDAR Data
    void readLidar(const sensor_msgs::LaserScan::ConstPtr&);
};

#endif  // ROBOT_HPP_