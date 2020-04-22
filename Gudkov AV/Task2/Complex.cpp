#include "Complex.h"

Complex::Complex()
{
	this->Re = fraction(0, 1);
	this->Im = fraction(0, 1);
}

Complex::~Complex()
{
	this->Re = fraction(0, 1);
	this->Im = fraction(0, 1);
}

void Complex::scan()
{
	int c, d;
    cout << "������� ������ �����" << endl;
    cout << "������� ���������" << endl;
    cin >> c;
    cout << "������� �����������" << endl;
    do
    {
        cin >> d;
        if (d == 0)
            cout << "������ ���" << endl;
    } while (d == 0);
    this->Re = fraction(c,d);
    cout << "������� ������ �����" << endl;
    cout << "������� ���������" << endl;
    cin >> c;
    cout << "������� �����������" << endl;
    do
    {
        cin >> d;
        if (d == 0)
            cout << "������ ���" << endl;
    } while (d == 0);
    this->Im = fraction(c, d);
}

Complex& Complex::operator=(const Complex& tmp)
{
    this->Re = tmp.Re;
    this->Im= tmp.Im;
    return *this;

}

ostream& operator<<(ostream& out, Complex& tmp)
{
    out << tmp.Re.GetChisl()<<"/"<< tmp.Re.GetZnam()<<"+"<<tmp.Im.GetChisl()<<"/"<< tmp.Im.GetZnam()<<"*i";
    return out;
}