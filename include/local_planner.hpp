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

#ifndef LOCAL_PLANNER_HPP_
#define LOCAL_PLANNER_HPP_

// abstract class from which our plugin inherits
#include <nav_core/base_local_planner.h>

#include <string>
#include <vector>
#include <ros/ros.h>
#include "std_msgs/String.h"

// using namespace std;

namespace simple_local_planner {
class LocalPlanner : public nav_core::BaseLocalPlanner {
 public:
    LocalPlanner();

    LocalPlanner(std::string name, tf::TransformListener* tf,
        costmap_2d::Costmap2DROS* costmap_ros);

    ~LocalPlanner();

    void initialize(std::string name, tf::TransformListener* tf,
        costmap_2d::Costmap2DROS* costmap_ros);


    bool setPlan(
        const std::vector<geometry_msgs::PoseStamped>& orig_global_plan);

    bool computeVelocityCommands(geometry_msgs::Twist& cmd_vel);

    bool isGoalReached();

 private:
};
};  // namespace simple_local_planner

#endif  // LOCAL_PLANNER_HPP_
