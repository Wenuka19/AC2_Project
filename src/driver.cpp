#include "driver.h"

Driver::Driver(int motor1_1, int motor1_2, int motor2_1, int motor2_2, int motor1_EN, int motor2_EN, int speed)
{
    this->LM_1 = motor1_1;
    this->LM_2 = motor1_2;
    this->LM_EN = motor1_EN;
    this->RM_1 = motor2_1;
    this->RM_2 = motor2_2;
    this->RM_EN = motor2_EN;
    this->speed = speed;
}
