#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <climits>
#include <string>

using namespace std;

int countOnesBits(int n) {
  int i=0;
  int count=0;

  while (i < 32) {
    if ((n & (1<<i)) > 0) {
      count++;
    }

    i++;
  }

  return count;
}

int findPreviousBinaryNumber(int n) {
  int count = countOnesBits(n);
  for (int i=n-1; i>=0; i--) {
    if (count == countOnesBits(i)) {
      return i;
    }
  }

  return -1;
}

int findNextBinaryNumber(int n) {
  int count = countOnesBits(n);
  for (int i=n+1; i<=INT_MAX; i++) {
    if (count == countOnesBits(i)) {
      return i;
    }
  }

  return -1;
}

int main() {
  // tests
  int prev = findPreviousBinaryNumber(2);
  int next = findNextBinaryNumber(2);
  cout << prev << endl << next << endl;
  assert(prev == 1);
  assert(next == 4);

  prev = findPreviousBinaryNumber(42);
  next = findNextBinaryNumber(42);
  cout << prev << endl << next << endl;
  assert(prev == 41);
  assert(next == 44);

  prev = findPreviousBinaryNumber(31);
  next = findNextBinaryNumber(31);
  cout << prev << endl << next << endl;
  assert(prev == -1);
  assert(next == 47);

  return 0;
}
