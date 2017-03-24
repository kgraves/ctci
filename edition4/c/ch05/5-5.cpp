#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <climits>
#include <string>

using namespace std;

int countOnesBits(int n) {
  int count=0;

  for (int i=0; i<32; i++) {
    if ((n & (1<<i)) > 0) {
      count++;
    }
  }

  return count;
}

int countBitDifference(int n, int m) {
  int res = n ^ m;
  return countOnesBits(res);
}

int main() {
  // tests
  assert(countBitDifference(1, 0) == 1);
  assert(countBitDifference(7, 0) == 3);
  assert(countBitDifference(31, 14) == 2);

  return 0;
}
