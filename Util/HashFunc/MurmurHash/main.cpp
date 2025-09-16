#include <iostream>
#include <string>

#include "murmur.hpp"

int main() {
  std::string s1{"Hello World!"};
  std::string s2{"Hello Moon!"};
  std::cout << murmur{s1.c_str(), s1.length(), 0x1F351}() << std::endl;
  std::cout << murmur{s2.c_str(), s2.length(), 0x1F351}() << std::endl;
  return 0;
}
