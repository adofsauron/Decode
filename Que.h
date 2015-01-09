#ifndef __QUE_H__
#define __QUE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXQUE 56

class Que
{
public:
	Que(){ index = 0; var = 0; };
	~Que(){};

	void push(int x);
	int pop();
	int size();
	bool isIn(int x);

private:
	int stg[MAXQUE];
	int index;
	int var;
};


#endif //__QUE_H__