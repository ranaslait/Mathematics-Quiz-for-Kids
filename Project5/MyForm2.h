#pragma once
#include <cstdlib>
#include <fstream>
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class 
		MyForm2 : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		MyForm2(void)
		{
			InitializeComponent();
			intialize_data();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm2(Form^ obj1)
		{
			obj = obj1;
			InitializeComponent();
			intialize_data();
			//
		//	//TODO: Add the constructor code here
		//	//
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private:int level = 0;
	private:double final_value = 0.0;
	private: System::Windows::Forms::Label^ label1;
		   
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(272, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"n/a";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(387, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"=";
			// 
			// button1
		// 
			this->button1->Location = System::Drawing::Point(206, 298);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(297, 47);
			this->button1->TabIndex = 2;
			this->button1->Text = L"check  answer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click1);
		// 
			// label3
		// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(203, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(321, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"label4";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(417, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(188, 22);
			this->textBox1->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(321, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 16);
			this->label5->TabIndex = 8;
			this->label5->Text = L"score:";
		// 
		// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(733, 470);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void intialize_data() {
			int x, y,mod;
			mod = ((level / 10 )+1)*(10);
			x = rand() % mod;
			y = rand() % mod;
			label3->Text =System::Convert::ToString(x);
			label4->Text= System::Convert::ToString(y);
			if (level %4 == 0) { //levl 0 +
				label1->Text = "+";
				 final_value = x + y;
			}
			else if (level %4 == 1) { 
				label1->Text = "-";
				 final_value = x - y;
			}
			else if (level %4 == 2) {
				label1 -> Text = "x";
				 final_value = x * y;
			}
			else {
				label1->Text = "/";
				 final_value = x / y;
			}
		}
	

		   private: Void button1_Click1(Object^ sender, System::EventArgs^ e) {
			 double result= Convert::ToInt16(textBox1->Text);
			 if (result == final_value)
			 {
				 level++;
				 textBox1->Clear();
				 intialize_data();
				 label5 -> Text = "score:" + level;
				 textBox1->Clear();

			   }
			 else {
				 String^ msg = "Try Again!";
				 String^ cap = "Error";
				 MessageBox::Show(msg, cap);
				 textBox1->Clear();
			 }

		   }
 private: Void button2_Click(Object^ sender, EventArgs^ e) {
	 intialize_data();
		
				   }
		private: void Form1_FormClosing(Object sender, FormClosingEventArgs e) {

			String^ msg = "Try Again!";
			String^ cap = "Error";
			MessageBox::Show(msg, cap);
		}
			   //void myForm_FormClosing(Object^ sender, FormClosingEventArgs^ e)
			   //{
				  // //your code here
				 
				  // String^ msg = "Hello";
				  // String^ cap = "GRT22";
				  // MessageBox::Show(msg, cap);
			   //}
	};
}
