// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: Maintain big number, define the format and operator of the big number

#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX_INT 10000000000
#define MAX_DIGIT 10

using std::pow;
using std::sort;
using std::swap;
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
	BigNumber(const string&);
	BigNumber(const BigNum& _numerator, const BigNum& _denominator, bool _sign) : numerator(_numerator), denominator(_denominator), sign(_sign) {};
	~BigNumber();

	friend BigNumber& operator +(const BigNumber&, const BigNumber&);
	friend BigNumber& operator -(const BigNumber&, const BigNumber&);
	friend BigNumber& operator *(const BigNumber&, const BigNumber&);
	friend BigNumber& operator /(const BigNumber&, const BigNumber&);
	friend BigNumber& operator -(const BigNumber&);

	friend bool operator ==(const BigNum&, const BigNum&);

	friend BigNum& ADD(const BigNum&, const BigNum&, bool&, bool&);
	friend BigNum& SUB(const BigNum&, const BigNum&, bool&, bool&);
	friend BigNum& MUL(const BigNum&, const BigNum&);
};

