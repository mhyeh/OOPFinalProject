#include "Formula.h"
#include "Computer.h"
#include "Integer.h"

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

	this->formulaStr = this->changePowerFormat(this->formulaStr);
	this->replaceSign();
	this->addSpace();
	this->inToPostfix();
}

string Formula::changePowerFormat(string _str) {
	string str = _str;
	string result = "";
	string tmp = "";

	bool isPower = false;
	for (long long int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')' || str[i] == '!' || str[i] == ',') {
			isPower = (tmp == "Power");

			if (isPower) {
				if (str[i] != '(')
					throw "format is illegal";

				long long int count = 0;
				long long int j = i + 1;
				string s = "";
				for (int k = 0; k < 2; k++) {
					while (1) {
						if (str[j] == '(')
							count++;
						else if (str[j] == ')')
							count--;

						if (count == 0 && k == 0 && str[j] == ',') {
							result += "(" + changePowerFormat(s) + ")^";
							s = "";
							break;
						} else if (count == -1 && k == 1) {
							result += "(" + changePowerFormat(s) + ")";
							s = "";
							break;
						} else {
							stringstream t;
							t << str[j];
							t >> tmp;
							s += tmp;
						}
						j++;
					}
					j++;
				}

				i += j - i;
			} else
				result += tmp;

			stringstream t;
			t << str[i];
			t >> tmp;
			result += tmp;
			tmp = "";
		} else
			tmp += str[i];
	}
	result += tmp;
	str.erase(remove(str.begin(), str.end(), '\0'), str.end());

	return result;
}

void Formula::replaceSign() {
	string str = this->formulaStr;
	bool flagContinous = false;
	bool flagSign = false;

	for (unsigned long long i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == '^') {
			if (i != str.length() - 1 && (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ')' || str[i + 1] == '!' || str[i + 1] == '^'))
				throw "format is illegal";

			bool flagcurrentSign = ((str[i] == '+') ? true : false);

			if (!flagContinous && (str[i] == '+' || str[i] == '-')) {
				flagSign = ((str[i] == '+') ? true : false);
				flagContinous = true;
			} else if (flagContinous && (str[i] == '+' || str[i] == '-')) {
				str.erase(str.begin() + i);
				i--;

				flagSign = !flagSign ^ flagcurrentSign;
				str.replace(i, 1, ((flagSign) ? "+" : "-"));
			}
		} else if (str[i] == '!') {
			if (i != str.length() - 1 && str[i + 1] != '+' && str[i + 1] != '-' && str[i + 1] != '*' && str[i + 1] != '/' && str[i + 1] != ')' && str[i + 1] != '!')
				throw "format is illegal";
			flagContinous = false;
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
		else if (str[i] == '+' || str[i] == '-') {
			if (str[i + 1] == '(' && (str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^'))
				ss << " " << str[i];
			else
				ss << " " << str[i] << " ";
		} else if (str[i] == '*' || str[i] == '/' || str[i] == ')' || str[i] == '!' || str[i] == '^')
			ss << " " << str[i] << " ";
		else
			ss << str[i];
	}

	getline(ss, this->formulaStr);
}

int Formula::priority(string _opr) {
	if (_opr == ")" || _opr == "@" || _opr == "(")
		return 1;
	else if (_opr == "!")
		return 5;
	else if (_opr == "^")
		return 4;
	else if (_opr == "*" || _opr == "/")
		return 3;
	else if (_opr == "+" || _opr == "-")
		return 2;
}

void Formula::inToPostfix() {
	string str = this->formulaStr;
	stringstream ss;
	
	ss.str("");
	ss.clear();
	
	ss << str;
	str = "";
	
	string tmp;
	stack<string> op;

	while (ss >> tmp) {
		if (tmp == "-(")
			op.push("@");
		else if (tmp == "+(" || tmp == "(")
			op.push("(");
		else if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/" || tmp == "!") {
			while (op.size() > 0 && priority(op.top()) >= priority(tmp)) {
				str += " " + op.top() + " ";
				op.pop();
			}

			op.push(tmp);
		} else if (tmp == "^") {
			while (op.size() > 0 && priority(op.top()) > priority(tmp)) {
				str += " " + op.top() + " ";
				op.pop();
			}

			op.push(tmp);
		} else if (tmp == ")") {
			while (op.size() > 0 && (op.top() != "(" && op.top() != "@")) {
				str += " " + op.top() + " ";
				op.pop();
			}

			if (op.top() == "@")
				str += " @ ";
			op.pop();
		} else 
			str += " " + tmp + " ";
	}

	while (op.size() > 0) {
		str += " " + op.top() + " ";
		op.pop();
	}

	this->formulaStr = str;
}



Formula Formula::operator=(const string& _formulaStr) {
	this->formulaStr = _formulaStr;

	try {
		this->processString();
		return *this;
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
	NumberObject num1, num2;
	try {
		while (ss >> f) {
			if (f == "+") {
				num2 = num.top();
				num.pop();

				if (num.size() > 0) {
					num1 = num.top();
					num.pop();
				}
				else
					num1 = 0;
				num.push(num1 + num2);
			} else if (f == "-") {
				num2 = num.top();
				num.pop();

				if (num.size() > 0) {
					num1 = num.top();
					num.pop();
				}
				else
					num1 = 0;
				num.push(num1 - num2);
			}
			else if (f == "*") {
				num2 = num.top();
				num.pop();
				num1 = num.top();
				num.pop();
				
				num.push(num1 * num2);
			}
			else if (f == "/") {
				num2 = num.top();
				num.pop();
				num1 = num.top();
				num.pop();

				num.push(num1 / num2);
			}
			else if (f == "!") {
				num1 = num.top();
				num.pop();

				if(num1.getNumType() != INTEGER)
					throw "syntax error";

				num.push(factorial(num1));
			}
			else if (f == "@") {
				num1 = num.top();
				num.pop();
				num.push(-num1);
			}
			else if (f == "^") {
				num2 = num.top();
				num.pop();
				num1 = num.top();
				num.pop();

				num.push(num1 ^ num2);
			}
			else if (!isdigit(f[0])) {
				num.push(Computer::getVar(f));
			}
			else
			{
				num.push(f);
			}
		}

		return num.top();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}