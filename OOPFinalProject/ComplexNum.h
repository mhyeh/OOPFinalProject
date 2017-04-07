// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: Maintain complex number, define the format and operator of the complex number

#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "BigNumber.h"

using std::sort;
using std::reverse;
using std::string;
using std::vector;

class ComplexNum {
private:
	BigNumber realPart, imagePart;

public:
	ComplexNum() : realPart(), imagePart() {};
	ComplexNum(string&);
	ComplexNum(BigNumber& _realPart, BigNumber& _imagePart) : realPart(_realPart), imagePart(_imagePart) {};
	~ComplexNum();

	friend ComplexNum& operator +(const ComplexNum&, const ComplexNum&);
	friend ComplexNum& operator -(const ComplexNum&, const ComplexNum&);
	friend ComplexNum& operator *(const ComplexNum&, const ComplexNum&);
	friend ComplexNum& operator /(const ComplexNum&, const ComplexNum&);
	friend ComplexNum& operator -(const ComplexNum&);
};

