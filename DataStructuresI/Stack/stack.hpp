#ifndef STACK_HPP_INC
#define STACK_HPP_INC

#include <cassert>
#include <utility>
#include <cstddef>
#include <iostream>

template <typename T>
class stack{
  private:
    T * m_data; 
    size_t m_size;
    size_t m_cap;
    
    void reallocate(){
        size_t new_cap = 2*m_cap;
        T * new_data = new T[new_cap];
        for(auto i{0} ; i<m_size ; i++) new_data[i] = std::move(m_data[i]);
        delete [] m_data;
        m_data = new_data;
        m_cap = new_cap;
        //std::cout << "\tm_cap changed from " << new_cap/2 << " to " << new_cap << std::endl; 
    }
  
  public:
    stack(size_t cap=4):m_data{nullptr},
                      m_size{0},
                      m_cap{cap}
    {
       assert(cap>0);
       m_data = new T[m_cap];
    }

    ~stack(){
	delete[] m_data;
    }

    bool empty() const{
        return m_size==0;
    }

    size_t size() const{
        return m_size;
    }

    void push(const T & elem){
       std::cout << "\tpushing const lvalue" << std::endl;
       if(m_size==m_cap) reallocate();
       m_data[m_size] = elem;
       m_size++;
    }

    void push(T && elem){
       std::cout << "\tpushing rvalue" << std::endl;
       if(m_size==m_cap) reallocate();     
       m_data[m_size] = std::move(elem);
       m_size++;
    }

    /*template <typename S>
    void push(S && elem){
       if(m_size==m_cap) reallocate();
       m_data[m_size] = std::forward<S>(elem);
       m_size++;
    }*/
 
    T & top() {
      assert(m_size>0);
      return m_data[m_size-1];
    }

    T pop(){
      assert(m_size>0);
      m_size--;
      return std::move(m_data[m_size]);
    }   
};

#endif
