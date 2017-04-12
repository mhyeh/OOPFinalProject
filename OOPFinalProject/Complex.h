#pragma once
#include "NumberObject.h"
#include "Decimal.h"

class Complex : public NumberObject {
private:
	Decimal realPart, imagePart;

	void strToNum(const string&);
public:
	Complex() : realPart(Decimal()), imagePart(Decimal()) {};
	Complex(string _str) : realPart(Decimal()), imagePart(Decimal()), NumberObject(_str) {};
	Complex(Decimal _realPart, Decimal _imagePart) : realPart(_realPart), imagePart(_imagePart) {};
	~Complex();

	//void operator =(const string&);

	friend Complex& operator +(const Complex&, const Complex&);
	friend Complex& operator -(const Complex&, const Complex&);
	friend Complex& operator *(const Complex&, const Complex&);
	friend Complex& operator /(const Complex&, const Complex&);
	friend Complex& operator -(const Complex&);

	//friend istream& operator >>(istream&, Complex&);
	friend ostream& operator <<(ostream&, const Complex&);
};

