#pragma once
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

class CExpr
{
private:
	char* expr;
public:
	CExpr(char*);
	~CExpr;
	double eval();
};

