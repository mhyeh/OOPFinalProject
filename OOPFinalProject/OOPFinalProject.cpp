#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Computer.h"

using namespace std;

int main()
{
	cout << "===================================================================================================     " << endl << endl;
	cout << "  ==========     ==============       =====      |\\\\         ||   ||          ||   |\\\\        //|   " << endl;
	cout << "  ||        \\\\         ||          //            ||\\\\        ||   ||          ||   ||\\\\      //|| " << endl;
	cout << "  ||         ||        ||         //             || \\\\       ||   ||          ||   || \\\\    // ||   " << endl;
	cout << "  ||         ||        ||        //              ||  \\\\      ||   ||          ||   ||  \\\\  //  ||   " << endl;
	cout << "  ||        //         ||       ||               ||   \\\\     ||   ||          ||   ||   \\\\//   ||   " << endl;
	cout << "  ==========           ||       ||       ====    ||    \\\\    ||   ||          ||   ||          ||     " << endl;
	cout << "  ||        \\\\         ||       ||          ||   ||     \\\\   ||   ||          ||   ||          ||   " << endl;
	cout << "  ||         ||        ||        \\\\         //   ||      \\\\  ||   ||          ||   ||          ||   " << endl;
	cout << "  ||         ||        ||         \\\\       //    ||       \\\\ ||   \\\\          //   ||          || " << endl;
	cout << "  ||        //         ||          \\\\     //     ||        \\\\||    \\\\        //    ||          || " << endl;
	cout << "  ==========     ==============       =====      ||         \\\\|     \\\\======//     ||          ||   " << endl << endl;
	cout << "===================================================================================================     " << endl << endl;

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

			if (op == "Help") {
				cout << endl;
				cout << "Usage:" << endl << endl;
				cout << "set value:    Set <Number Type> <Value Name> [= <Value>/<Formula>]" << endl;
				cout << "              <Value Name> = <Value Name> " << endl << endl;
				cout << "get value:    Get <Value Name> " << endl << endl;
				cout << "caculate:     <Formula>" << endl << endl;
				cout << "exit:         Exit" << endl << endl;
			} else if (op == "Set") {
				string type, name, tmp, value;

				ss >> type;
				if(type != "Integer" && type != "Decimal" && type != "Complex")
					throw "syntex error";

				if (!ss.eof())
					ss >> name;
				else
					throw "syntex error";

				if (!ss.eof()) 
					ss >> tmp;
				else
					value = "0";

				if(!ss.eof())
					getline(ss, value);
			    else
					value = "0";

				Computer::setVar(name, value);
			} else if(op == "Get"){
				string name;

				if (!ss.eof())
					ss >> name;
				else
					throw "syntex error";

				cout << Computer::getVar(name) << endl;
			} else {
				string tmp;
				
				ss >> tmp;
				if (tmp == "=") {
					string value;

					if (!ss.eof())
						getline(ss, value);
					else
						throw "syntex error";

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

