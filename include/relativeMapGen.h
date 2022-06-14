// IMPORTS
#pragma once

#include "Arduino.h"
#include <Servo.h>
#include "../include/sharp.h"

// servo motor
class RelativeMapGen
{
private:
    uint8_t servoPin = 11;
    int servoRange = 180; // 180 degree full range of servo motor

    Servo sharpMountServo;
    Sharp sharp;

    int (*relMap_arr)[11];

    /*int relMap_arr[6][11] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};*/

    // If the robot is facing in +y direction,
    // 0 degrees is to the -x direction

    const int angles[65] =
        {0, 0, 0, 0, 0, 11, 14, 18, 21, 27, 27, 31, 34, 37, 39, 45, 45, 45, 45, 45, 51, 53, 56, 59, 63, 63, 68, 72, 76, 79, 90, 90, 90, 90, 90, 101, 104, 108, 112, 117, 117, 121, 124, 127, 129, 135, 135, 135, 135, 135, 141, 143, 146, 149, 153, 153, 159, 162, 166, 169, 180, 180, 180, 180, 180};
    const int dist[65] =
        {10, 20, 30, 40, 50, 51, 41, 32, 54, 22, 45, 58, 36, 50, 64, 14, 28, 42, 56, 70, 64, 50, 36, 58, 22, 45, 53, 32, 41, 51, 10, 20, 30, 40, 50, 51, 41, 32, 53, 22, 45, 58, 36, 50, 64, 14, 28, 42, 56, 70, 64, 50, 36, 58, 22, 45, 54, 32, 41, 51, 10, 20, 30, 40, 50};
    const int mapBlock[65][2] =
        {{5, 6}, {5, 7}, {5, 8}, {5, 9}, {5, 10}, {4, 10}, {4, 9}, {4, 8}, {3, 10}, {4, 7}, {3, 9}, {2, 10}, {3, 8}, {2, 9}, {1, 10}, {4, 6}, {3, 7}, {2, 8}, {1, 9}, {0, 10}, {0, 9}, {1, 8}, {2, 7}, {0, 8}, {3, 6}, {1, 7}, {0, 7}, {2, 6}, {1, 6}, {0, 6}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}, {0, 4}, {1, 4}, {2, 4}, {0, 3}, {3, 4}, {1, 3}, {0, 2}, {2, 3}, {1, 2}, {0, 1}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 0}, {1, 0}, {2, 1}, {3, 2}, {2, 0}, {4, 3}, {3, 1}, {3, 0}, {4, 2}, {4, 1}, {4, 0}, {5, 4}, {5, 3}, {5, 2}, {5, 1}, {5, 0}};

    // Methods
    bool checkForObstacle(int index);
    bool isInRange(float sharpReading, int blockVal);

public:
    // passed map array should be a 2-D array with dimensions 6x11
    RelativeMapGen(int (*relMapIn_arr)[11]);
    bool initArray(int (*relMapIn_arr)[11]);

    // Call this method
    void updateMap();
};