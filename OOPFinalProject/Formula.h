// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 6, 2017 
// Problem statement: Handle the formula, to read the input string and calculate it
// Still thinking that maybe we can use design pattern to complete the mathematical operations

#pragma once

#include <string>
#include <vector>
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"

using std::string;
using std::vector;

class Formula {
private:
	string formulaStr;
	NumberObject answer;

public:
	Formula(const string& _formulaStr) formulaStr(_formulaStr), answer() {};
	~Formula();

	void operator =(const string&);

	void seteFormula(const string&);
	void calculate();
	void print();
};

