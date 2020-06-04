#include "Header1.h"

zmei::zmei()
{
	x = 5;
	y = 10;
	orientation = 0;
}

void zmei::set_x(int a)
{
	x=a;
}

void zmei::set_y(int a)
{
	y = a;
}

int zmei::get_x()
{
	return x;
}

int zmei::get_y()
{
	return y;
}

int zmei::get_orientation()
{
	return orientation;
}
