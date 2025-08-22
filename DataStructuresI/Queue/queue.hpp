#ifndef QUEUE_HPP_INC
#define QUEUE_HPP_INC

#include <cassert>
#include <utility>
#include <cstddef>

template <typename T>
class queue{
  private:
    T * m_data;
    size_t m_size;
    size_t m_cap;
    size_t m_head;
    size_t m_tail;

    bool full() const{
        return m_size==m_cap;
    }

    void reallocate(){
      size_t new_cap = m_cap*2;
      T * new_data = new T[new_cap];
      for(size_t i{0} ; i<m_size ; i++)
         new_data[i] = std::move(m_data[(m_head+i)%m_cap]);
      delete [] m_data;
      m_data = new_data;
      m_cap = new_cap;
      m_head = 0;
      m_tail = m_size;
    }

  public:
    queue(size_t cap=4)
    :m_data{nullptr},
     m_size{0},
     m_cap{cap},
     m_head{0},
     m_tail{0}
    {
       assert(cap>0);
       m_data = new T[m_cap];
    }

    ~queue(){
       delete [] m_data;
    }

    bool empty() const{
        return m_size==0;
    }

    void enqueue(const T & elem){
        if(full()) reallocate();
        m_data[m_tail] = elem;
        m_tail = (m_tail+1)%m_cap;
        m_size++;
    }

    void enqueue(T && elem){
        if(full()) reallocate();
        m_data[m_size] = std::move(elem);
        m_tail = (m_tail+1)%m_cap;
        m_size++;
    }

    T dequeue(){
        assert(m_size>0);
        m_head = (m_head+1)%m_cap;
        T first  = std::move(m_data[m_head]);
        m_size--;
        return first;
    }

    T & head(){
        assert(m_size>0);
        return m_data[m_head];
    }

    T & tail(){
        assert(m_size>0);
        return m_data[(m_tail+m_cap-1)%m_cap];
    }
};

#endif
