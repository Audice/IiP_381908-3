#include "Header2.h"
#include <ctime>
#include <random>

int aple::get_x()
{
	return x;
}

int aple::get_y()
{
	return y;
}

void aple::random(int r ,int d)
{
	r-=2;
	d-=2;
	srand(time(0));
	x=rand() %r+1;
	y = rand() %d + 1;
}
