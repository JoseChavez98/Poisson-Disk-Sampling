#ifndef MINH_H
#define MINH_H
#include <climits>
#include "heap.h"


template <typename T>
class MinHeap : public Heap<T>
{ 

public: 
	MinHeap(int max_size) 
	{ 
	    Heap<T>::size = 0; 
	    Heap<T>::max_size = max_size; 
	    Heap<T>::data = new T[max_size]; 
	}
    
    T getMin() 
    { 
    	return Heap<T>::data[0]; 
    } 
	
	int insert(T k) 
	{ 
	    if (Heap<T>::size == Heap<T>::max_size) 
	    { 
	        return -1; 
	    } 
	  
	    Heap<T>::size++; 
	    int i = Heap<T>::size - 1; 
	    Heap<T>::data[i] = k; 
	  
	    while (i != 0 && Heap<T>::data[Heap<T>::parentIndex(i)]->comparingVal() > Heap<T>::data[i]->comparingVal()) 
	    { 
	        Heap<T>::swap(&Heap<T>::data[i], &Heap<T>::data[Heap<T>::parentIndex(i)]); 
	       i = Heap<T>::parentIndex(i); 
	    } 
	    return 0;
	} 
	  
	void decreaseKey(int i, T new_val) 
	{ 
	    Heap<T>::data[i] = new_val; 
	    while (i != 0 && Heap<T>::data[Heap<T>::parentIndex(i)]->comparingVal() > Heap<T>::data[i]->comparingVal()) 
	    { 
	        Heap<T>::swap(&Heap<T>::data[i], &Heap<T>::data[Heap<T>::parentIndex(i)]); 
	       i = Heap<T>::parentIndex(i); 
	    } 
	} 
  
	T extractMin() 
	{ 
	    if (Heap<T>::size <= 0) 
	        return Heap<T>::data[0]; 
	    if (Heap<T>::size == 1) 
	    { 
	        Heap<T>::size--; 
	        return Heap<T>::data[0]; 
	    } 
	  
	    T root = Heap<T>::data[0]; 
	    Heap<T>::data[0] = Heap<T>::data[Heap<T>::size-1]; 
	    Heap<T>::size--; 
	    heapify(0); 
	  
	    return root; 
	} 

	T extractRoot()
    {
    	return extractMin();
    }
  
	void deleteKey(int i) 
	{ 
	    decreaseKey(i, INT_MIN); 
	    extractMin(); 
	}

	void heapify(int i) 
	{ 
	    int l = Heap<T>::leftIndex(i); 
	    int r = Heap<T>::rightIndex(i); 
	    int smallest = i; 
	    if (l < Heap<T>::size && Heap<T>::data[l]->comparingVal() < Heap<T>::data[smallest]->comparingVal()) 
	        smallest = l; 
	    if (r < Heap<T>::size && Heap<T>::data[r]->comparingVal() < Heap<T>::data[smallest]->comparingVal()) 
	        smallest = r; 
	    if (smallest != i) 
	    { 
	         Heap<T>::swap(&Heap<T>::data[i], &Heap<T>::data[smallest]); 
	        heapify(smallest); 
	    } 
	} 

}; 



#endif