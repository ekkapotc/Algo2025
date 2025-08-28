#ifndef STACK_HPP_INC
#define STACK_HPP_INC

#include <cassert>
#include <cstddef>
#include <utility>

template <typename T> class stack {
private:
  T *m_data;
  size_t m_size;
  size_t m_cap;

  bool full() const { return m_size == m_cap; }

  void reallocate() {
    size_t new_cap = 2 * m_cap;
    T *new_data = new T[new_cap];
    for (size_t i{0}; i < m_size; i++)
      new_data[i] = std::move(m_data[i]);
    delete[] m_data;
    m_data = new_data;
    m_cap = new_cap;
  }

public:
  stack(size_t cap = 4) : m_data{nullptr}, m_size{0}, m_cap{cap} {
    assert(cap > 0);
    m_data = new T[m_cap];
  }

  stack(const stack &other) {
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_data = nullptr;

    if (m_cap > 0)
      m_data = new T[m_cap];

    for (size_t i{0}; i < m_size; i++)
      m_data[i] = other.m_data[i];
  }

  stack &operator=(const stack &other) {
    if (this != &other) {
      delete[] m_data;
      m_size = other.m_size;
      m_cap = other.m_cap;
      m_data = nullptr;

      if (m_cap > 0)
        m_data = new T[m_cap];

      for (size_t i{0}; i < m_size; i++)
        m_data[i] = other.m_data[i];
    }
    return *this;
  }

  stack(stack &&other) noexcept {
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_data = other.m_data;

    other.m_size = 0;
    other.m_cap = 0;
    other.m_data = nullptr;
  }

  stack &operator=(stack &&other) noexcept {
    if (this != &other) {
      delete[] m_data;
      m_size = other.m_size;
      m_cap = other.m_cap;
      m_data = other.m_data;

      other.m_size = 0;
      other.m_cap = 0;
      other.m_data = nullptr;
    }
    return *this;
  }

  ~stack() { delete[] m_data; }

  bool empty() const { return m_size == 0; }

  size_t size() const { return m_size; }

  /*
  void push(const T &elem) {
    if (full())
      reallocate();
    m_data[m_size] = elem;
    m_size++;
  }

  void push(T &&elem) {
    if (full())
      reallocate();
    m_data[m_size] = std::move(elem);
    m_size++;
  }*/

  template <typename S> void push(S &&elem) {
    if (full())
      reallocate();
    m_data[m_size] = std::forward<S>(elem);
    m_size++;
  }

  T &top() {
    assert(m_size > 0);
    return m_data[m_size - 1];
  }

  T pop() {
    assert(m_size > 0);
    m_size--;
    return std::move(m_data[m_size]);
  }

  T &operator[](size_t index) {
    assert(index >= 0 && index < m_size);
    return m_data[index];
  }

  const T &operator[](size_t index) const {
    assert(index >= 0 && index < m_size);
    return m_data[index];
  }
};

#endif
