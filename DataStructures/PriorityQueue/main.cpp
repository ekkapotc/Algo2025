#include <string>
#include <iostream>

#include "priority_queue.hpp"

int main(){
  priority_queue<std::string,double> pq_sd;
  pq_sd.insert("Bosco",1.0);
  pq_sd.insert("Liz",4.0);
  pq_sd.insert("Hideyuki",2.0);
  pq_sd.insert("Simon",7.0);
  pq_sd.insert("Mickey",2.0);
  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  while(!pq_sd.empty()){
    std::cout << "\tExtracted : " << pq_sd.extract_max() << std::endl;
  }

  return 0;
}


