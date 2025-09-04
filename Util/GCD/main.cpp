#include <iostream>

#include "gcd.hpp"

int main(){
  std::cout << "gcd(1160718174u,316258250u) = " << gcd{1160718174u,316258250u}() << std::endl;
  return 0;
}
