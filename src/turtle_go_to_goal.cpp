#include "ros/ros.h"
#include<math.h>
#include "turtlesim/Pose.h"

using namespace std;

float x_real = 0;
float y_real = 0;

float EuclidianDistance(float x_g, float y_g, float x_r, float y_r)
{
  return sqrt(pow((x_g - x_r),2) + pow((x_g - x_r),2));
}

// Manage here the callback
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", to_string(msg->x));
}
//



int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_go_to_goal");
  ros::NodeHandle n;
  float x_goal = 0;
  float y_goal = 0;

  cout << "Insert X and Y coordinates that the robot should reach" <<endl;
  cin >> x_goal >> y_goal;

  ros::Rate loop_rate(30);
  int counter = 0;

  // Manage here the publisher and the subscriber
  // Subscribe to Pose of turtlesim
  ros::Subscriber sub_pose = n.subscribe("turtle1/pose", 60, poseCallback);
  //

  while (ros::ok())
  {
    // Send here the velocity command to the robot


    //

    // Exit conditions
    counter++;
    if(counter>=900)
    {
      break;
    }
    if(EuclidianDistance(x_goal,y_goal,x_real,y_real)<0.5)
    {
      break;
    }
  }
  cout << "The process has finished in " << counter << " iterations"<<endl;
  cout << "The position error is " << EuclidianDistance(x_goal,y_goal,x_real,y_real) <<endl;
}
