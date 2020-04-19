#include "fraction.h"

int gcd (int x, int y)
{
	x = abs(x);
	y = abs(y);
	int o1 = 1,c;
	if (x < y)
	{
		c = x;
		x = y;
		y = c;
	}
	while (o1 > 0)
	{
		o1 = x % y;
		x = y;
		y = o1;
	}
	return x;
}

int res(int c)
{
	if (c == 0)
	{
		cout << "��������� = 0" << endl;
		return 0;
	}
	else
		return 1;
}

int integer(int c, int z)
{
	c = abs(c);
	z = abs(z);
	if (c > z)
	{
		int i, rest, vib;
		do {
			cout << "�������� ����� �����?\n1) ��\n2) ���\n";
			cin >> vib;
		} while (1> vib || vib > 2);
		if (vib == 1) {
			rest = c % z;
			i = c / z;
			if (rest != 0)
			{
				int n = gcd(rest, z);
				cout << "���������:\n����� ����� = " << i << "\n������� ����� = " << rest / n << "/" << z / n << endl;
			}
			else
			cout << "��������� = " << i << endl;
			return 0;
		}
		else
			return 1;
	}
	else
		return 1;
}

fraction::fraction()
{
	this->chils = 0;
	this->znam = 1;
}

fraction::fraction(int _a, int _b)
{
	this->chils = _a;
	this->znam = _b;
}
void fraction::input(int *a, int*b, int n)
{
	int ch, z;

	cout << "������� ����� �" << n << "\n���������:\n";
	cin >> ch;

	do {
		cout << "�����������:\n";
		cin >> z;
		if (z == 0)
			cout << ("�� ���� ������ ��������������\n");
	} while (z == 0);
	this->chils=ch;
	this->znam= z;
	*a = ch;
	*b = z;

}

void fraction::showFrac(int n)
{
	if (getFracZnam()>0)
		cout << "����� �"<< n <<" = " << getFracChisl() << "/" << getFracZnam() << endl;
	else
		cout << "����� �" << n << " = -" << getFracChisl() << "/" << abs(getFracZnam()) << endl;

}

int fraction::getFracChisl() const
{
	return this->chils;
}

int fraction::getFracZnam() const
{
	return this->znam;
}

void fraction::setFracChisl(int newChis)
{
	this->chils = newChis;
}

void fraction::setFracZnam(int newZnam)
{
	this->znam = newZnam;
}

int fraction::mult(fraction f1, fraction f2)
{
	int c, z;
	c = f1.getFracChisl() * f2.getFracChisl();
	int r = res(c);
	if (r == 0)
		return 0;
	z = f1.getFracZnam()  * f2.getFracZnam();
	twomin(&c, &z);
	int n = gcd(c, z);
	int in = integer(c,z);
	if (in == 0)
		return 0;
	else
		cout << "��������� ��������� = " << c / n << "/" << z / n << endl; return 0;
}

int fraction::divis(fraction f1, fraction f2)
{
	int vib;
	do {
		cout << "1)������ ����� ��������� �� ������\n2)������ ����� ��������� �� ������" << endl;
		cin >> vib;
	} while (1 > vib || vib > 2);
	int c, z;
	c = f1.getFracChisl() * f2.getFracZnam();
	z = f1.getFracZnam() * f2.getFracChisl();
	int r = res(c);
	if (r == 0)
		return 0;
	twomin(&c, &z);
	int n = gcd(c, z);
	int in = integer(c, z);
	if (in == 0)
		return 0;
	else
	{
		if (vib == 1)
		{
			cout << "��������� ������� = " << c / n << "/" << z / n << endl;
			return 0;
		}
		else
		{
			cout << "��������� ������� = " << z / n << "/" << c / n << endl;
			return 0;
		}
	}
}

fraction::~fraction()
{
	this->chils = 0;
	this->znam = 1;
	//cout << "�������� ���������� fraction" << endl;
}

int fraction::sum(fraction f1, fraction f2)
{
	int c, z;
	z = f1.getFracZnam() * f2.getFracZnam();
	int ch1 = f1.getFracChisl() * f2.getFracZnam();
	int ch2 = f2.getFracChisl() * f1.getFracZnam();
	c = ch1 + ch2;
	int r = res(c);
	if (r == 0)
		return 0;
	twomin(&c, &z);
	int n = gcd(c, z);
	int in = integer(c, z);
	if (in == 0)
		return 0;
	else
	{
		cout << "��������� �������� = " << c / n << "/" << z / n << endl; return 0;
	}
}

int fraction::diff(fraction f1, fraction f2)
{
	int c, z, vib;
	do {
		cout << "1)�� ������ ����� ������� ������\n2)�� ������ ����� ������� ������" << endl;
		cin >> vib;
	} while (1 > vib || vib > 2);
	z = f1.getFracZnam() * f2.getFracZnam();
	int ch1 = f1.getFracChisl() * f2.getFracZnam();
	int ch2 = f2.getFracChisl() * f1.getFracZnam();

	if (vib == 1)
		c = ch1 - ch2;
	else
		c = ch2 - ch1;
	int r = res(c);
	if (r == 0)
		return 0;
	twomin(&c, &z);
	int n = gcd(c, z);
	int in = integer(c, z);
	if (in == 0)
		return 0;
	else
	{		cout << "��������� ��������� = " << c / n << "/" << z / n << endl; 
	return 0;
}
}

std::istream& operator>>(std::istream& in, fraction& tmp)
{
	cout << "���������"<<endl;
	in >> tmp.chils; 
	cout << "�����������" << endl;
	in >> tmp.znam;
	return in;
}

void twomin(int* a, int* b)
{
	int ch = *a, z = *b;
	if (ch < 0 && z < 0)
	{
		ch = ch * (-1);
		z = z * (-1);
	}
	*a = ch;
	*b = z;
}
