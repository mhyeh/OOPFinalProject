#pragma once

#include "NumberObject.h"
#include "Decimal.h"

class Complex : public NumberObject {
private:
	Decimal realPart, imagePart;

protected:
	void strToNum(const string&) override;
	ostream& output(ostream&) override;

public:
	Complex() : realPart(Decimal()), imagePart(Decimal()) {};
	Complex(string);
	Complex(int);
	Complex(Integer _realPart) : realPart(_realPart), imagePart(Decimal()) {};
	Complex(Decimal _realPart) : realPart(_realPart), imagePart(Decimal()) {};
	Complex(Decimal _realPart, Decimal _imagePart) : realPart(_realPart), imagePart(_imagePart) {};
	~Complex();

	void operator =(const string&);
	void operator =(const char*);

	friend Complex& operator +(const Complex&, const Complex&);
	friend Complex& operator -(const Complex&, const Complex&);
	friend Complex& operator *(const Complex&, const Complex&);
	friend Complex& operator /(const Complex&, const Complex&);
	friend Complex& operator -(const Complex&);

	friend istream& operator >>(istream&, Complex&);
};

