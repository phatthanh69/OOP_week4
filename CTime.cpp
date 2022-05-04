#include "CTime.h"
ctime::ctime(int a, int b, int c)
{
	hour = (a < 0 || a>23) ? 0 : a;
	minutes = (b < 0 || b>59) ? 0 : b;
	second = (c < 0 || c>59) ? 0 : c;
}
ctime::~ctime(void)
{
}
ctime ctime::operator+(const int& x)
{
	ctime c;
	int a, b;
	a = (this->second + x) / 60;
	c.second = (this->second + x) % 60;
	b = (this->minutes + a) / 60;
	c.minutes = (this->minutes + a) % 60;
	c.hour = hour + b;
	return c;
}
ostream& operator<<(ostream& out, const ctime& a)
{
	if (a.hour < 0 || a.minutes < 0 || a.second < 0) out << "-";
	out << (a.hour < 10 && a.hour >= 0 ? "0" : "") << abs(a.hour) << ":"
		<< (a.minutes < 10 && a.minutes >= 0 ? "0" : "") << abs(a.minutes) << ":"
		<< (a.second < 10 && a.second >= 0 ? "0" : "") << abs(a.second);
	return out;
}
istream& operator>>(istream& in, ctime& a)
{
	in >> a.hour >> a.minutes >> a.second;
	return in;
}
ctime ctime::operator-(const int& x)
{
	ctime c;
	int a, b;
	a = (this->second - x < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - x : second - x;
	b = (minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes + a : minutes + a;
	c.hour = b + hour;
	if (c.hour < 0)
	{
		a = (-this->second + x < 0) ? -1 : 0;
		c.second = (a == -1) ? 60 - second + x : -second + x;
		b = (-minutes + a) < 0 ? -1 : 0;
		c.minutes = (b == -1) ? 60 - minutes + a : -minutes + a;
		c.hour = -(b - hour);
		if (c.hour == 0)
		{
			if (c.minutes != 0) c.minutes = 0 - c.minutes;
			else if (c.second != 0) c.second = 0 - c.second;
		}
		return c;
	}
	return c;
}
void ctime::operator++()
{
	ctime c;
	int a, b;
	a = (this->second + 1) / 60;
	c.second = (this->second + 1) % 60;
	b = (this->minutes + a) / 60;
	c.minutes = (this->minutes + a) % 60;
	c.hour = hour + b;
	hour = c.hour;
	minutes = c.minutes;
	second = c.second;
}
void ctime::operator--()
{
	ctime c;
	int a, b;
	a = (this->second - 1 < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - 1 : second - 1;
	b = (minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes + a : minutes + a;
	c.hour = b + hour;
	if (c.hour < 0)
	{
		a = (-this->second + 1 < 0) ? -1 : 0;
		c.second = (a == -1) ? 60 - second + 1 : -second + 1;
		b = (-minutes + a) < 0 ? -1 : 0;
		c.minutes = (b == -1) ? 60 - minutes + a : -minutes + a;
		c.hour = -(b - hour);
		if (c.hour == 0)
		{
			if (c.minutes != 0) c.minutes = 0 - c.minutes;
			else if (c.second != 0) c.second = 0 - c.second;
		}
		hour = c.hour;
		minutes = c.minutes;
		second = c.second;
	}
	hour = c.hour;
	minutes = c.minutes;
	second = c.second;
}