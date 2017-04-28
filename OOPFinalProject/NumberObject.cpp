#include "NumberObject.h"
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"



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



NumberObject* numberFactory(int _type1, int _type2) {
	int type = std::max(_type1, _type2);

	switch (type) {
	case NUM_OBJ:
		return new NumberObject();
		break;
	case INTEGER:
		return new Integer();
		break;
	case DECIMAL:
		return new Decimal();
		break;
	case COMPLEX:
		return new Complex();
		break;
	}
}


NumberObject operator +(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return numberFactory(num1.numType, num2.numType)->add(num1, num2);
}

NumberObject operator -(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return numberFactory(num1.numType, num2.numType)->sub(num1, num2);
}

NumberObject operator *(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return numberFactory(num1.numType, num2.numType)->mul(num1, num2);
}

NumberObject operator /(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	try {
		return numberFactory(num1.numType, num2.numType)->div(num1, num2);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject operator -(const NumberObject& _num) {
	NumberObject num = _num;

	return numberFactory(num.numType, 0)->minus(num);
}


istream& operator >>(istream& _istream, NumberObject& _num) {
	_num.input(_istream);

	return _istream;
};

ostream& operator <<(ostream& _ostream, NumberObject& _num) {
	try {
		_num.output(_ostream);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}

	return _ostream;
};