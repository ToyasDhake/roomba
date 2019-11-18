
#ifndef INCLUDE_DEPTHCALCULATION_HPP_
#define INCLUDE_DEPTHCALCULATION_HPP_

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"





class DepthCalculation {
 private:
  bool collision = false;

 public:
  DepthCalculation();
  ~DepthCalculation();
  bool Collision();
  void findDepth(const sensor_msgs::LaserScan::ConstPtr& msg);
  
};

#endif  // INCLUDE_DEPTHCALCULATION_HPP_


