/*
* Copyright [MIT] 2019 Toyas Dhake
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* @file walker.cpp
* @author Toyas Dhake
* @date 18 Nov 2019
* @copyright 2019 Toyas Dhake
* @brief Implementation of walker class
*/
#include "walker.hpp"

Walker::Walker() {
  velocity = nh.advertise <geometry_msgs::Twist>
 ("/mobile_base/commands/velocity", 1000);
  distanceList = nh.subscribe <sensor_msgs::LaserScan>
 ("/scan", 50, &DistanceCalculation::findDepth, &depth);

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
    if (depth.isCollision()) {
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

Walker::~Walker() {
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
  velocity.publish(msg);
}


