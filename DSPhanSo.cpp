#include "DSPhanSo.h"

DSPhanSo::DSPhanSo()
{
	n = 0;
	a = NULL;
}

DSPhanSo::DSPhanSo(int x)
{
	n = x;
	a = new cPhanSo[n + 1];
}

DSPhanSo::~DSPhanSo()
{
	delete[] a;
}

float DSPhanSo::PSLN()
{
}

istream& operator>>(istream& is, DSPhanSo& ds)
{
	is >> ds.n;
	ds.a = new cPhanSo[ds.n + 1];
	for (int i = 0; i < ds.n; i++) {
		is >> ds.a[i];
	} return is;
}

ostream& operator<<(ostream& os, DSPhanSo ds)
{
	for (int i = 0; i < ds.n; i++)
		os << ds.a[i] << " ";
	return os;
}
