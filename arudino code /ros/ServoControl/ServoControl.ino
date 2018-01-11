/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32.h>
sensor_msgs::JointState js;
std_msgs::Float32 pos_msgs;
ros::NodeHandle  nh;
int pos[4];
Servo baseservo1, baseservo2, elbow, wrist, hand;

ros::Publisher pub_js("js", &js);
std_msgs::Float32 debug;
void servo_cb( const std_msgs::JointStates& cmd_msg){
   js = cmd_msg;
   pub_js.publish(&js);
  pos[1] = cmd_msg.position[0];
  pos[2] = cmd_msg.position[1];
  pos[3] = cmd_msg.position[2];
  pos[4] = cmd_msg.position[3];
  baseservo1.write(pos[1]); //set servo angle, should be from 0-180
  baseservo2.write(pos[1]); //set servo angle, should be from 0-180
  elbow.write(pos[2]]); //set servo angle, should be from 0-180
  wrist.write(pos[3]); //set servo angle, should be from 0-180
  hand.write(pos[4]); //set servo angle, should be from 0-180


  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<sensor_msgs::JointState> sub("/joint_states", servo_cb);
//ros::Publisher pub_debugR("debugR", &pos_msgs);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
//nh.advertise(pub_debugR);
  nh.advertise(pub_js);
  
  baseservo1.attach(9); //attach it to pin 9
  baseservo2.attach(10);
  elbow.attach(11);
  wrist.attach(6);
  hand.attach(5);
}
void loop(){
  pos_msgs.data =pos[1];
  //pub_debugR.publish(&pos_msgs);
  pos_msgs.data= pos [2];
  //pub_debugR.publish(&pos_msgs);
  pos_msgs.data= pos[3];
  //pub_debugR.publish(&pos_msgs);
  pos_msgs.data= pos[4];

  nh.spinOnce();
  delay(1);
}
