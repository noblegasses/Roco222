### Servo control

**Arduino Control**
code 1:

*Notes* this works ok, but not perfectly. according to the servo datasheet, there are 3 extremes, -90, 0, and 90. the pulse width required for the 0 position is 1.5 ms, -90 is 1ms and 90 is 2ms. 2ms for pwm is 255 or 100% duty cycle. 1.5ms is 75% of the duty cycle or 191 pwm. Finally, 1 ms is 50% duty cyle or 127.

code 2:
Taking into consideration the notes from the previous code I will try to improve the servo.

*Notes* 255 does not work for pwm as it is just a high signal. Although 127 should be the minimum value, trial and error shows 50 is the lowest signal that can be registered. As the pwm signal is expected to be 20 ms by the motor it might be worth it to try to making my own form of pwm with the digtial signals and delays.
