#pragma once

#include "payload.h"

struct Node {
  Payload current_payload; // defining current payload for the node 
  Node* link; // defining node link that links one node to another
  Node(const Payload& p) : current_payload(p), link(nullptr) {};
};

struct List {
  Node* list_head; // head of the list
  Node* list_tail; // tail of the list
  List(); // construtor
  ~List(); // destructor

  void push_front(const Payload& new_payload); // method for adding new element 
  void pop_front(); // method for removing the first element
  void push_back(const Payload& new_payload); // method for adding new element
  void pop_back(); // method for removing the last element
  Payload& operator[](int i); // operator to access the element at index i
  int size() const; // method for getting the size of the list
  void print() const; // method for printing the list
};