#ifndef MURMUR_HPP_INC
#define MURMUR_HPP_INC

#include <cassert>
#include <cstdint>
#include <cstring>

#include "rot.hpp"

class murmur {
private:
  bool m_ready;
  uint32_t m_hash;

public:
  murmur() = delete;

  murmur(const murmur &other) = delete;

  murmur(murmur &&other) = delete;

  murmur operator=(const murmur &other) = delete;

  murmur operator=(murmur &&other) = delete;

  murmur(const void *key, size_t len, uint32_t seed)
      : m_ready{false}, m_hash{0} {
    const uint8_t *k = static_cast<const uint8_t *>(
        key);                       // cast const void * to const uint8_t *
    const size_t nblocks = len / 4; // one block is 4 bytes long
    m_hash = seed;

    constexpr uint32_t c1 = 0xcc9e2d51;
    constexpr uint32_t c2 = 0x1b873593;

    for (size_t i{0}; i < nblocks; i++) {
      uint32_t k1;
      std::memcpy(&k1, k + 4 * i, 4);
      k1 *= c1;
      k1 = rotl<uint32_t>{}(k1, 15);
      k1 *= c2;
      m_hash ^= k1;
      m_hash = rotl<uint32_t>{}(m_hash, 13);
      m_hash = m_hash * 5 + 0xe6546b64;
    }

    uint32_t k1 = 0;
    const size_t remaining = len % 4;
    if (remaining >= 3)
      k1 ^= (k[len - 3] << 16);
    if (remaining >= 2)
      k1 ^= (k[len - 2] << 8);
    if (remaining >= 1) {
      k1 ^= k[len - 1];
      k1 *= c1;
      k1 = rotl<uint32_t>{}(k1, 15);
      k1 *= c2;
      m_hash ^= k1;
    }

    m_hash ^= len;
    m_hash ^= (m_hash >> 16);
    m_hash *= 0x85ebca6b;
    m_hash ^= (m_hash >> 13);
    m_hash *= 0xc2b2ae35;
    m_hash ^= (m_hash >> 16);

    m_ready = true;
  }

  bool ready() const { return m_ready; }

  uint32_t operator()() const {
    assert(m_ready);
    return m_hash;
  }
};

#endif
