#include "Vector.h"
Vector::Vector()
{
	coords = NULL;
}

Vector::Vector(int N, double x)
{
	n = N;
	coords = new double[n];
	for (int i = 0; i < n; i++)
		coords[i] = x;
}

Vector::Vector(const Vector& a)
{
	n = a.n;
	coords = new double[n];
	for (int i = 0; i < n; i++)
		coords[i] = a.coords[i];
}


Vector::~Vector()
{
	if (coords != NULL)
		delete[] coords;
}

int Vector::Cong(const Vector& a)
{
	if (n != a.n)
		return 0;
	for (int i = 0; i < n; i++)
		coords[i] += a.coords[i];
	return 1;
}

void Vector::NhanK(const double& k)
{
	for (int i = 0; i < n; i++)
		coords[i] *= k;
}

int Vector::Tru(Vector a)
{
	if (n != a.n)
		return 0;
	a.NhanK(-1);
	Cong(a);
	return 1;
}

double Vector::TichVoHuong(const Vector& a)
{
	double res = 0;
	for (int i = 0; i < n; i++)
		res += coords[i] * a.coords[i];
	return res;
}

istream& operator>>(istream& is, Vector& vt)
{
	is >> vt.n;
	vt.coords = new double[vt.n];
	for (int i = 0; i < vt.n; i++)
		is >> vt.coords[i];
	return is;
}

ostream& operator<<(ostream& os, Vector& vt)
{
	for (int i = 0; i < vt.n; i++)
		os << roundf(vt.coords[i] * 100) / 100 << " ";
	os << endl;
	return os;
}
