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
#define ENB_M1 9
#define ENB_M2 10

// Left Motor
#define IN1 2
#define IN2 3

// Right Motor
#define IN3 4
#define IN4 5
#define SERVO_PIN 11

// 1.2 Motor Params
#define speed 5
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
Grid *nodeMap = new Grid;
Driver m_driver(IN1, IN2, IN3, IN4, ENB_M1, ENB_M2, speed);
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
  Serial.println("");

  // Create mapper objects
  fullMap.initData_array(fullMapTest);
  fullMap.updateMap_arr(currPos, relMapIn);
  sharpMountServoInit.attach(SERVO_PIN);
  /*
    int counter = 0;
    for (int rows = 0; rows < 11; rows++)
    {
      counter += 100;
      for (int cols = 0; cols < 11; cols++)
      {
        fullMapTest[rows][cols] = counter;
        counter += 1;
      }
    }*/

  for (int rows = 0; rows < 11; rows++)
  {
    for (int cols = 0; cols < 11; cols++)
    {
      // Node *curNode = nodeMap->fullMap[rows][cols];
      // Serial.print("(");
      // Serial.print(rows);
      // Serial.print(",");
      // Serial.print(cols);
      // Serial.print(")-");
      Serial.print(fullMapTest[rows][cols]);
      Serial.print(" | ");
    }
    Serial.println("");
  }

  // point the servo to front
  sharpMountServoInit.write(90);
  // arr_to_graph(nodeMap, fullMapTest);

  // Find initial path for a map with no obstacles
  int path[20] = {1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  1,
                  -1};
  m_driver.follow_path(path);
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
  // relMapper.updateMap();
  // fullMap.updateMap_arr(currPos, relMapIn);

  // // Creating the node map
  // // arr_to_graph(nodeMap, fullMapTest);
  // Serial.println("Node map");
  // for (int rows = 0; rows < 11; rows++)
  // {
  //   for (int cols = 0; cols < 11; cols++)
  //   {
  //     Node *curNode = nodeMap->fullMap[rows][cols];
  //     Serial.print("(");
  //     Serial.print(curNode->row);
  //     Serial.print(",");
  //     Serial.print(curNode->col);
  //     Serial.print(")-");
  //     Serial.print(curNode->state);
  //     Serial.print(" | ");
  //   }
  //   Serial.println("");
  // }

  // delay(2000000);
}
