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


### Output

Simulated environment (as input)
#### Gazebo

![gazebo image](images/project4_gazebo_world.png)


My program should both launch as follow

#### Rviz

![rviz image](images/project4_output_rviz.png)

#### RTAB

![RTAB image](images/project4_output_RTAB.png)
