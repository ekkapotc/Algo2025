#include "heap_sort.hpp"

int main(){

  std::vector<int> v = {4,6,0,2,6,10,8,3,5,8,5,6,1};

  heap_sort<int,std::less<int>> h_int{v};

  auto sorted_data = h_int.sort();
 
  std::cout << "Sorted: " << std::endl;
 
  for(size_t i{0} ; i<v.size() ; i++){
     std::cout << sorted_data[i] << ( i+1 < v.size()  ? ",":"\n");
  }
 
  return 0;
}
