#pragma once

#include "NumberObject.h"
#include "Integer.h"

class Decimal : public NumberObject {
private:
	Integer numerator, denominator;

	void checkSign();

protected:
	void strToNum(const string&) override;

public:
	Decimal() : numerator(Integer()), denominator("1") {};
	Decimal(string);
	Decimal(int);
	Decimal(float);
	Decimal(double);
	Decimal(Integer _numerator) : numerator(_numerator), denominator(Integer()) {};
	Decimal(Integer _numerator, Integer _denominator) : numerator(_numerator), denominator(_denominator) {};
	~Decimal();

	bool getSign();

	void operator =(const string&);

	friend Decimal& operator +(const Decimal&, const Decimal&);
	friend Decimal& operator -(const Decimal&, const Decimal&);
	friend Decimal& operator *(const Decimal&, const Decimal&);
	friend Decimal& operator /(const Decimal&, const Decimal&);
	friend Decimal& operator -(const Decimal&);

	friend istream& operator >>(istream&, Decimal&);
	friend ostream& operator <<(ostream&, const Decimal&) override;
};

