#ifndef ROT_HPP_INC
#define ROT_HPP_INC

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

template <typename T> struct rotl {

  static_assert(std::is_unsigned<T>::value, "rotl requires T to be unsigned!");

  T operator()(T x, T r) const {
    constexpr uint32_t N = std::numeric_limits<T>::digits;
    r = r % N;
    return (x << r) | (x >> (N - r));
  }
};

template <typename T> struct rotr {

  static_assert(std::is_unsigned<T>::value, "rotr requires T to be unsigned!");

  T operator()(T x, T r) const {
    constexpr uint32_t N = std::numeric_limits<T>::digits;
    r = r % N;
    return (x >> r) | (x << (N - r));
  }
};

#endif
