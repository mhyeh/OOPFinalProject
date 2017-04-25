#include "Computer.h"



Computer::Computer() {

}


Computer::~Computer() {
	this->result.reset();
	for (auto &i : this->variableSet) {
		i.second.reset();
	}
	this->variableSet.clear();
}


NumberObjectPtr Computer::getVarPtr(const string& _varName) {
    string varName = _varName;
    auto it = this->variableSet.find(varName);

    if(it == this->variableSet.end())
        throw "varable not found";
    
    return this->variableSet[varName];
}

void Computer::setVarPtr(const string& _varName) {
    string varName = _varName;
	NumberObjectPtr varVal(new NumberObject());

    this->variableSet[varName] = varVal;
}

void Computer::setVarPtr(const string& _varName, const string& _varVal) {
    string varName = _varName;
    auto it = this->variableSet.find(varName);

    string varVal = _varVal;

    this->setFormula(varVal);
    this->caculate();

    this->variableSet[varName] = this->result;
}

void Computer::setVarPtr(const string& _varName, const NumberObjectPtr _varVal) {
    string varName = _varName;
	NumberObjectPtr varVal = _varVal;

    this->variableSet[varName] = varVal;
}


void Computer::setFormula(const string&) {
    this->f.clear();
    Formula fObject;

    //TODO: use FormulaFactory to create the formula
}

void Computer::caculate() {
    this->result = NumberObjectPtr(new Integer("0"));

    for(int i = 0; i < f.size(); i++) {
        //TODO: calculate the formula
    }
}

void Computer::print() {
    cout << *(this->result);
}