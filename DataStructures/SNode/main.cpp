#include <iostream>
#include <string>

#include "snode.hpp"

int main() {
  SNode<int> ni1{3};
  SNode<int> ni2{4};
  // SNode<int> ni3 = ni2; //since the copy constructor is deleted, this will
  // trigger a compiler error SNode<int> ni4{5}; ni4 = ni1; //since the copy
  // assignment operator is deleted, this will trigger a compiler error
  ni1.set_next(&ni2);

  std::string s1{"world"};

  SNode<std::string> ns1{"hello"};
  SNode<std::string> ns2{s1};
  ns1.set_next(&ns2);

  return 0;
}
