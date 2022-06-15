#include "driver.h"

void Driver::followPath(int *path)
{
    while (*path != -1)
    {
        switch (*path)
        {
        case FWD:
            forward();
            break;

        case LFT:
            left();
            break;

        case RGT:
            right();
            break;

        case BCK:
            left();
            left();
            break;
        default:
            break;
        }
        path++;
        delay(1000);
    }
}

void Driver::forward()
{
    Serial.println("FWD");
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(1000);
    stop();
}

void Driver::left()
{
    Serial.println("LFT");
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    delay(500);
    digitalWrite(4, LOW);
}

void Driver::right()
{
    Serial.println("RHGT");
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(500);
    digitalWrite(2, LOW);
}

void Driver::stop()
{
    Serial.println("STOP");
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
}