// write your codes here
#include "AlgorithmSortAll.h"
#include <iostream>

//constructor
AlgorithmSortAll::AlgorithmSortAll(int k) : SelectionAlgorithm(k) {
	this->k = k;
}

//search algorithm
int AlgorithmSortAll::select() {
	int* numbers = 0;
	int temp;
	int check;
	int N;

	//creates an array with the input N from the text
	std::cin >> N;
	numbers = new int[N];

	//inserts the input from the text
	for (int i = 0; i < N; i++) {
		std::cin >> numbers[i];
	}


	for (int i = 1; i < N; i++) {
		temp = numbers[i];
		check = i;

		//starting from the index 1, checks all the way to the index 0, changes 
		//if the number is smaller and repeats it for every index to index N-1
		while (check > 0 && temp > numbers[check - 1]) {
			numbers[check] = numbers[check - 1];
			check--;
		}

		numbers[check] = temp;
	}

	//returns the kth largest element and deletes the array
	return numbers[k - 1];
	delete[] numbers;
	numbers = 0;
}