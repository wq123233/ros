/*********************************
 * 串口节点，订阅cmd_vel话题并发布odometry话题
 * 从cmd_vel话题中分解出速度值通过串口送到移动底盘
 * 从底盘串口接收里程消息整合到odometry话题用于发布
 * 
 * @StevenShi
 * *******************************/
#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

#define	sBUFFERSIZE	15//send buffer size 串口发送缓存长度
#define	rBUFFERSIZE	27//receive buffer size 串口接收缓存长度
unsigned char s_buffer[sBUFFERSIZE];//发送缓存
unsigned char r_buffer[rBUFFERSIZE];//接收缓存

/************************************
 * 串口数据发送格式共15字节
 * head head linear_v_x  linear_v_y angular_v  CRC
 * 0xff 0xff float       float      float      u8
 * **********************************/
/**********************************************************
 * 串口接收数据格式共27字节
 * head head x-position y-position x-speed y-speed angular-speed pose-angular CRC
 * 0xaa 0xaa float      float      float   float   float         float(yaw)   u8
 * ********************************************************/

//联合体，用于浮点数与16进制的快速转换
typedef union{
	unsigned char cvalue[4];
	float fvalue;
}float_union;

serial::Serial ser;

//订阅turtle1/cmd_vel话题的回调函数，用于显示速度以及角速度
void cmd_vel_callback(const geometry_msgs::Twist& cmd_vel){
	ROS_INFO("I heard linear velocity: x-[%f],y-[%f],",cmd_vel.linear.x,cmd_vel.linear.y);
	ROS_INFO("I heard angular velocity: [%f]",cmd_vel.angular.z);
	std::cout << "Twist Received" << std::endl;
	
	memset(s_buffer,0,sizeof(s_buffer));
	s_buffer[0] = 0xff;//send_data
	ser.write(s_buffer,sBUFFERSIZE);
}


int main (int argc, char** argv)
{
    ros::init(argc, argv, "my_serial_receive_node");
    ros::NodeHandle nh;

	//订阅/turtle1/cmd_vel话题用于测试 $ rosrun turtlesim turtle_teleop_key
	ros::Subscriber write_sub = nh.subscribe("/turtle1/cmd_vel",1000,cmd_vel_callback);

    try
    {
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(9600);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }

    if(ser.isOpen())
	{
        ROS_INFO_STREAM("Serial Port initialized");
    }else{
        return -1;
    }

	//定义时间
	ros::Time current_time, last_time;
	current_time = ros::Time::now();
	last_time = ros::Time::now();

    //10hz频率执行
    ros::Rate loop_rate(10);
    while(ros::ok())
	  {

        ros::spinOnce();

        if(ser.available())
		{
            ROS_INFO_STREAM("Reading from serial port");
			ser.read(r_buffer,rBUFFERSIZE);
			
            int i;
			//for(i=0;i<rBUFFERSIZE;i++)
			ROS_INFO("[0x%02x]",r_buffer[i]);
			ROS_INFO_STREAM("End reading from serial port");
			
		
		}
			memset(r_buffer,0,rBUFFERSIZE);
     }

        loop_rate.sleep();

}
