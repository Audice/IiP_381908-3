#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	Vector(int size, double* data);
	Vector(int size);//0 ������ ,��� ������ 
	Vector(const Vector& tmp);
	Vector& operator=(const Vector& tmp);
//	double operator+(const Vector& tmp)const;
//	double operator-(const Vector& tmp)const;
	Vector operator+(const Vector& tmp)const;
	Vector operator-(const Vector& tmp)const;
	double operator*(const Vector& tmp)const;
	Vector operator*(const double tmp);
	//Vector& operator/(const Vector& tmp)const;
	// Matrix operator*(const Vector& tmp)const;//������ ��������-������� �/�
	//Matrix -����� �����-��������� �������� �������
	// <,=,>,!=,[]
	void print();
	void SetSize(int s);
	void SetData(double* m);
	double GetLegth()const;
	double GetCosA(const Vector& vec2)const;
	double GetDistance(const Vector& vec2)const;
private:
	int  Size;//���-�� ����������� (x,y,z)
	double* Data;
};


