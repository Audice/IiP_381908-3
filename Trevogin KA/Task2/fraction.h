#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fraction
{

public:
	Fraction();
	Fraction(int a ,int b);
	int soc(int x, int y) const;
	void Division(int a[], int b[], int n);
	void Razn(int a[], int b[], int n);
	void Sum(int a[], int b[], int n);
	Fraction Sum1(int a, int b, int a1, int b1) const;
	Fraction Razn1(int a, int b, int a1, int b1);
	Fraction Multiplication1(int a, int b, int a1, int b1);
	Fraction Division1(int a, int b, int a1, int b1);
	void Multiplication(int a[], int b[], int n);
	void Conversion(int nomer);
	int getNumerator() const;
	void setNumerator(int a);
	Fraction& operator = (const Fraction& tmp);
	int getDenominator() const;
	Fraction operator * (const Fraction& tmp)const;
	Fraction operator / (const  Fraction& tmp)const;
	void setDenominator(int a);
	Fraction operator + (const Fraction& tmp) const;
	Fraction operator-(const Fraction& tmp) const;
	~Fraction();

private:
	int numerator;
	int denominator;
};