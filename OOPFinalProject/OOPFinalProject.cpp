#include <string>;
#include <iostream>
#include <vector>
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	Integer a = "1";
	Integer b = "123", c, d, e;
	vector<NumberObject*> num;
	//std::cin >> a;
	c = a + b;
	num.push_back(&a);
	num.push_back(&b);
	num.push_back(&c);
	d = *num[1] * *num[2];
	e = d * d * d;
	num.push_back(&d);
	num.push_back(&e);
	for (auto &i : num) {
		cout << *i << endl;
	}
	
	
	system("pause");
    return 0;
}

