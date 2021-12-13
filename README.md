# ACME Inspection Robot
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://app.travis-ci.com/dngo13/enpm808x_inspection_robot.svg?branch=Phase1_Setup)](https://app.travis-ci.com/dngo13/enpm808x_inspection_robot)
[![Coverage Status](https://coveralls.io/repos/github/dngo13/enpm808x_inspection_robot/badge.svg?branch=master)](https://coveralls.io/github/dngo13/enpm808x_inspection_robot?branch=master)
## Authors
- Diane Ngo (dngo13)
- Charu Sharma

## Information
The goal of this project is to simulate a facility room with a boiler, chiller, and air handler. This system provides heating, ventilation, and air conditioning to a building and a robot needs to inspect the pressure readings for all the units and detect if there are any anomalies.

## Required Software/Dependencies
- C++11
- Ubuntu 18.04
- ROS Melodic
- Gazebo, RVIZ
- Turtlebot 3 Burger
- Turtlebot 3 Dependencies (move_base, amcl, navigation, gazebo)
Install turtlebot 3 from this link: https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/

## Agile Iterative Process
We have been following the agile methodology in this project to track all the tasks involved. We have been utilizing the notion platform to achieve this which can be seen in the link below:

# Phase 1 and 2 Deliverables
- UMLs are in UML/initial/ directory
- [AIP Document](https://docs.google.com/spreadsheets/d/1DOCv0d4YN2u2S71dpkWC5jOVsrEH4w9d/edit?usp=sharing&ouid=113553065067285094891&rtpof=true&sd=true)
- [Sprint Planing Notes](https://docs.google.com/document/d/1maDs29Tq0LcT0_IH3nwbV9nM2bu69N_wtKcM96Btzhw/edit?usp=sharing)
- []

# Cloning the repository
In terminal 
```bash
cd ~/catkin_ws/src/
git clone git@github.com:dngo13/enpm808x_inspection_robot.git
cd ../..
catkin_make
source devel/setup.bash
```

# Updating bashrc 
Please run this command on terminal to make sure bashrc is updated with the gazebo model locations.
```bash
echo "export GAZEBO_MODEL_PATH=$HOME/catkin_ws/src/enpm808x_inspection_robot/worlds" >> ~./bashrc
```

# Running Gazebo/RVIZ
After cloning the directory, ensure you are in Phase2 branch
```bash
git checkout Phase2
```
Then make sure you are in the catkin workspace directory.
```ash
roslaunch enpm808x_inspection_robot explore.launch
```

# Resources
Below are links to the free 3D Models we used for our Gazebo Simulation. Gazebo can read Collada mesh files.
Models are from the free website https://3dwarehouse.sketchup.com/ 
- [Steam Boiler](https://3dwarehouse.sketchup.com/model/3dd98b18-6e63-46db-b74f-18b04cf2b7b9/STEAM-BOILER)
- [Chiller](https://3dwarehouse.sketchup.com/model/e43f320c5caa18b8cb2bf6e8b9d93fb0/CHILLER)
- [Air Handler Unit](https://3dwarehouse.sketchup.com/model/4bcb7bc201809bb610d42f17c59729bc/Air-Handler-with-Hot-Water-Coil)

