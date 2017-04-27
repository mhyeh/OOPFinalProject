#include "Computer.h"



Computer::Computer() {
}


Computer::~Computer() {
}


NumberObject Computer::getVarPtr(const string& _varName) {
    string varName = _varName;
    auto it = this->variableSet.find(varName);

    if(it == this->variableSet.end())
        throw "varable not found";
    
    return this->variableSet[varName];
}

void Computer::setVarPtr(const string& _varName) {
    string varName = _varName;
	NumberObject varVal;

    this->variableSet[varName] = varVal;
}

void Computer::setVarPtr(const string& _varName, const string& _varVal) {
    string varName = _varName;
    auto it = this->variableSet.find(varName);
    string varVal = _varVal;

    Formula f(varVal);

    this->variableSet[varName] = f.caculate();
}

void Computer::setVarPtr(const string& _varName, const NumberObject _varVal) {
    string varName = _varName;
	NumberObject varVal = _varVal;

    this->variableSet[varName] = varVal;
}


void Computer::setFormula(const string& _formula) {
    this->f = _formula;
}

void Computer::caculate() {
    this->result = NumberObjectPtr(this->f.caculate());
}

void Computer::print() {
    cout << *(this->result);
}