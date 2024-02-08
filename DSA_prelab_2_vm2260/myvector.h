#pragma once 
#include "payload.h"

#include <iostream> // including lib for the input-output operations
using std::cout;
struct Vector {

    //Payload payloads[4]; // fixed size array of payload objects (task 2)

    Payload* payloads; // TASK 3: pointer to the array of Payloads

    int size_var; // the number of elements in the array (task 2)
    int capacity_max = 1; // the number of elements the array can hold


    Vector(); // default constructor
    ~Vector(); // destructor


    void push_back(const Payload& paylodochka); // add a new Payload to the end of the array
    void push_front(const Payload& paylodochka); // add a new Payload to the beginning of the array
    void pop_back(); // remove the last Payload from the array
    void pop_front(); // remove the first Payload from the array
    int size() const; // return the number of elements in the array;

    //show capacity
    int capacity() const; 

    //print method
    void print() const;

   // Implement an operator[](int i) in Vector that accesses the i-th element in the Vector.
    Payload& operator[](int i);
};

