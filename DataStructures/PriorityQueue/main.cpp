#include "priority_queue.hpp"
#include <cassert>
#include <iostream>
#include <string>

template <typename U, typename V>
std::ostream &operator<<(std::ostream &os, const PQNode<U, V> &node) {
  os << "(payload=" << node.get_payload()
     << " , priority=" << node.get_priority() << ")";
  return os;
}

template <typename T, typename Comp>
std::ostream &operator<<(std::ostream &os, const heap<T, Comp> &h) {
  for (size_t i{0}; i < h.size(); i++) {
    os << h[i] << (i + 1 < h.size() ? " " : "");
  }
  return os;
}

template <typename U, typename V, typename Comp>
std::ostream &operator<<(std::ostream &os,
                         const priority_queue<U, V, Comp> &pq) {
  os << pq.get_heap();
  return os;
}

int main() {
  std::cout << "=== Testing MAX-HEAP (default) ===\n";
  priority_queue<std::string, double> max_pq;

  max_pq.insert("Bosco", 1.0);
  max_pq.insert("Liz", 4.5);
  max_pq.insert("Hideyuki", 2.2);
  max_pq.insert("Simon", 7.0);
  max_pq.insert("Mickey", 2.3);

  std::cout << "Content (max-heap): " << max_pq << "\n";
  std::cout << "Max element (peek): " << max_pq.root() << "\n\n";

  // Test extract_root
  std::cout << "Extracting all elements:\n";
  while (!max_pq.empty()) {
    std::cout << "\tExtracted: " << max_pq.extract_root() << "\n";
  }
  std::cout << "Heap empty? " << std::boolalpha << max_pq.empty() << "\n\n";

  // Test copy + move
  std::cout << "=== Testing Copy & Move Semantics ===\n";
  max_pq.insert("Adam", 5.0);
  max_pq.insert("Jennie", 6.1);
  std::cout << "Original: " << max_pq << "\n";

  priority_queue<std::string, double> copy_pq{max_pq};
  std::cout << "Copy constructed: " << copy_pq << "\n";

  priority_queue<std::string, double> move_pq{std::move(copy_pq)};
  std::cout << "Move constructed: " << move_pq << "\n";
  std::cout << "Copy after move (should be empty): " << copy_pq << "\n\n";

  // Test assignment
  priority_queue<std::string, double> assign_pq;
  assign_pq = move_pq;
  std::cout << "Assigned from move_pq: " << assign_pq << "\n\n";

  // Test increase_key
  std::cout << "=== Testing increase_key ===\n";
  assign_pq.insert("Amuro", 0.5);
  std::cout << "Before increase: " << assign_pq << "\n";
  assign_pq.update_key(assign_pq.size() - 1, 10.0); // bump up "Amuro"
  std::cout << "After increase: " << assign_pq << "\n\n";

  // Test MIN-HEAP
  std::cout << "=== Testing MIN-HEAP ===\n";
  priority_queue<std::string, double, std::less<PQNode<std::string, double>>>
      min_pq;
  min_pq.insert("Bosco", 1.0);
  min_pq.insert("Liz", 4.5);
  min_pq.insert("Hideyuki", 2.2);
  min_pq.insert("Simon", 7.0);
  min_pq.insert("Mickey", 2.3);

  std::cout << "Content (min-heap): " << min_pq << "\n";
  std::cout << "Extracting all (min order):\n";
  while (!min_pq.empty()) {
    std::cout << "\tExtracted: " << min_pq.extract_root() << "\n";
  }

  std::cout << "\nAll tests complete.\n";
  return 0;
}
