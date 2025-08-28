#include <iostream>
#include <string>

#include "singly_linked_list.hpp"

int main() {
  singly_linked_list<std::string> list;

  list.add("Alice");
  list.add("Bob");
  list.add("Eve");
  list.add("Oscar");
  list.add("Alice");
  list.add("Mallory");

  std::cout << list << std::endl;

  list.remove("Carol");
  list.remove("Eve");

  std::cout << list << std::endl;

  list.remove("Alice");
  list.remove("Mallory");
  list.remove("Oscar");
  list.remove("Bob");
  std::cout << list << std::endl;

  return 0;
}
