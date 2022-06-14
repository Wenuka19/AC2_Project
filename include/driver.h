#pragma once
#include "Arduino.h"

class Driver
{
public:
    int LM_1;
    int LM_2;
    int RM_1;
    int RM_2;
    int LM_EN;
    int RM_EN;
    int speed;

public:
    Driver(int motor1_1, int motor1_2, int motor2_1, int motor2_2, int motor1_EN, int motor2_EN, int speed);
};
