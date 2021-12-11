/*******************************************************************************
 * MIT License
 * Copyright (c)  Charu Sharma 2021
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ********************************************************************************/

/**
 *  @file    main.cpp
 *  @author  Charu Sharma
 *  @date    12/05/2021
 *  @version 1.0
 *
 *  @brief Main source file
 *
 *  @section DESCRIPTION
 *
 *  Main source file to implement the exploration of an unknown environment
 * using a turtlebot.
 *
 */
// ROS header files
#include <ros/ros.h>
#include <memory>
#include <sstream>
// Class header files
#include "../include/robot.h"


/**
 *   @brief  Main function to set up the ROS node and implement the exploration
 *
 *   @param  argc - argument count as integer
 *   @param  argv - argument vector as character array
 *
 *   @return integer 0 indication successful execution
 */

int main(int argc, char **argv) {
  // Set up ROS
  ros::init(argc, argv, "inspection");
  ros::NodeHandle n;

  // Declaring the Twist publisher
  ros::Publisher chatter_pub = n.advertise < geometry_msgs::Twist
                                                    > ("cmd_vel", 1000);

  // Set up the publisher rate to 10
  ros::Rate loop_rate(10);

  // Initialize the robot
  Robot robot(n);

  // spin ROS to execute the callbacks to obtain the occupancy grid map before
  // exploration
  ros::spinOnce();

  // sleep the node for a duration of 10 seconds to allow time for other nodes
  // and environment to be set up
  ros::Duration(10).sleep();

  // start the turtlebot
  robot.initiateRobot(n, chatter_pub, loop_rate, robot.obstacle_detected);

  return 0;
}