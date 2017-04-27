// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: The details of Formula class

#include "Formula.h"



Formula::Formula() {

}

Formula::Formula(string& _formulaStr) {
    this->formulaStr = _formulaStr;

    this->postfix();
}


Formula::~Formula() {

}



void Formula::postfix() {

}

NumberObject Formula::cal(string& _str) {

}



string Formula::setFormula(string& _formulaStr) {
    this->formulaStr = _formulaStr;

    this->postfix();
}

NumberObject Formula::caculate() {
    return this->cal(this->formulaStr);
}