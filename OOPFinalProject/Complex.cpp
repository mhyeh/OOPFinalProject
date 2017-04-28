#include "Complex.h"



Complex::Complex() : realPart(Decimal()), imagePart(Decimal()) {
	this->numType = COMPLEX;
}

Complex::Complex(const NumberObject& _numberObject) {
	NumberObject numberObject = _numberObject;
	this->numType = COMPLEX;
	this->numData = numberObject.getNumData();

	this->decode();
}

Complex::Complex(string _str) : realPart(Decimal()), imagePart(Decimal()) {
	this->numType = COMPLEX;
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}

	this->encode();
}

Complex::Complex(int _number) {
	this->numType = COMPLEX;
	this->realPart = _number;
	this->imagePart = 0;

	this->encode();
}

Complex::Complex(const NumberObject& _realPart, const NumberObject& _imagePart) : realPart(_realPart), imagePart(_imagePart) {
	this->numType = COMPLEX;

	this->encode();
}


Complex::~Complex() {
}


void Complex::strToNum(const string& _str) {
	regex reg("[-+]?[0-9]*\.?[0-9]*[-+]?([0-9]*\.?[0-9]*i)?");
	string str = _str;

	if(!regex_match(str, reg))
		throw "number format error";

	//TODO: convert the string to Complex
}

void Complex::encode() {
	this->numData.rNumerator = this->realPart.getNumData().rNumerator;
	this->numData.rDenominator = this->realPart.getNumData().rDenominator;
	this->numData.iNumerator = this->imagePart.getNumData().rNumerator;
	this->numData.rDenominator = this->imagePart.getNumData().rDenominator;
	this->numData.rSign = this->realPart.getNumData().rSign;
	this->numData.iSign = this->imagePart.getNumData().rSign;
}

void Complex::decode() {
	this->realPart = Decimal(Integer(this->numData.rNumerator, this->numData.rSign), Integer(this->numData.rDenominator, false));
	this->imagePart = Decimal(Integer(this->numData.iNumerator, this->numData.iSign), Integer(this->numData.iDenominator, false));
}


NumberObject Complex::add(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	realPart = Decimal::add(num1.realPart, num2.realPart);
	imagePart = Decimal::add(num1.imagePart, num2.imagePart);

	return Complex(realPart, imagePart);
}

NumberObject Complex::sub(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	realPart = Decimal::sub(num1.realPart, num2.realPart);
	imagePart =  Decimal::sub(num1.imagePart, num2.imagePart);

	return Complex(realPart, imagePart);
}

NumberObject Complex::mul(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	realPart = Decimal::sub(Decimal::mul(num1.realPart, num2.realPart), Decimal::mul(num1.imagePart, num2.imagePart));
	imagePart = Decimal::add(Decimal::mul(num1.realPart, num2.imagePart), Decimal::mul(num1.imagePart, num2.realPart));

	return Complex(realPart, imagePart);
}

NumberObject Complex::div(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;
	Decimal denominator;

	denominator = Decimal::add(Decimal::mul(num2.realPart, num2.realPart), Decimal::mul(num2.imagePart, num2.imagePart));
	realPart = Decimal::div(Decimal::mul(Decimal::mul(num1.realPart, num2.realPart), Decimal::mul(num1.imagePart, num2.imagePart)), denominator);
	imagePart = Decimal::div((Decimal::add(Decimal::mul(Decimal::minus(num1.realPart), num2.imagePart), Decimal::mul(num1.imagePart, num2.realPart))), denominator);

	return Complex(realPart, imagePart);
}

NumberObject Complex::minus(const NumberObject& _num) {
	Complex num = _num;

	Decimal realPart = Decimal::minus(num.realPart);
	Decimal imagePart = Decimal::minus(num.imagePart);

	return Complex(realPart, imagePart);
}


void Complex::output(ostream& _ostream) {
	Complex num = *this;

	_ostream << num.realPart << (num.imagePart.getSign() ? "" : "+") << num.imagePart;
}



void Complex::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}

void Complex::operator =(const char* _str) {
	string str(_str);
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}
