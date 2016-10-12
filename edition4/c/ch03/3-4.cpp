#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// void hanoi(int n, int from, int to, int spare) {
void hanoi(int n, stack<int> &from, stack<int> &to, stack<int> &spare) {
  if (n == 1) {
    // cout << "move from " << from << " to " << to << endl;
    to.push( from.top() );
    from.pop();
  } else {
    hanoi(n-1, from, spare, to);
    hanoi(1, from, to, spare);
    hanoi(n-1, spare, to, from);
  }
}

void printTowers(stack<int> towers[3]) {
  // print towers
  cout << "Tower 1:" << endl;
  while (!towers[0].empty()) {
    cout << "\t " << towers[0].top() << endl;
    towers[0].pop();
  }

  cout << "Tower 2:" << endl;
  while (!towers[1].empty()) {
    cout << "\t " << towers[1].top() << endl;
    towers[1].pop();
  }

  cout << "Tower 3:" << endl;
  while (!towers[2].empty()) {
    cout << "\t " << towers[2].top() << endl;
    towers[2].pop();
  }
}

int main() {
  const int NUM_DISCS = 3;
  stack<int> towers[3];

  // create towers
  for (int i=0; i<NUM_DISCS; i++) {
    stack<int> tmp;
    towers[i] = tmp;
  }

  // seed first tower with discs
  for (int i=NUM_DISCS; i>0; i--) {
    towers[0].push(i);
  }

  // hanoi(4, 0, 1, 2);
  hanoi(3, towers[0], towers[1], towers[2]);

  printTowers(towers);

  // tests
  return 0;
}
