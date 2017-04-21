#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Formula.h"
#include "NumberObject.h"

using std::shared_ptr;
using std::string;
using std::vector;
using std::map;
using std::cout;


typedef shared_ptr<NumberObject> NumberObjectPtr;

class Computer {
private:
	NumberObjectPtr result;
    vector<Formula> f;
    map<string, NumberObjectPtr> variableSet;

public:
    Computer();
    ~Computer();

	NumberObjectPtr getVarPtr(const string&);
    void setVarPtr(const string&);
    void setVarPtr(const string&, const string&);
    void setVarPtr(const string&, const NumberObjectPtr);

    void setFormula(const string&);
    void caculate();
    void print();
};