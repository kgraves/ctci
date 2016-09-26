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

void LinkedList::deleteFromNode(Node *n) {
  if (!n || !n->next) {
    return;
  }

  Node *next = n->next;

  n->value = n->next->value;
  n->next = n->next->next;

  delete next;
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

int main() {
  LinkedList list;
  list.deleteFromNode(list.head);

  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.deleteFromNode(list.head->next);
  assert(list.length() == 3);
  assert(list.head->value == 1);
  assert(list.head->next->value == 3);
  assert(list.head->next->next->value == 4);

  return 0;
}
