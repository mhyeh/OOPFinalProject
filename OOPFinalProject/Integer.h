#pragma once

#include "NumberObject.h"
//#include "Complex.h"
//#include "Decimal.h"

class Integer : public NumberObject {
private:
	BigNum number;
	bool sign;

protected:
	void strToNum(const string&) override;

public:
	Integer() : number(BigNum()), sign(false) {};
	Integer(string);
	Integer(BigNum _number, bool _sign) : number(_number), sign(_sign) {};
	~Integer();

	bool getSign();
	void setSign(bool);

	//operator Decimal();
	//operator Complex();

	void operator =(const string&);

	friend Integer& operator +(const Integer&, const Integer&);
	friend Integer& operator -(const Integer&, const Integer&);
	friend Integer& operator *(const Integer&, const Integer&);
	friend Integer& operator /(const Integer&, const Integer&);
	friend Integer& operator -(const Integer&);

	friend istream& operator >>(istream&, Integer&);
	friend ostream& operator <<(ostream&, const Integer&);

	friend bool operator ==(const Integer&, const Integer&);
};

