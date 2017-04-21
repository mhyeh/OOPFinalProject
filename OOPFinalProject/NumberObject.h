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
	virtual void strToNum(const string&) = 0;

	virtual ostream& output(ostream&) = 0;

public:
	NumberObject() = default;
	~NumberObject() = default;
	
	
	void operator =(const string& _str) {
		try {
			this->strToNum(_str);
		}
		catch (const char* errorMsg) {
			throw errorMsg;
		}
	};

	void operator =(const char* _str) {
		string str(_str);
		try {
			this->strToNum(_str);
		}
		catch (const char* errorMsg) {
			throw errorMsg;
		}
	};
	
	
	/*
	friend NumberObject& operator +(const NumberObject&, const NumberObject&);
	friend NumberObject& operator -(const NumberObject&, const NumberObject&);
	friend NumberObject& operator *(const NumberObject&, const NumberObject&);
	friend NumberObject& operator /(const NumberObject&, const NumberObject&);
	friend NumberObject& operator -(const NumberObject&);

	friend istream& operator >>(istream&, NumberObject&);
	
	*/
	friend ostream& operator <<(ostream& _ostream, NumberObject& _num) {
		_num.output(_ostream);

		return _ostream;
	};
};