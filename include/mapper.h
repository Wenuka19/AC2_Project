#pragma once
#include "mapArrays.h"

struct Node
{
  // Pointers to nodes around the current npde
  // Cost of each edge is 1
  // Indexing
  Node *front, *rear, *left, *right;

  // index of the node - Give the position (row, col)
  int index[2];
  // Save if the ndeo is obstacle, free to move, unsearched
  int state;
};

struct Grid // Map of nodes
{
  // An array to store nodes in order
  // of the map
  Node fullMap[11][11];
};