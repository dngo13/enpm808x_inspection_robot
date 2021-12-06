#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    ros::NodeHandle n;
    return RUN_ALL_TESTS();
}