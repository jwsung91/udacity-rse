## Project 1. Build My World


### Project Aspect
- My Office : A building model designed on the Building Editor tool of Gazebo. The structure contains features, and colors.
- Humanoid robot : A model designed on the Model Editor tool of Gazebo. (Models don't have colors because i don't know how to do this)
- Tables : A model imported from the Gazebo online library
- Terminal : A welcome message generated from a world plugin and printed to the terminal.


### Directory Structure
```
Project1
- model
   - HumanoidRobot
   - myBuilding
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
$ mkdir ~/catkin_ws
$ cd ~/catkin_ws
$ git clone https://github.com/samchiRobot/UND_Robotics
```

#### Step 3 Compile the code
```sh
$ cd ~/catkin_ws/UND_Robotics/project1/build/
$ cmake ../
$ make
```

#### Step 4 Add the library path to the Gazebo plugin path  
```sh
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}: ~/catkin_ws/UND_Robotics/project1/build
```

#### Step 5 Run the Gazebo World file  
```sh
$ cd ~/catkin_ws/UND_Robotics/project1/build/
$ gazebo jin_world
```

### Output
Gazebo World should both launch as follow
![alt text](images/project1_output.png)
