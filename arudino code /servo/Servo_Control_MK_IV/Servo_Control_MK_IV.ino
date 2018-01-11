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
