#include <assert.h>

#include <algorithm>
#include <cmath>
#include <iostream>
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
    void deleteFromNode(Node *n);
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

int listToInt(LinkedList list) {
  int n = 0;
  int multiplier = 1;
  Node *curr = list.head;

  while (curr) {
    n += curr->value * multiplier;

    curr = curr->next;
    multiplier *= 10;
  }

  return n;
}

int sumLists(LinkedList n1, LinkedList n2) {
  return listToInt(n1) + listToInt(n2);
}

int main() {
  LinkedList n1;
  n1.add(1);
  n1.add(2);
  n1.add(3);
  LinkedList n2;
  n2.add(1);
  n2.add(2);
  n2.add(3);
  assert(sumLists(n1, n2) == 642);

  LinkedList n3;
  LinkedList n4;
  n4.add(2);
  n4.add(4);
  assert(sumLists(n3, n4) == 42);

  return 0;
}
