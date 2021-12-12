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
 *  @file    LaserScan.cpp
 *  @author  Charu Sharma
 *  @date    12/11/2021
 *  @version 1.0
 *
 *  @brief Laser scan file
 *
 *  @section DESCRIPTION
 *
 * Laser Scan file to recieving the navigation of an unknown environment
 * using a turtlebot.
 *
 */

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "laser_scan_publisher");

    ros::NodeHandle nl;
    ros::Publisher scan_pub = nl.advertise<sensor_msgs::LaserScan>("scan", 50);

    unsigned int kNumReadings = 100;
    double laser_frequency = 40;
    double ranges[kNumReadings];
    double intensities[kNumReadings];

    int count = 0;
    ros::Rate r(1.0);
    while (nl.ok()) {
        // generate some fake data for our laser scan
        for (unsigned int i = 0; i < kNumReadings; ++i) {
            ranges[i] = count;
            intensities[i] = 100 + count;
        }
        ros::Time scan_time = ros::Time::now();

        // populate the LaserScan message
        sensor_msgs::LaserScan scan;
        scan.header.stamp = scan_time;
        scan.header.frame_id = "laser_frame";
        scan.angle_min = -1.57;
        scan.angle_max = 1.57;
        scan.angle_increment = 3.14 / kNumReadings;
        scan.time_increment = (1 / laser_frequency) / (kNumReadings);
        scan.range_min = 0.0;
        scan.range_max = 100.0;

        scan.ranges.resize(kNumReadings);
        scan.intensities.resize(kNumReadings);
        for (unsigned int i = 0; i < kNumReadings; ++i) {
            scan.ranges[i] = ranges[i];
            scan.intensities[i] = intensities[i];
        }

        scan_pub.publish(scan);
        ++count;
        r.sleep();
    }
}
