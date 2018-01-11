int signal = 3;// define pin 3 as a signal
int Duty_Cycle = 20000;// the total length of the servo's duty cycle 
int negative= 450; // value (in microseconds) of the pulse which correlates to the -90 position of the servo.
int zero = 1500;//value (in microseconds) of the pulse which correlates to the 0 position of the servo.
int positive = 2300;// value (in microseconds) of the pulse which correlates to the 90 position of the servo.
float pos= 0; // initializing the value which will tell the servo what position to go to 
int angle=0;// the angle (in degrees) that will corelate to the sine position, it increases by 1 each cycle
int n=0;// initializing a counter
float rad = 0;// the angle in radians that will be used in the sine function
void setup(){// setup code goes here
  pinMode (signal, OUTPUT);//configure pin 3 as an output
 Serial.begin(9600);
}
void loop () {
  rad = angle*3.1415/180;// converting the angle in radians
  pos = sin(rad);// assigns the angle to a position
  pos = pos * 100; // stops pos from being a decimal
  Serial.print ("A: "); 
  Serial.print (pos); 
  pos = map (pos, -100,100, negative,positive);// relates the negate and positive limits of sin to the negative and positive limits of the postion
  Serial.print (" B: "); 
  Serial.println (pos);  
  while(n <10)// send the position to the servo 10 times
  {
  servo_move (pos);// a function to move the servo
  n++;
  }
  n=0;// resets the counter
  angle++;// increases the angle
  
 }  
 
 
 void servo_move (int pos)
 {
   digitalWrite (signal, HIGH);// makes the pin high to start the pulse
  delayMicroseconds(pos);//waits for the length of the pulse which relates to a position
  digitalWrite (signal, LOW); // ends the pulse 
  delayMicroseconds (Duty_Cycle-pos);// waits for the remainder of the duty cycle
 }
