#include "Computer.h"



NumberObject Computer::getVar(const string& _varName) {
    string varName = _varName;
    auto it = this->variableSet.find(varName);

    if(it == this->variableSet.end())
        throw "varable not found";
    
    return this->variableSet[varName];
}

void Computer::setVar(const string& _varName) {
    string varName = _varName;
    NumberObject varVal = NumberObject();

    this->variableSet[varName] = varVal;
}

void Computer::setVar(const string& _varName, const string& _varVal) {
    string varName = _varName;
    auto it = this->variableSet.find(varName);

    string varVal = _varVal;

    this->setFormula(varVal);
    this->caculate();
    NumberObject number = this->result;
    this->variableSet[varName] = number;
}

void Computer::setVar(const string& _varName, const NumberObject& _varVal) {
    string varName = _varName;
    NumberObject varVal = _varVal;

    this->variableSet[varName] = varVal;
}


void Computer::setFormula(const string&) {
    this->f.clear();
    Formula fObject;

    //TODO: use FormulaFactory to create the formula
}

void Computer::caculate() {
    this->result = Integer("0");

    for(int i = 0; i < f.size(); i++) {
        //TODO: calculate the formula
    }
}

void Computer::print() {
    cout << this->result;
}