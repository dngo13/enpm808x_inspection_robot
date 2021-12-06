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
- Turtlebot 3 Waffle Pi
- Turtlebot 3 Dependencies (move_base, amcl, navigation, gazebo)
Install turtlebot 3 from this link: https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/

# Phase 1 and 2 Deliverables
- UMLs are in UML/initial/ directory
- [AIP Document](https://docs.google.com/spreadsheets/d/1DOCv0d4YN2u2S71dpkWC5jOVsrEH4w9d/edit?usp=sharing&ouid=113553065067285094891&rtpof=true&sd=true)
- [Sprint Planing Notes](https://docs.google.com/document/d/1maDs29Tq0LcT0_IH3nwbV9nM2bu69N_wtKcM96Btzhw/edit?usp=sharing)

# Cloning the repository
In terminal 
```bash
cd ~/catkin_ws/src/
git clone git@github.com:dngo13/enpm808x_inspection_robot.git
cd ../..
catkin_make
source devel/setup.bash
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
