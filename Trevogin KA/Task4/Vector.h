#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <cmath>


using namespace std;
class Vector
{
private:
	int Size;
	double* Data;
public:
	Vector();
	Vector(int _size);
	Vector(const Vector& v);
	~Vector();
	void Random();
	int Get_Size();
	double lenght();
	double lenghtbwnvec(const Vector &tmp);
	double Cos(Vector& tmp);
	Vector vectorProizv(const Vector* Vec);

	double& operator[](const int tmp);
	friend std::istream& operator>>(std::istream& in, const Vector& tmp);
	friend std::ostream& operator<<(std::ostream& out, const Vector& tmp);
	Vector& operator=(const Vector& tmp);
	Vector operator+(const Vector& tmp) const;
	Vector operator-(const Vector& tmp)const;
	double operator*(const Vector& tmp)const;
	Vector operator*(const int tmp)const;
	Vector operator/(const int tmp)const;

};
