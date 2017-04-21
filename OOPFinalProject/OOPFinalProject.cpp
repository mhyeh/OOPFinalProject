#include <string>;
#include <iostream>
#include <vector>
#include "Integer.h"
#include "Decimal.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	Decimal a, b, c;
	vector<NumberObject*> num;
	a = "1.1";
	b = "2.213456";
	c = b * 40;
	num.push_back(&a);
	num.push_back(&b);
	num.push_back(&c);
	/*
	for (auto &i : num) {
		cout << *i << endl;
	}
	*/
	
	system("pause");
    return 0;
}

