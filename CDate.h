#pragma once
#include<iostream>
using namespace std;
class cdate
{
private:
	int ngay, thang, nam;
public:
	cdate(void);
	~cdate(void);
	bool check(const int&, const int&, const int&);
	cdate operator+(const int&);
	cdate operator-(const int&);
	long long operator-(const cdate&);
	void operator++();
	void operator--();
	friend ostream& operator<<(ostream& out, const cdate&);
	friend istream& operator>>(istream& in, cdate&);
};

