#include "Matrix.h"



void CutTheMatri(double** mas, double** p, int i, int j, int m)
{

	int ki, kj, iSmesh, jSmesh;
	iSmesh = 0;
	for (ki = 0; ki < m - 1; ki++) {
		if (ki == i)
			iSmesh = 1;
		jSmesh = 0;
		for (kj = 0; kj < m - 1; kj++) {
			if (kj == j)
				jSmesh = 1;
			p[ki][kj] = mas[ki + iSmesh][kj + jSmesh];
		}
	}
}
int Dett(double** arrays, int m, double* dres, int ii, bool three) {
	int  jojo, ty, nafany;
	double d;
	double** p;
	p = new double* [m];
	for (int i = 0; i < m; i++)
		p[i] = new double[m];
	jojo = 0; d = 0;
	ty = 1;
	nafany = m - 1;
	if (m < 1)
		cout << "nafig vse";
	if (m == 1)
	{
		d = arrays[0][0];
		return(d);
	}

	if (m == 2) {
		d = arrays[0][0] * arrays[1][1] - (arrays[1][0] * arrays[0][1]);

		if (three == true)
			dres[ii] = d;
		return(d);
	}
	if (m > 2) {
		for (int i = 0; i < m; i++) {
			CutTheMatri(arrays, p, 0, i, m);
			d = d + (ty * arrays[0][i] * Dett(p, nafany, dres, i, three));
			if (three == false)
				dres[ii] = d;
			ty = -ty;
		}
	}
	return(d);
}

int Matrix::D()
{
	bool _3;
	if (col == 3)
		_3 = true;
	else
		_3 = false;
	int d;
	double** p;
	double* mRes = new double[col];
	double* Res = new double[col];
	int s = col;
	p = new double* [col];
	for (int i = 0; i < col; i++)
		p[i] = new double[col];
	double** m;
	m = new double* [col];
	for (int i = 0; i < col; i++)
		m[i] = new double[col];
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = Rows[i][j];
		}
	}
	CutTheMatri(p, m, 0, 0, s);
	d = 0;
	Dett(p, s, mRes, 0, _3);
	d += mRes[0];
	return d;
}
Matrix::Matrix()
{
	this->str = 3;
	this->col = 3;
	this->Rows = static_cast<Vector*>(operator new[](this->str * sizeof(Vector)));
	for (int i = 0; i < str; i++)
	{
		new (Rows + i) Vector(col);
	}
}

Matrix::~Matrix()	
{
	
	for (int i = 0; i < str; i++)
	{
		Rows[i].~Vector();
	}
	this->str = 0;
	this->col = 0;
	operator delete[] (Rows);
}

Matrix::Matrix(int str, int stolp)
{
	this->str = str;
	this->col = stolp;
	this->Rows = static_cast<Vector*>(operator new[](this->str * sizeof(Vector)));
	for (int i = 0; i < str; i++)
	{
		new (Rows + i) Vector(col);
	}
}

Matrix::Matrix(const Matrix& tmp)
{
	if (tmp.Rows == nullptr)
		throw 1;
	this->str = tmp.str;
	this->col = tmp.col;
	this->Rows = static_cast<Vector*>(operator new[](this->str * sizeof(Vector)));
	for (int i = 0; i < str; i++)
	{
		new (Rows + i) Vector(col);
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Rows[i][j] = tmp.Rows[i][j];
		}

	}
}

Matrix& Matrix::operator=(const Matrix& tmp)
{
	if (tmp.Rows == nullptr)
		throw 1;
	this->str = tmp.str;
	this->col = tmp.col;
	this->Rows = static_cast<Vector*>(operator new[](this->str * sizeof(Vector)));
	for (int i = 0; i < str; i++)
	{
		new (Rows + i) Vector(col);
	}
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Rows[i][j] = tmp.Rows[i][j];
		}

	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& tmp) const
{
	Matrix res(tmp.str,tmp.col);

	if (str != tmp.str)
	{
		cout << "m or n no equal"<<endl;
		return res;
	}
	if (col != tmp.col)
	{
		cout << "m or n no equal" << endl;
		return res;
	}
	else {
		for (int i = 0; i < str; i++)
		{

			res.Rows[i] = this->Rows[i] + tmp.Rows[i];
		}

	}
	return res;
}

Matrix Matrix::operator-(const Matrix& tmp) const
{
	Matrix res(tmp.str, tmp.col);

	if (str != tmp.str)
	{
		cout << "m or n no equal" << endl;
		return res;
	}
	if (col != tmp.col)
	{
		cout << "m or n no equal" << endl;
		return res;
	}
	else {
		for (int i = 0; i < str; i++)
		{

			res.Rows[i] = this->Rows[i] - tmp.Rows[i];
		}

	}
	return res;
}

Matrix Matrix::operator*(const int& k) const
{
	Matrix res(str, col);
	for (int  i = 0; i < str; i++)
	{
		res.Rows[i] = Rows[i] * k;
	}
	return res;
}

Matrix Matrix::operator/(const int& k) const
{
	Matrix res(str, col);
	for (int i = 0; i < str; i++)
	{
		res.Rows[i] = Rows[i] / k;
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& tmp) const
{
	Matrix res(str,tmp.col);
	int ki = 0,kj=0,k ;

	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < str; j++)
		{
			for (int k = 0; k <tmp.col ; k++)
			{
				res.Rows[i][j] +=(this->Rows[i][k] * tmp.Rows[k][j]);
			}
		}
		
	}
	return res;
}

Matrix Matrix::operator/(const Matrix& tmp) const
{
	Matrix res(str, col),j(str, col);
	int d;
	res = tmp;
	d = res.D();
	if (d == 0)
	{
		cout << "DETERMINANT IS 0" << endl;
		return j;
	}
	res = res.T();
	res = res / d;
	res = res* *this;
	return res;
}

Matrix Matrix::operator^(const int tmp) const
{
	Matrix res(str, col);
	res = *this;
	if (tmp > 1)
	{
		for (int i = 1; i < tmp; i++)
		{
			res = res * *this;
		}
		return res;
	}
	else if (tmp == 0)
	{
		for (int i = 0; i < str; i++)
			for (int j = 0; j < col; j++)
			{
				res.Rows[i][j] = 1;
			}
		return res;
	}
	else
	{
		cout << "IT'S IMPOSIBLE" << endl;
		return *this;
	}

}

Matrix Matrix::T()
{
	Matrix tmp(col, str);
	Matrix t(col, str);
	t = *this;
	for (int i = 0; i < col; ++i)
	{
		for (int j = i; j < str; ++j)
		{
			tmp.Rows[i][j] = t.Rows[i][j];
			t.Rows[i][j] = t.Rows[j][i];
			t.Rows[j][i] = tmp.Rows[i][j];
		}
	}
	return t;
}




void Matrix::Set( Vector& tmp, int i)
{
	this->col = tmp.Get_Size();
	this->str = i+1;
	this->Rows[i] = tmp;
}

void Matrix::PrintM()
{
	for (int i = 0; i < this->str; i++)
	{
		cout << this->Rows[i];
	}
}

