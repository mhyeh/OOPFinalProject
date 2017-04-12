#include "Decimal.h"



Decimal::Decimal(string _str) : numerator(Integer()), denominator("1") {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}


Decimal::~Decimal() {
}


void Decimal::strToNum(const string& _str) {
	regex reg("-?[0-9]*\.?[0-9]*");
	string str = _str;
	int decimalPos = 0;

	if(!regex_match(str, reg))
		throw "number format error";

	reverse(str.begin(), str.end());

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			decimalPos = i;
			str.erase(i);
			break;
		}
	}
	reverse(str.begin(), str.end());
	this->numerator = str;

	str = "1";
	while (decimalPos--) {
		str += "0";
	}
	this->denominator = str;
}

void Decimal::checkSign() {
	if (this->denominator.getSign()) {
		this->denominator.setSign(true);
		this->numerator.setSign(true);
	}
}


bool Decimal::getSign() {
	return this->numerator.getSign();
}


/*
Decimal::operator Complex() {
	return Complex(*this, Decimal("0"));
}
*/


void Decimal::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}


Decimal& operator +(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;
	Integer denominator;
	Integer numerator;

	num1.checkSign();
	num2.checkSign();

	if (num1.denominator == num2.denominator) {
		denominator = num1.denominator;
		numerator = num1.numerator + num2.numerator;
	} else {
		denominator = num1.denominator * num2.denominator;
		numerator = num1.numerator * num2.denominator + num1.denominator * num2.numerator;
	}
	bool sign = denominator.getSign() ^ numerator.getSign();

	return Decimal(numerator, denominator);
}

Decimal& operator -(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	num2.numerator.setSign(!num2.numerator.getSign());

	return num1 + num2;
}

Decimal& operator *(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	Integer denominator = num1.denominator * num2.denominator;
	Integer numerator = num1.numerator * num2.numerator;

	return Decimal(numerator, denominator);
}

Decimal& operator /(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	Integer denominator = num1.denominator * num2.numerator;
	Integer numerator = num1.numerator * num2.denominator;

	return Decimal(numerator, denominator);
}

Decimal& operator -(const Decimal& _num) {
	Decimal num = _num;

	num.checkSign();

	Integer numerator = -num.numerator;
	Integer denominator = num.denominator;

	return Decimal(numerator, denominator);
}


istream& operator >>(istream& _istream, Decimal& _num) {
	string str;

	_istream >> str;
	_num.strToNum(str);

	return _istream;
}

ostream& operator <<(ostream& _ostream, const Decimal& _num) {
	//TODO: Output _num

	return _ostream;
}
