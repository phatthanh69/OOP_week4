#pragma once
#include<iostream>
#include<string>
using namespace std;
class cstring
{
private:
	string s;
public:
	cstring();
	~cstring();
	friend ostream& operator<<(ostream& out, const cstring& a);
	friend istream& operator>>(istream& in, cstring& a);
	cstring operator+(const cstring& a);
	void operator=(const cstring& a);
	bool operator<(const cstring& a);
	bool operator<=(const cstring& a);
	bool operator>(const cstring& a);
	bool operator>=(const cstring& a);
	bool operator==(const cstring& a);
	bool operator!=(const cstring& a);
};
