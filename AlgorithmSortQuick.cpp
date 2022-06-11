#include <iostream>
#include "AlgorithmSortQuick.h"

AlgorithmSortQuick::AlgorithmSortQuick(int k) : SelectionAlgorithm(k) {
	this->k = k;
}

int AlgorithmSortQuick::select() {
	int N, temp, check;

	std::cin >> N;
	int* numbers = new int[N];

	//inserts the input from the text
	for (int i = 0; i < N; i++) {
		std::cin >> numbers[i];
	}

	if (N <= 10) {

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
	else {
		return quickselect(numbers, 0, N - 1, this->k);
	}
}

int AlgorithmSortQuick::quickselect(int* numbers, int left, int right, int k) {

	//if the group only contains one element, returns it
	if (left >= right) {
		int n = numbers[left];
		delete[] numbers;
		numbers = 0;
		return n;
	}
	else {

		//picks the pivot to be the last element of array 
		//and index as the first element
		int pivot = numbers[right];
		int index = left;

		for (int i = left; i < right; i++) {

			//swaps if the certain element is bigger than the pivot
			if (numbers[i] >= pivot) {
				int temp = numbers[i];
				numbers[i] = numbers[index];
				numbers[index] = temp;
				
				//increments the index
				index++;
			}

		}

		//at the end, swaps the pivot and the element at the index 
		int temp = numbers[right];
		numbers[right] = numbers[index];
		numbers[index] = temp;

		//calls function recursively if k is
		//smaller than the size of first group
		if (k <= index) {
			return quickselect(numbers, left, index - 1, k);
		}

		//returns pivot if k is equal to the 
		//size of first group + 1
		if (k == index + 1) {
			delete[] numbers;
			numbers = 0;
			return pivot;
		}

		//calls function recursively if the k is
		//larger than the size of first group
		else {
			return quickselect(numbers, index + 1, right, k);
		}

	}

}