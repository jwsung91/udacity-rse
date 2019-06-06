## Project 2. Go Chase It!

### Project Aspect
- `drive_bot`
   - Create a `my_robot` ROS package
   - Design a differential drive robot with the Unified Robot Description Format
   - Add two sensors to my robot : `Camera`, `LIDAR`
- `world`
   - Add a white-colored ball to my gazebo world (whichi is created in project 1)
- `ball_chaser`
   - Create a ball_chaser ROS package
   - Create `ball_chaser/command_robot` service to drive the robot by controlling its linear x and angular z velocities
   - Write a `process_image` C++ node that reads my robot’s camera image
      - And analyzes it to determine the presence and position `of a white ball.
      - If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.

##myrectory Structure
```
   - And roject1
- model
   - HumanoidRobot
    myBuilding
- script
   - hello.cpp
- world
   - jin_world.world
- CmakeLists.txt

```

### Steps to launch the simulation
#### Step 1 Update and upgrade the Workspace image
```sh
$ sudo apt-get update
$ sudo apt-get upgrade -y
```

#### Step 2 Clone the lab folder in /home/workspace/
```sh
$ cd /home/workspace/
$ git clone https://github.com/samchiRobot/Udacity_RoboticsEngineer/tree/master/project1
```

#### Step 3 Compile the code
```sh
$ cd /home/workspace/project1/build/
$ cmake ../
$ make
```

#### Step 4 Add the library path to the Gazebo plugin path  
```sh
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/workspace/project1/build
```

#### Step 5 Run the Gazebo World file  
```sh
$ cd /home/workspace/project1/world/
$ gazebo jin_world
```

### Output
Gazebo World should both launch as follow
![alt text](images/project1_output.png)
