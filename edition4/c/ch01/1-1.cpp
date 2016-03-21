#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool hasAllUnique(string str) {
  bitset<245> seen;

  for (int i=0; i<str.length(); i++) {
    if (seen.test(str[i]) == true) {
      return false;
    }

    seen.set(str[i], true);
  }

  return true;
}

int main() {
  string str1 = string("a");
  assert(hasAllUnique(str1));

  string str2 = string("abcdefghijklmnopqrstuvwxyz");
  assert(hasAllUnique(str2));

  string str3 = string("aa");
  assert(!hasAllUnique(str3));

  string str4 = string("abcdefghijklmnopqrstuvwxyza");
  assert(!hasAllUnique(str4));

  return 0;
}
