// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: The details of Formula class

#include "Formula.h"



Formula::Formula() {

}

Formula::Formula(string& _formulaStr) {
    this->formulaStr = _formulaStr;

	try {
		this->postfix();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}


Formula::~Formula() {

}



void Formula::postfix() {
	int left = 0, right = 0;
	this->formulaStr.erase(remove_if(this->formulaStr.begin(), this->formulaStr.end(), isspace), this->formulaStr.end());
	for (auto &i : this->formulaStr) {
		if (i == '(')
			left += 1;
		else if (i == ')')
			right += 1;
	}
	if (left != right)
		throw "formate is illegal";
}

NumberObject Formula::cal(string& _str) {

	return NumberObject();
}



string Formula::setFormula(string& _formulaStr) {
    this->formulaStr = _formulaStr;

	try {
		this->postfix();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject Formula::caculate() {
	try {
		return this->cal(this->formulaStr);
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}



Formula Formula::operator=(const string& _formulaStr) {
	this->formulaStr = _formulaStr;

	try {
		this->postfix();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}