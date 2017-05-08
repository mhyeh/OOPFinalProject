#include "Computer.h"



Computer::Computer() {
}


Computer::~Computer() {
}



map<string, NumberObject> Computer::variableSet = map<string, NumberObject>();



NumberObject Computer::getVar(const string& _varName) {
    string varName = _varName;
    auto it = variableSet.find(varName);

    if(it == variableSet.end())
        throw "varable not found";
    
    return variableSet[varName];
}

void Computer::setVar(const string& _varName) {
    string varName = _varName;
	NumberObject varVal;

    variableSet[varName] = varVal;
}

void Computer::setVar(const string& _varName, const string& _varVal) {
    string varName = _varName;
    auto it = variableSet.find(varName);
    string varVal = _varVal;

    Formula f(varVal);

    variableSet[varName] = f.caculate();
}

void Computer::setVar(const string& _varName, const NumberObject& _varVal) {
    string varName = _varName;
	NumberObject varVal = _varVal;

    variableSet[varName] = varVal;
}


void Computer::setFormula(const string& _formula) {
	try {
		this->f = _formula;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

void Computer::caculate() {
	try {
		this->result = this->f.caculate();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

void Computer::print() {
    cout << this->result;
}