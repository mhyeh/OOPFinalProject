#include "Integer.h"



Integer::Integer(string _str) : number(BigNum(0)), sign(false) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}

Integer::Integer(int _number) : sign(false) {
	if(_number < 0)
		sign = true;

	this->number.push_back(std::labs(_number));
}


Integer::~Integer() {
}


void Integer::strToNum(const string& _str) {
	regex reg("-?[0-9]+");
	string str = _str;
	long long int num = 0;

	if(!regex_match(str, reg))
		throw "number format error";

	reverse(str.begin(), str.end());

	if (str.back() == '-') {
		str.pop_back();
		this->sign = true;
	}

	for (int i = 0; i < str.length(); i++) {
		num += (str[i] - '0') * pow(10, i % MAX_DIGIT);
		if (i % MAX_DIGIT == MAX_DIGIT - 1 || i == str.length() - 1) {
			this->number.push_back(num);
			num = 0;
		}
	}
}


void Integer::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}

void Integer::operator =(const char* _str) {
	string str(_str);
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}

/*
NumberObject& Integer::add(const NumberObject&) {
	std::cout << "int add" << std::endl;
	return Integer();
}

NumberObject& Integer::sub(const NumberObject&) {
	return Integer();
}

NumberObject& Integer::mul(const NumberObject&) {
	return Integer();
}

NumberObject& Integer::div(const NumberObject&) {
	return Integer();
}

NumberObject& Integer::minus() {
	return Integer();
}


istream& Integer::input(istream& _istream) {
	return _istream;
}
*/

ostream& Integer::output(ostream& _ostream) {
	Integer num = *this;

	reverse(num.number.begin(), num.number.end());

	if(num.sign)
		_ostream << "-";

	for(auto &i : num.number)
		_ostream << i;

	return _ostream;
}


bool Integer::getSign() {
	return this->sign;
}

void Integer::setSign(bool _sign) {
	this->sign ^= _sign;
}


Integer operator +(const Integer& _num1, const Integer& _num2) {
	BigNum num1 = _num1.number;
	BigNum num2 = _num2.number;
	BigNum ans;

	bool num1Sign = _num1.sign;
	bool num2Sign = _num2.sign;

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

Integer operator -(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;

	num2.sign = !num2.sign;
	return num1 + num2;
}

Integer operator *(const Integer& _num1, const Integer& _num2) {
	Integer num1 = _num1;
	Integer num2 = _num2;
	BigNum ans;
	bool sign;
	long long int carry = 0;
	long long int num = 0;

	for(int i = 0; i < num1.number.size(); i++) {
		for(int j = 0; j < num2.number.size(); j++) {
			num = num1.number[i] * num2.number[j] + carry;
			if(i + j >= ans.size()) {
				ans.push_back(num % MAX_INT);
				carry = num / MAX_INT;
			} else {
				ans[i + j] += num % MAX_INT;
				carry = (num + ans[i + j]) / MAX_INT;
				ans[i + j] %= MAX_INT;
			}
		}
	}
	if(carry)
		ans.push_back(carry);

	sign = num1.sign ^ num2.sign;

	return Integer(ans, sign);
}

Integer operator /(const Integer& _num1, const Integer& _num2) {
	BigNum num1 = _num1.number;
	BigNum num2 = _num2.number;
	BigNum ans;
	bool sign;

	//TODO: Caculate _num1 / _num2 and return

	return Integer(ans, sign);
}

Integer operator -(const Integer& _num) {
	BigNum num = _num.number;
	bool sign = !_num.sign;

	return Integer(num, sign);
}


istream& operator >>(istream& _istream, Integer& _num) {
	string str;

	_istream >> str;
	_num.strToNum(str);

	return _istream;
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