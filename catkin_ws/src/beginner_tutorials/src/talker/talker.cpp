// #include "ros/ros.h"
// #include "std_msgs/String.h"
// #include <sstream>

// int main(int argc, char **argv)
// {
//     ros::init(argc,argv,"talker");
//     ros::NodeHandle n;
//     ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1);

//     ros::Rate loop_rate(10);
//     int count = 0;
//     while (ros::ok())
//     {
//         /* code */
//         std_msgs::String msg;

//         std::stringstream ss;
//         ss << "hello world!!" << count;
//         msg.data = ss.str();
//         ROS_INFO("%s",msg.data.c_str());
//         chatter_pub.publish(msg);
//         ros::spinOnce();
//         loop_rate.sleep();
//         ++count;

//     }
//     return 0;
// }

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1);

    ros::Rate loop_rate(10);
    int count = 0;
    while (ros::ok())
    {
        /* code */
        std_msgs::String msg;

        std::stringstream ss;
        ss << "nihao shijie !" << count;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);
        ros::spinOnce();  // 这里可以不加，处理完了回调函数以后会再处理主函数
        loop_rate.sleep();
        ++count;
    }
    return 0;
}