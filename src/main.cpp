// Arduino Libraries
#include <Servo.h>
#include <Arduino.h>

// Required Files
#include "fullMapGen.h"
#include "relativeMapGen.h"

// DEFINITIONS

// 1.1 Motor pins
#define ENB_M1 5
#define ENB_M2 10
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define SERVO_PIN 11

// 1.2 Motor Params
#define speed 50
const int TIME_PER_REV = 100;

// 2.1 IR pins - A0
#define SHARP_PIN 14

// 3.1 Map Inits
#include "mapArrays.h"
int currPos[2] = {5, 5};

// 3.2 Map structs

// Path Finding variables
/*  Set the following variable to true when the robot
 *  completed cleaning the room */
bool isComplete;

// Sharp and Servo objects - Not used
Servo sharpMountServoInit;

// Mapper objects
FullMapGen fullMap;
RelativeMapGen relMapper(relMapIn);

void setup()
{
  // SETTING PINS
  // Motor pins
  pinMode(ENB_M1, OUTPUT);
  pinMode(ENB_M2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // Servo and IR pins
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(SHARP_PIN, INPUT);

  // Initiate Serial for testing
  Serial.begin(9600);

  // Create mapper objects
  fullMap.initData_array(fullMapIn);
  fullMap.updateMap_arr(currPos, relMapIn);
  sharpMountServoInit.attach(SERVO_PIN);

  // point the servo to front
  sharpMountServoInit.write(90);
}

// the loop function runs over and over again forever
void loop()
{
  // sharpMountServo1.write(0);
  /*for (int i=0; i<90; i++){
    sharpMountServo1.write(i);
    delay(1000);
  }
  for (int i=90; i<0; i--){
    sharpMountServo1.write(i);
    delay(1000);
  }*/
  relMapper.updateMap();
  fullMap.updateMap_arr(currPos, relMapIn);

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      Serial.print(relMapIn[i][j]);
      Serial.print(" ");
    }
    Serial.println(" ");
  }
  Serial.println(" ");
  delay(200);
}
