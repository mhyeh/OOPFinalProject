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

void Formula::check() {
	int left = 0, right = 0;
	bool flagContinous = false, flagSign = false;

	this->formulaStr.erase(remove_if(this->formulaStr.begin(), this->formulaStr.end(), isspace), this->formulaStr.end());
	//erase the spaces

	for (auto &i : this->formulaStr) {
		if (i == '(')
			left += 1;
		else if (i == ')')
			right += 1;
	}
	if (left != right)
		throw "formate is illegal";
	//left and right brackets

	for (unsigned long long pos = 0; pos < this->formulaStr.length(); pos++) {
		if (this->formulaStr[pos] == '+' || this->formulaStr[pos] == '-' || this->formulaStr[pos] == '*' || this->formulaStr[pos] == '/') {
			bool flagcurrentSign = ((this->formulaStr[pos] == '+') ? true : false);
			if (this->formulaStr[pos + 1] == '*' || this->formulaStr[pos + 1] == '/' || this->formulaStr[pos + 1] == ')' || this->formulaStr[pos + 1] == '!')
				throw "format is illegal";
			// /* management
			if (flagContinous == false && (this->formulaStr[pos] == '+' || this->formulaStr[pos] == '-')) {
				flagSign = ((this->formulaStr[pos] == '+') ? true : false);
				flagContinous = true;
			}
			else if (flagContinous == true) {
				flagSign = !(flagSign^flagcurrentSign);
				if (this->formulaStr[pos] == '+' || this->formulaStr[pos] == '-')
					this->formulaStr.erase(this->formulaStr.begin() + pos);
				pos -= 1;
				if (this->formulaStr[pos + 1] != '+'&&this->formulaStr[pos + 1] != '-') {
					this->formulaStr.replace(pos, 1, ((flagSign) ? "+" : "-"));
				}
			}
		}
		if (this->formulaStr[pos] == 'i' || (this->formulaStr[pos] >= '0'&&this->formulaStr[pos] <= '9')) {
			flagContinous = false;
		}
	}
	//clean out the continous operater

}

void Formula::postfix() {
	bool flagContinous = false;
	for (unsigned long long pos = 0; pos < this->formulaStr.length(); pos++) {
		if (this->formulaStr[pos] == 'i' || (this->formulaStr[pos] >= '0'&&this->formulaStr[pos] <= '9')) {
			if (this->formulaStr[pos + 1] != 'i' || (this->formulaStr[pos] <= '0' || this->formulaStr[pos] >= '9'))
				this->formulaStr.insert(pos + 1, " ");
		}
		else {
			if (this->formulaStr[pos + 1] == 'i' || (this->formulaStr[pos + 1] >= '0'&&this->formulaStr[pos + 1] <= '9'))
				this->formulaStr.insert(pos + 1, " ");
		}
	}
	//insert the spaces

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