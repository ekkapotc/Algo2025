#ifndef MERGE_SORT_HPP_INC
#define MERGE_SORT_HPP_INC

#include <cassert>
#include <functional>
#include <utility>
#include <vector>

template <typename T> using IncOrd = std::greater<T>;

template <typename T> using DecOrd = std::less<T>;

template <typename T, typename Compare = IncOrd<T>> class merge_sort {
private:
  T *m_data;
  T *m_temp; // scratch temporary buffer
  size_t m_len;
  Compare m_cmp;

  void sort(size_t p, size_t r) {
    if (p < r) {
      size_t q = (p + r) / 2;
      sort(p, q);
      sort(q + 1, r);
      merge(p, q, r);
    }
  }

  void merge(size_t p, size_t q, size_t r) {

    size_t nl = q - p + 1;
    size_t nr = r - q;

    for (size_t i = 0; i < nl; i++)
      m_temp[p + i] = m_data[p + i];
    for (size_t i = 0; i < nr; i++)
      m_temp[q + 1 + i] = m_data[q + 1 + i];

    size_t lp = p;
    size_t rp = q + 1;
    size_t kp = p;

    while (lp < p + nl && rp < q + 1 + nr) {
      if (m_cmp(m_temp[rp], m_temp[lp])) {
        m_data[kp] = std::move(m_temp[lp]);
        lp++;
      } else {
        m_data[kp] = std::move(m_temp[rp]);
        rp++;
      }
      kp++;
    }

    while (lp < p + nl) {
      m_data[kp] = std::move(m_temp[lp]);
      lp++;
      kp++;
    }

    while (rp < q + 1 + nr) {
      m_data[kp] = std::move(m_temp[rp]);
      rp++;
      kp++;
    }
  }

public:
  merge_sort(const T *arr, size_t len)
      : m_data{nullptr}, m_temp{nullptr}, m_len{len} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = arr[i];
    m_temp = new T[m_len];
  }

  merge_sort(std::vector<T> &vec)
      : m_data{nullptr}, m_temp{nullptr}, m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = vec[i];
    m_temp = new T[m_len];
  }

  merge_sort(std::vector<T> &&vec)
      : m_data{nullptr}, m_temp{nullptr}, m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = std::move(vec[i]);
    m_temp = new T[m_len];
  }

  merge_sort(const merge_sort &other) = delete;

  merge_sort(merge_sort &&other) = delete;

  merge_sort operator=(const merge_sort &other) = delete;

  merge_sort operator=(merge_sort &&other) = delete;

  ~merge_sort() {
    delete[] m_temp;
    delete[] m_data;
  }

  T *sort() {
    if (m_data) {
      sort(0, m_len - 1);
    }

    return m_data;
  }
};

#endif
