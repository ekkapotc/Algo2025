#include <iostream>
#include <tuple>
#include <string>

#include "queue.hpp"

void test_basic() {
    std::cout << "=== Basic Enqueue/Dequeue Test ===\n";
    queue<int> q(3);

    for (int i = 0; i < 5; i++) {
        q.enqueue(i);
        std::cout << "Enqueued: " << i << " | size=" << q.size()
                  << " head=" << q.head()
                  << " tail=" << q.tail() << "\n";
    }

    while (!q.empty()) {
        int x = q.dequeue();
        std::cout << "Dequeued: " << x << " | size=" << q.size() << "\n";
    }
}

void test_copy() {
    std::cout << "\n=== Copy Constructor/Assignment Test ===\n";
    queue<int> q1;
    for (int i = 0; i < 6; i++) q1.enqueue(i);

    std::cout << "Original queue head=" << q1.head() 
              << " tail=" << q1.tail()
              << " size=" << q1.size() << "\n";

    // Copy constructor
    queue<int> q2(q1);
    std::cout << "Copy constructor head=" << q2.head() 
              << " tail=" << q2.tail()
              << " size=" << q2.size() << "\n";

    // Copy assignment
    queue<int> q3;
    q3 = q1;
    std::cout << "Copy assignment head=" << q3.head() 
              << " tail=" << q3.tail()
              << " size=" << q3.size() << "\n";
}

void test_move() {
    std::cout << "\n=== Move Constructor/Assignment Test ===\n";
    queue<std::string> q1;
    for (int i = 10; i < 15; i++) q1.enqueue(i);

    // Move constructor
    queue<std::string> q2(std::move(q1));
    std::cout << "After move constructor, q2(moved in) size=" << q2.size() << " cap= " << q2.capacity() << "\n";  
    std::cout << "After move constructor, q1(moved out) size=" << q1.size() << " cap= " << q1.capacity() << "\n";
  
    // Move assignment
    queue<std::string> q3;
    q3 = std::move(q2);
    std::cout << "After move constructor, q3(moved in) size=" << q3.size() << " cap= " << q3.capacity() << "\n";  
    std::cout << "After move constructor, q2(moved out) size=" << q2.size() << " cap= " << q2.capacity() << "\n";
  
}

void test_tuples() {
    std::cout << "\n=== Tuple Test ===\n";
    queue<std::tuple<int,int>> qt;
    for (int i = 0; i < 5; i++) qt.enqueue(std::tuple<int,int>(i, i*10));

    while (!qt.empty()) {
        auto t = qt.dequeue();
        std::cout << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ")\n";
    }
}

void test_stress() {
    std::cout << "\n=== Stress/Reallocation Test ===\n";
    
    queue<int> q(2);
    for (int i = 0; i < 100; i++) q.enqueue(i);
    std::cout << "After 100 enqueues, size=" << q.size() << "\n";

    for (int i = 0; i < 90; i++) q.dequeue();
    std::cout << "After 90 dequeues, size=" << q.size() 
              << " head=" << q.head() 
              << " tail=" << q.tail() << "\n";

    for (int i = 100; i < 110; i++) q.enqueue(i);
    while (!q.empty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << "\n";
}

int main() {
    test_basic();
    test_copy();
    test_move();
    test_tuples();
    test_stress();
    return 0;
}

