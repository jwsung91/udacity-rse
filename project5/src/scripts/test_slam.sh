#!/bin/sh

# Set catkin_ws path
workspace=~/workspace/UND_Robo/project5
#workspace=/home/worksapce/catkin_ws

# source setup.bash
xterm -e "source $workspace/devel/setup.bash"

## deploy a turtlebot in my environment
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$workspace/src/map/jin.world" &
sleep 10

## perform SLAM
xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 2

## observe the map in rviz
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 2

## manually control the robot
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"


