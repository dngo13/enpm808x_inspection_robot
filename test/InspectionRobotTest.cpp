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

/**
 * @file InspectionRobotTest.cpp
 * @author Diane Ngo (dngo13)
 * @brief Test cases for inspection robot
 * @version 0.1
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Headers
#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include "../include/PressureDetection.hpp"

/**
 * @brief Checks if AHU pressure is in range
 * 
 */
TEST(PressureDetection, pressureAHUTest) {
    static float ahu_low_pressure = 482633.0;
    static float ahu_high_pressure = 689476.0;
    float ahu_pressure = 500000.0;
    EXPECT_LE(ahu_pressure, ahu_high_pressure);
    EXPECT_GE(ahu_pressure, ahu_low_pressure);
}

/**
 * @brief Checks if boiler pressure is in range
 * 
 */
TEST(PressureDetection, pressureBoilerTest) {
    static float boiler_low_pressure = 413685.0;
    static float boiler_high_pressure = 620528.0;
    float boiler_pressure = 500000.0;
    EXPECT_LE(boiler_pressure, boiler_high_pressure);
    EXPECT_GE(boiler_pressure, boiler_low_pressure);
}

/**
 * @brief Checks if chiller pressure is in range
 * 
 */
TEST(PressureDetection, pressureChillerTest) {
    static float chiller_low_pressure = 241317.0;
    static float chiller_high_pressure = 448159.0;
    float chiller_pressure = 300000.0;
    EXPECT_LE(chiller_pressure, chiller_high_pressure);
    EXPECT_GE(chiller_pressure, chiller_low_pressure);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "InspectionRobotTest");
    ros::NodeHandle n;
    return RUN_ALL_TESTS();
}