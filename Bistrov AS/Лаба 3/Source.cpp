#include "Header.h"
#include <iostream>

using namespace std;

int Load::GetCompA()
{
	return this->CompA;
};

void Load::SetCompA(int a)
{
	this->CompA = a;
};

int Load::GetCompB()
{
	return this->CompB;
};

void Load::SetCompB(int b)
{
	this->CompB = b;
};

void Load::Output(const Load& load)
{
	cout << "Complex count is: " << load.CompA << "+" << load.CompB << "*i" << endl;
};



