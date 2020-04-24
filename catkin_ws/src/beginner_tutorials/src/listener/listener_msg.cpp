// #include"ros/ros.h"
// #include"std_msgs/String.h"

// void chatterCallback(const std_msgs::String::ConstPtr& msg) // ::和/ 表示的是在文件夹下 ->表示文件夹下的某个变量 rosmsg 能显示文件夹下的变量
// {
//     ROS_INFO("l:[%s]", msg->data.c_str());
// }

// int main(int argc, char **argv)
// {
//     ros::init(argc,argv,"listener");
//     ros::NodeHandle n;
//     ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//     ros::spin(); //  等待zhixing回调函数 
//     return 0;
// }

// #include "ros/ros.h"
// #include "std_msgs/String.h"

// void  chatterCallback(const std_msgs::String::ConstPtr& msg)
// {
//     ROS_INFO("l:[%s]", msg->data.c_str());
// }


// int main(int argc, char **argv)
// {
//     ros::init(argc,argv,"listener");
//     ros::NodeHandle n;
//     ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//     ros::spin();  // 一般的 监听者都这么写 直接进入回调函数 不在执行 return 0
//     return 0;

// }
#include "ros/ros.h"
#include "beginner_tutorials/Num.h"

void chatterCallback(const beginner_tutorials::Num::ConstPtr& msg) // beginner_tutorials是功能包名字 Num是文件的名字
{
    ROS_INFO("I heard: [%d %d %d]", msg->a,msg->b,msg->a+msg->b);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener_msg");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter_msg",1, chatterCallback);
    ros::spin();
    return 0;
}