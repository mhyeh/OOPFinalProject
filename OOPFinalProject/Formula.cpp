// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: The details of Formula class

#include "Formula.h"
#include "Computer.h"


Formula::Formula() {

}

Formula::Formula(string& _formulaStr) {
    this->formulaStr = _formulaStr;

	try {
		this->processString();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}


Formula::~Formula() {

}



void Formula::processString() {
	string str = this->formulaStr;
	long long int count = 0;

	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());

	for (auto &i : str) {
		if (i == '(')
			count++;
		else if (i == ')')
			count--;
	}
	if (count != 0)
		throw "formate is illegal";

	this->formulaStr = str;

	this->replaceSign();
	this->addSpace();
	this->inToPostfix();
}

void Formula::replaceSign() {
	string str = this->formulaStr;
	bool flagContinous = false;
	bool flagSign = false;

	for (unsigned long long i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ')' || str[i + 1] == '!')
				throw "format is illegal";

			bool flagcurrentSign = ((str[i] == '+') ? true : false);

			if (!flagContinous && (str[i] == '+' || str[i] == '-')) {
				flagSign = ((str[i] == '+') ? true : false);
				flagContinous = true;
			} else if (flagContinous) {
				if (str[i] == '+' || str[i] == '-')
					str.erase(str.begin() + i);
				i--;

				flagSign = !flagSign ^ flagcurrentSign;
				if (str[i + 1] != '+'&&str[i + 1] != '-') 
					str.replace(i, 1, ((flagSign) ? "+" : "-"));
			}
		} else
			flagContinous = false;
	}

	this->formulaStr = str;
}

void Formula::addSpace() {
	string str = this->formulaStr;
	stringstream ss;

	ss.str("");
	ss.clear();

	for (unsigned long long i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			ss << str[i] << " ";
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ')') {
			if (i > 0 && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '(' || str[i - 1] == ')'))
				ss << str[i];
			else
				ss << " " << str[i] << " ";
		} else
			ss << str[i];
	}

	getline(ss, this->formulaStr);
}

void Formula::inToPostfix() {



}



Formula Formula::operator=(const string& _formulaStr) {
	this->formulaStr = _formulaStr;

	try {
		this->processString();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}



string Formula::setFormula(string& _formulaStr) {
    this->formulaStr = _formulaStr;

	try {
		this->processString();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject Formula::caculate() {
	stack<NumberObject> num;
	stringstream ss;
	string f;

	ss.str("");
	ss.clear();
	ss << this->formulaStr;

	try {
		while (ss >> f) {

		}

		return num.top();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}