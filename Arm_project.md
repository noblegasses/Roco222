#Arm Project#

URDF this was written for my partner's computer. As such, some of the code doesn't work off of it . There are 2 main parts to this  the visual, and the joints. the visual uses the STL's specified by the path and displays them in RViz. The joints are the important part of the URDF as they define the range of motion that the motors have so they can be modified with the joint state publisher/ 
```
<?xml version="1.0"?>
<robot name="robot-arm">
  <link name="base_link">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/base.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="1.57 0 0" xyz="0 0 0" />
    </visual>
  </link>

  <link name="arm_base">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/arm_base.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="1.57 0 0" xyz="-0.05 -0.045 -0.062" />
    </visual>
  </link>

  <joint name="base to armbase" type="revolute">
    <axis xyz="0 0 1" />
    <limit effort="1000" lower="-3.14"
		upper="3.14" velocity="0.5" />
    <parent link="base_link"/>
    <child link="arm_base"/>
    <origin xyz="0 0 0.057" />
  </joint>

  <link name="upper_arm">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/upper_arm.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="1.57 0 0" xyz="-0.005 0.001 0.021"/>
    </visual>
  </link>

  <joint name="armbase to upperarm" type="revolute">
    <axis xyz="0 1 0" />
    <limit effort="1000" lower="1.57"
		upper="-1.57" velocity="0.5" />
    <parent link="arm_base"/>
    <child link="upper_arm"/>
    <origin xyz="0 0 0.047" />
  </joint>

  <link name="lower_arm">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/lower_arm.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="1.57 0 0" xyz="-0.00495 0.002 -0.1375"/>
    </visual>
  </link>

  <joint name="upperarm to lowerarm" type="revolute">
    <axis xyz="0 1 0" />
    <limit effort="1000" lower="-1.57"
		upper="1.57" velocity="0.5" />
    <parent link="upper_arm"/>
    <child link="lower_arm"/>
    <origin xyz="-0.00005 0 0.1585" />
  </joint>

  <link name="Gripper_baseplate">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/Gripper_baseplate.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="0 -1.57 3.14" xyz="-0.005 -0.0189 0.0483"/>
    </visual>
  </link>

  <joint name="lowerarm to gripperbase" type="revolute">
    <axis xyz="0 1 0" />
    <limit effort="1000" lower="-0.7"
		upper="0.7" velocity="0.5" />
    <parent link="lower_arm"/>
    <child link="Gripper_baseplate"/>
    <origin xyz="-0.0004 0 0.1581" />
  </joint>

  <link name="Gripper_Gear_arm_1">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/Gripper_Gear_arm_1.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="0 -1.57 3.14" xyz="-0.0044 0 0.02"/>
    </visual>
  </link>

  <joint name="gripperbase to grippergear" type="revolute">
    <axis xyz="1 0 0" />
    <limit effort="1000" lower="-0.7"
		upper="0.7" velocity="0.5" />
    <parent link="Gripper_baseplate"/>
    <child link="Gripper_Gear_arm_1"/>
    <origin xyz="0 -0.0189 0.0283" />
  </joint>

  <link name="Gripper_Short_arm_1">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/Gripper_Short_arm_1.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="3.14 1.57 0" xyz="0.0176 -0.0016 0.002"/>
    </visual>
  </link>

  <joint name="gripperbase to grippershortarm" type="revolute">
    <axis xyz="1 0 0" />
    <limit effort="1000" lower="-0.7"
		upper="0.7" velocity="0.5" />
    <mimic joint="gripperbase to grippergear" multiplier="1" offset="0"/>
    <parent link="Gripper_baseplate"/>
    <child link="Gripper_Short_arm_1"/>
    <origin xyz="0 -0.0173 0.0503" />
  </joint>

  <link name="gripper1">
    <visual>
      <geometry>
	<mesh filename="file:///home/csaba/Documents/roco222/robot-project/robot-arm/gripper1.stl" scale="0.001 0.001 0.001" />
      </geometry>
	<origin rpy="0 -1.57 3.14" xyz="-0.0043 0.0257 0.0053"/>
    </visual>
  </link>

  <joint name="grippergear to gripper1" type="revolute">
    <axis xyz="1 0 0" />
    <limit effort="1000" lower="-0.7"
		upper="0.7" velocity="0.5" />
    <mimic joint="gripperbase to grippergear" multiplier="-1" offset="0"/>
    <parent link="Gripper_Gear_arm_1"/>
    <child link="gripper1"/>
    <origin xyz="0 -0.0276 0.0007" />
  </joint>
```
the next is an arduino code I was writing to control the servos of the arm. It takes the values from the Joint state publisher and writes them to the servos.
```arduino
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <sensor_msgs/JointState.h
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
```

##Photos:
![Built arm](https://github.com/noblegasses/Roco222/blob/master/Journal_Photos/real_arm.jpg)
![rviz model](https://github.com/noblegasses/Roco222/blob/master/Journal_Photos/ROS_arm.png)
