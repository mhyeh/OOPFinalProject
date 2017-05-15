#pragma once
#include "Computer.h"

namespace OOPFinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->textInit();

			this->computer = new Computer();

			this->ValueList->View = View::Details;
			this->ValueList->GridLines = true;
			this->ValueList->Columns->Insert(0, "Name", 150, HorizontalAlignment::Center);
			this->ValueList->Columns->Insert(1, "Value", 150, HorizontalAlignment::Center);

			this->Input->Focus();
			this->Input->Select();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete this->computer;
		}
	private: System::Windows::Forms::TextBox^  Show;
	protected:

	protected:
	private: System::Windows::Forms::Button^  Num1;
	private: System::Windows::Forms::Button^  Num2;
	private: System::Windows::Forms::Button^  Num3;
	private: System::Windows::Forms::Button^  Num4;
	private: System::Windows::Forms::Button^  Num5;
	private: System::Windows::Forms::Button^  Num6;
	private: System::Windows::Forms::Button^  Num7;
	private: System::Windows::Forms::Button^  Num8;
	private: System::Windows::Forms::Button^  Num9;
	private: System::Windows::Forms::Button^  Num0;
	private: System::Windows::Forms::Button^  Decimal;
	private: System::Windows::Forms::Button^  ImagePart;
	private: System::Windows::Forms::Button^  Add;
	private: System::Windows::Forms::Button^  Sub;
	private: System::Windows::Forms::Button^  Mul;
	private: System::Windows::Forms::Button^  Div;
	private: System::Windows::Forms::Button^  Fac;















	private: System::Windows::Forms::Button^  Pow;

	private: System::Windows::Forms::Button^  Right;

	private: System::Windows::Forms::Button^  Left;
	private: System::Windows::Forms::Button^  Eql;
	private: System::Windows::Forms::Button^  Enter;
	private: System::Windows::Forms::Button^  Set;
	private: System::Windows::Forms::Button^  Get;
	private: System::Windows::Forms::Button^  Int;
	private: System::Windows::Forms::Button^  Dec;
	private: System::Windows::Forms::Button^  Com;
	private: System::Windows::Forms::ListView^  ValueList;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  ValueName;
	private: System::Windows::Forms::Button^  Submit;
	private: System::Windows::Forms::Button^  Clear;

	private: System::Windows::Forms::Button^  Delete;
	private: System::Windows::Forms::Button^  ClearAll;
	private: System::Windows::Forms::Button^  Help;

	private: Computer* computer;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
            this->Show = (gcnew System::Windows::Forms::TextBox());
            this->Num1 = (gcnew System::Windows::Forms::Button());
            this->Num2 = (gcnew System::Windows::Forms::Button());
            this->Num3 = (gcnew System::Windows::Forms::Button());
            this->Num4 = (gcnew System::Windows::Forms::Button());
            this->Num5 = (gcnew System::Windows::Forms::Button());
            this->Num6 = (gcnew System::Windows::Forms::Button());
            this->Num7 = (gcnew System::Windows::Forms::Button());
            this->Num8 = (gcnew System::Windows::Forms::Button());
            this->Num9 = (gcnew System::Windows::Forms::Button());
            this->Num0 = (gcnew System::Windows::Forms::Button());
            this->Decimal = (gcnew System::Windows::Forms::Button());
            this->ImagePart = (gcnew System::Windows::Forms::Button());
            this->Add = (gcnew System::Windows::Forms::Button());
            this->Sub = (gcnew System::Windows::Forms::Button());
            this->Mul = (gcnew System::Windows::Forms::Button());
            this->Div = (gcnew System::Windows::Forms::Button());
            this->Fac = (gcnew System::Windows::Forms::Button());
            this->Pow = (gcnew System::Windows::Forms::Button());
            this->Right = (gcnew System::Windows::Forms::Button());
            this->Left = (gcnew System::Windows::Forms::Button());
            this->Eql = (gcnew System::Windows::Forms::Button());
            this->Enter = (gcnew System::Windows::Forms::Button());
            this->Set = (gcnew System::Windows::Forms::Button());
            this->Get = (gcnew System::Windows::Forms::Button());
            this->Int = (gcnew System::Windows::Forms::Button());
            this->Dec = (gcnew System::Windows::Forms::Button());
            this->Com = (gcnew System::Windows::Forms::Button());
            this->ValueList = (gcnew System::Windows::Forms::ListView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->Input = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->ValueName = (gcnew System::Windows::Forms::TextBox());
            this->Submit = (gcnew System::Windows::Forms::Button());
            this->Clear = (gcnew System::Windows::Forms::Button());
            this->Delete = (gcnew System::Windows::Forms::Button());
            this->ClearAll = (gcnew System::Windows::Forms::Button());
            this->Help = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // Show
            // 
            this->Show->BackColor = System::Drawing::SystemColors::ButtonHighlight;
            this->Show->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Show->Location = System::Drawing::Point(12, 72);
            this->Show->Multiline = true;
            this->Show->Name = L"Show";
            this->Show->ReadOnly = true;
            this->Show->Size = System::Drawing::Size(789, 627);
            this->Show->TabIndex = 0;
            // 
            // Num1
            // 
            this->Num1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num1->Location = System::Drawing::Point(831, 422);
            this->Num1->Margin = System::Windows::Forms::Padding(5);
            this->Num1->Name = L"Num1";
            this->Num1->Size = System::Drawing::Size(60, 60);
            this->Num1->TabIndex = 1;
            this->Num1->Text = L"1";
            this->Num1->UseVisualStyleBackColor = true;
            this->Num1->Click += gcnew System::EventHandler(this, &MyForm::Num1_Click);
            // 
            // Num2
            // 
            this->Num2->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num2->Location = System::Drawing::Point(901, 422);
            this->Num2->Margin = System::Windows::Forms::Padding(5);
            this->Num2->Name = L"Num2";
            this->Num2->Size = System::Drawing::Size(60, 60);
            this->Num2->TabIndex = 2;
            this->Num2->Text = L"2";
            this->Num2->UseVisualStyleBackColor = true;
            this->Num2->Click += gcnew System::EventHandler(this, &MyForm::Num2_Click);
            // 
            // Num3
            // 
            this->Num3->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num3->Location = System::Drawing::Point(971, 422);
            this->Num3->Margin = System::Windows::Forms::Padding(5);
            this->Num3->Name = L"Num3";
            this->Num3->Size = System::Drawing::Size(60, 60);
            this->Num3->TabIndex = 3;
            this->Num3->Text = L"3";
            this->Num3->UseVisualStyleBackColor = true;
            this->Num3->Click += gcnew System::EventHandler(this, &MyForm::Num3_Click);
            // 
            // Num4
            // 
            this->Num4->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num4->Location = System::Drawing::Point(831, 492);
            this->Num4->Margin = System::Windows::Forms::Padding(5);
            this->Num4->Name = L"Num4";
            this->Num4->Size = System::Drawing::Size(60, 60);
            this->Num4->TabIndex = 4;
            this->Num4->Text = L"4";
            this->Num4->UseVisualStyleBackColor = true;
            this->Num4->Click += gcnew System::EventHandler(this, &MyForm::Num4_Click);
            // 
            // Num5
            // 
            this->Num5->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num5->Location = System::Drawing::Point(901, 492);
            this->Num5->Margin = System::Windows::Forms::Padding(5);
            this->Num5->Name = L"Num5";
            this->Num5->Size = System::Drawing::Size(60, 60);
            this->Num5->TabIndex = 5;
            this->Num5->Text = L"5";
            this->Num5->UseVisualStyleBackColor = true;
            this->Num5->Click += gcnew System::EventHandler(this, &MyForm::Num5_Click);
            // 
            // Num6
            // 
            this->Num6->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num6->Location = System::Drawing::Point(971, 492);
            this->Num6->Margin = System::Windows::Forms::Padding(5);
            this->Num6->Name = L"Num6";
            this->Num6->Size = System::Drawing::Size(60, 60);
            this->Num6->TabIndex = 6;
            this->Num6->Text = L"6";
            this->Num6->UseVisualStyleBackColor = true;
            this->Num6->Click += gcnew System::EventHandler(this, &MyForm::Num6_Click);
            // 
            // Num7
            // 
            this->Num7->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num7->Location = System::Drawing::Point(831, 562);
            this->Num7->Margin = System::Windows::Forms::Padding(5);
            this->Num7->Name = L"Num7";
            this->Num7->Size = System::Drawing::Size(60, 60);
            this->Num7->TabIndex = 7;
            this->Num7->Text = L"7";
            this->Num7->UseVisualStyleBackColor = true;
            this->Num7->Click += gcnew System::EventHandler(this, &MyForm::Num7_Click);
            // 
            // Num8
            // 
            this->Num8->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num8->Location = System::Drawing::Point(901, 562);
            this->Num8->Margin = System::Windows::Forms::Padding(5);
            this->Num8->Name = L"Num8";
            this->Num8->Size = System::Drawing::Size(60, 60);
            this->Num8->TabIndex = 8;
            this->Num8->Text = L"8";
            this->Num8->UseVisualStyleBackColor = true;
            this->Num8->Click += gcnew System::EventHandler(this, &MyForm::Num8_Click);
            // 
            // Num9
            // 
            this->Num9->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num9->Location = System::Drawing::Point(971, 562);
            this->Num9->Margin = System::Windows::Forms::Padding(5);
            this->Num9->Name = L"Num9";
            this->Num9->Size = System::Drawing::Size(60, 60);
            this->Num9->TabIndex = 9;
            this->Num9->Text = L"9";
            this->Num9->UseVisualStyleBackColor = true;
            this->Num9->Click += gcnew System::EventHandler(this, &MyForm::Num9_Click);
            // 
            // Num0
            // 
            this->Num0->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Num0->Location = System::Drawing::Point(831, 632);
            this->Num0->Margin = System::Windows::Forms::Padding(5);
            this->Num0->Name = L"Num0";
            this->Num0->Size = System::Drawing::Size(60, 60);
            this->Num0->TabIndex = 10;
            this->Num0->Text = L"0";
            this->Num0->UseVisualStyleBackColor = true;
            this->Num0->Click += gcnew System::EventHandler(this, &MyForm::Num0_Click);
            // 
            // Decimal
            // 
            this->Decimal->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                               static_cast<System::Byte>(0)));
            this->Decimal->Location = System::Drawing::Point(901, 632);
            this->Decimal->Margin = System::Windows::Forms::Padding(5);
            this->Decimal->Name = L"Decimal";
            this->Decimal->Size = System::Drawing::Size(60, 60);
            this->Decimal->TabIndex = 11;
            this->Decimal->Text = L".";
            this->Decimal->UseVisualStyleBackColor = true;
            this->Decimal->Click += gcnew System::EventHandler(this, &MyForm::Decimal_Click);
            // 
            // ImagePart
            // 
            this->ImagePart->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
            this->ImagePart->Location = System::Drawing::Point(971, 632);
            this->ImagePart->Margin = System::Windows::Forms::Padding(5);
            this->ImagePart->Name = L"ImagePart";
            this->ImagePart->Size = System::Drawing::Size(60, 60);
            this->ImagePart->TabIndex = 12;
            this->ImagePart->Text = L"i";
            this->ImagePart->UseVisualStyleBackColor = true;
            this->ImagePart->Click += gcnew System::EventHandler(this, &MyForm::ImagePart_Click);
            // 
            // Add
            // 
            this->Add->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Add->Location = System::Drawing::Point(1056, 422);
            this->Add->Margin = System::Windows::Forms::Padding(5);
            this->Add->Name = L"Add";
            this->Add->Size = System::Drawing::Size(60, 60);
            this->Add->TabIndex = 13;
            this->Add->Text = L"+";
            this->Add->UseVisualStyleBackColor = true;
            this->Add->Click += gcnew System::EventHandler(this, &MyForm::Add_Click);
            // 
            // Sub
            // 
            this->Sub->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Sub->Location = System::Drawing::Point(1056, 492);
            this->Sub->Margin = System::Windows::Forms::Padding(5);
            this->Sub->Name = L"Sub";
            this->Sub->Size = System::Drawing::Size(60, 60);
            this->Sub->TabIndex = 14;
            this->Sub->Text = L"-";
            this->Sub->UseVisualStyleBackColor = true;
            this->Sub->Click += gcnew System::EventHandler(this, &MyForm::Sub_Click);
            // 
            // Mul
            // 
            this->Mul->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Mul->Location = System::Drawing::Point(1056, 562);
            this->Mul->Margin = System::Windows::Forms::Padding(5);
            this->Mul->Name = L"Mul";
            this->Mul->Size = System::Drawing::Size(60, 60);
            this->Mul->TabIndex = 15;
            this->Mul->Text = L"*";
            this->Mul->UseVisualStyleBackColor = true;
            this->Mul->Click += gcnew System::EventHandler(this, &MyForm::Mul_Click);
            // 
            // Div
            // 
            this->Div->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Div->Location = System::Drawing::Point(1056, 632);
            this->Div->Margin = System::Windows::Forms::Padding(5);
            this->Div->Name = L"Div";
            this->Div->Size = System::Drawing::Size(60, 60);
            this->Div->TabIndex = 16;
            this->Div->Text = L"/";
            this->Div->UseVisualStyleBackColor = true;
            this->Div->Click += gcnew System::EventHandler(this, &MyForm::Div_Click);
            // 
            // Fac
            // 
            this->Fac->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Fac->Location = System::Drawing::Point(1126, 632);
            this->Fac->Margin = System::Windows::Forms::Padding(5);
            this->Fac->Name = L"Fac";
            this->Fac->Size = System::Drawing::Size(60, 60);
            this->Fac->TabIndex = 17;
            this->Fac->Text = L"!";
            this->Fac->UseVisualStyleBackColor = true;
            this->Fac->Click += gcnew System::EventHandler(this, &MyForm::Fac_Click);
            // 
            // Pow
            // 
            this->Pow->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Pow->Location = System::Drawing::Point(1126, 562);
            this->Pow->Margin = System::Windows::Forms::Padding(5);
            this->Pow->Name = L"Pow";
            this->Pow->Size = System::Drawing::Size(60, 60);
            this->Pow->TabIndex = 18;
            this->Pow->Text = L"^";
            this->Pow->UseVisualStyleBackColor = true;
            this->Pow->Click += gcnew System::EventHandler(this, &MyForm::Pow_Click);
            // 
            // Right
            // 
            this->Right->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Right->Location = System::Drawing::Point(1126, 492);
            this->Right->Margin = System::Windows::Forms::Padding(5);
            this->Right->Name = L"Right";
            this->Right->Size = System::Drawing::Size(60, 60);
            this->Right->TabIndex = 19;
            this->Right->Text = L")";
            this->Right->UseVisualStyleBackColor = true;
            this->Right->Click += gcnew System::EventHandler(this, &MyForm::Right_Click);
            // 
            // Left
            // 
            this->Left->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Left->Location = System::Drawing::Point(1126, 422);
            this->Left->Margin = System::Windows::Forms::Padding(5);
            this->Left->Name = L"Left";
            this->Left->Size = System::Drawing::Size(60, 60);
            this->Left->TabIndex = 20;
            this->Left->Text = L"(";
            this->Left->UseVisualStyleBackColor = true;
            this->Left->Click += gcnew System::EventHandler(this, &MyForm::Left_Click);
            // 
            // Eql
            // 
            this->Eql->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Eql->Location = System::Drawing::Point(1212, 422);
            this->Eql->Margin = System::Windows::Forms::Padding(5);
            this->Eql->Name = L"Eql";
            this->Eql->Size = System::Drawing::Size(60, 60);
            this->Eql->TabIndex = 21;
            this->Eql->Text = L"=";
            this->Eql->UseVisualStyleBackColor = true;
            this->Eql->Click += gcnew System::EventHandler(this, &MyForm::Eql_Click);
            // 
            // Enter
            // 
            this->Enter->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Enter->Location = System::Drawing::Point(1211, 492);
            this->Enter->Margin = System::Windows::Forms::Padding(5);
            this->Enter->Name = L"Enter";
            this->Enter->Size = System::Drawing::Size(60, 60);
            this->Enter->TabIndex = 22;
            this->Enter->Text = L"Enter";
            this->Enter->UseVisualStyleBackColor = true;
            this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Enter_Click);
            // 
            // Set
            // 
            this->Set->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Set->Location = System::Drawing::Point(831, 16);
            this->Set->Margin = System::Windows::Forms::Padding(5);
            this->Set->Name = L"Set";
            this->Set->Size = System::Drawing::Size(130, 40);
            this->Set->TabIndex = 23;
            this->Set->Text = L"Set";
            this->Set->UseVisualStyleBackColor = true;
            this->Set->Click += gcnew System::EventHandler(this, &MyForm::Set_Click);
            // 
            // Get
            // 
            this->Get->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Get->Location = System::Drawing::Point(971, 16);
            this->Get->Margin = System::Windows::Forms::Padding(5);
            this->Get->Name = L"Get";
            this->Get->Size = System::Drawing::Size(130, 40);
            this->Get->TabIndex = 24;
            this->Get->Text = L"Get";
            this->Get->UseVisualStyleBackColor = true;
            this->Get->Click += gcnew System::EventHandler(this, &MyForm::Get_Click);
            // 
            // Int
            // 
            this->Int->Enabled = false;
            this->Int->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Int->Location = System::Drawing::Point(831, 72);
            this->Int->Margin = System::Windows::Forms::Padding(5);
            this->Int->Name = L"Int";
            this->Int->Size = System::Drawing::Size(130, 40);
            this->Int->TabIndex = 25;
            this->Int->Text = L"Integer";
            this->Int->UseVisualStyleBackColor = true;
            this->Int->Click += gcnew System::EventHandler(this, &MyForm::Int_Click);
            // 
            // Dec
            // 
            this->Dec->Enabled = false;
            this->Dec->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Dec->Location = System::Drawing::Point(971, 72);
            this->Dec->Margin = System::Windows::Forms::Padding(5);
            this->Dec->Name = L"Dec";
            this->Dec->Size = System::Drawing::Size(130, 40);
            this->Dec->TabIndex = 26;
            this->Dec->Text = L"Decimal";
            this->Dec->UseVisualStyleBackColor = true;
            this->Dec->Click += gcnew System::EventHandler(this, &MyForm::Dec_Click);
            // 
            // Com
            // 
            this->Com->Enabled = false;
            this->Com->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                           static_cast<System::Byte>(0)));
            this->Com->Location = System::Drawing::Point(1111, 72);
            this->Com->Margin = System::Windows::Forms::Padding(5);
            this->Com->Name = L"Com";
            this->Com->Size = System::Drawing::Size(130, 40);
            this->Com->TabIndex = 27;
            this->Com->Text = L"Complex";
            this->Com->UseVisualStyleBackColor = true;
            this->Com->Click += gcnew System::EventHandler(this, &MyForm::Com_Click);
            // 
            // ValueList
            // 
            this->ValueList->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
            this->ValueList->Location = System::Drawing::Point(831, 225);
            this->ValueList->Name = L"ValueList";
            this->ValueList->Size = System::Drawing::Size(440, 169);
            this->ValueList->TabIndex = 28;
            this->ValueList->UseCompatibleStateImageBehavior = false;
            this->ValueList->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &MyForm::ValueList_ItemSelectionChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(836, 202);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(120, 23);
            this->label1->TabIndex = 29;
            this->label1->Text = L"Value List";
            // 
            // Input
            // 
            this->Input->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Input->ImeMode = System::Windows::Forms::ImeMode::Alpha;
            this->Input->Location = System::Drawing::Point(13, 16);
            this->Input->Name = L"Input";
            this->Input->Size = System::Drawing::Size(788, 45);
            this->Input->TabIndex = 30;
            this->Input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Input_KeyDown);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(836, 151);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(54, 23);
            this->label2->TabIndex = 31;
            this->label2->Text = L"Name";
            // 
            // ValueName
            // 
            this->ValueName->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                 static_cast<System::Byte>(0)));
            this->ValueName->ImeMode = System::Windows::Forms::ImeMode::Alpha;
            this->ValueName->Location = System::Drawing::Point(903, 142);
            this->ValueName->Name = L"ValueName";
            this->ValueName->Size = System::Drawing::Size(283, 32);
            this->ValueName->TabIndex = 32;
            this->ValueName->TextChanged += gcnew System::EventHandler(this, &MyForm::ValueName_TextChanged);
            this->ValueName->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::ValueName_KeyDown);
            // 
            // Submit
            // 
            this->Submit->Enabled = false;
            this->Submit->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(0)));
            this->Submit->Location = System::Drawing::Point(1194, 139);
            this->Submit->Margin = System::Windows::Forms::Padding(5);
            this->Submit->Name = L"Submit";
            this->Submit->Size = System::Drawing::Size(63, 40);
            this->Submit->TabIndex = 33;
            this->Submit->Text = L"Submit";
            this->Submit->UseVisualStyleBackColor = true;
            this->Submit->Click += gcnew System::EventHandler(this, &MyForm::Submit_Click);
            // 
            // Clear
            // 
            this->Clear->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                             static_cast<System::Byte>(0)));
            this->Clear->Location = System::Drawing::Point(1212, 632);
            this->Clear->Margin = System::Windows::Forms::Padding(5);
            this->Clear->Name = L"Clear";
            this->Clear->Size = System::Drawing::Size(60, 60);
            this->Clear->TabIndex = 34;
            this->Clear->Text = L"Clear";
            this->Clear->UseVisualStyleBackColor = true;
            this->Clear->Click += gcnew System::EventHandler(this, &MyForm::Clear_Click);
            // 
            // Delete
            // 
            this->Delete->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                              static_cast<System::Byte>(0)));
            this->Delete->Location = System::Drawing::Point(1212, 562);
            this->Delete->Margin = System::Windows::Forms::Padding(5);
            this->Delete->Name = L"Delete";
            this->Delete->Size = System::Drawing::Size(60, 60);
            this->Delete->TabIndex = 35;
            this->Delete->Text = L"Del";
            this->Delete->UseVisualStyleBackColor = true;
            this->Delete->Click += gcnew System::EventHandler(this, &MyForm::Delete_Click);
            // 
            // ClearAll
            // 
            this->ClearAll->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                                static_cast<System::Byte>(0)));
            this->ClearAll->Location = System::Drawing::Point(1294, 14);
            this->ClearAll->Margin = System::Windows::Forms::Padding(5);
            this->ClearAll->Name = L"ClearAll";
            this->ClearAll->Size = System::Drawing::Size(130, 40);
            this->ClearAll->TabIndex = 36;
            this->ClearAll->Text = L"Clear All";
            this->ClearAll->UseVisualStyleBackColor = true;
            this->ClearAll->Click += gcnew System::EventHandler(this, &MyForm::ClearAll_Click);
            // 
            // Help
            // 
            this->Help->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                                            static_cast<System::Byte>(0)));
            this->Help->Location = System::Drawing::Point(1294, 72);
            this->Help->Margin = System::Windows::Forms::Padding(5);
            this->Help->Name = L"Help";
            this->Help->Size = System::Drawing::Size(130, 40);
            this->Help->TabIndex = 37;
            this->Help->Text = L"Help";
            this->Help->UseVisualStyleBackColor = true;
            this->Help->Click += gcnew System::EventHandler(this, &MyForm::Help_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1438, 711);
            this->Controls->Add(this->Help);
            this->Controls->Add(this->ClearAll);
            this->Controls->Add(this->Delete);
            this->Controls->Add(this->Clear);
            this->Controls->Add(this->Submit);
            this->Controls->Add(this->ValueName);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->Input);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->ValueList);
            this->Controls->Add(this->Com);
            this->Controls->Add(this->Dec);
            this->Controls->Add(this->Int);
            this->Controls->Add(this->Get);
            this->Controls->Add(this->Set);
            this->Controls->Add(this->Enter);
            this->Controls->Add(this->Eql);
            this->Controls->Add(this->Left);
            this->Controls->Add(this->Right);
            this->Controls->Add(this->Pow);
            this->Controls->Add(this->Fac);
            this->Controls->Add(this->Div);
            this->Controls->Add(this->Mul);
            this->Controls->Add(this->Sub);
            this->Controls->Add(this->Add);
            this->Controls->Add(this->ImagePart);
            this->Controls->Add(this->Decimal);
            this->Controls->Add(this->Num0);
            this->Controls->Add(this->Num9);
            this->Controls->Add(this->Num8);
            this->Controls->Add(this->Num7);
            this->Controls->Add(this->Num6);
            this->Controls->Add(this->Num5);
            this->Controls->Add(this->Num4);
            this->Controls->Add(this->Num3);
            this->Controls->Add(this->Num2);
            this->Controls->Add(this->Num1);
            this->Controls->Add(this->Show);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"MyForm";
            this->Text = L"Big Number Calculator";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

		void textInit();
		void help();
		void setList();
		void compute();
#pragma endregion
private: System::Void Set_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Get_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Int_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Dec_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Com_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Submit_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num1_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num3_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num4_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num5_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num6_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num7_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num8_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num9_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Num0_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Decimal_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ImagePart_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Add_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Left_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Sub_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Right_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Mul_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Pow_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Div_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Fac_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Eql_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Enter_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void ValueName_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void ClearAll_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Help_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Delete_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Clear_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void Input_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void ValueName_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void ValueList_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e);
};
}
