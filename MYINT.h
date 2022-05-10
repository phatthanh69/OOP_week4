#pragma once
#include <iostream>
using namespace std;

class MYINT
{
private:
	float so;
public:
	MYINT(void);
	~MYINT(void);
	friend istream& operator>>(istream&, MYINT&);
	friend ostream& operator<<(ostream&, MYINT);
	MYINT operator+(const MYINT&);
	MYINT operator-(const MYINT&);
	MYINT operator*(const MYINT&);
	MYINT operator/(const MYINT&);
	void operator++();
	void operator--();
};

