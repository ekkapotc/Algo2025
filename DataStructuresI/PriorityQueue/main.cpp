#include <iostream>

#include "heap.hpp"

int main(){
  int arr [] = {4,8,2,0,9,5,12,32,20,18,6};
  heap<int> heap_int{arr,10};
  std::cout << heap_int << std::endl;
  std::cout << "max = " << heap_int.max() << std::endl;
  return 0;
}
