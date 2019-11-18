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
* @file Distance.hpp
* @author Toyas Dhake
* @date 18 Nov 2019
* @copyright 2019 Toyas Dhake
* @brief Declaration of class DistanceCalcualtion to calculate distance
*/
#ifndef INCLUDE_DISTANCE_HPP_
#define INCLUDE_DISTANCE_HPP_

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

class DistanceCalculation {
 private:
    bool collision = false;

 public:
    /**
    * @brief Constructor DistanceCalculation sets collision flag
    */
    DistanceCalculation();
    /**
    * @brief Destructor DistanceCalculation deletes object
    */
    ~DistanceCalculation();
    /**
    * @brief Function returns true if the robot is going to collide with an 
    * obstacle else returns false
    * @return bool collision
    */
    bool isCollision();
    /**
    * @brief Function calculates distance of obstacle from robot and based on it 
    * sets collision flag.
    * @param msg type sensor_msgs::LaserScan
    */
    void findDepth(const sensor_msgs::LaserScan::ConstPtr& msg);
};

#endif  // INCLUDE_DISTANCE_HPP_
