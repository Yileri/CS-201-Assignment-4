// write your codes here
#ifndef ALGORITHMSORTALL_H
#define ALGORITHMSORTALL_H

#include "SelectionAlgorithm.h"

class AlgorithmSortAll : public SelectionAlgorithm {

public:
	AlgorithmSortAll(int k);
	int select();

protected:
	int k;
};
#endif