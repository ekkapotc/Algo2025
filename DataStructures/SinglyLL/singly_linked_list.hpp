#ifndef SINGLY_LINKED_LIST_HPP_INC
#define SINGLY_LINKED_LIST_HPP_INC

#include <cstddef>
#include <iostream>

#include "snode.hpp"

template <typename T> class singly_linked_list {
private:
  SNode<T> *m_head;

  size_t m_size;

  template <typename U> void add_node(U &&val) {
    SNode<T> *new_node = new SNode<T>(std::forward<U>(val));
    if (!m_head) {
      m_head = new_node;
    } else {
      SNode<T> *curr = m_head;
      while (curr->get_next()) {
        curr = curr->get_next();
      }
      curr->set_next(new_node);
    }
    m_size++;
  }

public:
  singly_linked_list() : m_head{nullptr}, m_size{0} {}

  singly_linked_list(const singly_linked_list &other)
      : m_head{nullptr}, m_size{other.m_size} {
    SNode<T> *other_curr = other.m_head;
    SNode<T> *this_curr = nullptr;
    while (other_curr) {
      SNode<T> *new_node = new SNode<T>(other_curr->get_val());
      if (other_curr == other.m_head) { // first node
        m_head = new_node;
      } else { // some node in the middle
        this_curr->set_next(new_node);
      }

      this_curr = new_node;
      other_curr = other_curr->get_next();
    }
  }

  singly_linked_list(singly_linked_list &&other) noexcept {
    m_size = other.m_size;
    m_head = other.m_head;
    other.m_size = 0;
    other.m_head = nullptr;
  }

  singly_linked_list &operator=(const singly_linked_list &other) {
    if (this != &other) {
      SNode<T> *other_curr = other.m_head;
      SNode<T> *this_curr = nullptr;
      while (other_curr) {
        SNode<T> *new_node = new SNode<T>(other_curr->get_val());
        if (other_curr == other.m_head) { // first node
          m_head = new_node;
        } else { // some node in the middle
          this_curr->set_next(new_node);
        }
        this_curr = new_node;
        other_curr = other_curr->get_next();
      }
      m_size = other.m_size;
    }

    return *this;
  }

  singly_linked_list &operator=(singly_linked_list &&other) noexcept {
    if (this != &other) {

      SNode<T> *curr = m_head;

      while (curr) {
        SNode<T> *tmp = curr;
        curr = curr->get_next();
        delete tmp;
      }

      m_size = other.m_size;
      m_head = other.m_head;

      other.m_size = 0;
      other.m_head = nullptr;
    }
    return *this;
  }

  ~singly_linked_list() {
    SNode<T> *curr = m_head;
    while (curr) {
      SNode<T> *tmp = curr;
      curr = curr->get_next();
      delete tmp;
    }
  }

  size_t size() const { return m_size; }

  bool empty() const { return m_size == 0; }

  void add(const T &val) { add_node(val); }

  void add(T &&val) { add_node(std::move(val)); }

  void remove(const T &val) {
    SNode<T> *curr = m_head;
    SNode<T> *prev = nullptr;

    while (curr) {

      if (curr->get_val() == val) {
        // case I: curr=first node
        if (curr == m_head) {
          m_head = curr->get_next();
          delete curr;
          curr = m_head;
          prev = nullptr;
        } else { // case II: curr=some node in the middle
          prev->set_next(curr->get_next());
          SNode<T> *tmp = curr;
          curr = curr->get_next();
          delete tmp;
        }
        m_size--;
      } else {
        prev = curr;
        curr = curr->get_next();
      }
    }
  }

  template <typename S> void remove(S &&val) {
    remove(static_cast<const T &>(val));
  }

  template <typename S>
  friend std::ostream &operator<<(std::ostream &os,
                                  const singly_linked_list<S> &l);
};

template <typename S>
std::ostream &operator<<(std::ostream &os, const singly_linked_list<S> &l) {
  SNode<S> *curr = l.m_head;
  os << "size : " << l.size() << std::endl;
  while (curr) {
    os << curr->get_val() << (curr->get_next() ? " , " : "");
    curr = curr->get_next();
  }
  return os;
}

#endif
