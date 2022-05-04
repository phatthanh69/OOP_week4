#include "cSoPhuc.h"

cSoPhuc::cSoPhuc()
{
	pt = 0;
	pa = 0;
}

cSoPhuc::cSoPhuc(float x, float y)
{
	pt = x;
	pa = y;
}

cSoPhuc::cSoPhuc(float x)
{
	pt = x;
	pa = 0;
}

istream& operator>>(istream& is, cSoPhuc& sp)
{
	cout << "nhap phan thuc: ";
	is >> sp.pt;
	cout << "nhap phan ao: ";
	is >> sp.pa;
	return is;
}

ostream& operator<<(ostream& os, cSoPhuc& sp)
{
	if (sp.pt != 0) {
		os << sp.pt << " + " << sp.pa << "i";
	}
	else os << sp.pa << "i";
	return os;
}

bool operator==(const cSoPhuc& u1, const cSoPhuc& u2)
{
	if (u1.pa == u2.pa && u1.pt == u2.pt) return true;
	return false;
}

bool operator!=(const cSoPhuc& u1, const cSoPhuc& u2)
{
	if (u1.pa != u2.pa && u1.pt != u2.pt) return true;
	return false;
}


cSoPhuc operator+(cSoPhuc u1, cSoPhuc u2)
{
	cSoPhuc u3;
	u3.pt = u1.pt + u2.pt;
	u3.pa = u1.pa + u2.pa;
	return u3;
}

cSoPhuc operator-(cSoPhuc u1, cSoPhuc u2)
{
	cSoPhuc u3;
	u3.pt = u1.pt - u2.pt;
	u3.pa = u1.pa - u2.pa;
	return u3;
}

cSoPhuc operator*(cSoPhuc u1, cSoPhuc u2)
{
	cSoPhuc u3;
	u3.pt = u1.pt * u2.pt - u1.pa * u2.pa;
	u3.pa = u1.pa * u2.pt + u1.pt * u2.pa;
	return u3;
}

cSoPhuc operator/(cSoPhuc u1, cSoPhuc u2)
{
	cSoPhuc u3;
	u3.pt = (u1.pt * u2.pt + u1.pa * u2.pa) / (pow(u1.pt, 2) + pow(u1.pa, 2));
	u3.pa = (u1.pt * u2.pt - u1.pa * u2.pa) / (pow(u1.pt, 2) + pow(u1.pa, 2));
	return u3;
}
