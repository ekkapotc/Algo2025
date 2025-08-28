#include <iostream>
#include <string>
#include <utility>  // for std::move

#include "singly_linked_list.hpp"

template <typename T>
void print_list(const singly_linked_list<T> &list,
                const std::string &msg = "") {
  std::cout << msg << " [size=" << list.size()
            << ", empty=" << std::boolalpha << list.empty() << "]: "
            << list << "\n";
}

singly_linked_list<std::string> make_list() {
  singly_linked_list<std::string> l;
  l.add("Carol");
  l.add("Eve");
  l.add("Carol");
  return l;   // returned as rvalue -> triggers move constructor
}

int main() {
  // ==== Test with strings ====
  singly_linked_list<std::string> l_str;
  l_str.add("Alice");
  l_str.add("Bob");
  l_str.add("Eve");
  l_str.add("Oscar");
  l_str.add("Alice");
  l_str.add("Mallory");

  print_list(l_str, "Initial string list");

  // Removing a non-existent element
  l_str.remove("Carol");
  print_list(l_str, "After removing Carol (not present)");

  // Removing existing elements
  l_str.remove("Eve");
  print_list(l_str, "After removing Eve");

  l_str.remove("Alice"); // removes all "Alice"
  l_str.remove("Mallory");
  l_str.remove("Oscar");
  l_str.remove("Bob");
  print_list(l_str, "After removing Alice, Mallory, Oscar, Bob");

  // ==== Test with move constructor ====
  singly_linked_list<std::string> l_str_move_con = make_list();
  print_list(l_str_move_con, "Move-constructed list from make_list()");

  // Move source should be empty after move construction
  singly_linked_list<std::string> l_str_temp = make_list();
  print_list(l_str_temp, "Before moving from l_str_temp");
  singly_linked_list<std::string> l_str_moved_to(std::move(l_str_temp));
  print_list(l_str_moved_to, "After move-constructing into l_str_moved_to");
  print_list(l_str_temp, "l_str_temp after being moved from (should be empty)");

  // ==== Test with move assignment ====
  singly_linked_list<std::string> l_str_move_asm;
  l_str_move_asm.add("Alice");
  l_str_move_asm.add("Carol");
  print_list(l_str_move_asm, "Before move assignment");

  l_str_move_asm = std::move(l_str_move_con); // --> will trigger move assignment
  print_list(l_str_move_asm, "After move assignment from l_str_move_con");
  print_list(l_str_move_con, "l_str_move_con after being moved from (should be empty)");

  // ==== Test with integers ====
  singly_linked_list<int> l_int;
  l_int.add(3);
  l_int.add(10);
  l_int.add(5);
  l_int.add(2);
  l_int.add(2);
  l_int.add(10);
  l_int.add(8);

  print_list(l_int, "Initial int list");

  l_int.remove(3);
  l_int.remove(8);
  l_int.remove(10); // removes all 10s
  print_list(l_int, "After removing 3, 8, and 10");

  // ==== Test copy constructor ====
  singly_linked_list<int> l_int_copy_con{l_int};
  print_list(l_int_copy_con, "Copy-constructed list from l_int");

  // ==== Test copy assignment ====
  singly_linked_list<int> l_int_copy_asm;
  l_int_copy_asm = l_int;
  print_list(l_int_copy_asm, "Copy-assigned list from l_int");

  return 0;
}

