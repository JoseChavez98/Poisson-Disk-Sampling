#ifndef MEDH_H
#define MEDH_H
#include "minheap.h"
#include "maxheap.h"

template <typename T>
class MedianHeap 
{ 
	int size;
public:
	MinHeap<T> * right;
	MaxHeap<T> * left;
	
	MedianHeap(int size)
	{
		this->size = size;
		right = new MinHeap<T>(size/2 +2);
		left = new MaxHeap<T>(size/2 +2);
	}    

	MedianHeap(Heap<T> *heap)
	{
		int size = heap->getSize();
		this->size = size;
		right = new MinHeap<T>(size/2 +2);
		left = new MaxHeap<T>(size/2 +2);

		for(int i = 0; i < heap->getSize();i++)
		{
			heap->at(i)->increaseLevel();
			heap->at(i)->nextComparingVal();
			insert(heap->at(i));
		}
		
	}

	void print()
	{
		left->print();
		cout << " / ";
		right->print();
		cout << endl;
	}

	void clear()
	{
		delete right;
		delete left;
	}

	int getSize()
	{
		return (left->getSize() + right->getSize());
	}

	void insert(T value)
	{
		if(left->getSize() == 0)
		{
			left->insert(value);
		}

		else if(value->comparingVal() < left->getMax()->comparingVal() || left->getSize() == 0)
		{
			left->insert(value);
		}
		
		else
			right->insert(value);

		if(left->getSize() - right->getSize() > 1)
		{
			T key = left->extractMax();
			right->insert(key);
		}
		else if (right->getSize() > left->getSize())
		{
			T key = right->extractMin();
			left->insert(key);
		}
	}

	T getMedian()
	{
		return left->getMax();
	}

	void extractMedian()
	{
		left->extractMax();
	}
}; 



#endif
