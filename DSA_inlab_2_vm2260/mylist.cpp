#include "payload.h"
#include "mylist.h"
#include <iostream>

#include "stdexcept" // For std::out_of_range
// constructor for List
List::List(){
  // setting default settings for when the size of the linked list is 0
  list_head = nullptr;
  list_tail = nullptr;
}

// destructor for List
List::~List(){
  Node* current = list_head; // setting the current element of the list as the head
  while (current != nullptr) { // loop until the end of the list is reached, deleting each element
    Node* link = current->link; // setting the link of the current element to the next element
    //We save the reference to the next node before the current node is deleted. 
    delete current; // deleting the current element 
    current = link; // setting the current element as the next element
  }
}

// push_front method for list
void List::push_front(const Payload& new_payload){
  Node* new_node = new Node(new_payload); // creating a new node with the given payload);
  new_node->link = list_head;// the new node points to the current head (since we pushed it to the front it should be the head)
  list_head = new_node; // update the head to the new node
  if(list_tail == nullptr){ // if the list is empty, the new node is both the head and tail
      list_tail = new_node;
  }
}

// pop_front method for list 
void List::pop_front(){
    if (list_head != nullptr) {
        Node* temp = list_head; // temporary pointer "temp" is initialized to point to the head node
        list_head = list_head->link; // setting the head node to the next node in the list
        delete temp;
    }
    // If the list is now empty, update list_tail as well
    if (list_head == nullptr) {
        list_tail = nullptr;
    }
}

// push_back method for linked list
void List::push_back(const Payload& new_payload){
  // creating new node with the given payload
  Node* new_node = new Node(new_payload);
    if(list_head == nullptr){ // if the list is empty, the new node is both the head and tail
      list_head = new_node;
      list_tail = new_node; // Now, new_node is both the head and the tail

    }
    else{
      list_tail->link = new_node; // Append the new node at the end
        list_tail = new_node; // Update the tail to the new node
    }
  }



// pop_back method for linked list 
void List::pop_back(){
  // check if the list is empty, i.e. the head is nullptr
  if (list_head == nullptr){
   std::cerr<<"The linked list you are trying to access is empty\n";
    return;
  }
  else if (list_head == list_tail) { // List has only one element
    delete list_head;
    list_head = list_tail = nullptr; // Reset the list
  } 
  else { // List has more than one element
    Node* temp = list_head;
    while (temp->link != list_tail) { // Find the penultimate node
      temp = temp->link;
    }
    // Now temp is the penultimate node
    delete list_tail; // Delete the last node
    list_tail = temp; // Update the tail to the penultimate node
    list_tail->link = nullptr; // Set new tail's link to nullptr
  }
}


// operator[](int i) in List that accesses the i-th element in the List. 

Payload& List::operator[](int index) {
    Node* current = list_head;
    int count = 0;

    while (current != nullptr && count < index) {
        current = current->link;
        ++count;
    }

    if (current == nullptr) {
        throw std::out_of_range("Index is out of the bounds of the List.");
    }

    return current->current_payload;
}



// list method size
int List::size() const{
    int count = 0; 
    Node* current = list_head;
    while(current != nullptr){
      count++;
      current = current->link;
        
    }
    return count;
}

// print method for list
void List::print() const{
    Node* current = list_head;
    while(current != nullptr){
        (current->current_payload).print();
        current = current->link;

    }
}
