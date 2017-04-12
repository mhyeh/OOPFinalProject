#include "Complex.h"



Complex::Complex(string _str) : realPart(Decimal()), imagePart(Decimal()) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}


Complex::~Complex() {
}


void Complex::strToNum(const string& _str) {
	regex reg("-?[0-9]*\.?[0-9]*+?-?([0-9]*\.?[0-9]*i)?");
	string str = _str;

	if(!regex_match(str, reg))
		throw "number format error";

	//TODO: convert the string to Complex
}


/*
void Complex::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}
*/


Complex& operator +(const Complex& _num1, const Complex& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	realPart = num1.realPart + num2.realPart;
	imagePart = num1.imagePart + num2.imagePart;

	return Complex(realPart, imagePart);
}

Complex& operator -(const Complex& _num1, const Complex& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	realPart = num1.realPart - num2.realPart;
	imagePart = num1.imagePart - num2.imagePart;

	return Complex(realPart, imagePart);
}

Complex& operator *(const Complex& _num1, const Complex& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	realPart = num1.realPart * num2.realPart - num1.imagePart * num2.imagePart;
	imagePart = num1.realPart * num2.imagePart + num1.imagePart * num2.realPart;

	return Complex(realPart, imagePart);
}

Complex& operator /(const Complex& _num1, const Complex& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;
	Decimal denominator;

	denominator = num2.realPart * num2.realPart + num2.imagePart * num2.imagePart;
	realPart = (num1.realPart * num2.realPart + num1.imagePart * num2.imagePart) / denominator;
	imagePart = (-num1.realPart * num2.imagePart + num1.imagePart * num2.realPart) / denominator;

	return Complex(realPart, imagePart);
}

Complex& operator -(const Complex& _num) {
	Complex num = _num;

	Decimal realPart = -num.realPart;
	Decimal imagePart = num.imagePart;

	return Complex(realPart, imagePart);
}


/*
istream& operator >>(istream& _istream, Complex& _num) {
string str;

_istream >> str;
_num.strToNum(str);

return _istream;
}
*/

ostream& operator <<(ostream& _ostream, const Complex& _num) {
	Complex num = _num;

	_ostream << num.realPart << (num.imagePart.getSign() ? "" : "+") << num.imagePart;

	return _ostream;
}