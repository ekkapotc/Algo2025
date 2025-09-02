#ifndef DNODE_HPP_INC
#define DNODE_HPP_INC

#include <iostream>
#include <utility>

template <typename T> class DNode {
private:
  DNode<T> *m_prev;
  DNode<T> *m_next;
  T m_val;

public:
  /*
  Make explicit to prevent implicit conversions
  */
  explicit DNode(const T &val) :m_prev{nullptr}, m_next{nullptr}, m_val{val} {}

  /*
  Make explicit to prevent implicit conversions
  */
  explicit DNode(T &&val) : m_prev{nullptr}, m_next{nullptr}, m_val{std::move(val)} {}

  /*
  Disable copy constructor and copy assignment operator
  */
  DNode(const DNode<T> &) = delete;
  DNode &operator=(const DNode<T> &) = delete;

  /*
  Disable move constructor and move assignment operator
  */
  DNode(DNode<T> &&other) = delete;
  DNode &operator=(DNode<T> &&other) = delete;

  T &get_val() { return m_val; }

  const T &get_val() const { return m_val; }
  
  DNode<T> *get_prev() { return m_prev; }

  const DNode<T> *get_prev() const { return m_prev; }

  DNode<T> *get_next() { return m_next; }

  const DNode<T> *get_next() const { return m_next; }

  void set_prev(DNode<T> *prev) { m_prev = prev; }

  void set_next(DNode<T> *next) { m_next = next; }
};

#endif
