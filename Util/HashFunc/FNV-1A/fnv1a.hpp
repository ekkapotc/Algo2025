#ifndef FNV1A_HPP_INC
#define FNV1A_HPP_INC

#include <cassert>
#include <cstdint>

class fnv1a {
private:
  static constexpr uint32_t Prime = 16777619u;
  static constexpr uint32_t Base = 2166136261u;

  bool m_ready;
  uint32_t m_hash;

public:
  fnv1a() = delete;

  fnv1a(const fnv1a &other) = delete;

  fnv1a(fnv1a &&other) = delete;

  fnv1a operator=(const fnv1a &other) = delete;

  fnv1a operator=(fnv1a &&other) = delete;

  fnv1a(const void *key, size_t len) : m_ready{false}, m_hash{fnv1a::Base} {

    const uint8_t *byte = static_cast<const uint8_t *>(key);

    for (size_t i = 0; i < len; i++) {
      m_hash ^= byte[i];
      m_hash *= fnv1a::Prime;
    }

    m_ready = true;
  }

  bool ready() const { return m_ready; }

  uint32_t operator()() const {
    assert(m_ready);
    return m_hash;
  }
};

#endif
