#include "Complex.h"



Complex::Complex() : realPart(Decimal()), imagePart(Decimal()) {
	this->numType = COM;
}

Complex::Complex(const NumberObject& _numberObject) {
	NumberObject numberObject = _numberObject;
	this->numType = COM;
	this->numData = numberObject.getNumData();

	this->decode();
}

Complex::Complex(string _str) : realPart(Decimal()), imagePart(Decimal()) {
	this->numType = COM;
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}

	this->encode();
}

Complex::Complex(int _number) {
	this->numType = COM;
	this->realPart = _number;
	this->imagePart = 0;

	this->encode();
}

Complex::Complex(const NumberObject& _realPart, const NumberObject& _imagePart) : realPart(_realPart), imagePart(_imagePart) {
	this->numType = COM;

	this->encode();
}


Complex::~Complex() {
}


void Complex::strToNum(const string& _str) {
	regex reg("[-+]?[0-9]*\.?[0-9]*[-+]?([0-9]*\.?[0-9]*i)?");
	string str = _str;

	if(!regex_match(str, reg))
		throw "number format error";
	
	if(str[0] != '+' && str[0] != '-')
		str.insert(str.begin(), '+');
	
	stringstream ss;
	string tmp[2];
	int count = 0;

	ss.str("");
	ss.clear();
	
	ss << str[0];
	for(int i = 1; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			ss >> tmp[count++];
			ss.str("");
			ss.clear();
		}
		ss << str[i];
	}
	ss >> tmp[count++];

	this->realPart = "0";
	this->imagePart = "0";
	for(int i = 0; i < count; i++) {
		if(tmp[i].back() == 'i') {
			tmp[i].pop_back();
			this->imagePart = tmp[i];
		} else {
			this->realPart = tmp[i];
		}
	}
}

void Complex::encode() {
	this->numData.rNumerator = this->realPart.getNumData().rNumerator;
	this->numData.rDenominator = this->realPart.getNumData().rDenominator;
	this->numData.iNumerator = this->imagePart.getNumData().rNumerator;
	this->numData.iDenominator = this->imagePart.getNumData().rDenominator;
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

	try {
		realPart = num1.realPart + num2.realPart;
		imagePart = num1.imagePart + num2.imagePart;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return Complex(realPart, imagePart);
}

NumberObject Complex::sub(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	try {
		realPart = num1.realPart - num2.realPart;
		imagePart = num1.imagePart - num2.imagePart;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return Complex(realPart, imagePart);
}

NumberObject Complex::mul(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;

	try {
		realPart = num1.realPart * num2.realPart - num1.imagePart * num2.imagePart;
		imagePart = num1.realPart * num2.imagePart + num1.imagePart * num2.realPart;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return Complex(realPart, imagePart);
}

NumberObject Complex::div(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Complex num2 = _num2;
	Decimal realPart;
	Decimal imagePart;
	Decimal denominator;

	try {
		denominator = num2.realPart * num2.realPart + num2.imagePart * num2.imagePart;
		realPart = (num1.realPart * num2.realPart + num1.imagePart, num2.imagePart) / denominator;
		imagePart = (-num1.realPart * num2.imagePart + num1.imagePart * num2.realPart) / denominator;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return Complex(realPart, imagePart);
}

NumberObject Complex::power(const NumberObject& _num1, const NumberObject& _num2) {
	Complex num1 = _num1;
	Decimal num2 = _num2;
	Complex ans = 1;

	if(num2 == 0)
		return 1;
	if(num2 < 0)
		throw "can not powered by negative number";
	if(Integer(num2.getNumData().rDenominator, false) > 1)
		throw "can not powwered by decimal";

	Integer count = Integer(num2.getNumData().rNumerator, false) / Integer(num2.getNumData().rDenominator, false);

	for(; count > 0; count = count - 1)
		ans = Complex::mul(ans, num1);

	return ans;
}

NumberObject Complex::minus(const NumberObject& _num) {
	Complex num = _num;

	Decimal realPart = -num.realPart;
	Decimal imagePart = -num.imagePart;

	return Complex(realPart, imagePart);
}


void Complex::output(const NumberObject& _num, ostream& _ostream) {
	Complex num = _num;
	stringstream ss;
	string str;

	ss.str("");
	ss.clear();

	ss << num.realPart;
	ss >> str;
	_ostream << str.substr(0, str.length() - 85) << (num.imagePart.getSign() ? "" : "+");

	ss.str("");
	ss.clear();
	
	ss << num.imagePart;
	ss >> str;
	_ostream << str.substr(0, str.length() - 85) << "i";
}



void Complex::operator =(const string& _str) {
	try {
		this->numType = COM;
		this->strToNum(_str);
		this->encode();
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}

void Complex::operator =(const char* _str) {
	string str(_str);
	try {
		this->numType = COM;
		this->strToNum(_str);
		this->encode();
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}
