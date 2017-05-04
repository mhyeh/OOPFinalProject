#include "Integer.h"
#include "Complex.h"


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



Integer Integer::factorial2() {
	if (*this <= 15) {
		long long int i = (*this).number[0];
		long long int ans = 1;
		for(; i > 0; i -= 2)
			ans *= i;
		return ans;
	}
}

Integer Integer::factorial2(const Integer& _num) {
	Integer min = _num;
	Integer ans = *this;

	for (Integer max = *this - 2; max > min; max = max - 2) {
		if (max <= 15) {
			ans = ans * max.factorial2();
			break;
		}
		ans = ans * max;
	}

	if (min == 15) {
		ans = ans * min.factorial2();
	}

	return ans;
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

	for (long long int i = 0; i < str.length(); i++) {
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
	this->numData.iDenominator = BigNum(1,1);
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

		for (long long int i = 0; i < std::max(num1.size(), num2.size()); i++) {
			int num = (i < num1.size() ? num1[i] : 0) + (i < num2.size() ? num2[i] : 0) + carry;
			carry = num / MAX_INT;
			ans.push_back(num % MAX_INT);
		}

		if (carry) 
			ans.push_back(carry);

	} else {
		int borrow = 0;

		if (num1.size() < num2.size()) {
			swap(num1, num2);
			swap(num1Sign, num2Sign);
		}

		for (long long int i = 0; i < num1.size(); i++) {
			int num = (i < num1.size() ? num1[i] : 0) - (i < num2.size() ? num2[i] : 0) - borrow;

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
		while(ans.size() > 1 && ans.back() == 0)
			ans.pop_back();

		if (borrow)
			num1Sign = !num1Sign;
	}

	return Integer(ans, num1Sign);
}

NumberObject Integer::sub(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	return Integer::add(num1, Integer::minus(num2));
}

NumberObject Integer::mul(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	BigNum ans;
	bool sign = num1.sign ^ num2.sign;
	
	long long int num = 0;

	for(long long int i = 0; i < num1.number.size(); i++) {
		long long int carry = 0;
		for(long long int j = 0; j < num2.number.size(); j++) {
			num = (long long int)num1.number[i] * (long long int)num2.number[j] + carry;
			if(i + j >= ans.size()) {
				ans.push_back(num % MAX_INT);
				carry = num / MAX_INT;
			} else {
				ans[i + j] += num % MAX_INT;
				carry = num / MAX_INT + (long long int)ans[i + j] / MAX_INT;
				ans[i + j] %= MAX_INT;
			}
		}
		if(carry)
			ans.push_back(carry);
	}

	return Integer(ans, sign);
}

NumberObject Integer::div(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	BigNum ans;
	bool sign = num1.sign ^ num2.sign;

	num1 = abs(num1);
	num2 = abs(num2);
	
	if(num2 == 0)
		throw "can not devided by 0";
	if(num1 < num2)
		return Integer(0);
	if(num1 == num2)
		return Integer(1);

	long long int DigitNum1 = num1.getLength();
	long long int DigitNum2 = num2.getLength();

	int maxDigit = MAX_DIGIT * 2;
	long long int maxInt = MAX_INT * MAX_INT;
	
	long long int shiftLen = DigitNum1 - DigitNum2 - maxDigit;

	if(shiftLen > 0) {
		while(shiftLen % maxDigit)
		shiftLen++;

		num2 = rShift(num2, shiftLen);
	} else
		shiftLen = 0;
	
	for(long long int i = 0; i < shiftLen / maxDigit + 1; i++) {
		long long int tmp = binSearch(num1, num2, 0, maxInt);
		if(!ans.size())
			ans.push_back(tmp / MAX_INT);
		else
			ans.insert(ans.begin(), tmp / MAX_INT);
		ans.insert(ans.begin(), tmp % MAX_INT);
		num1 = Integer::sub(num1, Integer::mul(num2, tmp));
		num2 = lShift(num2, maxDigit);
	}
	while(ans.size() > 1 && ans.back() == 0)
		ans.pop_back();

	int carry = 0;
	for (long long int i = 0; i < ans.size(); i++) {
		int num = ans[i] + carry;
		ans[i] = num % MAX_INT;
		carry = num / MAX_INT;
	}
	if(carry)
		ans.push_back(carry);

	return Integer(ans, sign);
}

NumberObject Integer::power(const NumberObject& _num1, const NumberObject& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	Integer ans = 1;

	if(num2 < 0)
		throw "can not powered by negative number";
	if(num2 == 0)
		return 1;
	if(num2 == 1)
		return num1;

	for(; num2 > 0; num2 = Integer::sub(num2, 1))
		ans = Integer::mul(ans, num1);

	return ans;
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
	this->sign = _sign;
	this->encode();
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

NumberObject Integer::sqrt() {
	Integer num = *this;
	BigNum ans;
	bool flag = true;

	if (num < 0) {
		num = abs(num);
		flag = false;
	}
	if(num == 0)
		return 0;

	//caculate

	if (!flag) {
		Integer tmp(ans, false);
		stringstream ss;
		string str;

		tmp.output(ss);
		ss >> str;
		return Complex(str + "i");
	}

	return Integer(ans, false);
}



void Integer::operator =(const string& _str) {
	try {
		this->number.clear();
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
		this->number.clear();
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

Integer GCD(const Integer& _num1, const Integer& _num2) {
	Integer num1 = abs(_num1);
	Integer num2 = abs(_num2);

	try {
		while(num2 != 0) { 
			Integer r = num1 % num2; 
			num1 = num2; 
			num2 = r; 
		} 
		return num1;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

Integer GCD(const Integer& _num1, const Integer& _num2, Integer& _num3, Integer& _num4) {
	Integer num1 = abs(_num1);
	Integer num2 = abs(_num2);
	Integer num3 = 1;
	Integer num4 = 0;
	_num3 = 0;
	_num4 = 1;

	try {
		while (true)
		{
			Integer q = num1 / num2;
			Integer r = num1 % num2;
			Integer tmp;

			if (r == 0) 
				break;

			num1 = num2; 
			num2 = r;

			tmp = num3; 
			num3 = _num3; 
			_num3 = tmp - q * _num3;

			tmp = num4; 
			num4 = _num4; 
			_num4 = tmp - q * _num4;
		}
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return num2;
}

Integer factorial(const Integer& _num) {
	Integer num = _num;

	if(num < 0)
		throw "can not caculate the factorial of negative number";

	if (num <= 15) {
		long long int i = num.getNumData().rNumerator[0];
		long long int ans = 1;
		for(; i > 0; i--)
			ans *= i;
		return ans;
	}

	Integer ans = 0;
	long long int count = 0;

	for (Integer tmp = num / 2; tmp > 7; tmp = tmp / 2, count++) {
		ans = ans + tmp;
	}
	ans = 2 ^ ans;

	Integer x = num * 2;
	Integer y = num;
	long long int i = 0;
	bool xFlag = false;
	bool yFlag = false;
	vector<Integer> FVec;
	while (y > 15) {
		x = x / 2;
		if (x % 2 == 0) {
			x = x - 1;
			xFlag = true;
		}

		y = y / 2;
		if (y % 2 == 0) {
			y = y - 1;
			yFlag = true;
		}

		FVec.push_back(x.factorial2(y));

		if (xFlag) {
			x = x + 1;
			xFlag = false;
		}

		if (yFlag) {
			y = y + 1;
			yFlag = false;
		}
	}

	for (long long int i = 0; i < FVec.size(); i++) {
		if(i % 2 == 0)
			ans = ans * FVec[i];
	}

	Integer tmp = 1;
	for (long long int i = FVec.size() - 1; i > 0;) {
		if (i == FVec.size() - 1 && i % 2 == 1) {
			tmp = FVec[i] ^ 2;
			i--;
		}
		else {
			tmp = (tmp * FVec[i] * FVec[i - 1]) ^ 2;
			i -= 2;
		}
	}

	ans = ans * tmp;

	ans = ans * factorial(x / 2);
	return ans;
}


long long int binSearch(const Integer& _num1, const Integer& _num2, long long int lower, long long int upper) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	if(num1 < num2)
		return 0;
	if(num1 == num2)
		return 1;

	if(lower == upper) {
		if(num1 < num2 * lower)
			return lower - 1;
		return lower;
	}

	long long int m = (lower + upper) / 2;

	if(num1 > num2 * m)
		return binSearch(num1, num2, m + 1, upper);
	if(num1 < num2 * m)
		return binSearch(num1, num2, lower, m);
	return m;
}


Integer operator %(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	BigNum ans;
	bool sign = num1.sign ^ num2.sign;

	if(num2 == 0)
		throw "can not devided by 0";

	num1 = abs(num1);
	num2 = abs(num2);
	
	if(num2 == 0)
		return _num1;
	if(num1 < num2)
		return Integer(num1.number, sign);
	if(num1 == num2)
		return 0;

	long long int DigitNum1 = num1.getLength();
	long long int DigitNum2 = num2.getLength();

	int maxDigit = MAX_DIGIT * 2;
	long long int maxInt = MAX_INT * MAX_INT;
	
	long long int shiftLen = DigitNum1 - DigitNum2 - maxDigit;

	if(shiftLen > 0) {
		while(shiftLen % maxDigit)
		shiftLen++;

		num2 = rShift(num2, shiftLen);
	} else
		shiftLen = 0;
	
	int carry = 0;
	for(long long int i = 0; i < shiftLen / maxDigit + 1; i++) {
		long long int tmp = binSearch(num1, num2, 0, maxInt);
		num1 = num1 - num2 * tmp;
		num2 = lShift(num2, maxDigit);
	}

	return Integer(num1.number, sign);
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

bool operator !=(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	return !(num1 == num2);
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
	if(!num1.sign && num1.number.size() > num2.number.size())
		return false;
	if(num1.sign && num1.number.size() > num2.number.size())
		return true;
	if(num1.sign && num1.number.size() < num2.number.size())
		return false;

	for (int i = num1.number.size() - 1; i >= 0; i--) {
		if(!num1.sign && num1.number[i] < num2.number[i])
			return true;
		if(num1.sign && num1.number[i] > num2.number[i])
			return true;
		if(num1.number[i] != num2.number[i])
			return false;
	}
	
	return false;
}

bool operator <=(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	return (num1 < num2 || num1 == num2);
}

bool operator >(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	return !((num1 <= num2));
}

bool operator >=(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	return !(num1 < num2);
}