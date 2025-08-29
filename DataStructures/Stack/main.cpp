#include <iostream>
#include <string>
#include <tuple>
#include <utility>

#include "stack.hpp"

// ===== Printing Utility =====

template <typename T>
std::ostream &operator<<(std::ostream &os, const stack<T> &s) {
    for (size_t i{0}; i < s.size(); i++) {
        os << s[i] << (i + 1 < s.size() ? "," : "");
    }
    return os;
}

template <typename T>
void print_stack(const stack<T> &s, const std::string &msg = "") {
    std::cout << msg
              << " [size=" << s.size()
              << ", empty=" << std::boolalpha << s.empty()
              << "]: " << s << "\n";
}

// ===== Tests =====

void test_basic_int() {
    std::cout << "=== Basic int push/pop test ===\n";
    stack<int> st;
    for (int i = 0; i < 10; i++) {
        st.push(i);
        std::cout << "Pushed " << i << " top=" << st.top() << "\n";
    }
    print_stack(st, "After pushes");

    while (!st.empty()) {
        std::cout << "Popped " << st.top() << "\n";
        st.pop();
    }
    print_stack(st, "After popping all");
}

void test_copy_assign() {
    std::cout << "\n=== Copy constructor & assignment test ===\n";
    stack<std::string> st;
    st.push("alpha");
    st.push("beta");
    st.push("gamma");

    st = st;// self-assignment

    // Copy constructor
    stack<std::string> st_copy(st);
    print_stack(st, "Original stack");
    print_stack(st_copy, "Copy constructed stack");

    // Copy assignment
    stack<std::string> st_assign;
    st_assign = st;
    print_stack(st_assign, "Copy assigned stack");
}

void test_move() {
    std::cout << "\n=== Move constructor & assignment test ===\n";
    stack<std::string> st;
    st.push("hello");
    st.push("world");

    // Move constructor
    stack<std::string> moved_in(std::move(st));
    print_stack(moved_in, "After move constructor (moved in)");
    print_stack(st, "After move constructor (moved out)");

    // Move assignment
    stack<std::string> st2;
    st2 = std::move(moved_in);
    print_stack(st2, "After move assignment (moved in)");
    print_stack(moved_in, "After move assignment (moved out)");
}

void test_tuple() {
    std::cout << "\n=== Tuple test ===\n";
    stack<std::tuple<int,int>> st;
    for (int i = 0; i < 5; i++)
        st.push(std::tuple{i, i*i});
    while (!st.empty()) {
        auto [a, b] = st.top();
        std::cout << "(" << a << "," << b << ")\n";
        st.pop();
    }
}

void test_stress() {
    std::cout << "\n=== Stress test (reallocation) ===\n";
    stack<int> st;
    for (int i = 0; i < 100; i++) st.push(i);
    std::cout << "Size after 100 pushes: " << st.size() << "\n";

    for (int i = 0; i < 95; i++) st.pop();
    std::cout << "Size after popping 95: " << st.size()
              << " top=" << (st.empty() ? -1 : st.top()) << "\n";
}

// ===== Main =====

int main() {
    test_basic_int();
    test_copy_assign();
    test_move();
    test_tuple();
    test_stress();
    return 0;
}

