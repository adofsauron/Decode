#include "Que.h"

void Que::push(int x)
{
	stg[index++] = x;
}

int Que::pop()
{
	if (var > index)
		return 0;
	return stg[var++];
}

int Que::size()
{
	return index;
}

bool Que::isIn(int x)
{
	for (int i = 0; i < index; i++)
	{
		if (stg[i] == x)
			return true;
	}
	return false;
}
