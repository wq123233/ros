// #include "ros/ros.h"
// int main(int argc, char **argv)
// {
//     ros::init(argc,argv,"hello_world");
//     ros::NodeHandle n;
//     ROS_INFO("HELLO!");
//     ros::spin();
//     return 0;
// }

#include "ros/ros.h"

int main(int argc, char **argv)
{

    ros::init(argc,argv,"hello_world");
    ros::NodeHandle n;
    ROS_INFO("NI HAO!");
    ros::spin();                          //  等待处理回调函数，没有回调函数可以不写

}