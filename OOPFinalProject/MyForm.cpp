#include <sstream>
#include <string>
#include <vector>
#include <msclr\marshal_cppstd.h>

#include "MyForm.h"
#include "Computer.h"


using namespace msclr::interop;
using namespace System;
using namespace OOPFinalProject;
using namespace std;


int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MyForm());

	return 0;
}

void MyForm::Set_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "Set ";
	this->Get->Enabled = false;
	this->Set->Enabled = false;
	this->Int->Enabled = true;
	this->Dec->Enabled = true;
	this->Com->Enabled = true;
}

void MyForm::Get_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "Get ";
	this->Get->Enabled = false;
	this->Set->Enabled = false;
	this->Int->Enabled = false;
	this->Dec->Enabled = false;
	this->Com->Enabled = false;
}

void MyForm::Int_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "Integer ";
	this->Get->Enabled = false;
	this->Set->Enabled = false;
	this->Int->Enabled = false;
	this->Dec->Enabled = false;
	this->Com->Enabled = false;
}

void MyForm::Dec_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "Decimal ";
	this->Get->Enabled = false;
	this->Set->Enabled = false;
	this->Int->Enabled = false;
	this->Dec->Enabled = false;
	this->Com->Enabled = false;
}

void MyForm::Com_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "Complex ";
	this->Get->Enabled = false;
	this->Set->Enabled = false;
	this->Int->Enabled = false;
	this->Dec->Enabled = false;
	this->Com->Enabled = false;
}

void MyForm::ValueName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if(this->ValueName->Text->ToString() != "")
		this->Submit->Enabled = true;
	else
		this->Submit->Enabled = false;
}

void MyForm::Submit_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->Set->Enabled == false) {
		this->Set->Enabled = true;
		this->Get->Enabled = true;
	}

	this->Input->Text += this->ValueName->Text->ToString() + " ";
	this->ValueName->Text = "";
}

void MyForm::Num0_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "0";
}

void MyForm::Num1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "1";
}

void MyForm::Num2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "2";
}

void MyForm::Num3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "3";
}

void MyForm::Num4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "4";
}

void MyForm::Num5_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "5";
}

void MyForm::Num6_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "6";
}

void MyForm::Num7_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "7";
}

void MyForm::Num8_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "8";
}

void MyForm::Num9_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "9";
}

void MyForm::Decimal_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += ".";
}

void MyForm::ImagePart_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "i";
}

void MyForm::Add_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "+";
}

void MyForm::Sub_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "-";
}

void MyForm::Mul_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "*";
}

void MyForm::Div_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "/";
}

void MyForm::Left_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "(";
}

void MyForm::Right_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += ")";
}

void MyForm::Pow_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "^";
}

void MyForm::Fac_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += "!";
}

void MyForm::Eql_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text += " = ";
}

void MyForm::Enter_Click(System::Object^  sender, System::EventArgs^  e) {
	this->compute();
}

void MyForm::ClearAll_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textInit();
}

void MyForm::Help_Click(System::Object^  sender, System::EventArgs^  e) {
	this->help();
}

void MyForm::Delete_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->Input->Text->Length > 0)
		this->Input->Text = this->Input->Text->Substring(0, this->Input->Text->Length - 1);
}

void MyForm::Clear_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Input->Text = "";
}

void MyForm::Input_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter)
		this->compute();
}

void MyForm::ValueName_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter) {
		if (this->Set->Enabled == false) {
			this->Set->Enabled = true;
			this->Get->Enabled = true;
		}

		this->Input->Text += this->ValueName->Text->ToString() + " ";
		this->ValueName->Text = "";
	}
}

void MyForm::textInit() {
	this->Show->Text = "";
	this->Show->Text += "===================================================================================================     \r\n\r\n";
	this->Show->Text += "  ==========     ==============       =====      |\\\\         ||   ||          ||   |\\\\        //|   \r\n";
	this->Show->Text += "  ||        \\\\         ||          //            ||\\\\        ||   ||          ||   ||\\\\      //|| \r\n";
	this->Show->Text += "  ||         ||        ||         //             || \\\\       ||   ||          ||   || \\\\    // ||   \r\n";
	this->Show->Text += "  ||         ||        ||        //              ||  \\\\      ||   ||          ||   ||  \\\\  //  ||   \r\n";
	this->Show->Text += "  ||        //         ||       ||               ||   \\\\     ||   ||          ||   ||   \\\\//   ||   \r\n";
	this->Show->Text += "  ==========           ||       ||       ====    ||    \\\\    ||   ||          ||   ||          ||     \r\n";
	this->Show->Text += "  ||        \\\\         ||       ||          ||   ||     \\\\   ||   ||          ||   ||          ||   \r\n";
	this->Show->Text += "  ||         ||        ||        \\\\         //   ||      \\\\  ||   ||          ||   ||          ||   \r\n";
	this->Show->Text += "  ||         ||        ||         \\\\       //    ||       \\\\ ||   \\\\          //   ||          || \r\n";
	this->Show->Text += "  ||        //         ||          \\\\     //     ||        \\\\||    \\\\        //    ||          || \r\n";
	this->Show->Text += "  ==========     ==============       =====      ||         \\\\|     \\\\======//     ||          ||   \r\n\r\n";
	this->Show->Text += "===================================================================================================     \r\n\r\n";
}

void MyForm::help() {
	this->Show->Text += "\r\nUsage:\r\n";
	this->Show->Text += "set value:      Set <Number Type> <Value Name> [= <Value>/<Formula>]\r\n";
	this->Show->Text += "                <Value Name> = <Value Name> \r\n\r\n";
	this->Show->Text += "get value:      Get <Value Name> \r\n\r\n";
	this->Show->Text += "caculate:       <Formula>\r\n\r\n";
	this->Show->Text += "help:           Help\r\n\r\n";
	this->Show->Text += "clear text box: ClearAll\r\n\r\n";
}

void MyForm::setList() {
	this->ValueList->Clear();

	vector<string> varList;

	varList = Computer::getVarList();
	for (int i = 0; i < varList.size(); i++) {
		this->ValueList->Items->Add(gcnew String(varList[i].c_str()), i);
	}
}

void MyForm::compute() {
	string input = marshal_as<std::string>(this->Input->Text->ToString());

	this->Show->Text += this->Input->Text->ToString() + "\r\n";
	this->Input->Text = "";

	try {
		string op;
		stringstream ss;

		ss.str("");
		ss.clear();

		ss << input;
		ss >> op;

		if (op == "Help") {
			this->help();
		} else if(op == "ClearAll") {
			this->textInit();
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
			this->setList();
		} else if(op == "Get"){
			string name;

			if (!ss.eof())
				ss >> name;
			else
				throw "syntex error";

			ss.str("");
			ss.clear();

			ss << Computer::getVar(name);

			string value;
			getline(ss, value);

			this->Show->Text += gcnew String(value.c_str()) + "\r\n";
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
				this->setList();
			} else {
				computer->setFormula(input);
				computer->caculate();

				ss.str("");
				ss.clear();

				ss << computer->getResult();

				string value;
				getline(ss, value);

				this->Show->Text += gcnew String(value.c_str()) + "\r\n";
			}
		}
	}
	catch (const char *errMsg) {
		this->Show->Text += gcnew String(errMsg) + "\r\n";
	}
}