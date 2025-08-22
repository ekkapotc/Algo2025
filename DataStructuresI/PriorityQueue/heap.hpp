#ifndef HEAP_HPP_INC
#define HEAP_HPP_INC

#include <cassert>
#include <cstddef>
#include <cstring>
#include <utility>
#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
class heap{
  private:
    T * m_data;
    size_t m_size;
    size_t m_cap;

    bool full() const{
	return m_size==m_cap;
    }

    void reallocate(){
        size_t new_cap = 2*m_cap;
	T * new_data = new T[new_cap];
	for(size_t i{0} ; i<m_size ; i++) new_data[i] = m_data[i];
        delete [] m_data;
        m_data = new_data;
        m_cap = new_cap;
    }
    
   /*
    Precondition: If there will be any violation, that violation must be at the root i.
		  This assumes the left subtree and the right subtree of the root i are already max heaps.
    	          max_heapify will push the violation downwards towards a leaf.
   */
   void max_heapify(size_t i){
	auto largest = i;
  	auto left = 2*i+1;
	auto right = 2*i+2;
	
        if(left<m_size && m_data[left]>m_data[largest]) largest = left;
        
	if(right<m_size && m_data[right]>m_data[largest]) largest = right;
       
	if(largest!=i){
   	   std::swap(m_data[largest],m_data[i]);
	   max_heapify(largest);
        }
    }
    
  public:
     heap( const T * arr , size_t len ):
     m_data{nullptr},
     m_size{len},
     m_cap{len}
     {
	assert(m_cap>0);
	m_data = new T[m_cap];

	for(size_t i{0} ; i<m_cap ; i++) 
	   m_data[i] = arr[i];

     	build_max_heap();
     }

     /*
	Wrapper constructor that deduces the number of elements (N)
     */
     template <size_t N>
     heap(const T (&arr)[N]):heap(arr,N){
     
     }

     heap( const std::vector<T> & vec ):
     m_data{nullptr},
     m_size{vec.size()},
     m_cap{vec.size()}
     {	
	assert(m_cap>0);
	m_data = new T[m_cap];
	
	for(size_t i{0} ; i<m_cap ; i++)
	   m_data[i] = vec[i];

	build_max_heap();
     }


     heap( std::vector<T> && vec ):
     m_data{nullptr},
     m_size{vec.size()},
     m_cap{vec.size()}
     {	
	assert(m_cap>0);
	m_data = new T[m_cap];
	
	if constexpr (std::is_trivially_copyable_v<T>){
	   std::memcpy(m_data , vec.data() , m_size*sizeof(T));
        }else{
	   for(size_t i{0} ; i<m_cap ; i++) m_data[i] = std::move(vec[i]);
        }

	build_max_heap();
     }

     ~heap(){
	delete [] m_data;
	m_data = nullptr;
     }

     bool empty() const{
	return m_size==0;
     } 

     size_t size() const{
	return m_size;
     }

     T max() const{
	assert(m_size>0);
	return m_data[0];
     }
     
     void build_max_heap(){
	assert(m_size>0);
	for(int i {(static_cast<int>(m_size)/2)-1} ; i>=0 ; i--){
	    max_heapify(i);
        }
     }

     T extract_max(){
       assert(m_size>0);
       auto cur_max = m_data[0];
       m_data[0] = m_data[m_size-1];
       m_size--;
       max_heapify(0);
       return cur_max;
     }

     void insert(const T & elem){
	if(full()) reallocate();

        size_t i = m_size++;
	m_data[i] = elem;

	while(i>0){
	   size_t p = (i-1)/2;
	   if( m_data[i] > m_data[p] ){
		std::swap(m_data[i],m_data[p]);
		i = p;
           }else{
		break;
           }
        }
     }
    
     void insert(T && elem){
	if(full()) reallocate();

        size_t i = m_size++;
	m_data[i] = std::move(elem);

	while(i>0){
	   size_t p = (i-1)/2;
	   if( m_data[i] > m_data[p] ){
		std::swap(m_data[i],m_data[p]);
		i = p;
           }else{
		break;
           }
        }
     }


     template<typename S>
     friend std::ostream& operator<<(std::ostream& os, const heap<S> & h) {
        for (size_t i {0}; i<h.m_size; i++) {
          os << h.m_data[i] << (i + 1 < h.m_size ? " " : "");
        }
        return os;
     }
};

#endif
