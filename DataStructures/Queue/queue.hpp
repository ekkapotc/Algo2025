#ifndef QUEUE_HPP_INC
#define QUEUE_HPP_INC

#include <cassert>
#include <cstddef>
#include <utility>

template <typename T> class queue {
private:
  T *m_data;
  size_t m_size;
  size_t m_cap;
  size_t m_head;
  size_t m_tail;

  bool full() const { return m_size == m_cap; }

  void reallocate() {
    size_t new_cap = m_cap * 2;
    T *new_data = new T[new_cap];
    for (size_t i{0}; i < m_size; i++)
      new_data[i] = std::move(m_data[(m_head + i) % m_cap]);
    delete[] m_data;
    m_data = new_data;
    m_cap = new_cap;
    m_head = 0;
    m_tail = m_size;
  }

public:
  queue(size_t cap = 4)
      : m_data{nullptr}, m_size{0}, m_cap{cap}, m_head{0}, m_tail{0} {
    assert(cap > 0);
    m_data = new T[m_cap];
  }

  queue(const queue &other)
      : m_data{nullptr}, m_size{other.m_size}, m_cap{other.m_cap},
        m_head{other.m_head}, m_tail{other.m_tail} {
    if (m_cap > 0)
      m_data = new T[m_cap];
    for (size_t i{0}; i < m_size; i++)
      m_data[(i + m_head) % m_cap] =
          other.m_data[(i + other.m_head) % other.m_cap];
  }

  queue(queue &&other) noexcept {
    m_data = other.m_data;
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_head = other.m_head;
    m_tail = other.m_tail;

    other.m_data = nullptr;
    other.m_size = 0;
    other.m_cap = 0;
    other.m_head = 0;
    other.m_tail = 0;
  }

  queue &operator=(const queue &other) {
    if (this != &other) {
      delete[] m_data;

      m_size = other.m_size;
      m_cap = other.m_cap;
      m_head = other.m_head;
      m_tail = other.m_tail;

      if (m_cap > 0)
        m_data = new T[m_cap];

      for (size_t i{0}; i < m_size; i++)
        m_data[(i + m_head) % m_cap] =
            other.m_data[(i + other.m_head) % other.m_cap];
    }
    return *this;
  }

  queue &operator=(queue &&other) noexcept {
    if (this != &other) {
      delete[] m_data;

      m_data = other.m_data;
      m_size = other.m_size;
      m_cap = other.m_cap;
      m_head = other.m_head;
      m_tail = other.m_tail;

      other.m_data = nullptr;
      other.m_size = 0;
      other.m_cap = 0;
      other.m_head = 0;
      other.m_tail = 0;
    }
    return *this;
  }

  ~queue() { delete[] m_data; }

  bool empty() const { return m_size == 0; }

  size_t size() const { return m_size; }

  template <typename S> void enqueue(S &&elem) {
    if (full())
      reallocate();
    m_data[m_tail] = std::forward<S>(elem);
    m_tail = (m_tail + 1) % m_cap;
    m_size++;
  }

  T dequeue() {
    assert(m_size > 0);
    T first = std::move(m_data[m_head]);
    m_head = (m_head + 1) % m_cap;
    m_size--;
    return first;
  }

  T &head() {
    assert(m_size > 0);
    return m_data[m_head];
  }

  const T &head() const {
    assert(m_size > 0);
    return m_data[m_head];
  }

  T &tail() {
    assert(m_size > 0);
    return m_data[(m_tail + m_cap - 1) % m_cap];
  }

  const T &tail() const {
    assert(m_size > 0);
    return m_data[(m_tail + m_cap - 1) % m_cap];
  }
};

#endif
