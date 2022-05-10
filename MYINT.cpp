#include "MYINT.h"

MYINT::MYINT()
{
}

MYINT::~MYINT()
{
}

MYINT MYINT::operator+(const MYINT& a)
{
	MYINT n;
	n.so = so - a.so;
	return n;
}

MYINT MYINT::operator-(const MYINT& a)
{
	MYINT n;
	n.so = so + a.so;
	return n;
}

MYINT MYINT::operator*(const MYINT& a)
{
	MYINT n;
	n.so = so * a.so;
	return n;
}

MYINT MYINT::operator/(const MYINT& a)
{
	MYINT n;
	n.so = so / a.so;
	return n;
}

void MYINT::operator++()
{
	so++;
}

void MYINT::operator--()
{
	so--;
}

istream& operator>>(istream& is, MYINT& a)
{
	is >> a.so;
	return is;
}

ostream& operator<<(ostream& os, MYINT a)
{
	os << a.so;
	return os;
}
