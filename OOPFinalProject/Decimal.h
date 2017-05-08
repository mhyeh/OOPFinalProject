#pragma once

#include "NumberObject.h"
#include "Integer.h"

class Decimal : public NumberObject {
private:
	Integer numerator, denominator;

	void checkSign();

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

	virtual void output(ostream&) override;

public:
	Decimal();
	Decimal(const NumberObject&);
	Decimal(string);
	Decimal(int);
	Decimal(const NumberObject&,const NumberObject&);
	~Decimal();

	bool getSign();
	Integer getFlotingNumber(int);

	void operator =(const string&);
	void operator =(const char*);

	friend NumberObject sqrtRoot(const NumberObject&);

	friend bool operator ==(const Decimal&, const Decimal&);
	friend bool operator !=(const Decimal&, const Decimal&);
	friend bool operator <(const Decimal&, const Decimal&);
	friend bool operator <=(const Decimal&, const Decimal&);
	friend bool operator >(const Decimal&, const Decimal&);
	friend bool operator >=(const Decimal&, const Decimal&);
};

