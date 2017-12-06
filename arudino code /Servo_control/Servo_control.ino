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
