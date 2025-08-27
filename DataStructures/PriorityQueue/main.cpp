#include <iostream>
#include <string>

#include "priority_queue.hpp"

int main() {
  priority_queue<std::string, double, std::less<PQNode<std::string, double>>>
      pq_sd;
  pq_sd.insert("Bosco", 1.0);
  pq_sd.insert("Liz", 4.5);
  pq_sd.insert("Hideyuki", 2.2);
  pq_sd.insert("Simon", 7.0);
  pq_sd.insert("Mickey", 2.3);

  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  std::cout << "\tExtracted : " << pq_sd.extract_root() << std::endl;

  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  pq_sd.insert("Adam", 5.0);

  std::cout << "\tInserted (data=Adam , priority=5.0)" << std::endl;

  pq_sd.insert("Jennie", 6.1);

  std::cout << "\tInserted (data=Jennie , priority=6.1)" << std::endl;

  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  while (!pq_sd.empty()) {
    std::cout << "\tExtracted : " << pq_sd.extract_root() << std::endl;
  }

  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  return 0;
}
