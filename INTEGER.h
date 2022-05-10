#pragma once
#include <iostream>
using namespace std;

class INTEGER
{
private:
	float so;
public:
	INTEGER(void);
	~INTEGER(void);
	friend istream& operator>>(istream&, INTEGER&);
	friend ostream& operator<<(ostream&, INTEGER);
	INTEGER operator+(const INTEGER&);
	INTEGER operator-(const INTEGER&);
	INTEGER operator*(const INTEGER&);
	INTEGER operator/(const INTEGER&);
	void operator++();
	void operator--();
};

