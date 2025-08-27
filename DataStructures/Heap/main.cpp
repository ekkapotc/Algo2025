#include "heap.hpp"
#include <functional>
#include <iostream>

int main() {
  // ===== Test heap<int> construction from array =====
  int arr[] = {4, 8, 2, 0, 9, 5, 12, 32, 20, 18, 6};
  std::cout << "Testing heap<int> from array:" << std::endl;

  heap<int, std::less<int>> heap_int{arr};
  std::cout << "\tInitial size = " << heap_int.size() << std::endl;
  std::cout << "\tHeap contents: " << heap_int << std::endl;
  std::cout << "\tCurrent root = " << heap_int.root() << std::endl;

  // ===== Extract elements to test root_heapify and extract_root =====
  std::cout << "Extracting all elements:" << std::endl;
  while (!heap_int.empty()) {
    std::cout << "\tExtracted: " << heap_int.extract_root() << std::endl;
  }
  std::cout << "\tSize after extraction = " << heap_int.size() << std::endl;

  // ===== Insert elements to test insert(T) and dynamic reallocation =====
  std::cout << "Inserting elements 0..31:" << std::endl;
  for (int i = 0; i < 32; ++i) {
    heap_int.insert(i);
    std::cout << "\tInserted: " << i << std::endl;
  }
  std::cout << "\tSize after insertions = " << heap_int.size() << std::endl;
  std::cout << "\tHeap contents: " << heap_int << std::endl;

  // ===== Test heap<float> with default constructor =====
  std::cout << "\nTesting heap<float>:" << std::endl;
  heap<float> heap_flt;
  std::cout << "\tInitial size = " << heap_flt.size() << std::endl;

  for (int i = 0; i < 20; ++i) {
    float val = static_cast<float>(i) + 0.5f;
    heap_flt.insert(val);
    std::cout << "\tInserted: " << val << std::endl;
  }
  std::cout << "\tSize after insertions = " << heap_flt.size() << std::endl;
  std::cout << "\tHeap contents: " << heap_flt << std::endl;

  std::cout << "Extracting all elements from heap<float>:" << std::endl;
  while (!heap_flt.empty()) {
    std::cout << "\tExtracted: " << heap_flt.extract_root() << std::endl;
  }
  std::cout << "\tSize after extraction = " << heap_flt.size() << std::endl;

  return 0;
}
