// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 6, 2017 
// Problem statement: Handle the formula, to read the input string and calculate it
// Still thinking that maybe we can use design pattern to complete the mathematical operations

#pragma once

#include <string>
#include <vector>
#include "Computer.h"
#include "NumberObject.h"

using std::string;
using std::vector;

class Formula {
private:
    string formulaStr;

    void postfix();
    NumberObject cal(string&);

public:
    Formula();
    Formula(string&);
    ~Formula();

    string setFormula(string&);
    NumberObject caculate();
};

