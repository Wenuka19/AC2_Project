// Arduino Libraries
#include <Servo.h>
#include <Arduino.h>

// Required Files
#include "fullMapGen.h"
#include "relativeMapGen.h"
#include "mapper.h"
#include "driver.h"

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
Node nodeArray[11][11];

//  Path Finding variables
/*  Set the following variable to true when the robot
 *  completed cleaning the room */
bool isComplete;

// Sharp and Servo objects - Not used
// Servo sharpMountServoInit;

// Mapper objects
// FullMapGen fullMap;
// RelativeMapGen relMapper(relMapIn);

void setup()
{
  // SETTING PINS
  // Motor pins
  {
    pinMode(ENB_M1, OUTPUT);
    pinMode(ENB_M2, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    // Servo and IR pins
    pinMode(SERVO_PIN, OUTPUT);
    pinMode(SHARP_PIN, INPUT);
  }

  // Initiate Serial for testing
  {
    Serial.begin(9600);
  }

  // Create mapper objects
  // fullMap.initData_array(fullMapTest);
  // fullMap.updateMap_arr(currPos, relMapIn);

// Init Node array
#include "arr_to_graph.h"
}

// the loop function runs over and over again forever
void loop()
{
  /*
  01. Initialize the path in setup[For a map with no obstacles]
  02. Scan for obstacles.
  03. Update the map.
  04. Find a path.
  05. Travel along the path.
  06.
  */

  Serial.println("Node map");

  // Print node Array
  // for (int rows = 0; rows < 11; rows++)
  // {
  //   for (int cols = 0; cols < 11; cols++)
  //   {
  //     Serial.print(nodeArray[rows][cols].state);
  //     Serial.print(" ");
  //     Serial.print(nodeArray[rows][cols].row);
  //     Serial.print(" ");
  //     Serial.print(nodeArray[rows][cols].col);
  //     Serial.print(" ");
  //     // Serial.print((int)&nodeArray[rows][cols]);
  //     // Left node
  //     Serial.print(" (");
  //     Serial.print(nodeArray[rows][cols].right->row);
  //     Serial.print(",");
  //     Serial.print(nodeArray[rows][cols].right->col);
  //     Serial.print(")");
  //     Serial.print(" | ");
  //   }
  //   Serial.println("");
  // }

  delay(2000000);
}
