#pragma once

#include <vector>
#include <string>
#include "BigNumber.h"

using srd::string;

typedef BigNumber 

class Number {
private:
	BigNumber realPart, imagePart;

public:
	ComplexNum();
	~ComplexNum();

	virtual Number& operator +(const Number&);
	virtual Number& operator -(const Number&);
	virtual Number& operator *(const Number&);
	virtual Number& operator /(const Number&);
	virtual Number& operator -();
}