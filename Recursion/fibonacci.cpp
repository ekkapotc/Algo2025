#include <iostream>

unsigned long fib(unsigned long n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
  
   for(auto i{0} ; i<45 ; i++){
     std::cout << "fib(" << i << ") = " << fib(i) << std::endl;
   }

   return 0;
}
