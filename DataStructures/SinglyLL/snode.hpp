#ifndef SNODE_HPP_INC
#define SNODE_HPP_INC

#include <iostream>
#include <utility>

template <typename T> class SNode {
private:
  SNode<T> *m_next;
  T m_val;

public:
  /*
  Make explicit to prevent implicit conversions
  */
  explicit SNode(const T &val) : m_next{nullptr}, m_val{val} {}

  /*
  Make explicit to prevent implicit conversions
  */
  explicit SNode(T &&val) : m_next{nullptr}, m_val{std::move(val)} {}

  /*
  Disable copy constructor and copy assignment operator
  */
  SNode(const SNode<T> &) = delete;
  SNode &operator=(const SNode<T> &) = delete;

  /*
  Disable move constructor and move assignment operator
  */
  SNode(SNode<T> &&other) = delete;
  SNode &operator=(SNode<T> &&other) = delete;

  T &get_val() { return m_val; }

  const T &get_val() const { return m_val; }

  SNode<T> *get_next() { return m_next; }

  const SNode<T> *get_next() const { return m_next; }

  void set_next(SNode<T> *next) { m_next = next; }
};

#endif
