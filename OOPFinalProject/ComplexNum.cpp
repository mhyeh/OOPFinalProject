#include "ComplexNum.h"


ComplexNum::ComplexNum(string& _numStr) : realPart(), imagePart() {
	if (_numStr.back() == 'i') {
		_numStr.pop_back();
		imagePart = BigNumber(_numStr);
	}
	else {
		realPart = BigNumber(_numStr);
	}
}

ComplexNum::~ComplexNum() {
}


ComplexNum& operator +(const ComplexNum& _num1, const ComplexNum& _num2) {
	BigNumber realPart = _num1.realPart + _num2.realPart;
	BigNumber imagePart = _num1.imagePart + _num2.imagePart;

	return ComplexNum(realPart, imagePart);
}

ComplexNum& operator -(const ComplexNum& _num1, const ComplexNum& _num2) {
	BigNumber realPart = _num1.realPart - _num2.realPart;
	BigNumber imagePart = _num1.imagePart - _num2.imagePart;

	return ComplexNum(realPart, imagePart);
}

ComplexNum& operator *(const ComplexNum& _num1, const ComplexNum& _num2) {
	BigNumber realPart = _num1.realPart * _num2.realPart - _num1.imagePart * _num2.imagePart;
	BigNumber imagePart = _num1.realPart * _num2.imagePart + _num1.imagePart * _num2.realPart;

	return ComplexNum(realPart, imagePart);
}

ComplexNum& operator /(const ComplexNum& _num1, const ComplexNum& _num2) {
	BigNumber denominator = _num2.realPart * _num2.realPart + _num2.imagePart * _num2.imagePart;
	BigNumber realPart = (_num1.realPart * _num2.realPart + _num1.imagePart * _num2.imagePart) / denominator;
	BigNumber imagePart = (-_num1.realPart * _num2.imagePart + _num1.imagePart * _num2.realPart) / denominator;

	return ComplexNum(realPart, imagePart);
}

ComplexNum& operator -(ComplexNum& _num) {
	BigNumber realPart = -_num.realPart;
	BigNumber imagePart = -_num.imagePart;

	return ComplexNum(realPart, imagePart);
}