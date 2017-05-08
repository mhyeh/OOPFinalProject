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
	try {
		Integer a = "-4";
		Decimal b = "0.5", c, d, e;
		vector<NumberObject*> num;
		//std::cin >> a;
		c = a ^ b;
		num.push_back(&a);
		num.push_back(&b);
		num.push_back(&c);
		for (auto &i : num) {
			cout << *i << endl;
		}
	}
	catch (const char *errMsg) {

	}
	
	system("pause");
    return 0;
}

