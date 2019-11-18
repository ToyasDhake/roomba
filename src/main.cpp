

#include <ros/ros.h>
#include "walker.hpp"



int main(int argc, char* argv[]) {
  ros::init(argc, argv, "roombaRobot");
  Walker walkerRobot;
  walkerRobot.walk();
  return 0;
}
