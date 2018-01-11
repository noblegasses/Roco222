int signal = 3;// define pin 3 as a signal
int Duty_Cycle = 20000;// the total length of the servo's duty cycle 
int negative= 450; // value (in microseconds) of the pulse which correlates to the -90 position of the servo.
int zero = 1500;//value (in microseconds) of the pulse which correlates to the 0 position of the servo.
int positive = 2300;// value (in microseconds) of the pulse which correlates to the 90 position of the servo.
int pos= 0; // initializing the value which will tell the servo what position to go to 
int n=0;// initializing a counter
int HIGH_pin = 2;
int pot = 14;
void setup(){// setup code goes here
  pinMode (signal, OUTPUT);//configure pin 3 as an output
  pinMode (HIGH_pin, OUTPUT);//configure pin 2 as an output
  pinMode (pot, INPUT);//configure the pin with the potentiometer as an input
  digitalWrite (HIGH_pin, HIGH);// makes a pin high to use as a reference (it's always high )
 Serial.begin(9600);
}
void loop () {
  pos = analogRead(pot);// reads the value of the potentiometer
  pos = map (pos, 0,1023, negative,positive);// relates the negate and positive limits of sin to the negative and positive limits of the postion
  servo_move (pos);// a function to move the servo

  
}  
 
 
 void servo_move (int pos)
 {
   digitalWrite (signal, HIGH);// makes the pin high to start the pulse
  delayMicroseconds(pos);//waits for the length of the pulse which relates to a position
  digitalWrite (signal, LOW); // ends the pulse 
  delayMicroseconds (Duty_Cycle-pos);// waits for the remainder of the duty cycle
 }
