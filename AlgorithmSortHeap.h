//code here
#ifndef  ALGORITHMSORTHEAP
#define ALGORITHMSORTHEAP
#include "SelectionAlgorithm.h"

class AlgorithmSortHeap : public SelectionAlgorithm {
public:
	AlgorithmSortHeap(int);
	int select();

protected:
	int k;
};

#endif