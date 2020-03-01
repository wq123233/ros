#include "ros/ros.h"
int main(int argc, char **argv)
{
    ros::init(argc,argv,"hello_world");
    ros::NodeHandle n;
    ROS_INFO("HELLO!");
    ros::spin();
    return 0;
}