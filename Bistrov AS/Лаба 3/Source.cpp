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

void Load::output()
{
	cout << "Complex count is: " << CompA << "+" << CompB << "*i" << endl;
};

Load::Load()
{
	GetCompA();
	CompA = 0;
	GetCompB();
	CompB = 0;
}

Load::~Load()
{
	GetCompA();
	CompA = 0;
	GetCompB();
	CompB = 0;
}