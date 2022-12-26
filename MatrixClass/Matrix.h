#pragma once

#ifndef MATRIX_H
#define __MATRIX_H__
#include <fstream>
#include <iostream>

using namespace std;

class Matrix
{
private:
	int dims_;
	int **p;
	void allocSpace();
	Matrix expHelper(const Matrix&, int);

public:

	Matrix(int);
	Matrix(int,int);
	Matrix(int** ,int);
	Matrix();
	~Matrix();
	Matrix(const Matrix&);

	Matrix& operator+=(Matrix const&);
	Matrix& operator+=(int const);
	Matrix& operator-=(Matrix const&);
	Matrix& operator*=(Matrix const&);
	Matrix operator^(int);
	Matrix transpose();

	friend Matrix operator++(Matrix const&);
	friend Matrix operator--(Matrix const&);
	friend Matrix operator++(Matrix const&, int);
	friend Matrix operator--(Matrix const&, int);

	Matrix createIdentity(int);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);


};

Matrix operator+(Matrix const&, Matrix const&);
Matrix operator-(Matrix const&, Matrix const&);
Matrix operator*(Matrix const&, Matrix const&);
//ostream& operator<<(ostream& out, Matrix const& f);

#endif
