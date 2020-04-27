#pragma once
#pragma once

#include <iostream>

using namespace std;

class fraction

{

private:

	int chisl;

	int znam;

	int CompA;

	int CompB;

	int I;

public:

	fraction()
	{
	}
	~fraction()
	{
	}

	int GetCH();

	int GetCompA();

	void SetCH(int a);

	void SetCompA(int a);

	int GetZN();

	int GetCompB();

	void SetZN(int a);

	void SetCompB(int a);

	void Proizv(int a1, int b1, int a2, int b2);

	void Shastn(int a1, int b1, int a2, int b2);

	void Sum(int a1, int b1, int a2, int b2);

	void Razn(int a1, int b1, int a2, int b2);

	void output(int a, int b);

	fraction operator+ (const fraction& c);

	fraction operator- (const fraction& c);

	fraction operator* (const fraction& c);

	fraction operator/ (const fraction& c);

	friend std::ostream& operator<< (std::ostream& out, const fraction& fr);
};
