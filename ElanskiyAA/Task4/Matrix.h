#include "Vector.h";

class Matrix {
private:
	int str;
	int col;
	Vector* Rows;
public:
	Matrix();
	~Matrix();
	Matrix(int str, int stolp);
	Matrix(const Matrix& tmp);
	int D();
	void Set(Vector& tmp, int i);
	void PrintM();
	Matrix T();
	Matrix& operator=(const Matrix& tmp);
	Matrix operator+(const Matrix& tmp)const;
	Matrix operator-(const Matrix& tmp)const;
	Matrix operator*(const int& k)const;
	Matrix operator/(const int& k)const;
	Matrix operator*(const Matrix& tmp)const;
	Matrix operator/(const Matrix& tmp)const;
	Matrix operator^(const int tmp) const;
};