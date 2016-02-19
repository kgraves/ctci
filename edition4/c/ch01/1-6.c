#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

/**
 * Prints given matrix for debugging.
 */
void print(int matrix[][SIZE], int size) {
  for (int y=0; y < size; y++) {
    for (int x=0; x<size; x++) {
      printf("%d ", matrix[x][y]);
    }
    printf("\n");
  }
  printf("\n");
}

/**
 * Rotates, in place, an NxN matrix clockwise.
 *
 * Performs the rotation as follows:
 * - left -> top
 * - bottom -> left
 * - right -> bottom
 * - top -> right
 */
void rotate(int matrix[][SIZE], int size) {
  int numLayers = size/2;
  for (int layer=0; layer < numLayers; layer++) {
    int end = size - 1 - layer;

    for (int cell=layer; cell<end; cell++) {
      int top = matrix[cell][layer];
      int xMax = size - 1 - cell;
      int yMax = size - 1 - layer;

      matrix[cell][layer] = matrix[layer][xMax];
      matrix[layer][xMax] = matrix[xMax][yMax];
      matrix[xMax][yMax] = matrix[yMax][cell];
      matrix[yMax][cell] = top;
    }
  }
}

int main() {
  // tests
  int matrix[5][5] = {
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5}
  };
  int expected[5][5] = {
    {5,5,5,5,5},
    {4,4,4,4,4},
    {3,3,3,3,3},
    {2,2,2,2,2},
    {1,1,1,1,1}
  };
  rotate(matrix, 5);

  // compare matricies
  for (int i=0; i<SIZE; i++) {
    assert(memcmp(matrix[i], expected[i], SIZE) == 0);
  }

  return 0;
}
