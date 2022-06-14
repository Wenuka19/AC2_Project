#pragma once
#include <Arduino.h>

typedef struct Node Node;
typedef struct Grid Grid;



struct Node
{
  /* Pointers to nodes around the current npde
   *Cost of each edge is 1
   * path indexing (indexed clockwise)
   * 1 - front
   * 2 - left
   * 3 - rear
   * 4 - right
   */
  Node *front;
  Node *back;
  Node *left;
  Node *right;

  // index of the node - Give the position (col, row)
  int col;
  int row;
  // Save if the ndeo is obstacle, free to move, unsearched
  int state;
};

struct Grid // Map of nodes
{
  // An array to store nodes in order
  // of the map
  Node *fullMap[11][11];
};

// Convert a given array to a graph
void arr_to_graph(Grid *mapGrid, int (*fullMap_arr)[11]);