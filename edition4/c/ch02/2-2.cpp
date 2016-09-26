#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Node {
  public:
    int value;
    Node *next;
    Node(int value, Node *next);
};

Node::Node(int value, Node *next) {
  this->value = value;
  this->next = next;
}

class LinkedList {
  public:
    Node *head;
    LinkedList();
    void add(int value);
    Node* nthToLast(int n);
    int length();
    void print();
};

LinkedList::LinkedList() {
  this->head = NULL;
}

void LinkedList::add(int value) {
  if (!this->head) {
    this->head = new Node(value, NULL);
  } else {
    Node *temp = this->head;

    while (temp->next) {
      temp = temp->next;
    }

    temp->next = new Node(value, NULL);
  }
}

int LinkedList::length() {
  int length = 0;
  Node *curr = this->head;

  while (curr) {
    length++;
    curr = curr->next;
  }

  return length;
}

void LinkedList::print() {
  Node *curr = this->head;

  while (curr) {
    cout << curr->value << " -> ";
    curr = curr->next;
  }

  cout << "NULL" << endl;
}

Node* LinkedList::nthToLast(int n) {
  if (!this->head || n < 0) {
    return NULL;
  } else {
    Node *curr = this->head;
    Node *last;

    // #       *
    // 0 - 1 - 2 - 3
    int dist = n;
    while (dist--) {
      curr = curr->next;
    }

    last = this->head;

    while (curr->next != NULL) {
      curr = curr->next;
      last = last->next;
    }

    return last;
  }
}

int main() {
  LinkedList list;

  assert(list.nthToLast(0) == NULL);
  assert(list.nthToLast(1) == NULL);

  list.add(1);
  list.add(2);
  list.add(3);
  assert(list.nthToLast(0)->value == 3);
  assert(list.nthToLast(1)->value == 2);
  assert(list.nthToLast(2)->value == 1);

  return 0;
}
