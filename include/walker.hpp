
#ifndef INCLUDE_WALKER_HPP_
#define INCLUDE_WALKER_HPP_

#include <ros/ros.h>
#include <iostream>
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "Distance.hpp"


class Walker {
 private:
    ros::NodeHandle nh;
    geometry_msgs::Twist msg;
    ros::Publisher velocity;
    ros::Subscriber distanceList;
    DepthCalculation depth;

 public:
    Walker();
    ~Walker();
    void walk();
};

#endif  // INCLUDE_WALKER_HPP_

