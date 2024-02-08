#include <iostream>

#include "myvector.h"
//#include "mylist.h" seems like this line was unnecessary

using std::cout;

int main() {
  auto showVector = [](const Vector & v)
   {
   cout << "Vector size/capacity: " << v.size() << '/' <<
  v.capacity() << '\n';
   v.print();
   cout << '\n';
   };
  {
    Vector v;
    v.push_back("apple");
    showVector(v);
    v.push_back("pear");
    showVector(v);
    v.push_back("banana");
    showVector(v);
    v.push_front("mango");
    showVector(v);
    v.push_back("avocado");
    showVector(v);
    v.pop_back();
    showVector(v);
    v.pop_front();
    showVector(v);   
   v[0].print(); 
   v[2].print(); 
  }
}