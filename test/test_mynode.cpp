#include <gtest/gtest.h>
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/custom.h"

// Declare a test
TEST(ServiceTest, serviceNotAvailable) {
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<beginner_tutorials::custom>("/talker/change_string");
	bool exists(client.waitForExistence(ros::Duration(5)));
	EXPECT_TRUE(exists);
	beginner_tutorials::custom srv;
	std::string value = "Hello";
	srv.request.text = value;
	bool call = client.call(srv);
	ASSERT_TRUE(call);
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  	ros::init(argc, argv, "test_mynode");
  	testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
