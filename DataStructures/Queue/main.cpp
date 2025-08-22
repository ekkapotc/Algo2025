#include <iostream>
#include <tuple>

#include "queue.hpp"

int main(){

  queue<int> q_int{2};

  for(auto i{0} ; i<10 ; i++) q_int.enqueue(i);

  for(auto i{0} ; i<3 ; i++) q_int.dequeue();

  for(auto i{0} ; i<4 ; i++) q_int.enqueue(i);


  queue<std::tuple<int,int>> q_tup;
  for(auto i{0} ; i<10 ; i++) q_tup.enqueue(std::make_tuple(i,i*2));

  for(auto i{0} ; i<10 ; i++) {
      std::tuple<int,int> t = std::move(q_tup.dequeue());
      std::cout << "( " << std::get<0>(t) << " , " << std::get<1>(t) << ")" << std::endl;
  }

  for(auto i{0} ; i<5 ; i++) {
      q_tup.enqueue(std::tuple<int,int>(i,i*3));
  }

  for(auto i{0} ; i<3 ; i++) {
      std::tuple<int,int> t = std::move(q_tup.dequeue());
      std::cout << "( " << std::get<0>(t) << " , " << std::get<1>(t) << ")" << std::endl;
  }

  for(auto i{0} ; i<2 ; i++) {
      std::tuple<int,int> t = std::move(q_tup.dequeue());
      std::cout << "( " << std::get<0>(t) << " , " << std::get<1>(t) << ")" << std::endl;
  }


  return 0;
}
