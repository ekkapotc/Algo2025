#ifndef PQNODE_HPP_INC
#define PQNODE_HPP_INC

#include <type_traits>
#include <utility>

#if __GNUC__ >= 11 && __cplusplus >= 202002L
#define REQUIRES_ARITHMETIC(T) requires std::is_arithmetic_v<T>
#else
#define REQUIRES_ARITHMETIC(T)
#endif

template <typename S, typename T> REQUIRES_ARITHMETIC(T) class PQNode {
private:
  S m_data;
  T m_prio;

public:
  PQNode() = default;

  PQNode(const S &data, const T prio) : m_data{data}, m_prio{prio} {}

  PQNode(S &&data, const T prio) : m_data{data}, m_prio{prio} {}

  S &get_data() { return m_data; }

  const S &get_data() const { return m_data; }

  void set_data(const S &new_data) { m_data = new_data; }

  void set_data(S &&new_data) { m_data = std::move(new_data); }

  T get_priority() const { return m_prio; }

  void set_priority(T new_prio) { m_prio = new_prio; }

  friend std::ostream &operator<<(std::ostream &os, const PQNode<S, T> &node) {
    os << "(data=" << node.get_data() << " , priority=" << node.get_priority()
       << ")";
    return os;
  }

  friend bool operator<=(const PQNode<S, T> &p, const PQNode<S, T> &q) {
    return p.m_prio <= q.m_prio;
  }

  friend bool operator>=(const PQNode<S, T> &p, const PQNode<S, T> &q) {
    return p.m_prio >= q.m_prio;
  }

  friend bool operator<(const PQNode<S, T> &p, const PQNode<S, T> &q) {
    return p.m_prio < q.m_prio;
  }

  friend bool operator>(const PQNode<S, T> &p, const PQNode<S, T> &q) {
    return p.m_prio > q.m_prio;
  }

  friend bool operator==(const PQNode<S, T> &p, const PQNode<S, T> &q) {
    return p.m_prio == q.m_prio;
  }

  friend bool operator!=(const PQNode<S, T> &p, const PQNode<S, T> &q) {
    return p.m_prio != q.m_prio;
  }
};

#endif
