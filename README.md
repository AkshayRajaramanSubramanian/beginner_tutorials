# beginner_tutorials
ENPM 808X tutorials for simple publisher/subscriber modules

## Installing the package
Run the following command line scripts from inside your catkin workspace to install the package

```sh
cd src
git clone https://github.com/AkshayRajaramanSubramanian/beginner_tutorials.git
cd ..
catkin_make
source devel/setup.bash
```

## Running the code
In one terminal tab, start roscore using the following command:
```sh
roscore
```
In a second terminal tab, run the listener node using the following command:
```sh
rosrun beginner_tutorials listener
```
In the third terminal tab, run the talker node using the following command:
```sh
rosrun beginner_tutorials talker
```

You should be able to see the data stream published by the talker node being subscribed and printed by the listener subscriber node.

## Assumptions
You should have the ros kinetic distribution installed on ubuntu to run this code. 
