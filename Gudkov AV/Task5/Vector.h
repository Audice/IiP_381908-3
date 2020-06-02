#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
class Vector
{
public:
	Vector();
	//Vector(int _size, double*_data);
	Vector(int _size);
	Vector(const Vector& v);
	~Vector();
	Vector& operator=(const Vector& tmp);
	Vector operator+(const Vector& tmp) const;
	Vector operator-(const Vector& tmp)const;
	double operator*(const Vector& tmp)const;
	Vector operator*(const int tmp)const;
	Vector operator/(const int tmp)const;

	double& operator[](const int tmp);
	double lenght();
	double lenghtbetweenvectors(const Vector &tmp);
	double Cos(Vector& tmp);
	friend std::istream& operator>>(std::istream& in, const Vector& tmp);
	friend std::ostream& operator<<(std::ostream& out, const Vector& tmp);
	Vector VecProduct(Vector* Vec);
	void Random();
	int GetSize();

private:
	int Size;
	double* Data;
};
