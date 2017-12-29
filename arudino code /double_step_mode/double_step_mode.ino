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
