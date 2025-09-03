#include <iostream>
#include <string>

#include "fnv1a.hpp"

int main() {
  std::string s1{"Hello World!"};
  std::string s2{"Hellow Moon!"};
  std::cout << fnv1a{s1.c_str(), s1.length()}() << std::endl;
  std::cout << fnv1a{s2.c_str(), s2.length()}() << std::endl;
  return 0;
}
