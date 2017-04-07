// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: The details of BigNumber class

#include "BigNumber.h"


BigNumber::BigNumber(const string& _numStr) {
	string str = _numStr;
	int decimalPos = 0;
	long long int num = 0;

	reverse(str.begin(), str.end());

	if (str.back() == '-') {
		str.pop_back();
		this->sign = true;
	}
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			if(decimalPos)
				throw "number format error";
			decimalPos = i;
		} else {
			if(str[i] < '0' || str[i] > '9')
				throw "number format error";
			num += (str[i] - '0') * pow(10, i % MAX_DIGIT);
			if (i % MAX_DIGIT == MAX_DIGIT - 1 || i == str.length() - 1) {
				this->numerator.push_back(num);
				num = 0;
			}
		}
	}

	for (int i = 0; i < decimalPos / MAX_DIGIT; i++)
		this->denominator.push_back(0);
	this->denominator.push_back(pow(10, decimalPos % MAX_DIGIT));
}

BigNumber::~BigNumber() {
}


BigNumber& operator +(const BigNumber& _num1, const BigNumber& _num2) {
	BigNumber num1 = _num1;
	BigNumber num2 = _num2;
	BigNum denominator;
	BigNum numerator;

	if (num1.denominator == num2.denominator) {
		denominator = num1.denominator;
		numerator = ADD(num1.numerator, num2.numerator, num1.sign, num2.sign);
	} else {
		denominator = MUL(num1.denominator, num2.denominator);
		numerator = ADD(MUL(num1.numerator, num2.denominator), MUL( num1.denominator, num2.numerator), num1.sign, num2.sign);
	}
	bool sign = num1.sign;

	return BigNumber(numerator, denominator, sign);
}

BigNumber& operator -(const BigNumber& _num1, const BigNumber& _num2) {
	BigNumber num1 = _num1;
	BigNumber num2 = _num2;
	BigNum denominator;
	BigNum numerator;

	if (num1.denominator == num2.denominator) {
		denominator = num1.denominator;
		numerator = SUB(num1.numerator, num2.numerator, num1.sign, num2.sign);
	} else {
		denominator = MUL(num1.denominator, num2.denominator);
		numerator = SUB(MUL(num1.numerator, num2.denominator), MUL( num1.denominator, num2.numerator), num1.sign, num2.sign);
	}
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
	BigNum ans;

	if (_num1Sign == _num2Sign) {
		int carry = 0;

		for (int i = 0; i < std::max(num1.size(), num2.size()); i++) {
			long long int num = (i < num1.size() ? num1[i] : 0) + (i < num2.size() ? num2[i] : 0) + carry;
			carry = num / MAX_INT;
			ans.push_back(num);
		}

		if (carry) 
			ans.push_back(carry);

	} else {
		int borrow = 0;

		if (num1.size() < num2.size()) {
			swap(num1, num2);
			swap(_num1Sign, _num2Sign);
		}

		for (int i = 0; i < num1.size(); i++) {
			long long int num = (i < num1.size() ? num1[i] : 0) - (i < num2.size() ? num2[i] : 0) - borrow;

			if (num < 0) {
				if (i < num1.size() - 1) 
					num += MAX_INT;
				else
					num = -num;
				borrow = 1;
			} else 
				borrow = 0;

			ans.push_back(num);
		}

		if (borrow)
			_num1Sign = !_num1Sign;
	}

	return ans;
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