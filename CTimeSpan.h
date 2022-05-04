#pragma once
#include<iostream>
using namespace std;
class ctimespan
{
private:
	int hour, minutes, second;
public:
	ctimespan(int = 0, int = 0, int = 0);
	~ctimespan(void);
	ctimespan operator+(const ctimespan&);
	ctimespan operator-(const ctimespan&);
	bool operator<(ctimespan&);
	bool operator<=(ctimespan&);
	bool operator>(ctimespan&);
	bool operator>=(ctimespan&);
	bool operator==(ctimespan&);
	bool operator!=(ctimespan&);
	friend ostream& operator<<(ostream& out, const ctimespan& a);
	friend istream& operator>>(istream& in, ctimespan& a);
};