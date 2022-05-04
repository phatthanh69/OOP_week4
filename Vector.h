#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;
class Vector
{
private:
	double* coords;
	int n;
public:

	Vector();
	Vector(int, double);
	Vector(const Vector&);
	~Vector();
	friend istream& operator>>(istream&, Vector&);
	friend ostream& operator<<(ostream&, Vector&);
	int Cong(const Vector&);
	void NhanK(const double&);
	int Tru(Vector);
	double TichVoHuong(const Vector&);
	friend Vector multiply(const Matrix&, const Vector&);
};

