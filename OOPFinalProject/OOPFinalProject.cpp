// Name: Yeh, MinHsuan
// Date: April 6, 2017 
// Last Update: April 7, 2017 
// Problem statement: OOP final project main file

#include <iostream>
#include <string>
#include "Formula.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

	string inputStr;

	Integer a;
	a = "1";
	
	while (cin >> inputStr) {
		try {
			Formula f(inputStr);
			f.calculate();
			f.print();
		} 
		catch (const char* errorMsg) {
			cout << errorMsg << endl;
		}
	}
	

    return 0;
}

