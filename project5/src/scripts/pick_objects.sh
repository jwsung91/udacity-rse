#!/bin/bash

# Set catkin_ws path
workspace=~/workspace/UND_Robo/project5

## deploy a turtlebot in my environment
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$workspace/src/map/jin.world" &
sleep 10

## localize the turtlebot
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$workspace/src/map/jin_world_map.yaml" &
sleep 2

## observe the map in rviz
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 2

## pick up virtual objects
xterm -e "rosrun pick_objects pick_objects_node"
sleep 2