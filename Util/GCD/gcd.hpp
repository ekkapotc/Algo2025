#ifndef GCD_HPP_INC
#define GCD_HPP_INC

#include <cassert>

#if __GNUC__ >= 11 && __cplusplus >= 202002L
#define REQUIRES_INTEGRAL(T) requires std::is_integral_v<T>
#else
#define REQUIRES_INTEGRAL(T)
#endif

template <typename T> REQUIRES_INTEGRAL(T) class gcd {
private:
  bool m_ready;
  T m_a;
  T m_b;

public:
  gcd() = delete;

  gcd(const gcd &other) = delete;

  gcd(gcd &&other) = delete;

  gcd operator=(const gcd &other) = delete;

  gcd operator=(gcd &&other) = delete;

  gcd(const T &a, const T &b) : m_ready{false}, m_a{a}, m_b{b} {
    if (m_a < 0)
      m_a = -m_a;
    if (m_b < 0)
      m_b = -m_b;
    m_ready = true;
  }

  gcd(T &&a, T &&b) : m_ready{false}, m_a{a}, m_b{b} {
    if (m_a < 0)
      m_a = -m_a;
    if (m_b < 0)
      m_b = -m_b;
    m_ready = true;
  }

  T operator()() {
    assert(m_ready);
    if (!m_a || !m_b)
      return 0;
    while (m_b > 0) {
      T r = m_a % m_b;
      m_a = m_b;
      m_b = r;
    }
    return m_a;
  }
};

#endif
