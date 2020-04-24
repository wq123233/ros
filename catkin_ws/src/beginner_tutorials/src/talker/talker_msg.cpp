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

// #include "ros/ros.h"
// #include "std_msgs/String.h"
// #include <sstream>

// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "talker");
//     ros::NodeHandle n;
//     ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1);

//     ros::Rate loop_rate(10);
//     int count = 0;
//     while (ros::ok())
//     {
//         /* code */
//         std_msgs::String msg;

//         std::stringstream ss;
//         ss << "nihao shijie !" << count;
//         msg.data = ss.str();  // 将string类型的数据转换放到data中。
//         ROS_INFO("%s", msg.data.c_str());  // 将string类型的数据转换为字符串类型，c语言中没有string类型 
//         chatter_pub.publish(msg);
//         ros::spinOnce();  // 这里可以不加，处理完了回调函数以后会再处理主函数
//         loop_rate.sleep();
//         ++count;
//     }
//     return 0;
// }


#include "ros/ros.h"
#include "beginner_tutorials/Num.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "taler_msg");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<beginner_tutorials::Num>("chatter_msg",1);
    
    ros::Rate loop_rate(10);
    int count = 0;
    beginner_tutorials::Num num;

    while(ros::ok())
    {
        num.a = count;
        num.b = count + 1;
        ROS_INFO("%d %d %d", num.a,num.b,num.a+num.b);
        chatter_pub.publish(num);
        ros::spinOnce();
        loop_rate.sleep();  //与loop_rate(10)同时出现使用
        ++count;
    }
    return 0;
}