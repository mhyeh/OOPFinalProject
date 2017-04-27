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

class Computer {
private:
	NumberObject result;
    Formula f;
    static map<string, NumberObject&> variableSet;

public:
    Computer();
    ~Computer();

	static NumberObject getVar(const string&);
    static void setVar(const string&);
    static void setVar(const string&, const string&);
    static void setVar(const string&, const NumberObject&);

    void setFormula(const string&);
    void caculate();
    void print();
};