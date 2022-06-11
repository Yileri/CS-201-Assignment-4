#ifndef ALGORITHMSORTQUICK
#define ALGORITHMSORTQUICK
#include "SelectionAlgorithm.h"

class AlgorithmSortQuick : public SelectionAlgorithm {
public:
	AlgorithmSortQuick(int);
	int select();
	int quickselect(int*, int, int, int);

protected:
	int k;
};

#endif
