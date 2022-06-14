#pragma once
#include "stdio.h"

class FullMapGen
{
private:
public:
    /*============Array Implementation(Fully Functioning and to be used)=======================*/
    /*currPos format = {row index, column index}*/
    int (*fullMap_arr)[6];
    void initData_array(int (*ptr)[6]);
    void printMap_arr();
    void updateMap_arr(int *currentPos_arr, int (*relMap_arr)[11]);
    /*============Array Implementation(Fully Functioning and to be used)=======================*/
};
