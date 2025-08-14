#include <iostream>

int add(int m , int n){
   if(m==0) return n;
   if(m>0) return add(m-1,n+1);
   return add(m+1,n-1);
}

int main(){
   std::cout << "add(5,3) = " << add(5,3) << std::endl;
   std::cout << "add(3,5) = " << add(3,5) << std::endl;
   std::cout << "add(-2,-3) = " << add(-2,-3) << std::endl;
   std::cout << "add(5,0) = " << add(5,0) << std::endl;
   return 0;
}
