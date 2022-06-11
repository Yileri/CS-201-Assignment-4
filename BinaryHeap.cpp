//code here
#include "BinaryHeap.h"
#include <iostream>

//constructor
BinaryHeap::BinaryHeap(int capacity) {
	//capacity is +1 because of heap concept
	//(first index should be 1 not 0)
	this->capacity = capacity + 1;
	this->size = 0;
	this->heap = new int[this->capacity];
}

//if the size is 0, returns -1
//else, returns the first index (root)
int BinaryHeap::getMin() {
	if (size < 1) {
		size = 0;
		return -1;
	}
	else {
		return heap[1];
	}
}

void BinaryHeap::insert(int element) {
	//increments the size and puts the input
	size++;
	int hole = size;
	heap[hole] = element;

	//checks if the array is full or not
	if (size >= capacity) {
		size = capacity - 1;
		std::cout << "The array is full!" << std::endl;
		return;
	}

	//if the child is smaller than the parent, perculates up
	while (hole > 1 && heap[hole / 2] > element) {
		swap(hole, hole / 2);
		hole /= 2;
	}
}

void BinaryHeap::swap(int i, int j) {
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

int BinaryHeap::deleteMin() {
	int root = getMin();

	//swaps the root with last element, decrements the size
	//and perculates down the root until it finds the appropriate
	//spot
	if (size != 1) {
		swap(1, size);
		size--;
		percolateDown(1);
		return root;
	}

	//if the heap size is only one, simply 
	//decrements the size and returns the root
	else {
		size--;
		return root;
	}
}

void BinaryHeap::percolateDown(int hole) {
	int child;
	int temp = heap[hole];

	//checks if there is a spot to
	//move down to
	while (hole * 2 <= size) {
		child = hole * 2;

		//looks for the child which has lower number
		if (child != size && heap[child] > heap[child + 1]) {
			child++;
		}

		if (heap[hole] > heap[child]) {
			swap(hole, child);
		}

		//makes the hole equal to the child
		hole = child;
	}
}

//destructor
BinaryHeap::~BinaryHeap() {
	delete[] heap;
}
