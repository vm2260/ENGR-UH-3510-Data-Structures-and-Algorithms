#include "payload.h"
#include "mylist.h"

// constructor for List
List::List(){
  // setting default settings for when the size of the linked list is 0
  list_head = nullptr;
  list_tail = nullptr;
  size_var = 0;
}

// destructor for List
List::~List(){
  Node* current = list_head; // setting the current element of the list as the head
  while (current != nullptr) { // loop until the end of the list is reached, deleting each element
    Node* link = current->link; // temporary pointer "next" is initialized to point to the next node of the current node. 
    //We save the reference to the next node before the current node is deleted. 
    delete current; // deleting the current element 
    current = link; // setting the current element as the next element
    
  }
}

// push_front method for list
void List::push_front(const Payload& paylodochka){
  Node* new_node = new Node(paylodochka); // creating a new node with the given payload);
  new_node->link = list_head;

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

// list method size
int List::size() const{
    int count = 0;
    Node* iterator = list_head;
    while(iterator != nullptr){
        count++;
      iterator = iterator->link;
        
    }
    return count;
}

// print method for list
void List::print() const{
    Node* iterator = list_head;
    while(iterator != nullptr){
        (iterator->current_payload).print();
        iterator = iterator->link;

    }
}
