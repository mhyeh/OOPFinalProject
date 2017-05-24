#pragma once

#include "NumberObject.h"
#include "Decimal.h"

namespace BigNumber {
    class Complex : public NumberObject {
    private:
        Decimal realPart, imagePart;

    protected:
        virtual void strToNum(const string&) override;
        virtual void encode() override;
        virtual void decode() override;

        virtual NumberObject add(const NumberObject&, const NumberObject&) override;
        virtual NumberObject sub(const NumberObject&, const NumberObject&) override;
        virtual NumberObject mul(const NumberObject&, const NumberObject&) override;
        virtual NumberObject div(const NumberObject&, const NumberObject&) override;
        virtual NumberObject power(const NumberObject&, const NumberObject&) override;
        virtual NumberObject minus(const NumberObject&) override;

        virtual void output(const NumberObject&, ostream&) override;

    public:
        Complex();
        Complex(const NumberObject&);
        Complex(string);
        Complex(int);
        Complex(const NumberObject&,const NumberObject&);
        ~Complex();

        void operator =(const string&);
        void operator =(const char*);
    };
}


