#include "mapper.h"

void arr_to_graph(Grid *mapGrid, int (*fullMap_arr)[11])
{
  // int rowLen = sizeof(fullMap_arr[0]);
  int rowLen = 11;
  for (int cols = 0; cols < 11; cols++)
  {
    for (int rows = 0; rows < rowLen; rows++)
    {
      // Get the state from the created array
      int stateVal = fullMap_arr[cols][rows];

      // Creating a node for the current location
      struct Node *newNode = new Node;

      newNode->col = cols;
      newNode->row = rows;
      newNode->state = stateVal;
      mapGrid->fullMap[cols][rows] = newNode;
    }
  }
}