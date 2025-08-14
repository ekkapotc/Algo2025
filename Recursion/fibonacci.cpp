#include <iostream>

unsigned int fib(unsigned int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
  
   for(auto i{0} ; i<20 ; i++){
     std::cout << "fib(" << i << ") = " << fib(i) << std::endl;
   }

   return 0;
}
