/*
 * @file talker.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Akshay Rajaraman
 * @author Akshay Rajaraman
 * @brief Node that publishes a simple text which can be changed by calling the /talker1/talker/change_string service 
 *
 */

/*
 * MIT License
 *
 * Copyright (c) 2018 Akshay Rajaraman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <sstream>
#include <string>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/custom.h"

/*
 * initializing global variables
*/
int frequencyVal;
std::string displayString = "Publisher String";

/**
 * @brief function that runs on service call to change published text
 * @param req request object from service
 * @param resp response object to service
 * @return boolean success true or false
 */
bool changeString(beginner_tutorials::custom::Request &req, beginner_tutorials::custom::Response &res) {
	if(req.text.empty()) {
		ROS_ERROR("Empty message received, closing node");
		res.success = false;
	} else {
		ROS_INFO("Received request");
		displayString = req.text;
		ROS_DEBUG("String received is: %s",displayString.c_str());
		res.success=true;
	}
	return true;
}

/**
 * @brief main function of talker node
 * @return run status
 */
int main(int argc, char **argv) {
	// initializing node
  ros::init(argc, argv, "talker");
	//creating node handle
  ros::NodeHandle n("~");
	// advertising service
  ros::ServiceServer service = n.advertiseService("change_string",changeString);
	// getting parameter from launch file  
  n.getParam("frequencyVal",frequencyVal);
  if (frequencyVal == 0) {
		ROS_FATAL("frequency cannot be zero");
	} else if (frequencyVal > 10000) {
		ROS_WARN("Very high frequency entered, resetting frequency to 10");
		frequencyVal = 10;
	}
	// creating publisher
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	// setting publisher frequency
  ros::Rate loop_rate(frequencyVal);
  while (ros::ok()) {
		ROS_INFO("In ROS talker node");
		std::stringstream f;
  	std::string fstring;
  	f<<frequencyVal;
  	fstring=f.str();
  	ROS_INFO(fstring.c_str());
    std_msgs::String msg;
    std::stringstream ss;
		ROS_INFO("obtained: %s\n",displayString.c_str());
    ss << displayString.c_str();
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

