#include "Header.h"

int fraction::GetCH()

{

	return this->chisl;

}

int fraction::GetCompA()
{
	return this->CompA;
};

void fraction::SetCH(int a)

{

	this->chisl = a;

}

void fraction::SetCompA(int a)
{
	this->CompA=a;
};

int fraction::GetZN()

{

	return this->znam;

}

int fraction::GetCompB()
{
	return this->CompB;
};

void fraction::SetZN(int a)

{

	this->znam = a;

}

void fraction::SetCompB(int b)
{
	this->CompB=b;
};

void fraction::Proizv(int a1, int b1, int a2, int b2)

{

	cout << "Multiplication =" << a1 * a2 << "/" << b1 * b2 << endl;

}

void fraction::Shastn(int a1, int b1, int a2, int b2)

{

	cout << "Division =" << a1 * b2 << "/" << b1 * a2 << endl;

}

void fraction::Sum(int a1, int b1, int a2, int b2)

{

	int b11;

	b11 = b1 * b2;

	a1 = a1 * b2;

	a2 = a2 * b1;

	cout << "Addition =" << a1 + a2 << "/" << b11 << endl;

}

void fraction::Razn(int a1, int b1, int a2, int b2)

{

	int b11;

	b11 = b1 * b2;

	a1 = a1 * b2;

	a2 = a2 * b1;

	cout << "Subtraction' =" << a1 - a2 << "/" << b11 << endl;

}

void fraction::output(int a, int b)
{
	cout << "Complex count is: " << a + b << "*i" << endl;
};

fraction fraction::operator+ (const fraction& c)

{

	fraction res;

	if (znam != c.znam)

	{

		res.chisl = chisl * c.znam + c.chisl * znam;

		res.znam = c.chisl * znam;

	}

	else {

		res.chisl = chisl + c.chisl;

		res.znam = znam;

	}

	return res;

}

fraction fraction::operator- (const fraction& c)

{

	fraction res;

	if (znam != c.znam)

	{

		res.chisl = chisl * c.znam - c.chisl * znam;

		res.znam = c.chisl * znam;

	}

	else {

		res.chisl = chisl + c.chisl;

		res.znam = znam;

	}

	return res;

}

fraction fraction::operator*(const fraction& c)

{

	fraction res;

	res.chisl = chisl * c.chisl;

	res.znam = znam * c.znam;

	return res;

}

fraction fraction::operator/(const fraction& c)

{

	fraction res;

	res.chisl = chisl * c.znam;

	res.znam = znam * c.chisl;

	return res;

};

std::ostream& operator<<(std::ostream& out, const fraction& fr)

{

	cout << fr.chisl << "/" << fr.znam;

	return out;

}
