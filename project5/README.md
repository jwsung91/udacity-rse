## Project 4. Map My World

### Project Aspect
- `my_robot`
   - Create a `my_robot` ROS package
   - Design a differential drive robot with the Unified Robot Description Format
   - Add two sensors to my robot : `RGBD Camera`, `LIDAR`
- `world`
   - Which is created in `project 1` and `project 2`
- `mapping`
   - Create a 2D occupancy grid and 3D octomap from a simulated environment(`world`) using `my_robot` and `RTAB-Map` package
   
### Directory Structure
```
    .Project4                                 # Map My World Project
    ├── my_robot                              # my_robot package                   
    │   ├── launch                            # launch folder for launch files   
    │   │   ├── mapping.launch                # RTAB-Map launch file
    │   │   ├── robot_description.launch
    │   │   ├── world.launch
    │   ├── meshes                            # meshes folder for sensors
    │   │   ├── hokuyo.dae
    │   ├── urdf                              # urdf folder for xarco files
    │   │   ├── my_robot.gazebo               # my robot model
    │   │   ├── my_robot.xacro                # my robot model
    │   ├── worlds                            # world folder for world file
    │   │   ├── jin.world
    │   ├── CMakeLists.txt                    # compiler instructions
    │   ├── package.xml                       # package info
    ├── teleop_twist_keyboard                 # teleop_twist_keyboard package                   
    └── SLAM.rviz                             # rviz presets      
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
$ git clone https://github.com/samchiRobot/UND_Robo/
```

#### Step 3 Compile the code by catkin
```sh
$ cd /home/workspace/project4/
$ catkin_make
```

#### Step 4 Launch the robot inside my world
```sh
$ cd /home/workspace/project4/
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

#### Step 5 Run the `mapping` node

Open new terminal

```sh
$ cd /home/workspace/project4/
$ source devel/setup.bash
$ roslaunch my_robot mapping.launch
```
#### Step 6 Run teleop_twist_keyboard

Open new terminal

```sh
$ cd /home/workspace/project4/
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

#### Step 7 Database Analysis 

When mapping is set, terminal the node and you could find your map db file in the place. 

```sh
$ rtabmap-databaseViewer ~/.ros/rtabmap.db
```

#### (Optional) my DB link (for reference)

https://drive.google.com/open?id=1lJZRVs_ovUhlSxjhALg9QfMWZRiTvgbT


### Output

Simulated environment (as input)
#### Gazebo

![gazebo image](images/project4_world.png)


My program should both launch as follow

#### RTAB

![RTAB image](images/project4_RTAB.png)

#### RTAB_DB_viewer

![RTAB DB_image](images/project4_RTAB_DB_viewer.png)































## prereq.

sudo apt install xterm

sudo apt isntall ros-kinetic-turtlebot-*

sudo apt install ros-kinetic-openslam-gmapping

sudo apt install ros-kinetic-teleop-*

sudo apt install ros-kinetic-amcl

sudo apt install ros-kinetic-move-base

sudo apt install ros-kinetic-map-server

turtlebot_navigation, turtlebot_msgs (added)

## if issue

1. kobuki_description issue

sudo apt-get remove turtlebot-*

sudo apt-get remove kobuki-*

sudo apt-get install ros-kinetic-turtlebot


