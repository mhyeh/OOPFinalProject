#pragma once

#include <cmath>
#include <cstdlib>

#include "NumberObject.h"

class Integer : public NumberObject {
private:
	BigNum number;
	bool sign;

protected:
	virtual void strToNum(const string&) override;
	virtual void encode() override;
	virtual void decode() override;
	
	virtual NumberObject add(const NumberObject&, const NumberObject&) override;
	virtual NumberObject sub(const NumberObject&, const NumberObject&) override;
	virtual NumberObject mul(const NumberObject&, const NumberObject&) override;
	virtual NumberObject div(const NumberObject&, const NumberObject&) override;
	virtual NumberObject minus(const NumberObject&) override;

	virtual void output(ostream&) override;
public:
	Integer();
	Integer(const NumberObject&);
	Integer(string);
	Integer(int);
	Integer(BigNum& _number, bool _sign);
	~Integer();

	bool getSign();
	void setSign(bool);

	void operator =(const string&);
	void operator =(const char*);


	friend bool operator ==(const Integer&, const Integer&);
	friend bool operator <(const Integer&, const Integer&);
	friend bool operator <=(const Integer&, const Integer&);
	friend bool operator >(const Integer&, const Integer&);
	friend bool operator >=(const Integer&, const Integer&);
	
};

