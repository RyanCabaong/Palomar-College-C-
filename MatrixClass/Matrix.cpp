#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Matrix.h"

using std::ostream;
using std::istream;  using std::endl;
//1 add
//2 subtract
//3 mult
//4 pre inc
//5 pre dec
//6 transpose
//constructor
Matrix::Matrix(int dims) : dims_(dims)
{
	allocSpace();
	for (int i = 0; i < dims; ++i) {
		for (int j = 0; j < dims; ++j) {
			p[i][j] = 0;
		}
	}
}
//constructor rows and columns
Matrix::Matrix(int rows, int cols)
{
	allocSpace();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			p[i][j] = 0;
		}
	}
}
//constructor
Matrix::Matrix(int** a,int dims) : dims_(dims)
{
	allocSpace();
	for (int i = 0; i < dims_; ++i) {
		for (int j = 0; j < dims_; ++j) {
			p[i][j] = a[i][j];
		}
	}
}
//constructor
Matrix::Matrix()
{
	allocSpace();
	p[0][0] = 0;
}
//destructor
Matrix::~Matrix()
{
	for (int i = 0; i < dims_; ++i) {
		delete[] p[i];
	}
	delete[] p;
}
//constructor of given Matrix
Matrix::Matrix(const Matrix& m) : dims_(m.dims_)
{
	allocSpace();
	for (int i = 0; i < dims_; ++i) {
		for (int j = 0; j < dims_; ++j) {
			p[i][j] = m.p[i][j];
		}
	}
}
//add matrices
Matrix& Matrix::operator+=(const Matrix& m)
				{
	for (int i = 0; i < dims_; ++i) {
		for (int j = 0; j < dims_; ++j) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;
				}
//add matrix with integer
Matrix& Matrix::operator+=(const int d)
				{
	for (int i = 0; i < dims_; ++i) {
		for (int j = 0; j < dims_; ++j) {
			p[i][j] += d;
		}
	}
	return *this;
				}
//subtract matrices
Matrix& Matrix::operator-=(const Matrix& m)
				{
	for (int i = 0; i < dims_; ++i) {
		for (int j = 0; j < dims_; ++j) {
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
				}
//multiply matrices
Matrix& Matrix::operator*=(const Matrix& m)
				{
	Matrix temp(m.dims_);
	for (int i = 0; i < temp.dims_; ++i) {
		for (int j = 0; j < temp.dims_; ++j) {
			for (int k = 0; k < dims_; ++k) {
				temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	return (*this = temp);
				}
//positive exponential
//REFER TO EXPHELPER line 155
Matrix Matrix::operator^(int num)
{
	Matrix temp(*this);
	return expHelper(temp, num);
}
//TRANSPOSE
Matrix Matrix::transpose()
{
	Matrix ret(dims_);
	for (int i = 0; i < dims_; ++i) {
		for (int j = 0; j < dims_; ++j) {
			ret.p[j][i] = p[i][j];
		}
	}
	return ret;
}

//INC AND DEC MUST BE FRIEND FNS

//Matrix Pre-Increment inc and return
Matrix operator++(const Matrix& m)
				{

	for (int i = 0; i < m.dims_; ++i) {
		for (int j = 0; j < m.dims_; ++j) {
			m.p[j][i] += 1;
		}
	}
	return m;

				}
//Matrix Pre-Decrement dec and return
Matrix operator--(const Matrix& m)
				{
	for (int i = 0; i < m.dims_; ++i) {
		for (int j = 0; j < m.dims_; ++j) {
			m.p[j][i] += -1;
		}
	}
	return m;
				}
//Matrix Post-Increment return and update inc
Matrix operator++(const Matrix& m, int d)
				{
	Matrix temp(m);
	for (int i = 0; i < m.dims_; ++i) {
		for (int j = 0; j < m.dims_; ++j) {
			m.p[j][i] += 1;
		}
	}
	return temp;

				}
////Matrix Post-Decrement return and update dec
Matrix operator--(const Matrix& m, int d)
				{
	Matrix temp(m);
	for (int i = 0; i < m.dims_; ++i) {
		for (int j = 0; j < m.dims_; ++j) {
			m.p[j][i] += -1;
		}
	}
	return temp;

				}

//HELPING FUNCTIONS / matrix variables

void Matrix::allocSpace()
{
	p = new int* [dims_];
	for (int i = 0; i < dims_; ++i) {
		p[i] = new int[dims_];
	}
}
//EXPONENT HELP FUNCTION
Matrix Matrix::expHelper(const Matrix& m, int num)
{
	if (num == 0) {
		return createIdentity(m.dims_);
	}
	else if (num == 1) {
		return m;
	}
	else if (num % 2 == 0) {//exponent(num) is even
		return expHelper(m * m, num / 2);
	}
	else {//exponent(num) is odd
		return m * expHelper(m * m, (num - 1) / 2);
	}
}
//creates identity matrix
//1 0 0
//0 1 0
//0 0 1
Matrix Matrix::createIdentity(int size)
{
	Matrix temp(size);
	for (int i = 0; i < temp.dims_; ++i) {
		for (int j = 0; j < temp.dims_; ++j) {
			if (i == j) {
				temp.p[i][j] = 1;
			}
			else {
				temp.p[i][j] = 0;
			}
		}
	}
	return temp;
}

//Transfer += to + operator for objects Matrix!
//Overloading operators
Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp += m2);
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp -= m2);
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	Matrix temp(m1);
	return (temp *= m2);
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.dims_; ++i) {
		os << m.p[i][0];
		for (int j = 1; j < m.dims_; ++j) {
			os << " " << m.p[i][j];
		}
		os << endl;
	}
	return os;
}
