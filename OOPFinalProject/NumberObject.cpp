#include "NumberObject.h"
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"

using namespace BigNumber;


NumberObject::NumberObject(string _numStr) {
	if (_numStr.back() == 'i') {
		Complex complex = _numStr;
		*this = complex;
	} else {
		bool flag = false;
		for (auto &i : _numStr)
			if (i == '.') {
				flag = true;
				break;
			}
		if (flag) {
			Decimal decimal = _numStr;
			*this = decimal;
		} else {
			Integer decimal = _numStr;
			*this = decimal;
		}
	}
}

NumberObject::NumberObject(const NumberObject& _numberObject) {
	this->numType = _numberObject.numType;
	this->numData = _numberObject.numData;
}

NumberObject::NumberObject(long long int _number) {
	this->numType = INTEGER;
	this->numData = Integer(_number).getNumData();
}


NumberObject::~NumberObject() {
}



void NumberObject::input(istream& _istream) {
	string str;

	_istream >> str;
	try {
		this->strToNum(str);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}



NumberObject* BigNumber::numberFactory(int _type1, int _type2) {
	int type = std::max(_type1, _type2);

	switch (type) {
	case NUM:
		return new NumberObject();
		break;
	case INTEGER:
		return new Integer();
		break;
	case DEC:
		return new Decimal();
		break;
	case COM:
		return new Complex();
		break;
	}
}



NumberObject BigNumber::operator +(const NumberObject& _num1, const NumberObject& _num2) {

	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	try {
		return numberFactory(num1.numType, num2.numType)->add(num1, num2);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject BigNumber::operator -(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	try {
		return numberFactory(num1.numType, num2.numType)->sub(num1, num2);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject BigNumber::operator *(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	try {
		return numberFactory(num1.numType, num2.numType)->mul(num1, num2);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject BigNumber::operator /(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	try {
		return numberFactory(num1.numType, num2.numType)->div(num1, num2);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject BigNumber::operator ^(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	try {
		return numberFactory(num1.numType, num2.numType)->power(num1, num2);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject BigNumber::operator -(const NumberObject& _num) {
	NumberObject num = _num;

	return numberFactory(num.numType, 0)->minus(num);
}


istream& BigNumber::operator >>(istream& _istream, NumberObject& _num) {
	_num.input(_istream);

	return _istream;
};

ostream& BigNumber::operator <<(ostream& _ostream, NumberObject& _num) {
	NumberObject num = _num;

	try {
		numberFactory(num.numType, NUM)->output(num, _ostream);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return _ostream;
};