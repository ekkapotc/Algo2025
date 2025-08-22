#include <iostream>
#include <string>
#include <tuple>
#include <utility>

#include "stack.hpp"

int main() {

  stack<int> st_int;
  for (auto i{0}; i < 10; i++)
    st_int.push(i);
  for (auto i{0}; i < 10; i++)
    std::cout << st_int.pop() << std::endl;

  stack<std::tuple<int, int>> st_tup;
  for (auto i{0}; i < 10; i++)
    st_tup.push(std::make_tuple(i, 2 * i));
  for (auto i{0}; i < 10; i++) {
    std::tuple<int, int> t = std::move(st_tup.pop());
    std::cout << "( " << std::get<0>(t) << " , " << std::get<1>(t) << ")"
              << std::endl;
  }

  std::string dict[] = {"hello",   "bye",    "morning",
                        "welcome", "cheers", "thanks"};
  stack<std::string> st_str;
  for (auto i{0}; i < 6; i++)
    st_str.push(dict[i]);
  for (auto i{0}; i < 6; i++)
    std::cout << st_str.pop() << std::endl;

  return 0;
}
