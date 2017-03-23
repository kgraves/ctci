#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int setBitsEqual(int n, int m, int start, int end) {
  // create mask to zero out bit window in n
  int mask = ~(int(pow(2, (end - start) + 1) - 1) << start);

  // zero out bit window in n
  n &= mask;

  // copy over bits from m to n
  n |= (m << start);

  return n;
}

int main() {
  // tests
  int res1 = setBitsEqual(31, 0, 1, 3);
  bitset<32> result1(res1);
  assert(result1 == 17);

  int res2 = setBitsEqual(1024, 21, 2, 6);
  bitset<32> result2(res2);
  assert(result2 == 1108);

  return 0;
}
