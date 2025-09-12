#ifndef INSERTION_SORT_HPP_INC
#define INSERTION_SORT_HPP_INC

#include <cassert>
#include <functional>
#include <utility>
#include <vector>

template <typename T> using IncOrd = std::greater<T>;

template <typename T> using DecOrd = std::less<T>;

template <typename T, typename Compare = IncOrd<T>> class insertion_sort {
private:
  T *m_data;
  size_t m_len;
  Compare m_cmp;

public:
  insertion_sort(const T *arr, size_t len) : m_data{nullptr}, m_len{len} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = arr[i];
  }

  insertion_sort(std::vector<T> &vec) : m_data{nullptr}, m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = vec[i];
  }

  insertion_sort(std::vector<T> &&vec) : m_data{nullptr}, m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = std::move(vec[i]);
  }

  insertion_sort(const insertion_sort &other) = delete;

  insertion_sort(insertion_sort &&other) = delete;

  insertion_sort operator=(const insertion_sort &other) = delete;

  insertion_sort operator=(insertion_sort &&other) = delete;

  ~insertion_sort() { delete[] m_data; }

  T *sort() {
    if (m_data) {
      for (size_t i{1}; i < m_len; i++) {
        T key = m_data[i];
        size_t k = i;
        while (k > 0 && m_cmp(m_data[k - 1], key)) {
          std::swap(m_data[k - 1], m_data[k]);
          k--;
        }
      }
    }

    return m_data;
  }
};

#endif
