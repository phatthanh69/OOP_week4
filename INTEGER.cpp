#include "INTEGER.h"

INTEGER::INTEGER()
{
}

INTEGER::~INTEGER()
{
}

INTEGER INTEGER::operator+(const INTEGER& a)
{
	INTEGER n;
	n.so = so + a.so;
	return n;
}

INTEGER INTEGER::operator-(const INTEGER& a)
{
	INTEGER n;
	n.so = so - a.so;
	return n;
}

INTEGER INTEGER::operator*(const INTEGER& a)
{
	INTEGER n;
	n.so = so * a.so;
	return n;
}

INTEGER INTEGER::operator/(const INTEGER& a)
{
	INTEGER n;
	n.so = so / a.so;
	return n;
}

void INTEGER::operator++()
{
	so++;
}

void INTEGER::operator--()
{
	so--;
}

istream& operator>>(istream& is, INTEGER& a)
{
	is >> a.so;
	return is;
}

ostream& operator<<(ostream& os, INTEGER a)
{
	os << a.so;
	return os;
}
