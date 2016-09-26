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
    void removeDups();
    void removeDupsBetter();
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

void LinkedList::removeDupsBetter() {
  map<int, bool> m;
  Node *prev = this->head;
  Node *curr = this->head->next;

  // seed the map with value of first list element that we are skipping.
  // m.insert(prev->value, true);
  m.insert(pair<int,bool>(prev->value,true));

  while (curr) {
    // check hash, if exists, delete from list
    if (m.find(curr->value) != m.end()) {
        Node * temp = curr;
        curr = curr->next;
        prev->next = curr;
        delete temp;

        continue;
    } else {
      m.insert(pair<int,bool>(curr->value,true));
    }

    // add to map and increment the current pointer
    prev = curr;
    curr = curr->next;
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
  list.removeDupsBetter();
  assert(list.length() == 3);

  list.add(2);
  list.removeDupsBetter();
  assert(list.length() == 3);

  list.add(2);
  list.add(2);
  list.add(2);
  list.add(2);
  list.add(2);
  list.removeDupsBetter();
  assert(list.length() == 3);

  return 0;
}
