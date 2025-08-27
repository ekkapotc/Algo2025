#include <iostream>
#include <string>

#include "priority_queue.hpp"

int main() {
  priority_queue<std::string, double, std::greater<PQNode<std::string, double>>>
      pq_sd;
  pq_sd.insert("Bosco", 1.0);
  pq_sd.insert("Liz", 4.5);
  pq_sd.insert("Hideyuki", 2.2);
  pq_sd.insert("Simon", 7.0);
  pq_sd.insert("Mickey", 2.3);

  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  priority_queue<std::string, double> pq_sd_copy{std::move(pq_sd)};

  std::cout << "\tExtracted : " << pq_sd_copy.extract_root() << std::endl;

  std::cout << "Priority Queue content : " << pq_sd_copy << std::endl;

  pq_sd_copy.insert("Adam", 5.0);

  std::cout << "\tInserted (payload=Adam , priority=5.0)" << std::endl;

  pq_sd_copy.insert("Jennie", 6.1);

  std::cout << "\tInserted (payload=Jennie , priority=6.1)" << std::endl;

  std::cout << "Priority Queue content : " << pq_sd_copy << std::endl;

  while (!pq_sd_copy.empty()) {
    std::cout << "\tExtracted : " << pq_sd_copy.extract_root() << std::endl;
  }

  std::cout << "Priority Queue content : " << pq_sd_copy << std::endl;

  pq_sd_copy.insert("Araya", 4.2);

  std::cout << "\tInserted (payload=Araya , priority=4.2)" << std::endl;

  pq_sd = pq_sd_copy;

  std::cout << "Priority Queue content : " << pq_sd << std::endl;

  return 0;
}
