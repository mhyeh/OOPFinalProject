// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 6, 2017 
// Problem statement: Handle the formula, to read the input string and calculate it
// Still thinking that maybe we can use design pattern to complete the mathematical operations

#pragma once

#include <string>
#include <vector>
#include "ComplexNum.h"

using std::string;
using std::vector;

class Formula {
private:
	string formulaStr;
	ComplexNum answer;

public:
	Formula(string);
	~Formula();

	void calculate();
	void print();
};

