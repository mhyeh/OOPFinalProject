#pragma once

#include "NumberObject.h"

class Integer : public NumberObject {
private:
	BigNum number;
	bool sign;

protected:
	void strToNum(const string&) override;

public:
	Integer() : number(BigNum(0)), sign(false) {};
	Integer(string);
	Integer(int);
	Integer(BigNum _number, bool _sign) : number(_number), sign(_sign) {};
	~Integer();

	bool getSign();
	void setSign(bool);

	void operator =(const string&);

	friend Integer& operator +(const Integer&, const Integer&);
	friend Integer& operator -(const Integer&, const Integer&);
	friend Integer& operator *(const Integer&, const Integer&);
	friend Integer& operator /(const Integer&, const Integer&);
	friend Integer& operator -(const Integer&);

	friend istream& operator >>(istream&, Integer&);
	friend ostream& operator <<(ostream&, const Integer&) override;

	friend bool operator ==(const Integer&, const Integer&);
	friend bool operator <(const Integer&, const Integer&);
	friend bool operator <=(const Integer&, const Integer&);
	friend bool operator >(const Integer&, const Integer&);
	friend bool operator >=(const Integer&, const Integer&);
};

