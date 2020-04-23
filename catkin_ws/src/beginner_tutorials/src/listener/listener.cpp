#include"ros/ros.h"
#include"std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg) // ::和/ 表示的是在文件夹下 ->表示文件夹下的某个变量 rosmsg 能显示文件夹下的变量
{
    ROS_INFO("l:[%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::spin(); //  等待zhixing回调函数 
    return 0;
}

