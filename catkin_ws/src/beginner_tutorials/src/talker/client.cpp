#include "ros/ros.h"
#include "beginner_tutorials/Greeting.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "greeting_client");

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<beginner_tutorials::Greeting>("greetings"); 
    beginner_tutorials::Greeting srv;
    srv.request.name = "HAN";
    srv.request.age  = 20;

    if(client.call(srv))
    {
        ROS_INFO("Response from server: %s", srv.response.feedback.c_str());
    }
    else
    {
        ROS_ERROR("Failed to call service Service_demo");
		return 1;
    }
    
return 0;


}