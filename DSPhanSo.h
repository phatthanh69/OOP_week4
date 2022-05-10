#pragma once
#include "cPhanSo.h"
class DSPhanSo
{
private:
	cPhanSo* a;
	int n;
public:
	DSPhanSo();
	DSPhanSo(int);
	~DSPhanSo();
	friend istream& operator>>(istream&, DSPhanSo&);
	friend ostream& operator<<(ostream&, DSPhanSo);
	float PSLN();
};

