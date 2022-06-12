#include "relativeMapGen.h"

RelativeMapGen::RelativeMapGen(int (*relMapIn_arr)[6])
{
    this->relMap_arr = relMapIn_arr;
    sharpMountServo.attach(11);
}

bool RelativeMapGen::isInRange(float sharpReading, int blockVal)
{
    if (sharpReading >= blockVal - 5 && sharpReading <= blockVal + 5)
    {
        return true;
    }
    return false;
}

bool RelativeMapGen::checkForObstacle(int index)
{
    float distance = this->sharp.getDistance();
    if (isInRange(distance, this->dist[index]))
    {
        return (true);
    }
}

void RelativeMapGen::updateMap(int *map)
{
    int distance;
    {
        for (int index = 0; index < 42; index++)
        {
            sharpMountServo.write(angles[index]);
            if (this->checkForObstacle(index))
            {
                relMap_arr[mapBlock[index][0]][mapBlock[index][1]] += 1;
            }
        }
    }
}
