#pragma once

#include <string>
#include <vector>
#include <map>

#include "Formula.h"
#include "NumberObject.h"

using std::string;
using std::vector;
using std::map;

class Computer {
private:
    NumberObject result;
    vector<Formula> f;
    map<string, NumberObject> variableSet;

public:
    Computer();
    ~Computer();

    NumberObject getVar(const string&);
    void setVar(const string&);
    void setVar(const string&, const string&);
    void setVar(const string&, const NumberObject&);

    void setFormula(const string&);
    void caculate();
    void print();
};