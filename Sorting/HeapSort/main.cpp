#include <string>

#include "heap_sort.hpp"

int main() {

  std::vector<int> v = {4, 6, 0, 2, 6, 10, 8, 3, 5, 8, 5, 6, 1};

  heap_sort<int, std::less<int>> h_int{v};

  auto sorted_data_int = h_int.sort();

  std::cout << "Sorted: (decreasing)" << std::endl;

  for (size_t i{0}; i < v.size(); i++) {
    std::cout << sorted_data_int[i] << (i + 1 < v.size() ? "," : "\n");
  }

  std::vector<std::string> w = {"string", "int", "char",   "bool",  "vector",
                                "float",  "map", "double", "stack", "long"};

  heap_sort<std::string> h_str{w};

  auto sorted_data_str = h_str.sort();

  std::cout << "Sorted: (increasing)" << std::endl;

  for (size_t i{0}; i < w.size(); i++) {
    std::cout << sorted_data_str[i] << (i + 1 < w.size() ? "," : "\n");
  }

  return 0;
}
