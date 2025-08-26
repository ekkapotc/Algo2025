#include <iostream>

#include "heap.hpp"

int main() {
  int arr[] = {4, 8, 2, 0, 9, 5, 12, 32, 20, 18, 6};

  std::cout << "heap<int>:" << std::endl;

  heap<int> heap_int{arr};

  std::cout << "\t size = " << heap_int.size() << std::endl;

  std::cout << heap_int << std::endl;

  while (!heap_int.empty()) {
    std::cout << "Extracting " << heap_int.extract_max() << std::endl;
  }

  std::cout << "\t size = " << heap_int.size() << std::endl;

  for (auto i{0}; i < 32; i++) {
    heap_int.insert(i);
    std::cout << "Inserting " << i << std::endl;
  }

  std::cout << "\t size = " << heap_int.size() << std::endl;

  std::cout << "heap<float>:" << std::endl;

  heap<float> heap_flt;

  std::cout << "\t size = " << heap_flt.size() << std::endl;

  for (auto i{0}; i < 20; i++) {
    float new_elem;
    heap_flt.insert(new_elem = static_cast<float>(i));
    std::cout << "Inserting " << new_elem << std::endl;
  }

  std::cout << "\t size = " << heap_flt.size() << std::endl;

  while (!heap_flt.empty()) {
    std::cout << "Extracting " << heap_flt.extract_max() << std::endl;
  }

  std::cout << "\t size = " << heap_flt.size() << std::endl;

  return 0;
}
