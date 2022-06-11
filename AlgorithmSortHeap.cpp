//code here
#include "AlgorithmSortHeap.h"
#include "BinaryHeap.h"
#include <iostream>

//constructor
AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k) {
	this->k = k;
}

//search algorithm
int AlgorithmSortHeap::select() {
	int N;
	int num;

	//creates a heap with the capacity of the input N
	std::cin >> N;
	BinaryHeap* BHeap = new BinaryHeap(N);

	//inserts the text input to the heap k times
	for (int i = 0; i < k; i++) {
		int temp;
		std::cin >> temp;
		BHeap->insert(temp);
	}

	//checks the remaining N-k inputs and if
	//the input is bigger than the root,
	//swaps each other
	for (int i = 0; i < N - k; i++) {
		std::cin >> num;

		if (num > BHeap->getMin()) {
			BHeap->deleteMin();
			BHeap->insert(num);
		}
	}

	//returns the root and deletes the heap
	return BHeap->getMin();
	delete BHeap;
	BHeap = 0;
}