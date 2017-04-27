#include "Integer.h"



Integer::Integer() : number(BigNum()), sign(false) {
	this->numType = INTEGER;
	this->lenght = 0;
}

Integer::Integer(const NumberObject& _numberObject) : number(BigNum(0)), sign(false) {
	NumberObject numberObject = _numberObject;
	this->numType = INTEGER;
	this->numData = numberObject.getNumData();

	this->decode();
	this->setLength();
}

Integer::Integer(string _str) : number(BigNum(0)), sign(false) {
	this->numType = INTEGER;

	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}

	this->encode();
	this->setLength();
}

Integer::Integer(long long int _number) : sign(false) {
	this->numType = INTEGER;

	if (_number < 0) {
		sign = true;
		_number = std::labs(_number);
	}
	
	this->number.push_back(_number % MAX_INT);
	if(_number / MAX_INT)
		this->number.push_back(_number / MAX_INT);

	this->encode();
	this->setLength();
}

Integer::Integer(BigNum& _number, bool _sign) : number(_number), sign(_sign) {
	this->numType = INTEGER;

	this->encode();
	this->setLength();
};


Integer::~Integer() {
}



Integer Integer::karatsuba(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	Integer tmp0, tmp1, tmp2;

	if(num1 < MAX_INT && num2 < MAX_INT)
		return num1.number[0] * num2.number[0];

	long long int length = max(num1.getLength(), num2.getLength());
	long long int length2 = length / 2;

	stringstream ss;
	string num1Str, num2Str;
	ss << num1 << " " << num2;
	ss >> num1Str >> num2Str;

	string num1High, num1Low;
	string num2High, num2Low;

	num1High = num1Str.substr(0, length2);
	num1Low = num1Str.substr(length2, length - length2);
	num2High = num2Str.substr(0, length2);
	num2Low = num2Str.substr(length2, length - length2);

	tmp0 = karatsuba(num1Low, num2Low);
	tmp1 = karatsuba((Integer(num1Low) + Integer(num1High)), (Integer(num2Low) + Integer(num2High)));
	tmp2 = karatsuba(num1High, num2High);

	return rShift(tmp2, 2 * length2) + rShift(tmp1 - tmp2 - tmp0, length2) + tmp0;
}



void Integer::strToNum(const string& _str) {
	regex reg("[-+]?[0-9]+");
	string str = _str;
	long long int num = 0;

	if(!regex_match(str, reg))
		throw "number format error";

	reverse(str.begin(), str.end());

	if (str.back() == '-') {
		str.pop_back();
		this->sign = true;
	}

	if (str.back() == '+') 
		str.pop_back();

	for (int i = 0; i < str.length(); i++) {
		num += (str[i] - '0') * pow(10, i % MAX_DIGIT);
		if (i % MAX_DIGIT == MAX_DIGIT - 1 || i == str.length() - 1) {
			this->number.push_back(num);
			num = 0;
		}
	}
}

void Integer::encode() {
	this->numData.rNumerator = this->number;
	this->numData.rDenominator = BigNum(1,1);
	this->numData.iNumerator = BigNum(0);
	this->numData.rDenominator = BigNum(1,1);
	this->numData.rSign = this->sign;
	this->numData.iSign = false;
}

void Integer::decode() {
	this->number = this->getNumData().rNumerator;
	this->sign = this->getNumData().rSign;
}



NumberObject Integer::add(const NumberObject& _num1, const NumberObject& _num2) {
	Integer integer1 = Integer(_num1);
	Integer integer2 = Integer(_num2);
	BigNum num1 = integer1.number;
	BigNum num2 = integer2.number;
	BigNum ans;

	bool num1Sign = integer1.sign;
	bool num2Sign = integer2.sign;

	if (num1Sign == num2Sign) {
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
			swap(num1Sign, num2Sign);
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
			num1Sign = !num1Sign;
	}

	return Integer(ans, num1Sign);
}

NumberObject Integer::sub(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	return num1 + -num2;
}

