#pragma once

#include <iostream>
#include <string>
#include"fraction.h"
using namespace std;
class Complex
{
public:
	Complex();
	Complex(Fraction n, Fraction nr);
	Complex(const Complex& tmp);
	Complex& operator = (const Complex& tmp);
	Complex operator + (const Complex& tmp) const;
	Complex operator - (const Complex& tmp) const;
	Complex operator * (const Complex& tmp)const;
	Complex operator / (const Complex& tmp)const;
	bool operator == (const Complex& tmp);
	bool operator >= (const Complex& tmp);
	bool operator <= (const Complex& tmp);
	bool operator != (const Complex& tmp);
	Complex operator + (const int& tmp)const;
	Complex operator - (const int& tmp)const;
	Complex operator * (const int& tmp)const;
	Complex operator / (const int& tmp)const;
	Complex& operator += (const Complex& tmp);
	Complex& operator -= (const Complex& tmp);
	Complex& operator *= (const Complex& tmp);
	Complex& operator /= (const Complex& tmp);
	Complex& operator += (const int& tmp);
	Complex& operator -= (const int& tmp);
	Complex& operator *= (const int& tmp);
	Complex& operator /= (const int& tmp);
	Complex& operator ++ ();
	bool operator < (const Complex& tmp);
	bool operator > (const Complex& tmp);
	friend ostream& operator << (ostream& os, const Complex osn);
	~Complex();
	void printi();

public:
	Fraction Re;
	Fraction Im;

};