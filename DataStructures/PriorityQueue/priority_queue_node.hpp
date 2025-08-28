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
  S m_payload;
  T m_prio;

public:
  PQNode() = default;

  PQNode(const S &payload, const T prio) : m_payload{payload}, m_prio{prio} {}

  PQNode(S &&payload, const T prio) : m_payload{payload}, m_prio{prio} {}

  PQNode(const PQNode &) = default;

  PQNode(PQNode &&) noexcept = default;

  PQNode &operator=(const PQNode &) = default;

  PQNode &operator=(PQNode &&) noexcept = default;

  S &get_payload() { return m_payload; }

  const S &get_payload() const { return m_payload; }

  void set_payload(const S &new_payload) { m_payload = new_payload; }

  void set_payload(S &&new_payload) { m_payload = std::move(new_payload); }

  T get_priority() const { return m_prio; }

  void set_priority(T new_prio) { m_prio = new_prio; }
 
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
