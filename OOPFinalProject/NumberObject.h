#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <regex>

#define MAX_DIGIT 8
#define MAX_INT ((long long int)std::pow(10, MAX_DIGIT))

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
protected:
	virtual void strToNum(const string&) {};

public:
	NumberObject();
	NumberObject(string);
	~NumberObject();
	
	void operator =(const string&) {};

	/*
	friend NumberObject& operator +(const NumberObject&, const NumberObject&) {};
	friend NumberObject& operator -(const NumberObject&, const NumberObject&) {};
	friend NumberObject& operator *(const NumberObject&, const NumberObject&) {};
	friend NumberObject& operator /(const NumberObject&, const NumberObject&) {};
	friend NumberObject& operator -(const NumberObject&) {};

	friend istream& operator >>(istream&, NumberObject&) {};
	friend ostream& operator <<(ostream&, const NumberObject&) {};
	*/
	friend virtual ostream& operator <<(ostream& _ostream, const NumberObject&) { return _ostream}; //TODO: fix
};