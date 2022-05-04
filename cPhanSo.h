#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class cPhanSo
{
private:
	int tu, mau;
public:
	cPhanSo();
	cPhanSo(int, int);
	cPhanSo(int);
	friend istream& operator>>(istream&, cPhanSo&);
	friend ostream& operator<<(ostream&, cPhanSo&);
	friend bool operator==(const cPhanSo&, const cPhanSo&);
	friend bool operator!=(const cPhanSo&, const cPhanSo&);
	friend cPhanSo operator+(cPhanSo, cPhanSo);
	friend cPhanSo operator-(cPhanSo, cPhanSo);
	friend cPhanSo operator*(cPhanSo, cPhanSo);
	friend cPhanSo operator/(cPhanSo, cPhanSo);
};

