#include <Servo.h>

Servo servo; // create servo object to control a servo

int pos = 0; // variable to store the servo position
int mealsperday = 1;

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (mealsperday <= 4) {
    for (pos = 0; pos <= 200; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
      servo.write(pos);                   // tell servo to go to position in variable 'pos'
      delay(5);                           // waits 15ms for the servo to reach the position
    }
    for (pos = 200; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(5);
    }
    if (mealsperday < 4) {
      delay(4UL * 60UL * 60UL * 1000UL);
    }
    mealsperday++;
  } else {
    mealsperday = 1;
    delay(12UL * 60UL * 60UL * 1000UL);
  }
}
