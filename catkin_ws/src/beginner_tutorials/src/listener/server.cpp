#include <ros/ros.h>
#include "beginner_tutorials/Greeting.h"
#include "string"

bool handle_function(beginner_tutorials::Greeting::Request  &req,
                     beginner_tutorials::Greeting::Response &res)
{
    ROS_INFO("Request from %s with age %d", req.name.c_str(),req.age);

    res.feedback = "Hi " + req.name + ". I'm server!";
    return true;

}




int main(int argc, char **argv)
{
    ros::init(argc, argv, "greeting_server");

    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("greetings", handle_function);

    ros::spin();

    return 0;

}
