// The code is used for only navigation purposes.
#include <Arduino.h>
#include "car.h"

// define MOTOR PINS for L298N
#define MOTOR1_EN 9
#define MOTOR1Forward 8
#define MOTOR1Back 7

#define MOTOR2_EN 3
#define MOTOR2Forward 4
#define MOTOR2Back 5

#define encoderIn 2 // Interrupt pin

void setup()
{
  // Set motor control pins to OUT pins
  pinMode(MOTOR1_EN, OUTPUT);
  pinMode(MOTOR1Forward, OUTPUT);
  pinMode(MOTOR1Back, OUTPUT);
  pinMode(MOTOR2_EN, OUTPUT);
  pinMode(MOTOR2Forward, OUTPUT);
  pinMode(MOTOR2Back, OUTPUT);

  // Initialize the motor to OFF
  digitalWrite(MOTOR1Forward, LOW);
  digitalWrite(MOTOR1Back, LOW);
  digitalWrite(MOTOR2Forward, LOW);
  digitalWrite(MOTOR2Back, LOW);

  // Set Encoder Pins as IN
  pinMode(encoderIn, INPUT);
}

void loop()
{
}

void stepForward() {}
void turnLeft() {}
void turnRight() {}