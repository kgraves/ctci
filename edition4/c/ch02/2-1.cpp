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
    void removeDups();
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

void LinkedList::removeDups() {
  Node *prev = this->head;
  Node *curr = this->head->next;
  while (curr) {
    Node *runner = this->head;

    while (runner != curr) {
      if (runner->value == curr->value) {
        Node * temp = curr;
        curr = curr->next;
        prev->next = curr;
        delete temp;
        break;
      }

      runner = runner->next;
    }
    if (curr == runner) {
      prev = curr;
      curr = curr->next;
    }
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

int main() {
  LinkedList list;
  list.add(1);
  list.add(2);
  list.add(3);
  list.removeDups();
  assert(list.length() == 3);

  list.add(2);
  list.removeDups();
  assert(list.length() == 3);

  list.add(2);
  list.add(2);
  list.add(2);
  list.add(2);
  list.add(2);
  list.removeDups();
  cout << list.length() << endl;
  assert(list.length() == 3);

  return 0;
}
