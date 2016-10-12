#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <set>

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
    void deleteFromNode(Node *n);
    int length();
    void print();
    Node *findLoopBeginning();
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

Node* LinkedList::findLoopBeginning() {
  set<int> seen;
  Node *curr = this->head;

  while (curr && seen.find(curr->value) == seen.end()) {
    seen.insert(curr->value);
    curr = curr->next;
  }

  return curr;
}

int main() {
  // tests
  LinkedList l;

  assert(l.findLoopBeginning() == NULL);

  l.add(1);
  l.add(2);
  l.add(3);
  l.add(4);
  l.add(2);
  Node* n = l.findLoopBeginning();
  assert(n->value == 2);

  return 0;
}
