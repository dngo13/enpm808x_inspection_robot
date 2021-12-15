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

#ifndef INCLUDE_PRESSURE_DETECTION_HPP_
#define PRESSURE_DETECTION_HPP_

#include <sstream>
#include <string>
#include "ros/ros.h"
#include "sensor_msgs/FluidPressure.h"

class PressureDetection {
 private:
    // Detected pressure
    float ahu_pressure;  // Pascals
    float boiler_pressure;  // Pascals
    float chiller_pressure;  // Pascals

    // Air handler low and high pressure ranges
    float ahu_low_pressure;
    float ahu_high_pressure;
    // Boiler low and high pressure ranges
    float boiler_low_pressure;
    float boiler_high_pressure;
    // Chiller low and high pressure ranges
    float chiller_low_pressure;
    float chiller_high_pressure;

 public:
    // Constructor
    PressureDetection();
    // Destructor
    ~PressureDetection();
    void pressureCallback(const sensor_msgs::FluidPressure::ConstPtr& msg);
    // Methods for pressure detection for each unit
    bool detectAHUPressure();
    bool detectBoilerPressure();
    bool detectChillerPressure();
    // Methods to check range of pressure for each unit
    bool incorrectAHUPressure(float ahu_low_pressure, float ahu_high_pressure);
    bool incorrectBoilerPressure(float boiler_low_pressure,
                                                   float boiler_high_pressure);
    bool incorrectChillerPressure(float chiller_low_pressure,
                                             float chiller_high_pressure);
};

#endif  // PRESSURE_DETECTION_HPP_
