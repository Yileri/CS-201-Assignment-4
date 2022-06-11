//code here
#ifndef BINARYHEAP
#define BINARYHEAP

class BinaryHeap {
	//default access modifier is private
	int size;
	int capacity;
	int* heap;

	void percolateDown(int);
	void swap(int, int);

public:
	BinaryHeap(int);
	~BinaryHeap();
	void insert(int);
	int deleteMin();
	int getMin();
};

#endif