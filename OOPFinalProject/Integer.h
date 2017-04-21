#pragma once

#include <cmath>
#include <cstdlib>

#include "NumberObject.h"

class Integer : public NumberObject {
private:
	BigNum number;
	bool sign;

protected:
	void strToNum(const string&) override;
	/*
	NumberObject& add(const NumberObject&) override;
	NumberObject& sub(const NumberObject&) override;
	NumberObject& mul(const NumberObject&) override;
	NumberObject& div(const NumberObject&) override;
	NumberObject& minus() override;

	istream& input(istream&) override;
	*/
	ostream& output(ostream&) override;

public:
	Integer() : number(BigNum()), sign(false) {};
	Integer(string);
	Integer(int);
	Integer(BigNum& _number, bool _sign) : number(_number), sign(_sign) {};
	~Integer();

	bool getSign();
	void setSign(bool);

	void operator =(const string&);
	void operator =(const char*);

	friend Integer operator +(const Integer&, const Integer&);
	friend Integer operator -(const Integer&, const Integer&);
	friend Integer operator *(const Integer&, const Integer&);
	friend Integer operator /(const Integer&, const Integer&);
	friend Integer operator -(const Integer&);

	friend istream& operator >>(istream&, Integer&);

	friend bool operator ==(const Integer&, const Integer&);
	friend bool operator <(const Integer&, const Integer&);
	friend bool operator <=(const Integer&, const Integer&);
	friend bool operator >(const Integer&, const Integer&);
	friend bool operator >=(const Integer&, const Integer&);
	
};

