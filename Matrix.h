#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;
class Matrix
{
private:
	int m; // dòng
	int n; // cột
	double** elements;
public:
	Matrix();
	~Matrix();
	Matrix(const Matrix& a);
	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix&);
	int Cong(const Matrix& a); // return 1 nếu cộng dc
	void Nhan(const double& k);// Nhân với 1 số K
	int Nhan(const Matrix& a);// NHân với 1 CMatrix, return 1 nếu nhân đc
	friend Vector multiply(const Matrix&, const Vector&);
};

