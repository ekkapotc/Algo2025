#ifndef HEAP_SORT_HPP_INC
#define HEAP_SORT_HPP_INC

#include <vector>

#include "heap.hpp"

template <typename T, typename Compare=std::greater<T>> class heap_sort {
private:
  T *m_data;
  size_t m_len;

public:
  heap_sort(const T *arr, size_t len) : m_data{nullptr} , m_len{len} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = arr[i];
  }

  heap_sort(std::vector<T> &vec) : m_data{nullptr} , m_len{vec.size()} {
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = vec[i];
  }

  heap_sort(std::vector<T> &&vec) : m_data{nullptr} , m_len{vec.size()}{
    assert(m_len > 0);
    m_data = new T[m_len];
    for (size_t i{0}; i < m_len; i++)
      m_data[i] = std::move(vec[i]);
  }

  ~heap_sort() { delete[] m_data; }

  const T * sort() {
    if (m_data) {
      heap<T,Compare> h{m_data, m_len};
      for (size_t i{m_len-1}; i >0 ; --i) {
        std::swap(h[0],h[i]);
        h.shrink();
        h.heapify(0);
      }

      delete [] m_data;      

      m_data = new T[m_len];

      for(size_t i{0} ; i<m_len ; i++) m_data[i] = std::move((h.data())[i]);  
   }

   return m_data;
  }
};

#endif
