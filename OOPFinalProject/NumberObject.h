#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <regex>

#define MAX_DIGIT 8
#define MAX_INT std::pow(10, MAX_DIGIT)

using std::string;
using std::istream;
using std::ostream;
using std::vector;
using std::regex;
using std::regex_match;
using std::swap;
using std::reverse;

typedef vector<long long int> BigNum;

class NumberObject {
private:
	virtual void strToNum(const string&);

public:
	NumberObject();
	NumberObject(string);
	~NumberObject();

	/*
	virtual void operator =(const string&);

	friend virtual NumberObject& operator +(const NumberObject&, const NumberObject&);
	friend virtual NumberObject& operator -(const NumberObject&, const NumberObject&);
	friend virtual NumberObject& operator *(const NumberObject&, const NumberObject&);
	friend virtual NumberObject& operator /(const NumberObject&, const NumberObject&);
	friend virtual NumberObject& operator -(const NumberObject&);

	virtual friend ostream& operator <<(ostream&, const NumberObject&);
	*/
	void operator =(const string&);
	friend istream& operator >>(istream&, NumberObject&);
};