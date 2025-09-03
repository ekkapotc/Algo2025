#include <iostream>
#include <string>

#include "insertion_sort.hpp"

int main() {

  std::vector<int> v = {4, 6, 0, 2, 6, 10, 8, 3, 5, 8, 5, 6, 1};

  insertion_sort<int> i_int{v};

  auto sorted_data_int = i_int.sort();

  std::cout << "Sorted: (decreasing)" << std::endl;

  for (size_t i{0}; i < v.size(); i++) {
    std::cout << sorted_data_int[i] << (i + 1 < v.size() ? "," : "\n");
  }

  std::vector<std::string> w = {"string", "int", "char",   "bool",  "vector",
                                "float",  "map", "double", "stack", "long"};

  insertion_sort<std::string> i_str{w};

  auto sorted_data_str = i_str.sort();

  std::cout << "Sorted: (increasing)" << std::endl;

  for (size_t i{0}; i < w.size(); i++) {
    std::cout << sorted_data_str[i] << (i + 1 < w.size() ? "," : "\n");
  }

  sorted_data_str[4] = std::string{"array"};

  sorted_data_str = i_str.sort();

  std::cout << "ReSorted: (increasing)" << std::endl;

  for (size_t i{0}; i < w.size(); i++) {
    std::cout << sorted_data_str[i] << (i + 1 < w.size() ? "," : "\n");
  }

  return 0;
}
