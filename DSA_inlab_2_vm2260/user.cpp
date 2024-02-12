#include <iostream>
#include "myvector.h"
#include "mylist.h"
using std::cout;

int main()
{
  auto showList = [](const List & s)
  {
      cout << "List size: " << s.size() << '\n';
      s.print(); cout << '\n';
  };

      List s;
      s.pop_back();
      showList(s);
      s.push_front("apple");
      s.push_front("pear");
      s.push_front("banana");
      showList(s);
      s.pop_front();
      showList(s);
      s.push_back("orange");
      showList(s);
      s.push_back("grape");
      showList(s);
      s.pop_back();
      showList(s);
      s.pop_back();
      showList(s);
      s[0].print();
      s[1].print();
      s[2].print(); // should throw an error
}