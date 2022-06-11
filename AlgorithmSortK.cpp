// write your codes here
#include "AlgorithmSortK.h"
#include <iostream>

//constructor
AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k) {
	this->k = k;
}

//search algorithm
int AlgorithmSortK::select() {
	int* numbers = 0;
	int N;
	int num;

	//takes the total number input as N but
	//creates an array with only k nummbers
	std::cin >> N;
	numbers = new int[this->k];


	//inserts k amount of inputs to the array
	for (int i = 0; i < this->k; i++) {
		std::cin >> numbers[i];
	}

	//sorts the array
	sort(numbers);


	for (int i = this->k; i < N; i++) {
		std::cin >> num;

		//if the input is bigger than the last number,
		//replaces it and sorts the array
		if (num > numbers[this->k - 1]) {
			numbers[this->k - 1] = num;
			sort(numbers);
		}
	}

	//returns the last number and deletes the array
	return numbers[k - 1];
	delete[] numbers;
	numbers = 0;
}

//it has the same principle as AlgorithmSortAll.cpp -> select()
int* AlgorithmSortK::sort(int array[]) {
	int temp;
	int check;

	for (int i = 1; i < this->k; i++) {
		temp = array[i];
		check = i;

		while (check > 0 && temp > array[check - 1]) {
			array[check] = array[check - 1];
			check--;
		}

		array[check] = temp;
	}
	return array;
}
