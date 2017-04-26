#include "Decimal.h"


Decimal::Decimal() : numerator(Integer()), denominator("1") {
	this->numType = DECIMAL;
}

Decimal::Decimal(const NumberObject& _numberObject) {
	NumberObject numberObject = _numberObject;
	this->numType = INTEGER;
	this->numData = numberObject.getNumData();

	this->decode();
}

Decimal::Decimal(string _str) : numerator(Integer()), denominator("1") {
	this->numType = DECIMAL;
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}

	this->encode();
}

Decimal::Decimal(int _number) {
	this->numType = DECIMAL;
	this->numerator = _number;
	this->denominator = 1;

	this->encode();
}

Decimal::Decimal(const NumberObject& _numerator, const NumberObject& _denominator) : numerator(_numerator), denominator(_denominator) {
	this->numType = DECIMAL;

	this->encode();
}

Decimal::~Decimal() {
}



void Decimal::checkSign() {
	if (this->denominator.getSign()) {
		this->denominator.setSign(true);
		this->numerator.setSign(true);
	}
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
			str.erase(str.begin() + i);
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

void Decimal::encode() {
	this->numData.rNumerator = this->numerator.getNumData().rNumerator;
	this->numData.rDenominator = this->denominator.getNumData().rNumerator;
	this->numData.iNumerator = BigNum(0);
	this->numData.rDenominator = BigNum(1,1);
	this->numData.rSign = this->numerator.getNumData().rSign;
	this->numData.iSign = false;
}

void Decimal::decode() {
	this->numerator = Integer(this->numerator.getNumData().rNumerator, this->numerator.getNumData().rSign);
	this->denominator = Integer(this->denominator.getNumData().rNumerator, false);
}



NumberObject Decimal::add(const NumberObject& _num1, const NumberObject& _num2) {
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

NumberObject Decimal::sub(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	num2.numerator.setSign(!num2.numerator.getSign());

	return num1 + num2;
}

NumberObject Decimal::mul(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();
	
	Integer denominator = num1.denominator * num2.denominator;
	Integer numerator = num1.numerator * num2.numerator;

	return Decimal(numerator, denominator);
}

NumberObject Decimal::div(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	Integer denominator = num1.denominator * num2.numerator;
	Integer numerator = num1.numerator * num2.denominator;

	return Decimal(numerator, denominator);
}

NumberObject Decimal::minus(const NumberObject& _num) {
	Decimal num = _num;

	num.checkSign();

	Integer numerator = -num.numerator;
	Integer denominator = num.denominator;

	return Decimal(numerator, denominator);
}


void Decimal::output(ostream& _ostream) {
	Decimal num = *this;
}



bool Decimal::getSign() {
	return this->numerator.getSign();
}


void Decimal::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}

void Decimal::operator =(const char* _str) {
	string str(_str);
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}
