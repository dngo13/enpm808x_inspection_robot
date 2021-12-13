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

#include <iostream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/String.h"
#include "../include/robot.hpp"
#include "../include/PressureDetection.hpp"

Robot::Robot(ros::NodeHandle n) {
    ROS_INFO("Starting Inspection...");

    lidar_data = n.subscribe < sensor_msgs::LaserScan
                                        > ("/scan", 10,
                                            &Robot::readLidar, this);
}

Robot::~Robot() {
}

void Robot::initiateRobot(ros::NodeHandle n,
                    ros::Publisher chatter_pub,
                    ros::Rate loop_rate, bool obstacle_detected) {
    geometry_msgs::Twist msg;

    // Keep running till ros is running fine
    // while (ros::ok()) {
    if (obstacle_detected) {
        stopRobot(chatter_pub, loop_rate);  // Stop the turtlebot
        ROS_WARN_STREAM("OBSTACLE DETECTED");
        turnRobot(n, chatter_pub, loop_rate,
                    obstacle_detected);  // Turn the turtlebot
    } else {
        // ROS_INFO_STREAM("MOVING TOWARD TARGET");
        msg.linear.x = 0.0;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = 0.0;

        // move to location
        if (((x_pos <= -4) || (x_pos >= -5)) || ((y_pos <= -2.5) || (y_pos >= -3.5))) {
            PressureDetection.detectChillerPressure("true");
        }
        if (((x_pos <= -1) || (x_pos >= -2)) || ((y_pos <= -4.0) || (y_pos >= -5.0))) {
            PressureDetection.detectBoilerPressure("true");
        }
        if ((x_pos >= 0) ||  (y_pos >= -1.5)) {
            PressureDetection.detectAHUPressure("true");
        }
    }
    // Publish the twist message to anyone listening
    chatter_pub.publish(msg);
    // }
}

void Robot::stopRobot(ros::Publisher chatter_pub,
                        ros::Rate loop_rate) {
    geometry_msgs::Twist msg;

    // Stop the turtlebot
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    // Publish the twist message to anyone listening
    chatter_pub.publish(msg);
    ros::Duration(sleep_duration).sleep();
}

void Robot::turnRobot(ros::NodeHandle n,
                ros::Publisher chatter_pub,
                ros::Rate loop_rate, bool obstacle_detected) {
    geometry_msgs::Twist msg;

    // Turn the turtlebot
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = turn_speed;

    // Publish the twist message to anyone listening
    chatter_pub.publish(msg);
    ros::Duration(sleep_duration).sleep();

    while (!path_clear) {
        // Sleep for the remaining time until we hit our 10 Hz rate
        loop_rate.sleep();

        // "Spin" a callback in case we set up any callbacks
        ros::spinOnce();
    }
    stopRobot(chatter_pub, loop_rate);
    obstacle_detected = false;  // returns collision flag
}

void Robot::readLidar(const sensor_msgs::LaserScan::ConstPtr &msg) {
    int lidar_range = 30;

    std::vector<double> collision_detected;
    std::vector<double> lidar_range_vect;

    lidar_range_vect = std::vector<double>(msg->ranges.begin(),
                                            msg->ranges.begin() + lidar_range);

    collision_detected = std::vector<double>(msg->ranges.end() - lidar_range,
                                                msg->ranges.end());

    path_clear = true;

    for (auto &range : collision_detected) {
        if (range < collision_threshold) {
            // Returns the collision flag
            // collision_detected = true;
            path_clear = false;
        }
    }
}
