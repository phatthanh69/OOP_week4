#include "CDate.h"
cdate::cdate(void)
{
}
cdate::~cdate(void)
{
}
bool cdate::check(const int& a, const int& b, const int& c)
{
	switch (b)
	{
	case 1:case 3:case 5: case 7: case 8: case 10: case 12:
		if (a <= 0 || a > 31) return false;
		break;
	case 4: case 6: case 9: case 11:
		if (a <= 0 || a > 30) return false;
		break;
	case 2:
		if (c % 400 == 0 || (c % 4 == 0 && c % 100 != 0))
		{
			if (a <= 0 || a > 29) return false;
		}
		else if (a <= 0 || a > 28) return false;
		break;
	default: return false;
	}
	return true;
}
istream& operator>>(istream& in, cdate& d)
{
	bool k;
	do {
		k = false;
		cout << "ngay ="; in >> d.ngay;
		cout << "thang="; in >> d.thang;
		cout << "nam  ="; in >> d.nam;
		k = d.check(d.ngay, d.thang, d.nam);
		if (k == false) cout << "khong hop le!\n";
	} while (!k);
	return in;
}
cdate cdate::operator+(const int& x)
{
	cdate d;
	d.ngay = ngay;
	d.thang = thang;
	d.nam = nam;
	int k = d.ngay + x;
	do {
		switch (d.thang)
		{
		case 1:case 3:case 5: case 7:case 8: case 10: case 12:
			if (k > 31)
			{
				d.thang++;
				if (d.thang == 13)
				{
					d.thang = 1;
					d.nam++;
				}
				k -= 31;
			}
			else
			{
				d.ngay = k;
				k = 0;
			}
			break;
		case 4:case 6: case 9: case 11:
			if (k > 30)
			{
				d.thang++;
				k -= 30;
			}
			else
			{
				d.ngay = k;
				k = 0;
			}
			break;
		case 2:
			if (d.nam % 400 == 0 || (d.nam % 4 == 0 && d.nam % 100 != 0))
			{
				if (k > 29)
				{
					d.thang++;
					k -= 29;
				}
				else
				{
					d.ngay = k;
					k = 0;
				}
			}
			else
			{
				if (k > 28)
				{
					d.thang++;
					k -= 28;
				}
				else
				{
					d.ngay = k;
					k = 0;
				}
			}
			break;
		}
	} while (k > 0);
	return d;
}
ostream& operator<<(ostream& out, const cdate& d)
{
	out << d.ngay << "/" << d.thang << "/" << d.nam;
	return out;
}
cdate cdate::operator-(const int& a)
{
	cdate d;
	d.ngay = ngay;
	d.thang = thang;
	d.nam = nam;
	int x = a;
	do {
		if (d.ngay > x)
		{
			d.ngay -= x;
			x = 0;
		}
		else
		{
			x -= d.ngay;
			d.thang--;
			switch (d.thang)
			{
			case 1:case 3: case 5: case 7: case 8: case 10:
				d.ngay = 31;
				break;
			case 4: case 6: case 9: case 11:
				d.ngay = 30;
				break;
			case 2:
				if (d.nam % 400 == 0 || (d.nam % 4 == 0 && d.nam % 100 != 0)) d.ngay = 29;
				else d.ngay = 28;
				break;
			case 0:
				d.thang = 12;
				d.nam--;
				d.ngay = 31;
				break;
			}
		}
	} while (x > 0);
	return d;
}
long long cdate::operator-(const cdate& d)
{
	cdate x;
	x.ngay = ngay;
	x.thang = thang;
	x.nam = nam;
	long long a = x.ngay;
	do {
		switch (x.thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			a += 31;
			x.thang--;
			if (x.thang == 0)
			{
				x.nam--;
				x.thang = 12;
			}
			break;
		case 4: case 6: case 9: case 11:
			a += 30;
			x.thang--;
			break;
		case 2:
			if (x.nam % 400 == 0 || (x.nam % 4 == 0 && x.nam % 100 != 0))
			{
				a += 29;
				x.thang--;
			}
			else
			{
				a += 28;
				x.thang--;
			}
		}
	} while (x.nam > 0);

	x.ngay = d.ngay;
	x.thang = d.thang;
	x.nam = d.nam;
	long long b = x.ngay;
	do {
		switch (x.thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			b += 31;
			x.thang--;
			if (x.thang == 0)
			{
				x.nam--;
				x.thang = 12;
			}
			break;
		case 4: case 6: case 9: case 11:
			b += 30;
			x.thang--;
			break;
		case 2:
			if (x.nam % 400 == 0 || (x.nam % 4 == 0 && x.nam % 100 != 0))
			{
				b += 29;
				x.thang--;
			}
			else
			{
				b += 28;
				x.thang--;
			}
		}
	} while (x.nam > 0);
	return a - b;
}
void cdate::operator++()
{
	ngay++;
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (ngay > 31)
		{
			ngay = 1;
			thang++;
			if (thang > 12)
			{
				nam++;
				thang = 1;
			}
		}
		break;
	case 4: case 6: case 9: case 11:
		if (ngay > 30)
		{
			ngay = 1;
			thang++;
		}
		break;
	case 2:
		if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		{
			if (ngay > 29)
			{
				ngay = 1;
				thang++;
			}
		}
		else
		{
			if (ngay > 28)
			{
				ngay = 1;
				thang++;
			}
		}
	}
}
void cdate::operator--()
{
	ngay--;
	if (ngay == 0)
	{
		thang--;
		switch (thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10:
			ngay = 31;
			break;
		case 0:
			ngay = 31;
			thang = 12;
			nam--;
			break;
		case 4: case 6: case 9: case 11:
			ngay = 30;
			break;
		case 2:
			if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) ngay = 29;
			else ngay = 28;
			break;
		}
	}
}