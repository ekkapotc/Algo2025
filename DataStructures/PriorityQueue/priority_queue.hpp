#ifndef PRIORITY_QUEUE_HPP_INC
#define PRIORITY_QUEUE_HPP_INC

#include "heap.hpp"
#include "priority_queue_node.hpp"

template <typename S, typename T> class priority_queue {
private:
  heap<PQNode<S, T>> m_heap;

public:
  priority_queue() = default;

  bool empty() const { return m_heap.empty(); }

  size_t size() const { return m_heap.size(); }

  void insert(const S &elem, T prio) {
    m_heap.insert(PQNode<S, T>{elem, prio});
  }

  void insert(S &&elem, T prio) {
    m_heap.insert(PQNode<S, T>{std::move(elem), prio});
  }

  const S max() const { return m_heap.max().get_data(); }

  S &extract_max() { return m_heap.extract_max().get_data(); }

  void increase_key(size_t pos , const T & new_key){
    assert(pos<size() && new_key>=m_heap[pos].get_priority()) ;
    if(new_key>=m_heap[pos].get_priority()){
       m_heap[pos].set_priority(new_key);

       while(pos>0){
         size_t parent = (pos-1)/2;
 
         if(m_heap[parent].get_priority()>=m_heap[pos].get_priority()) break;
  
         std::swap(m_heap[pos],m_heap[parent]);
         pos = parent;
       }
    }
  }  

  friend std::ostream &operator<<(std::ostream &os,
                                  const priority_queue<S, T> &pq) {
    os << pq.m_heap;
    return os;
  }
};

#endif
