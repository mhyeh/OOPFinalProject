#pragma once

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <regex>
#include <memory>


#define MAX_DIGIT 8
#define MAX_INT ((long long int)std::pow(10, MAX_DIGIT))

//#define NUM_OBJ 0
//#define INTEGER 1
//#define DECIMAL 2
//#define COMPLEX 3

using namespace std;

typedef vector<long long int> BigNum;

enum NumType {
	NUM_OBJ,
	INTEGER,
	DECIMAL,
	COMPLEX
};

struct NumData {
	BigNum rNumerator;
	BigNum rDenominator;
	BigNum iNumerator;
	BigNum iDenominator;
	int rSign;
	int iSign;
};

class NumberObject {
protected:
	NumData numData;
	NumType numType;

	virtual void strToNum(const string&) {};
	virtual void encode() {};
	virtual void decode() {};

	virtual NumberObject add(const NumberObject&, const NumberObject&) { return NumberObject(); };
	virtual NumberObject sub(const NumberObject&, const NumberObject&) { return NumberObject(); };
	virtual NumberObject mul(const NumberObject&, const NumberObject&) { return NumberObject(); };
	virtual NumberObject div(const NumberObject&, const NumberObject&) { return NumberObject(); };
	virtual NumberObject minus(const NumberObject&) { return NumberObject(); };

	virtual void input(istream&);
	virtual void output(ostream&) {};

public:
	NumberObject() : numType(NUM_OBJ) {};
	NumberObject(string _numStr) : numType(NUM_OBJ) {};
	NumberObject(const NumberObject&);
	~NumberObject();
	
	NumData getNumData() { return this->numData; };
	NumType getNumType() { return this->numType; };

	friend NumberObject* numberFactory(int, int);

	friend NumberObject operator +(const NumberObject&, const NumberObject&);
	friend NumberObject operator -(const NumberObject&, const NumberObject&);
	friend NumberObject operator *(const NumberObject&, const NumberObject&);
	friend NumberObject operator /(const NumberObject&, const NumberObject&);
	friend NumberObject operator -(const NumberObject&);
	
	friend istream& operator >>(istream&, NumberObject&);
	friend ostream& operator <<(ostream&, NumberObject&);
};