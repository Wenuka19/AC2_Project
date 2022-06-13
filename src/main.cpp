// Arduino Libraries
#include <Servo.h>
#include <Arduino.h>

// Required Files
#include "fullMapGen.h"
#include "relativeMapGen.h"

int fullMapIn[6][6] = {
    {0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1},
    {0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 0, 1, 1, 1}};

int relMapIn[6][11] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int currPos[2] = {2, 3};
FullMapGen fullMap;
RelativeMapGen relMapper(relMapIn);

// Servo sharpMountServo1;

void setup()
{
  Serial.begin(9600);
  fullMap.initData_array(fullMapIn);
  fullMap.updateMap_arr(currPos, relMapIn);
  // sharpMountServo1.attach(11);
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
