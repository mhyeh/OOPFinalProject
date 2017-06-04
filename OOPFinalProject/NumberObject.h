#pragma once

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <regex>

#define MAX_DIGIT 8
#define MAX_INT ((long long int)std::pow(10, MAX_DIGIT))
#define MAX_DIGIT_DOUBLE (MAX_DIGIT * 2)
#define MAX_INT_DOUBLE ((long long int)std::pow(10, MAX_DIGIT_DOUBLE))

using namespace std;

typedef vector<int> BigNum;

namespace BigNumber {
    enum NumType {
        NUM,
        INTEGER,
        DEC,
        COM
    };

    struct NumData {
        BigNum rNumerator;
        BigNum rDenominator;
        BigNum iNumerator;
        BigNum iDenominator;
        int rSign;
        int iSign;
    };

    class NumberObject {
    protected:
        NumData numData;
        NumType numType;

        virtual void strToNum(const string&) {};
        virtual void encode() {};
        virtual void decode() {};

        virtual NumberObject add(const NumberObject&, const NumberObject&) { return NumberObject(); };
        virtual NumberObject sub(const NumberObject&, const NumberObject&) { return NumberObject(); };
        virtual NumberObject mul(const NumberObject&, const NumberObject&) { return NumberObject(); };
        virtual NumberObject div(const NumberObject&, const NumberObject&) { return NumberObject(); };
        virtual NumberObject power(const NumberObject&, const NumberObject&) { return NumberObject(); };
        virtual NumberObject minus(const NumberObject&) { return NumberObject(); };

        virtual void input(istream&);
        virtual void output(const NumberObject&, ostream&) {};

    public:
        NumberObject() : numType(NUM) {};
        NumberObject(string);
        NumberObject(const NumberObject&);
        NumberObject(long long int);
        ~NumberObject();

        NumData getNumData() { return this->numData; };
        NumType getNumType() { return this->numType; };

        friend NumberObject* numberFactory(int, int);

        friend NumberObject operator +(const NumberObject&, const NumberObject&);
        friend NumberObject operator -(const NumberObject&, const NumberObject&);
        friend NumberObject operator *(const NumberObject&, const NumberObject&);
        friend NumberObject operator /(const NumberObject&, const NumberObject&);
        friend NumberObject operator ^(const NumberObject&, const NumberObject&);
        friend NumberObject operator -(const NumberObject&);

        friend istream& operator >>(istream&, NumberObject&);
        friend ostream& operator <<(ostream&, NumberObject&);
    };
}