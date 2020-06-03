#pragma once
#include <fstream> 
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
	friend ostream& operator<<(ostream& stream, const Vector& vec); // ����� � �����
	friend istream& operator>>(istream& stream, Vector& vec); // ���� �� ������
	//Vector& operator/(const Vector& tmp)const;
	// Matrix operator*(const Vector& tmp)const;//������ ��������-������� �/�
	//Matrix -����� �����-��������� �������� �������
	// <,=,>,!=,[]
	void print();
	void printToMatrix();
	void printT();
	void SetSize(int s);
	void SetData(double* m);
	void SSetData(int index,double type);
	void SSSetData(int index, double type);
	double GetDataIndex(int index);
	double GetLegth()const;
	double GetCosA(const Vector& vec2)const;
	double GetDistance(const Vector& vec2)const;
	double& operator[](const int index);

private:
	int  Size;//���-�� ����������� (x,y,z)
	double* Data;
};
ostream& operator<<(ostream& stream, const Vector& vec); // ����� � �����
istream& operator>>(istream& stream, Vector& vec); // ���� �� ������
