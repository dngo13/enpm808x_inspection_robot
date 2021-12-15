# ACME Inspection Robot
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://app.travis-ci.com/dngo13/enpm808x_inspection_robot.svg?branch=Phase1_Setup)](https://app.travis-ci.com/dngo13/enpm808x_inspection_robot)
[![Coverage Status](https://coveralls.io/repos/github/dngo13/enpm808x_inspection_robot/badge.svg?branch=master)](https://coveralls.io/github/dngo13/enpm808x_inspection_robot?branch=master)
## Authors
- [Diane Ngo](<https://github.com/dngo13>) (dngo13)
- [Charu Sharma](<https://github.com/Sharma117555448>) (charu107)

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

# Deliverables
- UMLs are in UML/revised/ directory
- [AIP Document](https://docs.google.com/spreadsheets/d/1DOCv0d4YN2u2S71dpkWC5jOVsrEH4w9d/edit?usp=sharing&ouid=113553065067285094891&rtpof=true&sd=true)
- [Sprint Planing Notes](https://docs.google.com/document/d/1maDs29Tq0LcT0_IH3nwbV9nM2bu69N_wtKcM96Btzhw/edit?usp=sharing)
- [Video Presentation](https://drive.google.com/file/d/1GjrxeQDlWDVaCegv0pGn1_PuIU4vnw1r/view?usp=sharing)
- [Presentation Slides version](https://docs.google.com/presentation/d/1gdA-Wg3iN3sOJKsh5t0hrpo7kxvjluG39DgWep8n9k8/edit?usp=sharing)

## Standard install via command-line
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
echo "export GAZEBO_MODEL_PATH=$HOME/catkin_ws/src/enpm808x_inspection_robot/worlds" >> ~/.bashrc
```

# Running Gazebo/RVIZ
After cloning the directory, ensure you are in the master branch
```bash
git checkout master
```
Then make sure you are in the catkin workspace directory.
```bash
roslaunch enpm808x_inspection_robot mechanical_inspection_world.launch
```

# Running the Unit Tests
Inside catkin_ws you can run
```
catkin_make run_tests
```
or
```roscore``` in one terminal
```
roslaunch enpm808x_inspection_robot InspectionRobotTest.Launch
```
In a new terminal. 

# Running the Inspection Bot
Open two tabs and in each paste the following
```
roslaunch enpm808x_inspection_robot mechanical_inspection_world.launch
```
```
rosrun enpm808x_inspection_robot explore.py
```
# Running the Pressure Detection 
```
rosrun enpm808x_inspection_robot pressure_detector
```
# Checking the accuracy of the bot navigation
Open two tabs and in each paste the following
```
roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch 
```
```
rosrun enpm808x_inspection_robot explore.py
```

# Resources
Below are links to the free 3D Models we used for our Gazebo Simulation. Gazebo can read Collada mesh files.
Models are from the free website https://3dwarehouse.sketchup.com/ 
- [Steam Boiler](https://3dwarehouse.sketchup.com/model/3dd98b18-6e63-46db-b74f-18b04cf2b7b9/STEAM-BOILER)
- [Chiller](https://3dwarehouse.sketchup.com/model/e43f320c5caa18b8cb2bf6e8b9d93fb0/CHILLER)
- [Air Handler Unit](https://3dwarehouse.sketchup.com/model/4bcb7bc201809bb610d42f17c59729bc/Air-Handler-with-Hot-Water-Coil)

## Run cppcheck and cpplint
Run cppcheck: Results are stored in `./results/cppcheck.txt` 
```
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./lib") > results/cppcheck.txt 2>&1
```

Run cpplint: Results are stored in `./results/cpplint.txt`
```
cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" -e "^./lib/") > results/cpplint.txt 2>&1
```

## Demo
Run the program. The robot moves to the designated machinaries and as soon as it reaches the target location, we can read the pressures of each equipment. Depending on the readings, the bot responds in diffrerent manner.

Layout and working of the project with initiation of pressure detection

[Demo 1](<https://drive.google.com/drive/folders/1cZ3f1o89RABsgHytveCopZlESMJnTYB6>)

Accurate working of robot navigation

[Demo 2](<https://drive.google.com/drive/folders/1cZ3f1o89RABsgHytveCopZlESMJnTYB6>)

