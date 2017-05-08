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
	string str = this->formulaStr;
	int left = 0, right = 0;
	bool flagContinous = false, flagSign = false;

	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());

	for (auto &i : str) {
		if (i == '(')
			left += 1;
		else if (i == ')')
			right += 1;
	}
	if (left != right)
		throw "formate is illegal";

	for (unsigned long long i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			bool flagcurrentSign = ((str[i] == '+') ? true : false);
			if (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ')' || str[i + 1] == '!')
				throw "format is illegal";
			if (flagContinous == false && (str[i] == '+' || str[i] == '-')) {
				flagSign = ((str[i] == '+') ? true : false);
				flagContinous = true;
			}
			else if (flagContinous == true) {
				flagSign = !(flagSign^flagcurrentSign);
				if (str[i] == '+' || str[i] == '-')
					str.erase(str.begin() + i);
				i -= 1;
				if (str[i + 1] != '+'&&str[i + 1] != '-') {
					str.replace(i, 1, ((flagSign) ? "+" : "-"));
				}
			}
		}
		if (str[i] == 'i' || (str[i] >= '0'&&str[i] <= '9')) {
			flagContinous = false;
		}
	}

	stringstream ss;
	ss.str("");
	ss.clear();

	for (unsigned long long i = 0; i < str.length(); i++) {
    	if (str[i] == '(')
        	ss << str[i] << " ";
    	else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ')') {
        	if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '(' || str[i - 1] == ')')
            	ss << str[i];
			else
				ss << " " << str[i] << " ";
		} else
			ss << str[i];
	}
	getline(ss, this->formulaStr);

}

void Formula::postfix() {
	


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