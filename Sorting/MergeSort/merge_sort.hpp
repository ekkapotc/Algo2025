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

    T *al = new T[nl];
    T *ar = new T[nr];

    for (size_t i = 0; i < nl; i++)
      al[i] = m_data[p + i];
    for (size_t i = 0; i < nr; i++)
      ar[i] = m_data[i + q + 1];

    size_t lp = 0;
    size_t rp = 0;
    size_t kp = p;

    while (lp < nl && rp < nr) {
      if (m_cmp(ar[rp], al[lp])) {
        m_data[kp] = std::move(al[lp]);
        lp++;
      } else {
        m_data[kp] = std::move(ar[rp]);
        rp++;
      }
      kp++;
    }

    while (lp < nl) {
      m_data[kp] = std::move(al[lp]);
      lp++;
      kp++;
    }

    while (rp < nr) {
      m_data[kp] = std::move(ar[rp]);
      rp++;
      kp++;
    }

    delete[] ar;
    delete[] al;
  }

public:
  merge_sort(const T *arr, size_t len) : m_data{nullptr}, m_len{len} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = arr[i];
  }

  merge_sort(std::vector<T> &vec) : m_data{nullptr}, m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = vec[i];
  }

  merge_sort(std::vector<T> &&vec) : m_data{nullptr}, m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = std::move(vec[i]);
  }

  merge_sort(const merge_sort &other) = delete;

  merge_sort(merge_sort &&other) = delete;

  merge_sort operator=(const merge_sort &other) = delete;

  merge_sort operator=(merge_sort &&other) = delete;

  ~merge_sort() { delete[] m_data; }

  T *sort() {
    if (m_data) {
      sort(0, m_len - 1);
    }

    return m_data;
  }
};

#endif
