// write your codes here
#ifndef ALGORITHMSORTK_H
#define ALGORITHMSORTK_H
#include "SelectionAlgorithm.h"

class AlgorithmSortK : public SelectionAlgorithm {

public:
	AlgorithmSortK(int);
	int select();
	int* sort(int array[]);

protected:
	int k;
};

#endif