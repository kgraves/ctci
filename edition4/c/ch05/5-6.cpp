#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <climits>
#include <string>

using namespace std;

const int ODD_MASK = 2863311530;
const int EVEN_MASK = 1431655765;

int swapOddsAndEvens(int n) {
  int oddBits = n & ODD_MASK;
  int evenBits = n & EVEN_MASK;

  return (evenBits << 1) | (oddBits >> 1);
}

int main() {
  // tests
  int res = swapOddsAndEvens(955); // 1110111011
  int expected = 887;
  assert(res == expected);

  res = swapOddsAndEvens(443); // 0110111011
  expected = 631;
  assert(res == expected);

  return 0;
}
