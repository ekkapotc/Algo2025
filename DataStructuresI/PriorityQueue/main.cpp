#include <iostream>

#include "heap.hpp"

int main(){
  int arr [] = {4,8,2,0,9,5,12,20,18,6};
  heap<int> heap_int{arr,10};
  std::cout << heap_int << std::endl;
  return 0;
}
