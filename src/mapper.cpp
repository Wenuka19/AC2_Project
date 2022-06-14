#include "mapper.h"

void arr_to_graph(Grid *mapGrid, int (*fullMap_arr)[11])
{
  // int rowLen = sizeof(fullMap_arr[0]);
  int rowLen = 11;

  // Initiate all nodes
  // no pointers are set
  for (int rows = 0; rows < 11; rows++)
  {
    for (int cols = 0; cols < rowLen; cols++)
    {
      // Get the state from the created array
      int stateVal = fullMap_arr[rows][cols];

      // Creating a node for the current location
      Node *newNode = new Node;

      newNode->col = cols;
      newNode->row = rows;
      newNode->state = stateVal;
      mapGrid->fullMap[rows][cols] = newNode;
    }
  }
  // Setting pointers
  for (int rows = 0; rows < 11; rows++)
  {
    for (int cols = 0; cols < rowLen; cols++)
    {
      Node *curNode = mapGrid->fullMap[rows][cols];
      Node *fr; // Front pointer
      Node *bk; // back pointer
      Node *r;  // Right pointer
      Node *l;  // Left pointer

      if (rows == 0) // If robot is at top
      {
        fr = NULL; // No node to frontt
        bk = mapGrid->fullMap[rows + 1][cols];
        // Test for left and right availability
        if (cols == 0) //  If robot is at leftmost
        {
          r = mapGrid->fullMap[rows][cols + 1];
          l = NULL; // No node to left
        }
        else if (cols == 10) // If robot is at rightmost
        {
          r = NULL; // No node to right
          l = mapGrid->fullMap[rows][cols - 1];
        }
        else
        {
          r = mapGrid->fullMap[rows][cols + 1];
          l = mapGrid->fullMap[rows][cols - 1];
        }
      }
      else if (rows == 10)
      {
        fr = mapGrid->fullMap[rows - 1][cols];
        bk = NULL; // No node to the back
        // Test for left and right availability
        if (cols == 0) //  If robot is at leftmost
        {
          l = NULL; // No node to left
          r = mapGrid->fullMap[rows][cols + 1];
        }
        else if (cols == 10) // If robot is at rightmost
        {
          r = NULL;
          l = mapGrid->fullMap[rows][cols - 1];
        }
        else
        {
          r = mapGrid->fullMap[rows][cols + 1];
          l = mapGrid->fullMap[rows][cols - 1];
        }
      }
      else
      {
        fr = mapGrid->fullMap[rows + 1][cols];
        bk = mapGrid->fullMap[rows - 1][cols];
        // Test for left and right availability
        if (cols == 0) //  If robot is at leftmost
        {
          l = NULL;
          r = mapGrid->fullMap[rows][cols + 1];
        }
        else if (cols == 10) // If robot is at rightmost
        {
          r = NULL;
          l = mapGrid->fullMap[rows][cols - 1];
        }
        else
        {
          r = mapGrid->fullMap[rows][cols + 1];
          l = mapGrid->fullMap[rows][cols - 1];
        }
      }
    }
  }
}