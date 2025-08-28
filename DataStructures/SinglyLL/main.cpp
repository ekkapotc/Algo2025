#include <iostream>
#include <string>

#include "singly_linked_list.hpp"

int main() {
  singly_linked_list<std::string> l_str;

  l_str.add("Alice");
  l_str.add("Bob");
  l_str.add("Eve");
  l_str.add("Oscar");
  l_str.add("Alice");
  l_str.add("Mallory");

  std::cout << l_str << std::endl;

  l_str.remove("Carol");
  l_str.remove("Eve");

  std::cout << l_str << std::endl;

  l_str.remove("Alice");
  l_str.remove("Mallory");
  l_str.remove("Oscar");
  l_str.remove("Bob");
  std::cout << l_str << std::endl;

  singly_linked_list<int> l_int;
  
  l_int.add(3);
  l_int.add(10);
  l_int.add(5);
  l_int.add(2);
  l_int.add(2);
  l_int.add(10);
  l_int.add(8);

  std::cout << l_int << std::endl;

  l_int.remove(3);
  l_int.remove(8);
  l_int.remove(10);

  std::cout << l_int << std::endl;

  return 0;
}
