#include "CTimeSpan.h"
ctimespan::ctimespan(int a, int b, int c)
{
	hour = (a < 0 || a>23) ? 0 : a;
	minutes = (b < 0 || b>59) ? 0 : b;
	second = (c < 0 || c>59) ? 0 : c;
}
ctimespan::~ctimespan(void)
{
}
ctimespan ctimespan::operator+(const ctimespan& x)
{
	ctimespan c;
	int a, b;
	a = (this->second + x.second) / 60;
	c.second = (this->second + x.second) % 60;
	b = (this->minutes + x.minutes + a) / 60;
	c.minutes = (this->minutes + x.minutes + a) % 60;
	c.hour = hour + b + x.hour;
	return c;
}
ostream& operator<<(ostream& out, const ctimespan& a)
{
	if (a.hour < 0 || a.minutes < 0 || a.second < 0) out << "-";
	out << (a.hour < 10 && a.hour >= 0 ? "0" : "") << abs(a.hour) << ":"
		<< (a.minutes < 10 && a.minutes >= 0 ? "0" : "") << abs(a.minutes) << ":"
		<< (a.second < 10 && a.second >= 0 ? "0" : "") << abs(a.second);
	return out;
}
istream& operator>>(istream& in, ctimespan& a)
{
	in >> a.hour >> a.minutes >> a.second;
	return in;
}
ctimespan ctimespan::operator-(const ctimespan& x)
{
	ctimespan c;
	int a, b;
	a = (this->second - x.second < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - x.second : second - x.second;
	b = (minutes - x.minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes - x.minutes + a : minutes - x.minutes + a;
	c.hour = b + hour - x.hour;
	if (c.hour < 0)
	{
		a = (-this->second + x.second < 0) ? -1 : 0;
		c.second = (a == -1) ? 60 - second + x.second : -second + x.second;
		b = (-minutes + x.minutes + a) < 0 ? -1 : 0;
		c.minutes = (b == -1) ? 60 - minutes + x.minutes + a : -minutes + x.minutes + a;
		c.hour = -(b - hour + x.hour);
		return c;
	}
	return c;
}

bool ctimespan::operator<(ctimespan& x)
{
	ctimespan c;
	int a, b;
	a = (this->second - x.second < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - x.second : second - x.second;
	b = (minutes - x.minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes - x.minutes + a : minutes - x.minutes + a;
	c.hour = b + hour - x.hour;
	if (c.hour < 0) return true; return false;
}
bool ctimespan::operator<=(ctimespan& x)
{
	ctimespan c;
	int a, b;
	a = (this->second - x.second < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - x.second : second - x.second;
	b = (minutes - x.minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes - x.minutes + a : minutes - x.minutes + a;
	c.hour = b + hour - x.hour;
	if (c.hour <= 0) return true; return false;
}
bool ctimespan::operator>(ctimespan& x)
{
	ctimespan c;
	int a, b;
	a = (this->second - x.second < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - x.second : second - x.second;
	b = (minutes - x.minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes - x.minutes + a : minutes - x.minutes + a;
	c.hour = b + hour - x.hour;

	if (c.hour >= 0 && (c.minutes != 0 || c.second != 0)) return true; return false;
}
bool ctimespan::operator>=(ctimespan& x)
{
	ctimespan c;
	int a, b;
	a = (this->second - x.second < 0) ? -1 : 0;
	c.second = (a == -1) ? 60 + second - x.second : second - x.second;
	b = (minutes - x.minutes + a) < 0 ? -1 : 0;
	c.minutes = (b == -1) ? 60 + minutes - x.minutes + a : minutes - x.minutes + a;
	c.hour = b + hour - x.hour;
	if (c.hour >= 0 && c.minutes >= 0 && c.second >= 0) return true; return false;
}
bool ctimespan::operator==(ctimespan& x)
{
	if (second == x.second && minutes == x.minutes && hour == x.hour) return true; return false;
}
bool ctimespan::operator!=(ctimespan& x)
{
	if (second != x.second || minutes != x.minutes || hour != x.hour) return true; return false;
}