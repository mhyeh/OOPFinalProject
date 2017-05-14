#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <utility>

#include "Formula.h"
#include "NumberObject.h"

using namespace std;

class Computer {
private:
	NumberObject result;
    Formula f;
    static map<string, NumberObject> variableSet;

public:
    Computer();
    ~Computer();

	static NumberObject getVar(const string&);
	static vector<pair<string, string>> getVarList();
    static void setVar(const string&);
    static void setVar(const string&, const string&);
    static void setVar(const string&, const NumberObject&);

    void setFormula(const string&);
    void caculate();
	NumberObject getResult();
};