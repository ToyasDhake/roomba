
#include <iostream>
#include "Distance.hpp"

DepthCalculation::DepthCalculation() {
  collision = false;
}

DepthCalculation::~DepthCalculation() {
}

void DepthCalculation::findDepth
(const sensor_msgs::LaserScan::ConstPtr& msg) {
  for (auto temp : msg->ranges) {
    if (msg->ranges[temp] < 0.8) {
      collision = true;
      return;
    }
  }
  collision = false;
}

bool DepthCalculation::Collision() {
  return collision;
}


