# ENPM 808X PROGRAMMING ASSIGNMENT
## Description

This package contains simple publisher and subscriber nodes, that allow the user to change parameters such as the frequency of publishing and the text being published

## License

This project is licensed under the MIT License - see the [LICENSE](https://raw.githubusercontent.com/AkshayRajaramanSubramanian/beginner_tutorials/Week10_HW/LICENSE.md) file for details

## Dependencies
* ROS Kinetic
* Ubuntu 16.04
* catkin

## package dependencies

cpp_common
rostime
roscpp_traits
roscpp_serialization
catkin
genmsg
genpy
message_runtime
gencpp
geneus
gennodej
genlisp
message_generation
rosbuild
rosconsole
std_msgs
rosgraph_msgs
xmlrpcpp
roscpp
rosgraph
ros_environment 
rospack 
roslib 
rospy 

## Using this package
Clone beginner_tutorials repository
```
cd path_to_catkin_workspace/src
git clone -b Week10_HW --recursive https://github.com/AkshayRajaramanSubramanian/beginner_tutorials.git 
```
Build package and install using catkin
```
cd path_to_catkin_workspace
catkin_make install
source ./devel/setup.bash
```

Running the launch file
```
roslaunch beginner_tutorials beginner_tutorial.launch frequency:=1 // Run each command in a seperate terminal
``` 
This will run the talker and listener node with a publishing rate of 1 per second.
The default published string is "Publishing this String"
Calling the ros service
```
rosservice call /talker1/talker/change_string 'New string being published'
```
This should change the published string to "New string being published"

## RQT Graph

<p align="center">
<img src="/images/rqt_graph.png">
</p>

## Setting logger levels

Start the nodes as mentioned above
Open rqt_logger_level
```
rosrun rqt_logger_level rqt_logger_level
```
Select the  node and select logger level as needed form the GUI

## Viewing logger messages

Start the nodes as mentioned above
Set rqt_logger_level
Run rqt_console
```
rosrun rqt_console rqt_console
```
<p align="center">
<img src="/images/rqt_console_info.png">
</p>
<p align="center">
<img src="/images/rqt_console_error.png">
</p>






