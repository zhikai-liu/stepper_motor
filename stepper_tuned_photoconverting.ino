
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

int onPin = 3;
int offPin =2;
int LED = 7;
int on = 0;
int off = 0;

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  pinMode(onPin, INPUT);
  pinMode(offPin, INPUT);
  pinMode(LED, OUTPUT);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  on = digitalRead(onPin);
  off = digitalRead(offPin);
  Serial.println(on);
  Serial.println(off);
  if (on == HIGH)
  {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution/4);
  delay(500);
  digitalWrite(LED,HIGH);
  delay(10000);
  }
  if (off == HIGH)
  {
  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution/4);
  delay(10000);
  }
}

