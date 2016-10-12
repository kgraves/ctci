#include <assert.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int STACK_SIZE = 300;

class MinStack {
  public:
    MinStack();
    void push(int value);
    int pop();
    int min();

  private:
    int buffer[STACK_SIZE];
    int top;
    stack<int> _min;
};

MinStack::MinStack() {
  this->top = 0;
}

void MinStack::push(int value) {
  int top = this->_min.empty() ? INT_MAX : this->_min.top();
  this->_min.push( std::min(top, value) );

  this->buffer[this->top++] = value;
}

int MinStack::pop() {
  this->_min.pop();
  return this->buffer[this->top--];
}

int MinStack::min() {
  return this->_min.empty() ? INT_MAX : this->_min.top();
}

int main() {
  // tests
  MinStack s;

  assert(s.min() == INT_MAX);

  s.push(2);
  s.push(3);
  s.push(1);
  s.push(4);
  s.push(5);

  assert(s.min() == 1);

  return 0;
}
