## Project 5. Home Service Robot

### Prerequisites
- ROS : Kinetic (turtlebot, kobuki not support melodic)
- Ubuntu : 16.04 (for ROS Kinetic)

```
sudo apt install xterm
sudo apt isntall ros-kinetic-turtlebot-*
sudo apt install ros-kinetic-openslam-gmapping
sudo apt install ros-kinetic-teleop-*
sudo apt install ros-kinetic-amcl
sudo apt install ros-kinetic-move-base
sudo apt install ros-kinetic-map-server
```

### Project Aspect
- `add_markers`
   - Add a marker assumed to be an object
      - Phase 1. Create Marker at Destination 1
      - Phase 2. Delete Objects
      - Phase 3. Create Marker at Destination 2
- `pick_objects`
   - Robot Teleoperation algorithm for Two Destinations
- `scripts`
   - To launch multiple roslaunch command and set the params
      - `add_marker.sh` : marker test program (If you want to test this shell script, you need to modify add_markers copy.cpp in add_marker package to add_markers.cpp)
      - `home_service.sh` : main program
      - `launch.sh` : shell script test program
      - `test_navigation.sh` : amcl test program
      - `test_slam.sh` : gmapping test program
   
### Directory Structure
```
    .Project5                                 # Home Service Robot Project
    ├── add_markers                              # my_robot package                   
    │   ├── launch                            # launch folder for launch files   
    │   │   ├── home_robot.rviz                # RTAB-Map launch file
    │   │   ├── set_goal.launch
    │   ├── src                            # meshes folder for sensors
    │   │   ├── add_markers copy.cpp
    │   │   ├── add_markers.cpp
    │   ├── CMakeLists.txt                    # compiler instructions
    │   ├── package.xml                       # package info
    ├── map                 # teleop_twist_keyboard package                   
    ├── pick_objects                 # teleop_twist_keyboard package                   
    ├── scripts                 # teleop_twist_keyboard package                   
    ├── slam_gmapping                 # teleop_twist_keyboard package                   
    ├── turtlebot                 # teleop_twist_keyboard package                   
    ├── turtlebot_apps                 # teleop_twist_keyboard package                   
    ├── turtlebot_interactions                 # teleop_twist_keyboard package                   
    ├── turtlebot_msgs                 # teleop_twist_keyboard package                   
    └── turtlebot_simulator                             # rviz presets      
```

### Steps to launch the simulation
#### Step 1 Update and upgrade the Workspace image
```sh
$ sudo apt-get update
$ sudo apt-get upgrade -y
```

#### Step 2 Clone the lab folder in ~/workspace/
```sh
$ mkdir ~/workspace
$ cd ~/workspace
$ git clone https://github.com/samchiRobot/UND_Robo/
```

#### Step 3 Compile the code by catkin
```sh
$ cd /home/workspace/project5/
$ catkin_make
```

#### Step 4 Launch the robot inside my world
```sh
$ cd /home/workspace/project5/
$ source devel/setup.bash
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


