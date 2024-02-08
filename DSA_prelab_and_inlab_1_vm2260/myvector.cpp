#include "payload.h" // including payload header 
#include "myvector.h" // including myvector.h header
#include <iostream> // including lib for the input-output operations

using std::cout;

Vector::Vector() : size_var(0) {   // defining constructor for 'Vector' struct ; initializing member variables  1
  payloads = new Payload[capacity_max]; // allocating memory for payloads array

}

Vector::~Vector() { // defining destructor for 'Vector' struct

    delete[] payloads; // deleting dynamically allocated memory
}

void Vector::push_back(const Payload& paylodochka) {
    if (size_var >= capacity_max) {
        // Double the capacity and reallocate
        int new_capacity_max = capacity_max * 2;
        Payload* new_payloads = new Payload[new_capacity_max];
        for (int i = 0; i < size_var; ++i) {
            new_payloads[i] = payloads[i]; // Copy elements to the new array
        }
        delete[] payloads; // Free the old array
        payloads = new_payloads; // Update the pointer
      capacity_max = new_capacity_max;
    }
    payloads[size_var++] = paylodochka; // Add the new element and increment size
}


void Vector::push_front(const Payload& paylodochka) {
    if (size_var >= capacity_max) {
        // Double the capacity and reallocate
        capacity_max *= 2;

        Payload* new_payloads = new Payload[capacity_max];
        new_payloads[0] = paylodochka; // Insert the new element at the front of the new array
        for (int i = 0; i < size_var; ++i) {
            new_payloads[i + 1] = payloads[i]; // Correctly shift elements one position to the right
        }
        delete[] payloads; // Free the old array
        payloads = new_payloads; // Update the pointer
    } else {
        for (int i = size_var; i > 0; --i) {
            payloads[i] = payloads[i - 1]; // Shift elements to make space at the front
        }
        payloads[0] = paylodochka;
    }
    size_var++; // Increment the size after adding the new element
}


// Popback method
void Vector::pop_back() {
if (size_var > 0) {
  size_var--;
  } else {
      std::cerr << "Paylod is empty. Nothing to remove." << std::endl;
   }

}

// Popfront method
void Vector::pop_front() {

  if (size_var>0) {
  
    for (int i=0; i<size_var-1; i++){   
      payloads[i] = payloads[i+1]; 
    } 
    size_var--;
  }
  
  else {
      std::cerr << "Paylod is empty. Nothing to remove." << std::endl;
   }

}


// Size method
int Vector:: size() const {
  return size_var;
}

// print method
void Vector::print() const{
  for (int j = 0; j < size_var; ++j){
    // print the name of payloads
    payloads[j].print();
  }
}

// capacity print
int Vector::capacity() const {
    return capacity_max;
}


Payload& Vector:: operator[](int i) {
  return payloads[i];
}