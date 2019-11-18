[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/ToyasDhake/roomba/blob/master/LICENSE.txt)
# Roomba

## Overview

This project involves a robot which can travel in a workspace avoiding obstacles. For this ROS is used with gazebo and turtlebot. Basic idea is robot keeps traveling in one direction and when it detects an obstacel it stops moving forward and rotates until there isn't any obstacle in front of it.

## Dependencies

1. ROS Kinetic
2. Catkin
3. Turtle Bot
4. Gazebo


## Demo via command-line

Run roomba demo(Walker)

```
git clone --recursive https://github.com/ToyasDhake/roomba.git
cp <path to repository> <catkin_workspace/src/>
cd <catkin_workspace>
catkin_make
source ./devel/setup.bash
roslaunch roomba roomba.launch record_flag:=false

```

Record to rosbag

```
git clone --recursive https://github.com/ToyasDhake/roomba.git
cp <path to repository> <catkin_workspace/src/>
cd <catkin_workspace>
catkin_make
source ./devel/setup.bash
roslaunch roomba roomba.launch record_flag:=true
```

Inspect rosbag

First download rosbag file from link:
https://drive.google.com/file/d/1FcQJpExevW2-YiA0dzui91atSanxLAgw/view?usp=sharing

```
(terminal 1)
roscore
(terminal 2)
cd Downloads
rosbag play roombatopics.bag
```


## Copyright

Copyright (C) 2019 Toyas Dhake For license information, see LICENSE.txt.
