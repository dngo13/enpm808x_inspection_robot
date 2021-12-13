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

#include "../include/PressureDetection.hpp"
#include <std_msgs/Float64.h>
#include <sstream>
#include <string>
#include "ros/ros.h"
#include "sensor_msgs/FluidPressure.h"

#include "enpm808x_inspection_robot/inspect.h"


// Air handler low and high pressure ranges
static float ahu_low_pressure = 482633.0;  // 70 psi = 482633 Pa
static float ahu_high_pressure = 689476.0;  // 100 psi = 689476 Pa

// Boiler low and high pressure ranges (Need to convert PSI to Pascal)
static float boiler_low_pressure = 413685.0;  // 60 psi = 413685 Pa
static float boiler_high_pressure = 620528.0;  // 90 psi = 620528 Pa
// Chiller low and high pressure ranges
static float chiller_low_pressure = 241317.0;  // 35 psi = 241317 Pa
static float chiller_high_pressure = 448159.0;  // 65 psi = 448159 Pa
/** ADD IN X Y LOCATION AND DETECTED PRESSURE **/


PressureDetection::PressureDetection() {
    ros::NodeHandle nh;

    std::cout << "Hello World" << std::endl;
    // ros::Subscriber pressure_sub =
    //                 nh.subscribe("inspection", 1000, pressureCallback);
}

PressureDetection::~PressureDetection() {
}

/**
 * @brief Pressure callback function
 * 
 * @param msg 
 */
void pressureCallback(const enpm808x_inspection_robot::inspect &inspect) {
    // PressureDetection

    ROS_INFO("Pressure of AHU: %f", inspect.ahu_pressure);
    ROS_INFO("Pressure of boiler: %f", inspect.boiler_pressure);
    ROS_INFO("Pressure of chiller: %f", inspect.chiller_pressure);

    // if (detectAHUPressure() == true) {
    //     ROS_INFO("Pressure of AHU: %f", inspect.ahu_pressure);
    //     if (incorrectAHUPressure(
    //                        ahu_low_pressure, ahu_high_pressure) == true) {
    //         ROS_WARN_STREAM("Pressure out of range. Maintenance required!!");
    //     } else {
    //         ROS_INFO_ONCE("Air Handling Unit safe to operate");
    //     }
    // }
    // if (detectBoilerPressure == true) {
    //     ROS_INFO("Pressure of boiler: %f", inspect.boiler_pressure);
    //     if (incorrectBoilerPressure(
    //                     boiler_low_pressure, boiler_high_pressure) == true) {
    //         ROS_WARN_STREAM("Pressure out of range. Maintenance required!!");
    //     } else {
    //         ROS_INFO_ONCE("Boiler safe to operate");
    //         }
    // }

    // if (detectChillerPressure == true) {
    //     ROS_INFO("Pressure of chiller: %f", inspect.chiller_pressure);
    //     if (incorrectChillerPressure(chiller_low_pressure,
    //                                         chiller_high_pressure) == true) {
    //     ROS_WARN_STREAM("Pressure out of range. Maintenance required!!");
    // } else {
    //     ROS_INFO_ONCE("Chiller safe to operate");
    //     }
    // }
}

float PressureDetection::detectAHUPressure() {
    return ahu_pressure;
}

float PressureDetection::detectBoilerPressure() {
    return boiler_pressure;
}

float PressureDetection::detectChillerPressure() {
    return chiller_pressure;
}

/**
 * @brief Detects if AHU pressure is in specified range
 * 
 * @param ahu_low_pressure 
 * @param ahu_high_pressure 
 * @return true If pressure is less than low pressure or greater than high temperature
 * @return false If pressure is in range
 */
bool PressureDetection::incorrectAHUPressure(float ahu_low_pressure,
                                                float ahu_high_pressure) {
    // Calls detectAHUPressure()
    ahu_pressure = detectAHUPressure();
    if ((ahu_pressure < ahu_low_pressure) || (
                                        ahu_pressure > ahu_high_pressure)) {
        return true;  // Out of range, incorrect pressure
    } else if (
        (ahu_pressure >= ahu_low_pressure) || (
                                    ahu_pressure <= ahu_high_pressure)) {
        return false;  // Pressure is in range
    }
}

/**
 * @brief Detects if boiler pressure is in specified range
 * 
 * @param boiler_low_pressure 
 * @param boiler_high_pressure 
 * @return true If pressure is less than low pressure or greater than high temperature
 * @return false If pressure is in range
 */
bool PressureDetection::incorrectBoilerPressure(float boiler_low_pressure,
                                                float boiler_high_pressure) {
    // Calls detectBoilerPressure()
    boiler_pressure = detectBoilerPressure();
    if ((boiler_pressure < boiler_low_pressure) || (
                                    boiler_pressure > boiler_high_pressure)) {
        return true;  // Out of range, incorrect pressure
    } else if ((boiler_pressure >= boiler_low_pressure) || (
                                    boiler_pressure <= boiler_high_pressure)) {
        return false;  // Pressure is in range
    }
}

/**
 * @brief Detects if chiller pressure is in specified range
 * 
 * @param chiller_low_pressure 
 * @param chiller_high_pressure 
 * @return true If pressure is less than low pressure or greater than high temperature
 * @return false If pressure is in range
 */
bool PressureDetection::incorrectChillerPressure(float chiller_low_pressure,
                                               float chiller_high_pressure) {
    // Calls detectChillerPressure()
    chiller_pressure = detectChillerPressure();
    if ((chiller_pressure < chiller_low_pressure) || (
                                    chiller_pressure > chiller_high_pressure)) {
        return true;  // Out of range, incorrect pressure
    } else if ((chiller_pressure >= chiller_low_pressure) ||
                                (chiller_pressure <= chiller_high_pressure)) {
        return false;  // Pressure is in range
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "pressure_detector");
    ros::NodeHandle nh;

    ros::Subscriber pressure_sub =
                nh.subscribe("inspection", 1000, pressureCallback);

    ros::Publisher pressure_pub =
        nh.advertise<enpm808x_inspection_robot::inspect>("inspection", 1000);
    ros::Rate loop_rate(1);

    // ahu_low_pressure = 482633.0;
    // ahu_high_pressure = 689476.0;
    // boiler_low_pressure = 413685.0;
    // boiler_high_pressure = 620528.0;
    // chiller_low_pressure = 241317.0;
    // chiller_high_pressure = 448159.0;

    PressureDetection PressureDetection();

    while (ros::ok()) {
        enpm808x_inspection_robot::inspect inspect;
        inspect.ahu_pressure = 500000.0;
        inspect.boiler_pressure = 500000.0;
        inspect.chiller_pressure = 300000.0;

        pressure_pub.publish(inspect);

        ros::spinOnce();
        loop_rate.sleep();
    }

    ros::spin();
    // PressureDetection pressureSensor();
    return 0;
}


// To add float32 msg_robot_location &  float32 msgtarget_location @inspect.msg
