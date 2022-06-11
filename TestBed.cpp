// write your codes here

#include "TestBed.h"
#include <iostream>
#include <ctime>

TestBed::TestBed() {

}

TestBed::~TestBed() {
	delete algorithm;
}

void TestBed::execute() {
	std::cout << "Result: ";

	//checks the duration of search algorithm
	clock_t start = clock();
	int result = algorithm->select();
	clock_t end = clock();

	//prints the result and duration time
	std::cout << result << std::endl;
	double cpu_time = static_cast<double> (end - start) / CLOCKS_PER_SEC;
	std::cout << "Duration(sec): " << cpu_time << std::endl;
}

//chooses the right algorithm based on the number in the input
void TestBed::setAlgorithm(int type, int k) {
	if (type == 1)
		this->algorithm = new AlgorithmSortAll(k);
	else if (type == 2)
		this->algorithm = new AlgorithmSortK(k);
	else if (type == 3)
		this->algorithm = new AlgorithmSortHeap(k);
	else if (type == 4)
		this->algorithm = new AlgorithmSortQuick(k);
	else
		std::cout << "Error: Unknown algorithm type." << std::endl;
}