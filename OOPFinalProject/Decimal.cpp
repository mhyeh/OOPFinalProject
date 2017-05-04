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
		this->denominator.setSign(false);
		this->numerator.setSign(!this->numerator.getSign());
		this->encode();
	}
}



void Decimal::strToNum(const string& _str) {
	regex reg("[-+]?[0-9]*\.?[0-9]*");
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
	this->numData.iDenominator = BigNum(1,1);
	this->numData.rSign = this->numerator.getNumData().rSign;
	this->numData.iSign = false;
}

void Decimal::decode() {
	this->numerator = Integer(this->numData.rNumerator, this->numData.rSign);
	this->denominator = Integer(this->numData.rDenominator, false);
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
		try {
			Integer tmp1, tmp2;
			Integer gcd = GCD(num1.denominator, num2.denominator, tmp1, tmp2);

			denominator = num1.denominator * tmp1;
			numerator = num1.numerator * tmp1 + num2.numerator * tmp2;
		}
		catch (const char* errMsg) {
			throw errMsg;
		}
	}
	bool sign = denominator.getSign() ^ numerator.getSign();

	return Decimal(numerator, denominator);
}

NumberObject Decimal::sub(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	try {
		return Decimal::add(num1, Decimal::minus(num2));
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject Decimal::mul(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	try {
		Integer denominator = num1.denominator * num2.denominator;
		Integer numerator = num1.numerator * num2.numerator;
		Integer gcd = GCD(numerator, denominator);

		return Decimal(numerator / gcd, denominator / gcd);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject Decimal::div(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	num1.checkSign();
	num2.checkSign();

	try {
		Integer denominator = num1.denominator * num2.numerator;
		Integer numerator = num1.numerator * num2.denominator;
		Integer gcd = GCD(denominator, numerator);

		return Decimal(numerator / gcd, denominator / gcd);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject Decimal::power(const NumberObject& _num1, const NumberObject& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;
	NumberObject ans = 1;

	if(num2.numerator == 0)
		return 1;
	if(num2.numerator == 1)
		return num1;
	if(num2.numerator < 0)
		throw "can not powered by negative number";
	if(num2.denominator > 2)
		throw "can not powwered by decimal which denominator is larger than 2";

	Integer count = num2.numerator / num2.denominator;

	for(; count > 0; count = count - 1)
		ans = Decimal::mul(ans, num1);
	if(num2.denominator == 2)
		ans = ans * sqrtRoot(num1);

	return ans;
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

	Integer numerator = num.getFlotingNumber(100);
	BigNum tmp = numerator.getNumData().rNumerator;

	reverse(tmp.begin(), tmp.end());

	if(numerator.getSign())
		_ostream << "-";

	stringstream ss;
	for (auto &i : tmp) {
		ss << setw(MAX_DIGIT) << setfill('0');
		ss << i;
	}
	string str, intPart, floatPart;
	ss >> str;
	intPart = str.substr(0, str.length() - 100);
	floatPart = str.substr(str.length() - 100);

	while(intPart.length() > 1 && intPart[0] == '0')
		intPart.erase(intPart.begin());

	_ostream << intPart << "." << floatPart;
}



bool Decimal::getSign() {
	return this->numerator.getSign();
}

Integer Decimal::getFlotingNumber(int _length) {
	try {
		Integer ans = rShift(this->numerator, _length) / this->denominator;
		return ans;
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
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

Decimal sqrtRoot(const NumberObject& _num) {
	Decimal num = _num;

	try{
		NumberObject numerator = num.getFlotingNumber(30).sqrt();
		Integer denominator = rShift(1, 15);

		NumberObject ans;

		if (numerator.getNumType() == COMPLEX) 
			ans = numerator / denominator;
		else 
			ans = Decimal(numerator, denominator);

		return ans;
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}


bool operator ==(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	return num1.numerator == num2.numerator && num1.denominator == num2.denominator;
}

bool operator !=(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	return !(num1 == num2);
}

bool operator <(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	Integer tmp1, tmp2;
	GCD(num1.denominator, num2.denominator, tmp1, tmp2);

	return Integer(num1.numerator * tmp1) < Integer(num2.numerator * tmp2);
}

bool operator <=(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	return (num1 < num2 || num1 == num2);
}

bool operator >(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	return !((num1 <= num2));
}

bool operator >=(const Decimal& _num1, const Decimal& _num2) {
	Decimal num1 = _num1;
	Decimal num2 = _num2;

	return !(num1 < num2);
}
