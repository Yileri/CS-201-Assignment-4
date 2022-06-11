// write your codes here
#ifndef SELECTIONALGORITHM_H
#define SELECTIONALGORITHM_H

class SelectionAlgorithm {

public:
	SelectionAlgorithm(int);
	virtual int select() = 0;

protected:
	int k;
};

#endif