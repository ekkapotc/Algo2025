#include <iostream>
#include <string>
#include "singly_linked_list.hpp"

template <typename T>
void print_list(const singly_linked_list<T>& list, const std::string& msg = "") {
    std::cout << msg << " [size=" << list.size() 
              << ", empty=" << std::boolalpha << list.empty() << "]: "
              << list << "\n";
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

