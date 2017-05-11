// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 6, 2017 
// Problem statement: Handle the formula, to read the input string and calculate it
// Still thinking that maybe we can use design pattern to complete the mathematical operations

#pragma once

#include <string>
#include <stack>

#include "NumberObject.h"

using namespace std;

class Formula {
private:
    string formulaStr;

	void processString();
	void replaceSign();
	void addSpace();
	void inToPostfix();
	int priority(string);
	string changePowerFormat(string);

public:
    Formula();
    Formula(string&);
    ~Formula();

	Formula operator =(const string&);

    string setFormula(string&);
    NumberObject caculate();
};

