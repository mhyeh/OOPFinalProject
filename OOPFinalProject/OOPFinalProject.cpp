#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Computer.h"

using namespace std;

int main()
{
	string input;
	Computer computer;

	while (1) {
		getline(cin, input);

		if(input == "Exit")
			break;

		try {
			string op;
			stringstream ss;

			ss.str("");
			ss.clear();
			
			ss << input;
			ss >> op;

			if (op == "Set") {
				string tmp;
				string name;
				string value;

				ss >> tmp;
				ss >> name;
				ss >> tmp;
				getline(ss, value);

				Computer::setVar(name, value);
			} else if(op == "Get"){
				string name;

				ss >> name;
				cout << Computer::getVar(name) << endl;
			} else {
				string tmp;
				
				ss >> tmp;
				if (tmp == "=") {
					string value;

					getline(ss, value);
					Computer::setVar(op, value);
				} else {
					computer.setFormula(input);
					computer.caculate();
					cout << computer.getResult() << endl;
				}
			}
		}
		catch (const char *errMsg) {
			cout << errMsg << endl;
		}
	}
	
    return 0;
}

