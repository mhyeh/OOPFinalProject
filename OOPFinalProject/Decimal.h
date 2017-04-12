#pragma once
#include "NumberObject.h"
#include "Integer.h"

class Decimal : NumberObject {
private:
	Integer numerator, denominator;

	void strToNum(const string&);
	void checkSign();
public:
	Decimal() : numerator(Integer()), denominator("1") {};
	Decimal(string);
	Decimal(Integer _numerator, Integer _denominator) : numerator(_numerator), denominator(_denominator) {};
	~Decimal();

	bool getSign();

	operator Complex();

	//void operator =(const string&);

	friend Decimal& operator +(const Decimal&, const Decimal&);
	friend Decimal& operator -(const Decimal&, const Decimal&);
	friend Decimal& operator *(const Decimal&, const Decimal&);
	friend Decimal& operator /(const Decimal&, const Decimal&);
	friend Decimal& operator -(const Decimal&);

	//friend istream& operator >>(istream&, Decimal&);
	friend ostream& operator <<(ostream&, const Decimal&);
};

