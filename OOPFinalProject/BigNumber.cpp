#include "BigNumber.h"


BigNumber::BigNumber(string& _numStr) {
	//TODO: set numerator and denominator and sign
}

BigNumber::~BigNumber() {
}


BigNumber& operator +(const BigNumber& _num1, const BigNumber& _num2) {
	BigNumber num1 = _num1;
	BigNumber num2 = _num2;
	BigNum denominator = MUL(num1.denominator, num2.denominator);
	BigNum numerator = ADD(MUL(num1.numerator, num2.denominator), MUL( num1.denominator, num2.numerator), num1.sign, num2.sign);
	bool sign = num1.sign;

	return BigNumber(numerator, denominator, sign);
}

BigNumber& operator -(const BigNumber& _num1, const BigNumber& _num2) {
	BigNumber num1 = _num1;
	BigNumber num2 = _num2;
	BigNum denominator = MUL(num1.denominator, num2.denominator);
	BigNum numerator = SUB(MUL(num1.numerator, num2.denominator), MUL( num1.denominator, num2.numerator), num1.sign, num2.sign);
	bool sign = num1.sign;

	return BigNumber(numerator, denominator, sign);
}

BigNumber& operator *(const BigNumber& _num1, const BigNumber& _num2) {
	BigNumber num1 = _num1;
	BigNumber num2 = _num2;
	BigNum denominator = MUL(num1.denominator, num2.denominator);
	BigNum numerator = MUL(num1.numerator, num2.numerator);
	bool sign = !num1.sign ^ num2.sign;

	return BigNumber(numerator, denominator, sign);
}

BigNumber& operator /(const BigNumber& _num1, const BigNumber& _num2) {
	BigNumber num1 = _num1;
	BigNumber num2 = _num2;
	BigNum denominator = MUL(num1.denominator, num2.numerator);
	BigNum numerator = MUL(num1.denominator, num2.numerator);
	bool sign = !num1.sign ^ num2.sign;

	return BigNumber(numerator, denominator, sign);
}

BigNumber& operator -(const BigNumber& _num) {
	BigNum denominator = _num.denominator;
	BigNum numerator = _num.numerator;
	bool sign = !_num.sign;

	return BigNumber(numerator, denominator, sign);
}


BigNum& ADD(const BigNum& _num1, const BigNum& _num2, bool& _num1Sign, bool& _num2Sign) {
	BigNum num1 = _num1;
	BigNum num2 = _num2;

	//TODO: Add num1 and num2
}

BigNum& SUB(const BigNum& _num1, const BigNum& _num2, bool& _num1Sign, bool& _num2Sign) {
	BigNum num1 = _num1;
	BigNum num2 = _num2;

	_num2Sign = !_num2Sign;
	return ADD(num1, num2, _num1Sign, _num2Sign);
}

BigNum& MUL(const BigNum& _num1, const BigNum& _num2) {
	BigNum num1 = _num1;
	BigNum num2 = _num2;

	//TODO: Mul num1 and num2
}