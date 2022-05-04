#include "cPhanSo.h"

cPhanSo::cPhanSo()
{
	tu = 0;
	mau = 0;
}

cPhanSo::cPhanSo(int x, int y)
{
	tu = x;
	mau = y;
}

cPhanSo::cPhanSo(int x)
{
	tu = x;
	mau = 1;
}

istream& operator>>(istream& is, cPhanSo& ps)
{
	cout << "nhap tu so: ";
	is >> ps.tu;
	cout << "nhap mau so: ";
	is >> ps.mau;
	while (ps.mau == 0) {
		cout << "mau phai khac 0, nhap lai: ";
		is >> ps.mau;
	};
	return is;
}

ostream& operator<<(ostream& os, cPhanSo& ps)
{
	if (ps.tu == 0) os << 0;
	if (ps.mau == 1) os << ps.tu;
	else os << ps.tu << "/" << ps.mau;
	return os;
}

bool operator==(const cPhanSo& u1, const cPhanSo& u2)
{
	if (u1.tu == u2.tu && u1.mau == u2.mau) return true;
	if (u1.tu == 0 && u2.tu == 0) return true;
	return false;
}

bool operator!=(const cPhanSo& u1, const cPhanSo& u2)
{
	if (u1.tu == u2.tu && u1.mau == u2.mau) return false;
	if (u1.tu == 0 && u2.tu == 0) return false;
	return true;
}

cPhanSo operator+(cPhanSo u1, cPhanSo u2)
{
	cPhanSo u3;
	u3.tu = u1.mau * u2.tu + u2.mau * u1.tu;
	u3.mau = u1.mau * u2.mau;
	return u3;
}

cPhanSo operator-(cPhanSo u1, cPhanSo u2)
{
	cPhanSo u3;
	u3.tu = u1.mau * u2.tu - u2.mau * u1.tu;
	u3.mau = u1.mau * u2.mau;
	return u3;
}

cPhanSo operator*(cPhanSo u1, cPhanSo u2)
{
	cPhanSo u3;
	u3.tu = u1.tu * u2.tu;
	u3.mau = u1.mau * u2.mau;
	return u3;
}

cPhanSo operator/(cPhanSo u1, cPhanSo u2)
{
	cPhanSo u3;
	u3.tu = u1.tu * u2.mau;
	u3.mau = u1.mau * u2.tu;
	return u3;
}
