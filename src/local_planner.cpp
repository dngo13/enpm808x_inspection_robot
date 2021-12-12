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
 *  @file    local_planner.cpp
 *  @author  Charu Sharma
 *  @date    12/11/2021
 *  @version 1.0
 *
 *  @brief local planner file
 *
 *  @section DESCRIPTION
 *
 *  planner file to write a custom local planner to work with the project
 *  using a turtlebot.
 *
 */

#include "include/local_planner.hpp"
// #include "local_planner/local_planner.hpp"
#include <pluginlib/class_list_macros.h>

PLUGINLIB_DECLARE_CLASS(local_planner, LocalPlanner,
                    local_planner::LocalPlanner, nav_core::BaseLocalPlanner)

namespace local_planner {
    LocalPlanner::LocalPlanner() : costmap_ros_(NULL),
                                        tf_(NULL), initialized_(false) {}

    LocalPlanner::LocalPlanner(std::string name, tf::TransformListener* tf,
                                    costmap_2d::Costmap2DROS* costmap_ros)
        : costmap_ros_(NULL), tf_(NULL), initialized_(false) {
            initialize(name, tf, costmap_ros);
        }

    LocalPlanner::~LocalPlanner() {}

    void LocalPlanner::initialize(std::string name,
            tf::TransformListener* tf, costmap_2d::Costmap2DROS* costmap_ros) {
                if (!initialized_) {
                    ROS_ERROR("This planner is not initialized, initialize()");
                    return false;
                }
    }

    bool LocalPlanner::setPlan(
            const std::vector<geometry_msgs::PoseStamped>& orig_global_plan) {
                if (!initialized_) {
                    ROS_ERROR("This planner is not initialized, initialize()");
                    return false;
                }
                return true;
    }

    bool LocalPlanner::computeVelocityCommands(geometry_msgs::Twist& cmd_vel) {
        if (!initialized_) {
            ROS_ERROR("This planner is not initialized, initialize()");
            return false;
        }
        return true;

    }

    bool LocalPlanner::isGoalReached() {
        if (!initialized_) {
            ROS_ERROR("This planner is not initialized, initialize()");
            return false;
        }
        return false;
    }
}
