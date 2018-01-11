# Servo control

**Arduino Control**

code 1:

```arduino

int signal = 3;// define pin 3 as a signal
	pinMode (signal, OUTPUT);//configure pin 3 as an output
}

void loop() {
  int n = 0;//start with a PWM (or position) of zero
  while (n<=255)// the maimum value of PWM in the arduino language
    { 
      analogWrite (signal,n);// change the position of the servo  to the pwm value of n
      n= n+1 ;// add 1 to the position 
      delay (100); // wait 100 ms
    }
}
```

*Notes:* this works ok, but not perfectly. according to the servo datasheet, there are 3 extremes, -90, 0, and 90. the pulse width required for the 0 position is 1.5 ms, -90 is 1ms and 90 is 2ms. 2ms for pwm is 255 or 100% duty cycle. 1.5ms is 75% of the duty cycle or 191 pwm. Finally, 1 ms is 50% duty cyle or 127.

code 2:

Taking into consideration the notes from the previous code I will try to improve the servo.

```arduino

int signal = 3;// define pin 3 as a signal
int negative = 50;// min value that can be registered
int zero = 191;// mid value
int positive= 254; // min value that can be registered
void setup(){// setup code goes here
	pinMode (signal, OUTPUT);//configure pin 3 as an output
}

void loop() {
  analogWrite (signal,negative);
  delay (1000);
  analogWrite (signal, zero);
  delay (1000);
  analogWrite (signal, positive);
  delay (1000);
}

```

*Notes:* 255 does not work for pwm as it is just a high signal. Although 127 should be the minimum value, trial and error shows 50 is the lowest signal that can be registered. As the pwm signal is expected to be 20 ms by the motor it might be worth it to try to making my own form of pwm with the digtial signals and delays.

code 3:

```arduino

int signal = 3;// define pin 3 as a signal
int Duty_Cycle = 20000;// the total length of the servo's duty cycle 
int negative= 450; 
int zero = 1500;
int positive = 2550;
int n;
void setup(){// setup code goes here
  pinMode (signal, OUTPUT);//configure pin 3 as an output
}
void loop () {
  for(n=0;n<240;n++)
  {
  digitalWrite (signal, HIGH);
  delayMicroseconds(negative);
  digitalWrite (signal, LOW);
  delayMicroseconds (Duty_Cycle-negative);
  }
  for(n=0;n<240;n++)
  {
  digitalWrite (signal, HIGH);
  delayMicroseconds(zero);
  digitalWrite (signal, LOW);
  delayMicroseconds (Duty_Cycle-zero);
  }
  
  for(n=0;n<240;n++)
  {
  digitalWrite (signal, HIGH);
  delayMicroseconds(positive);
  digitalWrite (signal, LOW);
  delayMicroseconds (Duty_Cycle-positive);
  }
 }  

```

*Notes:* the scaled duty cycles  work far better than the datasheet. I can actually get the servo to the extremities. Now to figure out how to implement a sine wave and a potentiometer.

code 4:

```arduino

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
```
*Notes:* After far to much tinkering around I found that there is a map function in arduino which can associate a 2 ranges of numbers and scale them appropriately.The sine wave itself was fairly easy to generate, I did just have to know that arduino displays them in radians. The map function will make the potentiometer control pretty straightforward too.

Code 5:

```arduino

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

```
*Notes:* as previously stated, maping the servo to the potentiometer was pretty straight forward. Using the map function I associated the limits of the potentiometer with the limits of the servo.
