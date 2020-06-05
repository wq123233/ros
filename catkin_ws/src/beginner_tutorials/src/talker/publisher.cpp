#include <ros/ros.h>
#include "beginner_tutorials/gps.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_talkrer");
    ros::NodeHandle n;
    beginner_tutorials::gps Gps;
    Gps.x = 1.0;
    Gps.y = 1.0;
    Gps.state = "WORKING";

    ros::Publisher pub = n.advertise<beginner_tutorials::gps>("gos_info",1);

    ros::Rate loop_rate(1.0);
    while(ros::ok())
    {
        Gps.x = 1.03 * Gps.x;
        Gps.y = 1.03 * Gps.y;
        ROS_INFO("Talker: GPS: x = %f, y = %f ",  Gps.x ,Gps.y);
        pub.publish(Gps);

        loop_rate.sleep();//根据前面的定义的loop_rate,设置1s的暂停,两行配合使用

    }
}