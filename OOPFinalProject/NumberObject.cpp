#include "NumberObject.h"



NumberObject::NumberObject() {
}


NumberObject::~NumberObject() {
}


/*
void NumberObject::operator =(const string& _str) {
	this->assign(_str);
}

void NumberObject::operator =(const char* _str) {
	string str(_str);
	this->assign(str);
}
*/

void NumberObject::assign(const string& _str) {
	this->strToNum(_str);
}

/*
NumberObject& operator +(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return num1.add(num2);
}
*/

NumberObject& NumberObject::add(const NumberObject& _num) {
	std::cout << "num add" << std::endl;
	return NumberObject();
}

/*
NumberObject& operator -(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return num1.sub(num2);
}
*/

NumberObject& NumberObject::sub(const NumberObject& _num) {
	return NumberObject();
}

/*
NumberObject& operator *(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return num1.mul(num2);
}
*/

NumberObject& NumberObject::mul(const NumberObject& num) {
	return NumberObject();
}

/*
NumberObject& operator /(const NumberObject& _num1, const NumberObject& _num2) {
	NumberObject num1 = _num1;
	NumberObject num2 = _num2;

	return num1.div(num2);
}
*/

NumberObject& NumberObject::div(const NumberObject& num) {
	return NumberObject();
}

/*
NumberObject& operator -(const NumberObject& _num) {
	NumberObject num = _num;

	return num.minus();
}
*/

NumberObject& NumberObject::minus() {
	return NumberObject();
}


/*
istream& operator >>(istream& _istream, NumberObject& _num) {
	NumberObject num = _num;

	return num.input(_istream);
}
*/

istream& NumberObject::input(istream& _istream) {
	return _istream;
}

/*
ostream& operator <<(ostream& _ostream, const NumberObject& _num) {
	NumberObject num = _num;

	return num.output(_ostream);
}
*/

ostream& NumberObject::output(ostream& _ostream) {
	return _ostream;
}

