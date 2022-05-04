#include "CString.h"
cstring::cstring()
{
}
cstring::~cstring()
{
}
ostream& operator<<(ostream& out, const cstring& a)
{
	out << a.s;
	return out;
}
istream& operator>>(istream& in, cstring& a)
{
	getline(in, a.s);
	return in;
}
cstring cstring::operator+(const cstring& a)
{
	cstring z;
	z.s = s;
	z.s += a.s;
	return z;
}
void cstring::operator=(const cstring& a)
{
	s = a.s;
}
bool cstring::operator<(const cstring& a)
{
	if (s < a.s) return true;
	return false;
}
bool cstring::operator<=(const cstring& a)
{
	if (s <= a.s) return true;
	return false;
}
bool cstring::operator>(const cstring& a)
{
	if (s > a.s) return true;
	return false;
}
bool cstring::operator>=(const cstring& a)
{
	if (s >= a.s) return true;
	return false;
}
bool cstring::operator==(const cstring& a)
{
	if (s == a.s) return true;
	return false;
}
bool cstring::operator!=(const cstring& a)
{
	if (s != a.s) return true;
	return false;
}