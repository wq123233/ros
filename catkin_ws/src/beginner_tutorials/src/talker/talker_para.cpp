
// #include "ros/ros.h"    //ros.h 包含ros程序常用的头文件。
// #include "beginner_tutorials/Num.h"  //引用服务类型头文件

// int main(int argc, char **argv)
// {
//   ros::init(argc, argv, "talker_para");  //初始化ros，并命令节点名。
//   ros::NodeHandle n("~");    //初始化节点，调用ros api接口句柄。
//   //定义一个客户端
//   ros::Publisher client = n.advertise<beginner_tutorials::Num>("chatter_para",1);
//   ros::Rate loop_rate(1);  //设置发布频率
//   int count = 0;    //发布请求计数
//   beginner_tutorials::Num num;   //定义服务变量
//   int32_t a,b;
//   while (ros::ok()){    //检测节点是否正常运行
//     //srv.request.a = count;      //更新服务变量值。
//     //srv.request.b = count+1;
//     if(n.getParam("avalue",a))
//     {
//       num.a = a;
//     }else
//     {
//       ROS_WARN("fail get avalue");
//     }
//     if(n.getParam("bvalue",b))
//     {
//       num.b = b;
//     }else
//     {
//       ROS_WARN("fail get bvalue");
//     }
//     ROS_INFO("%d %d",num.a,num.b);
//     client.publish(num);
//     ros::spinOnce();    //处理回调函数，会返回，这里也可以不加，因为此节点没有回调函数。
//     loop_rate.sleep();  //与Line 10配套使用，用于控制发布频率。
//     ++count;            //消息计数。
//   }
//   return 0;
// }


#include "ros/ros.h"
#include "beginner_tutorials/Num.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker_para");
  ros::NodeHandle n("~");
  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::Num>("chatter_para",1);
  ros::Rate loop_rate(1);
  int count = 0;
  beginner_tutorials::Num num;
  int32_t a,b;
  while (ros::ok())
  {
    /* ros param */
    if(n.getParam("avalue",a))
    {
      num.a = a;
    }else
    {
      ROS_WARN("Fail get avalue");
    }
    if(n.getParam("bvalue",b))
    {
      num.b = b;
    }else
    {
      ROS_WARN("Fail get bvalue");
    }
    ROS_INFO("%d %d",num.a,num.b);
    chatter_pub.publish(num);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}