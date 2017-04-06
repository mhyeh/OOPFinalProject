// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: Maintain big number, define the format and operator of the big number

#pragma once

#include <vector>
#include <string>
#include <algorithm>

using std::sort;
using std::reverse;
using std::string;
using std::vector;

typedef vector<long long int> BigNum;

/*
* The form of big number: 
* Divide each big number into numerator and denominator
* Each operator is use fractional operation
*/

class BigNumber {
private:
	BigNum numerator, denominator;
	bool sign;

public:
	BigNumber() : numerator(), denominator(), sign(false) {};
	BigNumber(string&);
	BigNumber(BigNum& _numerator, BigNum& _denominator, bool _sign) : numerator(_numerator), denominator(_denominator), sign(_sign) {};
	~BigNumber();

	friend BigNumber& operator +(const BigNumber&, const BigNumber&);
	friend BigNumber& operator -(const BigNumber&, const BigNumber&);
	friend BigNumber& operator *(const BigNumber&, const BigNumber&);
	friend BigNumber& operator /(const BigNumber&, const BigNumber&);
	friend BigNumber& operator -(const BigNumber&);

	friend BigNum& ADD(BigNum&, BigNum&, bool&, bool&);
	friend BigNum& SUB(BigNum&, BigNum&, bool&, bool&);
	friend BigNum& MUL(BigNum&, BigNum&);
};

