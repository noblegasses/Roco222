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
