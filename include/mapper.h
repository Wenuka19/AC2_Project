#pragma once
#include "mapArrays.h"

struct Node
{

  // index of the node - GIve the position
  int index;
  // Save if the ndeo is obstacle, free to move, unsearched
  int state;
};

struct Grid // Map of nodes
{
  // An array to store nodes in order
  // of the map
  Node fullMap[11][11];
};