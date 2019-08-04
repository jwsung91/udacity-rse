#!/bin/sh

# Set catkin_ws path
workspace=~/workspace/UND_Robo/project5
#workspace=/home/worksapce/catkin_ws

# source setup.bash
xterm -e "source $workspace/devel/setup.bash"

## deploy a turtlebot in my environment
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$workspace/src/map/jin.world" &
sleep 5
## perform SLAM


## observe the map in rviz


## manually control the robot


#xterm  -e  " gazebo " &
#sleep 5
#xterm  -e  " source /opt/ros/kinetic/setup.bash; roscore" & 
#sleep 5
#xterm  -e  " rosrun rviz rviz"
#sleep 5

