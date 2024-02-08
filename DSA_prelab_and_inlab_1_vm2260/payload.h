#pragma once

#include <string>

using std::string;

struct Payload // define Payload structure 
{
    static int counter; // static variable to keep track of number of objects created
    int id; // id of the object
    string name; // name of the object

// Constructor with default arguments
    Payload(string n = "") : id(++counter), name(n) { say_born(); }
//Destructor
    ~Payload() { say_die(); }

// Constructor taking a C-style string
    Payload(const char * n) : Payload(string(n)) {}

// Copy Constructor
    Payload(const Payload & x) : id(++counter), name(x.name) { say_born(); }

// Move Constructor
    Payload(Payload && x) : id(++counter), name(x.name) { say_born(); } 

// Copy Assignment Operator
    void operator=(const Payload & x) { name = x.name; }

// Member function to print a message when an object is born
    void say_born() const;
// Member function to print a message when an object dies
    void say_die() const;
// Method to print the object’s data
    void print() const;
};
