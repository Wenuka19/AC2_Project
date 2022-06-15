// Add values to NodeArray
for (int rows = 0; rows < 11; rows++)
{
  for (int cols = 0; cols < 11; cols++)
  {
    nodeArray[rows][cols].col = cols;
    nodeArray[rows][cols].row = rows;
    nodeArray[rows][cols].state = fullMapTest[rows][cols];
  }
}

// Add pointers
for (int rows = 0; rows < 11; rows++)
{
  for (int cols = 0; cols < 11; cols++)
  {
    // Get the address of the current node
    // Node *curNode = &nodeArray[rows][cols];
    Node *fr; // Front pointer
    Node *bk; // back pointer
    Node *r;  // Right pointer
    Node *l;  // Left pointer

    if (rows == 0) // If robot is at top
    {
      fr = nullptr; // No node to frontt
      bk = &nodeArray[rows + 1][cols];
      // Test for left and right availability
      if (cols == 0) //  If robot is at leftmost
      {
        r = &nodeArray[rows][cols + 1];
        l = nullptr; // No node to left
      }
      else if (cols == 10) // If robot is at rightmost
      {
        r = nullptr; // No node to right
        l = &nodeArray[rows][cols - 1];
      }
      else
      {
        r = &nodeArray[rows][cols + 1];
        l = &nodeArray[rows][cols - 1];
      }
    }
    else if (rows == 10)
    {
      fr = &nodeArray[rows - 1][cols];
      bk = nullptr; // No node to the back
      // Test for left and right availability
      // Test for left and right availability
      if (cols == 0) //  If robot is at leftmost
      {
        r = &nodeArray[rows][cols + 1];
        l = nullptr; // No node to left
      }
      else if (cols == 10) // If robot is at rightmost
      {
        r = nullptr; // No node to right
        l = &nodeArray[rows][cols - 1];
      }
      else
      {
        r = &nodeArray[rows][cols + 1];
        l = &nodeArray[rows][cols - 1];
      }
    }
    else
    {
      fr = &nodeArray[rows - 1][cols];
      bk = &nodeArray[rows + 1][cols];
      // Test for left and right availability
      if (cols == 0) //  If robot is at leftmost
      {
        r = &nodeArray[rows][cols + 1];
        l = nullptr; // No node to left
      }
      else if (cols == 10) // If robot is at rightmost
      {
        r = nullptr; // No node to right
        l = &nodeArray[rows][cols - 1];
      }
      else
      {
        r = &nodeArray[rows][cols + 1];
        l = &nodeArray[rows][cols - 1];
      }
    }
    nodeArray[rows][cols].front = fr;
    nodeArray[rows][cols].back = bk;
    nodeArray[rows][cols].right = r;
    nodeArray[rows][cols].left = l;
  }
}