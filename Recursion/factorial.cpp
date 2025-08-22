#include <iostream>

unsigned long fac(unsigned long n){
   if(n==0) return 1;
   return n*fac(n-1);
}

int main(){
  for(auto i{0} ; i<20 ; i++){
    std::cout << "fac( " << i << ") = " << fac(i) << std::endl;
  }
  return 0;
}
