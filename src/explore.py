#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""*******************************************************************************
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
 ********************************************************************************"""

"""
 *  @file    explore.py
 *  @author  Charu Sharma
 *  @date    12/14/2021
 *  @version 1.0
 *
 *  @brief Main source file
 *
 *  @section DESCRIPTION
 *
 *  file to let the bot explore to the target locations and sending confirmation flag when reached
 *
 """
#!/usr/bin/env python
#importing Libraries
import rospy
import math
import tf
from geometry_msgs.msg import Twist, Point
from sensor_msgs.msg import LaserScan
from tf.transformations import euler_from_quaternion
from enpm808x_inspection_robot.msg import location, flag_array, flag


rospy.init_node("move_robot")

pub = rospy.Publisher("cmd_vel", Twist, queue_size=1)

# create another publisher for location
# rospy.init_node('location_node') 
# loc_pub = rospy.Publisher('location', array, queue_size=1) 
loc_pub = rospy.Publisher('flag', flag_array, queue_size=1) 
rate = rospy.Rate(1) 
velocity_msg = Twist()
rate = rospy.Rate(4)
tf_listener = tf.TransformListener()
parent_frame = 'odom'
child_frame = 'base_footprint'
k_h_gain = 1
k_v_gain = 1
distance_to_goal = 0.0
# locations = location()
flagged = flag()
flagged_arrays = flag_array()
flagged.check = 'false'


try:
    tf_listener.waitForTransform(parent_frame, child_frame, rospy.Time(), rospy.Duration(1.0))
except (tf.Exception, tf.ConnectivityException, tf.LookupException):
    rospy.loginfo("Cannot find transform between {p} and {c}".format(p=parent_frame, c=child_frame))
    rospy.signal_shutdown("tf Exception")

def get_odom_data():
    # Get the current pose of the robot from the /odom topic

    try:
        (trans, rot) = tf_listener.lookupTransform(parent_frame, child_frame, rospy.Time(0))
        rotation = euler_from_quaternion(rot)
    except (tf.Exception, tf.ConnectivityException, tf.LookupException):
        rospy.loginfo("TF Exception")
        return
    return Point(*trans), rotation[2]

def compute_distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def go_to_goal(goal_x, goal_y):

    global velocity_msg

    (position, rotation) = get_odom_data()
    last_rotation = 0

    # locations.loc_x = position.x
    # locations.loc_y = position.y

    distance_to_goal = compute_distance(position.x, position.y, goal_x, goal_y)

    while distance_to_goal > 0.05:
        (position, rotation) = get_odom_data()
        x_start = position.x
        y_start = position.y
        rospy.loginfo("x = {0}, y = {1}".format(x_start, y_start))
        angle_to_goal = math.atan2(goal_y - y_start, goal_x - x_start)

        if angle_to_goal < -math.pi / 4 or angle_to_goal > math.pi / 4:
            if 0 > goal_y > y_start:
                angle_to_goal = -2 * math.pi + angle_to_goal
            elif 0 <= goal_y < y_start:
                angle_to_goal = 2 * math.pi + angle_to_goal
        if last_rotation > math.pi - 0.1 and rotation <= 0:
            rotation = 2 * math.pi + rotation
        elif last_rotation < -math.pi + 0.1 and rotation > 0:
            rotation = -2 * math.pi + rotation

        velocity_msg.angular.z = k_v_gain * angle_to_goal - rotation
        distance_to_goal = compute_distance(position.x, position.y, goal_x, goal_y)

        velocity_msg.linear.x = min(k_h_gain * distance_to_goal, 0.2)

        if velocity_msg.angular.z > 0:
            velocity_msg.angular.z = min(velocity_msg.angular.z, 0.6)
        else:
            velocity_msg.angular.z = max(velocity_msg.angular.z, -0.6)
        last_rotation = rotation
        sub = rospy.Subscriber('scan', LaserScan, sensor_callback)
        pub = rospy.Publisher("cmd_vel", Twist, queue_size=1)  

        pub.publish(velocity_msg)
        rate.sleep()
    velocity_msg.linear.x = 0.0
    velocity_msg.angular.z = 0.0

    pub.publish(velocity_msg)
    rate.sleep()

    
def sensor_callback(msg):

    front = msg.ranges[0]
    left = msg.ranges[90]
    right = msg.ranges[270]

def read_scan():
    rospy.Subscriber("scan", LaserScan, sensor_callback)
    rospy.spin()

# while not rospy.is_shutdown():
#     loc_pub.publish(arrays.loc)

if __name__ == "__main__":
    action = ""
    
    go_to_goal(-3, -1)
    flagged.check = 'true'
    print("The robot has reached the Chiller")
    print("Commencing the pressure Detection")
    # print("locations.loc_x = ", locations.loc_x)
    # print("locations.loc_y = ", locations.loc_y)

    flagged.check = 'false'    
    go_to_goal(0, 3)
    print("The robot has reached the Boiler")
    print("Commencing the pressure Detection")
    # locations.loc_x = 0.0
    # locations.loc_y = 3.0
    # send message for boiler
    
    go_to_goal(1, 3)
    print("The robot has reached the Air Handling Units")
    print("Commencing the pressure Detection")
    # send message to AHU


        # arrays.id.insert(0,flag)
    while not rospy.is_shutdown():
        loc_pub.publish(flagged_arrays.id)
        flagged_arrays.id.insert(0,flagged)
        rate.sleep()

    exit()