NumberObject Integer::mul(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	BigNum ans;
	bool sign;
	
	long long int carry = 0;
	long long int num = 0;

	for(int i = 0; i < num1.number.size(); i++) {
		for(int j = 0; j < num2.number.size(); j++) {
			num = (long long int)num1.number[i] * (long long int)num2.number[j] + (long long int)carry;
			if(i + j >= ans.size()) {
				ans.push_back(num % MAX_INT);
				carry = num / MAX_INT;
			} else {
				ans[i + j] += num % MAX_INT;
				carry = (num + (long long int)ans[i + j]) / MAX_INT;
				ans[i + j] %= MAX_INT;
			}
		}
	}
	if(carry)
		ans.push_back(carry);
	
	//ans = karatsuba(abs(num1), abs(num2));

	sign = num1.sign ^ num2.sign;

	return Integer(ans, sign);
}

NumberObject Integer::div(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	BigNum ans;
	bool sign;
	
	if(num2 == 0)
		throw "can not devided by 0";
	if(num1 < num2)
		return Integer(0);
	if(num1 == num2)
		return Integer(1);
	if(num1 == -num2)
		return Integer(-1);

	long long int DigitNum1 = num1.getLength();
	long long int DigitNum2 = num2.getLength() + MAX_DIGIT;

	num2 = rShift(num2, DigitNum1 / DigitNum2 * DigitNum2);


	sign = num1.sign ^ num2.sign;

	return Integer(ans, sign);
}

NumberObject Integer::minus(const NumberObject& _num) {
	Integer integer = Integer(_num);
	BigNum num = integer.number;
	bool sign = !integer.sign;

	return Integer(num, sign);
}


void Integer::output(ostream& _ostream) {
	Integer num = *this;

	reverse(num.number.begin(), num.number.end());

	if(num.sign)
		_ostream << "-";

	_ostream << num.number[0];
	for (int i = 1; i < num.number.size(); i++) {
		_ostream << setw(MAX_DIGIT) << setfill('0');
		_ostream << num.number[i];
	}

}



bool Integer::getSign() {
	return this->sign;
}

void Integer::setSign(bool _sign) {
	this->sign ^= _sign;
}

long long int Integer::getLength() {
	return this->lenght;
}

void Integer::setLength() {
	stringstream ss;
	string back;
	ss.clear();
	ss << this->number.back();
	ss >> back;

	this->lenght = (this->number.size() - 1) * MAX_DIGIT + back.length();
}



void Integer::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}

	this->encode();
}

void Integer::operator =(const char* _str) {
	string str(_str);
	try {
		this->strToNum(str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}

	this->encode();
}


Integer rShift(const Integer& _num, long long int shiftLength) {
	Integer num = _num;
	stringstream ss;
	string str;
	ss.clear();
	ss << num;
	ss >> str;

	while (shiftLength--) 
		str += "0";

	return Integer(str);
}

Integer lShift(const Integer& _num, long long int shiftLength) {
	Integer num = _num;
	stringstream ss;
	string str;
	ss.clear();
	ss << num;
	ss >> str;

	while (shiftLength--) {
		if(str.back() == '0')
			str.pop_back();
		else
			break;
	}

	return Integer(str);
}

Integer abs(const Integer& _num) {
	Integer num = _num;

	return Integer(num.number, false);
}


bool operator ==(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	
	if(num1.sign != num2.sign)
		return false;

	if(num1.number.size() != num2.number.size())
		return false;

	for (int i = 0; i < num1.number.size(); i++) 
		if(num1.number[i] != num2.number[i])
			return false;

	return true;
}

bool operator <(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	if(num1.sign && !num2.sign)
		return true;

	if(!num1.sign && num2.sign)
		return false;

	if(!num1.sign && num1.number.size() < num2.number.size())
		return true;

	if(num1.sign && num1.number.size() > num2.number.size())
		return true;

	for (int i = num1.number.size() - 1; i >= 0; i--) {
		if(!num1.sign && num1.number[i] < num2.number[i])
			return true;
		else if(num1.sign && num1.number[i] > num2.number[i])
			return true;
	}
	
	return false;
}

bool operator <=(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	if(num1 < num2 || num1 == num2)
		return true;

	return false;
}

bool operator >(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	if(num1 <= num2)
		return false;

	return true;
}

bool operator >=(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	if(num1 < num2)
		return false;

	return true;
}