#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mark(int matrix[][5], int w, int h) {
  int rows[h];
  int cols[w];
  memset(rows, 0, h);
  memset(cols, 0, w);

  for (int y=0; y<h; y++) {
    for (int x=0; x<w; x++) {
      if (matrix[x][y] == 0) {
        rows[y] = 1;
        cols[x] = 1;
      }
    }
  }

  // run thru rows
  for (int y=0; y<h; y++) {
    if (rows[y] == 1) {
      for (int col=0; col<w; col++) {
        matrix[col][y] = 0;
      }
    }
  }
  // run thru cols
  for (int x=0; x<w; x++) {
    if (cols[x] == 1) {
      for (int row=0; row<h; row++) {
        matrix[x][row] = 0;
      }
    }
  }
}

void print(int matrix[][5], int w, int h) {
  for (int y=0; y<h; y++) {
    for (int x=0; x<w; x++) {
      printf("%d ", matrix[x][y]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  // tests
  int matrix[3][5] = {
    {1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1}
  };
  int expected[3][5] = {
    {1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1}
  };
  mark(matrix, 3, 5);

  // compare matricies
  for (int i=0; i<3; i++) {
    assert(memcmp(matrix[i], expected[i], 5) == 0);
  }

  return 0;
}
