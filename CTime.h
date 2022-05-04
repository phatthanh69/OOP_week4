#pragma once
#include<iostream>
using namespace std;
class ctime
{
private:
	int hour, minutes, second;
public:
	ctime(int = 0, int = 0, int = 0);
	~ctime(void);
	ctime operator+(const int&);
	ctime operator-(const int&);
	void operator++();
	void operator--();
	friend ostream& operator<<(ostream& out, const ctime& a);
	friend istream& operator>>(istream& in, ctime& a);
};