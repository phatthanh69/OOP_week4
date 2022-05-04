#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class cSoPhuc
{
private:
	float pt, pa;
public:
	cSoPhuc();
	cSoPhuc(float, float);
	cSoPhuc(float);
	friend istream& operator>>(istream&, cSoPhuc&);
	friend ostream& operator<<(ostream&, cSoPhuc&);
	friend bool operator ==(const cSoPhuc&, const cSoPhuc&);
	friend bool operator !=(const cSoPhuc&, const cSoPhuc&);
	friend cSoPhuc operator+(cSoPhuc, cSoPhuc);
	friend cSoPhuc operator-(cSoPhuc, cSoPhuc);
	friend cSoPhuc operator*(cSoPhuc, cSoPhuc);
	friend cSoPhuc operator/(cSoPhuc, cSoPhuc);
};

