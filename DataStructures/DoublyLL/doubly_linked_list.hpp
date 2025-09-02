#ifndef DOUBLY_LINKED_LIST_HPP_INC
#define DOUBLY_LINKED_LIST_HPP_INC

#include <cstddef>
#include <iostream>
#include <utility>

#include "dnode.hpp"

template <typename T>
class doubly_linked_list {
private:
    DNode<T>* m_head;
    size_t m_size;

    template <typename U>
    void add_node(U&& val) { // always insert at head
        DNode<T>* new_node = new DNode<T>(std::forward<U>(val));
        if (!m_head) { // empty list
            m_head = new_node;
            new_node->set_prev(new_node);
            new_node->set_next(new_node);
        } else { // non-empty list
            new_node->set_next(m_head);
            new_node->set_prev(m_head->get_prev());
            m_head->get_prev()->set_next(new_node);
            m_head->set_prev(new_node);
            m_head = new_node;
        }
        m_size++;
    }

    void clear() {
        if (!m_head) return;

        DNode<T>* curr = m_head;
        do {
            DNode<T>* tmp = curr;
            curr = curr->get_next();
            delete tmp;
        } while (curr != m_head);

        m_head = nullptr;
        m_size = 0;
    }

public:
    doubly_linked_list() : m_head{nullptr}, m_size{0} {}

    // Copy constructor
    doubly_linked_list(const doubly_linked_list& other) : m_head{nullptr}, m_size{0} {
        if (!other.m_head) return;

        DNode<T>* other_curr = other.m_head;
        do {
            add(other_curr->get_val());
            other_curr = other_curr->get_next();
        } while (other_curr != other.m_head);
    }

    // Move constructor
    doubly_linked_list(doubly_linked_list&& other) noexcept
        : m_head{other.m_head}, m_size{other.m_size} {
        other.m_head = nullptr;
        other.m_size = 0;
    }

    // Copy assignment
    doubly_linked_list& operator=(const doubly_linked_list& other) {
        if (this != &other) {
            clear();
            if (!other.m_head) return *this;

            DNode<T>* other_curr = other.m_head;
            do {
                add(other_curr->get_val());
                other_curr = other_curr->get_next();
            } while (other_curr != other.m_head);
        }
        return *this;
    }

    // Move assignment
    doubly_linked_list& operator=(doubly_linked_list&& other) noexcept {
        if (this != &other) {
            clear();
            m_head = other.m_head;
            m_size = other.m_size;
            other.m_head = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    ~doubly_linked_list() { clear(); }

    DNode<T>* head() { return m_head; }
    const DNode<T>* head() const { return m_head; }

    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }

    void add(const T& val) { add_node(val); }
    void add(T&& val) { add_node(std::move(val)); }

    void remove(const T& val) {
      if (!m_head) return;

      DNode<T>* curr = m_head;
      size_t visited = 0; // ensure we only loop original size times

      while (visited < m_size) {
        if (curr->get_val() == val) {
            if (curr->get_next() == curr) { // one node left
                delete curr;
                m_head = nullptr;
                m_size = 0;
                return;
            } else {
                DNode<T>* next = curr->get_next();
                DNode<T>* prev = curr->get_prev();
                prev->set_next(next);
                next->set_prev(prev);
                if (curr == m_head) m_head = next;
                delete curr;
                curr = next;
                --m_size;
                // do not increment visited
                continue;// skip to next node
            }
        }
        curr = curr->get_next();
        visited++;
      }
    }

    template <typename S>
    void remove(S&& val) {
        remove(static_cast<const T&>(val));
    }
};

#endif

