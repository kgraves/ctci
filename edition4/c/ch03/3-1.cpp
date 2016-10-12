#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

const int STACK_SIZE = 300;
int buffer[STACK_SIZE * 3];
int stackPointer[] = {0, 0, 0};

void push(int stackNum, int value) {
  stackPointer[stackNum]++;
  buffer[stackNum * STACK_SIZE + stackPointer[stackNum]] = value;
}

int pop(int stackNum) {
  int num = buffer[stackNum * STACK_SIZE + stackPointer[stackNum]];
  // optional: clear the vacated spot in array
  buffer[stackNum * STACK_SIZE + stackPointer[stackNum]] = 0;
  stackPointer[stackNum]--;

  return num;
}

int peek(int stackNum) {
  return buffer[stackNum * STACK_SIZE + stackPointer[stackNum]];
}

bool isEmpty(int stackNum) {
  return stackPointer[stackNum] == 0;
}

int main() {
  // tests
  assert(isEmpty(0));
  assert(isEmpty(1));
  assert(isEmpty(2));

  push(0, 1);
  push(0, 2);
  push(0, 3);

  assert(isEmpty(0) == false);

  push(1, 1);
  push(1, 2);
  push(1, 3);

  assert(isEmpty(1) == false);

  push(2, 1);
  push(2, 2);
  push(2, 3);

  assert(isEmpty(2) == false);

  assert(peek(0) == 3);
  assert(peek(1) == 3);
  assert(peek(2) == 3);

  push(0, 4);
  push(1, 4);
  push(2, 4);

  assert(peek(0) == 4);
  assert(peek(1) == 4);
  assert(peek(2) == 4);

  assert(pop(0) == 4);
  assert(pop(1) == 4);
  assert(pop(2) == 4);

  assert(peek(0) == 3);
  assert(peek(1) == 3);
  assert(peek(2) == 3);

  return 0;
}
