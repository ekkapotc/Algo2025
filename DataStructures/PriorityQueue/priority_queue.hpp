#ifndef PRIORITY_QUEUE_HPP_INC
#define PRIORITY_QUEUE_HPP_INC

#include <functional>
#include <limits>

#include "heap.hpp"
#include "priority_queue_node.hpp"

template <typename S, typename T, typename Compare = std::greater<PQNode<S, T>>>
class priority_queue {
private:
  heap<PQNode<S, T>, Compare> m_heap;
  Compare m_cmp;

public:
  priority_queue() = default;

  priority_queue(const priority_queue &other) = default;

  priority_queue(priority_queue &&other) noexcept = default;

  priority_queue &operator=(const priority_queue &other) = default;

  priority_queue &operator=(priority_queue &&other) noexcept = default;

  bool empty() const { return m_heap.empty(); }

  size_t size() const { return m_heap.size(); }

  void insert(const S &elem, T prio) {
    if constexpr (std::is_same_v<Compare, std::greater<PQNode<S, T>>>) {
      m_heap.insert(PQNode<S, T>{elem, std::numeric_limits<T>::lowest()});
      update_key(m_heap.size() - 1, prio);
    } else if constexpr (std::is_same_v<Compare, std::less<PQNode<S, T>>>) {
      m_heap.insert(PQNode<S, T>{elem, std::numeric_limits<T>::max()});
      update_key(m_heap.size() - 1, prio);
    }
  }

  void insert(S &&elem, T prio) {
    if constexpr (std::is_same_v<Compare, std::greater<PQNode<S, T>>>) {
      m_heap.insert(
          PQNode<S, T>{std::move(elem), std::numeric_limits<T>::lowest()});
      update_key(m_heap.size() - 1, prio);
    } else if constexpr (std::is_same_v<Compare, std::less<PQNode<S, T>>>) {
      m_heap.insert(
          PQNode<S, T>{std::move(elem), std::numeric_limits<T>::max()});
      update_key(m_heap.size() - 1, prio);
    }
  }

  const S root() const { return m_heap.root().get_payload(); }

  S &extract_root() { return m_heap.extract_root().get_payload(); }

  void update_key(size_t pos, const T &new_key) {
    assert(pos < size());

    if constexpr (std::is_same_v<Compare, std::greater<PQNode<S, T>>>) {

      assert(new_key >= m_heap[pos].get_priority());

      if (new_key >= m_heap[pos].get_priority())
        m_heap[pos].set_priority(new_key);

    } else if constexpr (std::is_same_v<Compare, std::less<PQNode<S, T>>>) {

      assert(new_key <= m_heap[pos].get_priority());

      if (new_key <= m_heap[pos].get_priority())
        m_heap[pos].set_priority(new_key);
    }

    while (pos > 0) {
      size_t parent = (pos - 1) / 2;

      if (m_cmp(m_heap[parent], m_heap[pos]))
        break;

      std::swap(m_heap[pos], m_heap[parent]);
      pos = parent;
    }
  }

  template <typename U, typename V, typename Comp>
  friend std::ostream &operator<<(std::ostream &os,
                                  const priority_queue<U, V, Comp> &pq);
};

template <typename U, typename V, typename Comp>
std::ostream &operator<<(std::ostream &os,
                         const priority_queue<U, V, Comp> &pq) {
  os << pq.m_heap;
  return os;
}

#endif
