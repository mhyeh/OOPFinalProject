#include "NumberObject.h"



NumberObject::NumberObject() {
}


NumberObject::~NumberObject() {
}


NumberObject::NumberObject(string _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}


void NumberObject::operator =(const string& _str) {
	try {
		this->strToNum(_str);
	}
	catch (const char* errorMsg) {
		throw errorMsg;
	}
}


istream& operator >>(istream& _istream, NumberObject& _num) {
	string str;

	_istream >> str;
	_num.strToNum(str);

	return _istream;
}

