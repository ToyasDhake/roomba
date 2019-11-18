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
* @file walker.hpp
* @author Toyas Dhake
* @date 18 Nov 2019
* @copyright 2019 Toyas Dhake
* @brief Declearation of walker class
*/
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
    ros::Publisher velocity;
    ros::Subscriber distanceList;
    geometry_msgs::Twist msg;
    DistanceCalculation depth;

 public:
    /**
    * @brief Constructor Walker initialize everything
    */
    Walker();
    /**
    * @brief Destructor Walker stops robot and deletes everything
    */
    ~Walker();
    /**
    * @brief Function controls motion of robot. It goes straight ahead if there 
    * is no obstacle in front of it. If it detects obstacle then it will start 
    * turning untill there is no obstacle in front of it.
    */
    void walk();
};

#endif  // INCLUDE_WALKER_HPP_

