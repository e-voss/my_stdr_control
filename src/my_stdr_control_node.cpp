#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

#include <math.h>


//node to send Twist commands to the Simple 2-Dimensional Robot Simulator via cmd_vel
int main(int argc, char **argv) {
      ros::init(argc, argv, "stdr_commander"); 
      ros::NodeHandle n; // two lines to create a publisher object that can talk to ROS
      ros::Publisher twist_commander = n.advertise<geometry_msgs::Twist>("/robot0/cmd_vel", 1);
      //some "magic numbers"
      double sample_dt = 0.1; //specify a sample period of 100ms  
      double speed = 1.0; // 1m/s speed command
      double yaw_rate = M_PI/2.0/3; // 90 degrees per 3 seconds
      double time_3_sec = 3.05; // should move 3 meters or 1.5 rad in 3 seconds
    
      
      geometry_msgs::Twist twist_cmd_zero; //this is the message type required to send twist commands to STDR 
      // start with all zeros in the command message; should be the case by default, but just to be safe..
      twist_cmd_zero.linear.x=0.0;
      twist_cmd_zero.linear.y=0.0;    
      twist_cmd_zero.linear.z=0.0;
      twist_cmd_zero.angular.x=0.0;
      twist_cmd_zero.angular.y=0.0;
      twist_cmd_zero.angular.z=0.0;

      //Another message that's a left turn
      geometry_msgs::Twist twist_cmd_left; //this is the message type required to send twist commands to STDR 
      // start with all zeros in the command message; should be the case by default, but just to be safe..
      twist_cmd_left.linear.x=0.0;
      twist_cmd_left.linear.y=0.0;
      twist_cmd_left.linear.z=0.0;
      twist_cmd_left.angular.x=0.0;
      twist_cmd_left.angular.y=0.0;
      twist_cmd_left.angular.z=yaw_rate;

      //Another message that's going forward
      geometry_msgs::Twist twist_cmd_for; //this is the message type required to send twist commands to STDR 
      // start with all zeros in the command message; should be the case by default, but just to be safe..
      twist_cmd_for.linear.x=1.0;
      twist_cmd_for.linear.y=0.0;
      twist_cmd_for.linear.z=0.0;
      twist_cmd_for.angular.x=0.0;
      twist_cmd_for.angular.y=0.0;
      twist_cmd_for.angular.z=0.0;

      //Another message that's a right turn
      geometry_msgs::Twist twist_cmd_right; //this is the message type required to send twist commands to STDR 
      // start with all zeros in the command message; should be the case by default, but just to be safe..
      twist_cmd_right.linear.x=0.0;
      twist_cmd_right.linear.y=0.0;    
      twist_cmd_right.linear.z=0.0;
      twist_cmd_right.angular.x=0.0;
      twist_cmd_right.angular.y=0.0;
      twist_cmd_right.angular.z=-yaw_rate;


      ros::Rate loop_timer(1/sample_dt); //create a ros object from the ros “Rate” class; set 100Hz rate     
      double timer=0.0;
      //start sending some zero-velocity commands, just to warm up communications with STDR
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      while(timer<time_3_sec) {
            twist_commander.publish(twist_cmd_left);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      } 

      timer=0.0; //reset the timer
      //command to move forward
      while(timer<time_3_sec) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      } 


      timer=0.0; //reset the timer
      while(timer<time_3_sec) {
            twist_commander.publish(twist_cmd_right);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      } 

      timer=0.0; //reset the timer
      while(timer<time_3_sec*2.25) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }
      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec) {
            twist_commander.publish(twist_cmd_left);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*.7) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*.96) {
            twist_commander.publish(twist_cmd_left);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*1.3) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec) {
            twist_commander.publish(twist_cmd_right);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*1.6) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*.96) {
            twist_commander.publish(twist_cmd_left);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*.8) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec) {
            twist_commander.publish(twist_cmd_right);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      timer=0.0; //reset the timer
      while(timer<time_3_sec*.55) {
            twist_commander.publish(twist_cmd_for);
            timer+=sample_dt;
            loop_timer.sleep();
      }

      //halt the motion
      for (int i=0;i<10;i++) {
            twist_commander.publish(twist_cmd_zero);
            loop_timer.sleep();
      }

      //done commanding the robot; node runs to completion
}