## Stepper motor
*Note 1*: the example code, seen on the lecture notes, as seen here :, loops the stepping of the motor one step. By changing the duration of the delay the speed can be increased or decreased. by reversing the order of the channels the direction of the stepper can be reversed.

*Note 2*: After reviewing the lab notes and the example code I have figured out what is what based off of the logic tables seen here: The digital channels control the A or not A and B and not B parts of the table respectivley. If A is High then you have selected A if it is low then you have selected not A. The analogue channels put a one or zero in the selected channel.

## Full Step Mode

```arduino
#define DIR_A 12
#define PWM_A 3
#define DIR_B 13
#define PWM_B 11
const int delayMs= 100;
int A_value =  255;
int B_value = 0;
void setup() {
pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(9, OUTPUT); 
digitalWrite(8, LOW);//No braking ch. A
pinMode(8, OUTPUT); 
digitalWrite(8, LOW);//No braking ch. B
}

void loop(){
for (int n=0;n<=200; n++){
  full_step();
}
while(1){}
}

void full_step(){

digitalWrite(DIR_A, HIGH);// Ch. A forward
digitalWrite(DIR_B, HIGH);// Ch. B forward
analogWrite(PWM_A,A_value);// Ch. A on
analogWrite(PWM_B,B_value);// Ch. B off
delay(delayMs);
analogWrite(PWM_A,B_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs);
digitalWrite(DIR_A, LOW);// Ch. A backwards
digitalWrite(DIR_B, LOW);// Ch. B backwards
analogWrite(PWM_A,A_value);// Ch. A on
analogWrite(PWM_B,B_value);// Ch. B off
delay(delayMs);
analogWrite(PWM_A,B_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs); 
}
```
## Half Step Mode

```arduino
#define DIR_A 12
#define PWM_A 3
#define DIR_B 13
#define PWM_B 11
const int delayMs= 10;
int A_value =  255;
int B_value = 0;
void setup() {
pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(9, OUTPUT); 
digitalWrite(8, LOW);//No braking ch. A
pinMode(8, OUTPUT); 
digitalWrite(8, LOW);//No braking ch. B
}

void loop(){
for (int n=0;n<=100; n++){
  half_step();
}
while(1){}
}

void half_step(){

digitalWrite(DIR_A, HIGH);// Ch. A forward
digitalWrite(DIR_B, HIGH);// Ch. B forward
analogWrite(PWM_A,A_value);// Ch. A on
analogWrite(PWM_B,B_value);// Ch. B off
delay(delayMs);
analogWrite(PWM_A,A_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs);
analogWrite(PWM_A,B_value);// Ch. A on
analogWrite(PWM_B,A_value);// Ch. B off
delay(delayMs);
digitalWrite(DIR_A, LOW);// Ch. A forward
analogWrite(PWM_A,A_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs);
digitalWrite(DIR_B, LOW);// Ch. B forward
analogWrite(PWM_A,A_value);// Ch. A on
analogWrite(PWM_B,B_value);// Ch. B off
delay(delayMs);
analogWrite(PWM_A,A_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs);
analogWrite(PWM_A,B_value);// Ch. A on
analogWrite(PWM_B,A_value);// Ch. B off
delay(delayMs);
digitalWrite(DIR_A, HIGH);// Ch. A forward
analogWrite(PWM_A,A_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs); 
}
```
## Double Step Mode

```arduino
#define DIR_A 12
#define PWM_A 3
#define DIR_B 13
#define PWM_B 11
const int delayMs= 10;
int A_value =  255;
int B_value = 0;
void setup() {
pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(9, OUTPUT); 
digitalWrite(8, LOW);//No braking ch. A
pinMode(8, OUTPUT); 
digitalWrite(8, LOW);//No braking ch. B
}

void loop(){
for (int n=0;n<=200; n++){
  Double_step();
}
while(1){}
}

void Double_step(){

digitalWrite(DIR_A, HIGH);// Ch. A forward
digitalWrite(DIR_B, HIGH);// Ch. B forward
analogWrite(PWM_A,A_value);// Ch. A on
analogWrite(PWM_B,A_value);// Ch. B off
delay(delayMs);
digitalWrite(DIR_A, LOW);// Ch. A forward
analogWrite(PWM_A,A_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs);
digitalWrite(DIR_B, LOW);// Ch. B backwards
analogWrite(PWM_A,A_value);// Ch. A on
analogWrite(PWM_B,A_value);// Ch. B off
delay(delayMs);
digitalWrite(DIR_A, HIGH);// Ch. A forward
analogWrite(PWM_A,A_value);// Ch. A off
analogWrite(PWM_B,A_value);// Ch. B on
delay(delayMs); 
}
```

