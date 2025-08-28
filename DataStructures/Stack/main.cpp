#include <iostream>
#include <string>
#include <tuple>
#include <utility>

#include "stack.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &os, const stack<T> &s) {
  for (size_t i{0}; i < s.size(); i++) {
    os << s[i] << (i + 1 < s.size() ? "," : "\n");
  }
  return os;
}

template <typename T>
void print_stack(const stack<T> &s, const std::string &msg = "") {
  std::cout << msg << " [size=" << s.size() << ", empty=" << std::boolalpha
            << s.empty() << "]: " << s << "\n";
}

int main() {

  // ==== Test with int =====

  stack<int> st_int;

  for (auto i{0}; i < 10; i++)
    st_int.push(i);

  print_stack(st_int, "Before popping all the elements off st_int");

  for (auto i{0}; i < 10; i++)
    st_int.pop();

  print_stack(st_int, "After popping all the elements off st_int");

  // ==== Test with std::string ====

  std::string dict[] = {"hello",   "bye",    "morning",
                        "welcome", "cheers", "thanks"};
  stack<std::string> st_str;

  for (auto i{0}; i < 6; i++)
    st_str.push(dict[i]);

  print_stack(st_str, "Before popping all the elements off st_str");

  stack<std::string> st_str_copy_con = st_str; // -->trigger copy constructor

  for (auto i{0}; i < 6; i++)
    st_str.pop();

  print_stack(st_str, "After popping all the elements off st_str");

  print_stack(st_str_copy_con,
              "Before popping all the elements off st_str_copy_con");

  for (auto i{0}; i < 6; i++)
    st_str_copy_con.pop();

  print_stack(st_str_copy_con,
              "After popping all the elements off st_str_copy_con");

  return 0;
}
