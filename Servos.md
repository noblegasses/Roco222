#Servo control

**Arduino Control**
code 1:

```arduino
int signal = 3;// define pin 3 as a signal

void setup(){// setup code goes here

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

*Notes* this works ok, but not perfectly. according to the servo datasheet, there are 3 extremes, -90, 0, and 90. the pulse width required for the 0 position is 1.5 ms, -90 is 1ms and 90 is 2ms. 2ms for pwm is 255 or 100% duty cycle. 1.5ms is 75% of the duty cycle or 191 pwm. Finally, 1 ms is 50% duty cyle or 127.

code 2:
Taking into consideration the notes from the previous code I will try to improve the servo.

*Notes* 255 does not work for pwm as it is just a high signal. Although 127 should be the minimum value, trial and error shows 50 is the lowest signal that can be registered. As the pwm signal is expected to be 20 ms by the motor it might be worth it to try to making my own form of pwm with the digtial signals and delays.

code 3:


