

#include "walker.hpp"

Walker::Walker() {
  velocity = nh.advertise <geometry_msgs::Twist>
 ("/mobile_base/commands/velocity", 1000);
  distanceList = nh.subscribe <sensor_msgs::LaserScan>
 ("/scan", 50, &DepthCalculation::findDepth, &depth);

  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  velocity.publish(msg);
}

Walker::~Walker() {
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  velocity.publish(msg);
}

void Walker::walk() {
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    if (depth.Collision()) {
      msg.linear.x = 0.0;
      msg.angular.z = 3.0;
    } else {
      msg.linear.x = 0.5;
      msg.angular.z = 0.0;
    }
    velocity.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
