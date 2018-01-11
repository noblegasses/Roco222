#include <Servo.h>
Servo myservo;
int pos = 0;
void setup () {
myservo.attach(9);
// attaches the servo on pin 9 to the servo object
}
void loop() {
for(pos= 0; pos <= 180; pos += 1) {
// in steps of 1 degree
myservo.write(pos); 
delay(15);
}
for(pos = 180; pos >= 0; pos -= 1) {
myservo.write(pos);
delay(15);
}
}
