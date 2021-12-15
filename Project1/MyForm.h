#pragma once
//#include "DiskInfo.h"
#include "PageHome.h"
#include "PageHard.h"
#include "PageLogical.h"
 
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	
	
	public:

		MyForm(void)
		{
			InitializeComponent();
			//PageHome^ h = gcnew PageHome();
			PageHard^ h = gcnew PageHard();
			this->panel1->Controls->Add(h);

			//	this->comboBox1->Items->Add(i);
			
			//
			//TODO: Add the constructor code here
			
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{	
			
			if (components)
			{
				delete components;
			}
		}
	protected:
	//private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ gioiThieu;
	private: System::Windows::Forms::Button^ hardDisk;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ LogicalDisk;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	//private: DiskInfo *info;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->gioiThieu = (gcnew System::Windows::Forms::Button());
			this->hardDisk = (gcnew System::Windows::Forms::Button());
			this->LogicalDisk = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::DimGray;
			this->flowLayoutPanel1->Controls->Add(this->hardDisk);
			this->flowLayoutPanel1->Controls->Add(this->LogicalDisk);
			this->flowLayoutPanel1->Controls->Add(this->gioiThieu);
			resources->ApplyResources(this->flowLayoutPanel1, L"flowLayoutPanel1");
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			// 
			// gioiThieu
			// 
			resources->ApplyResources(this->gioiThieu, L"gioiThieu");
			this->gioiThieu->Name = L"gioiThieu";
			this->gioiThieu->UseVisualStyleBackColor = true;
			this->gioiThieu->Click += gcnew System::EventHandler(this, &MyForm::gioiThieu_Click);
			// 
			// hardDisk
			// 
			resources->ApplyResources(this->hardDisk, L"hardDisk");
			this->hardDisk->Name = L"hardDisk";
			this->hardDisk->UseVisualStyleBackColor = true;
			this->hardDisk->Click += gcnew System::EventHandler(this, &MyForm::hardDisk_Click);
			// 
			// LogicalDisk
			// 
			resources->ApplyResources(this->LogicalDisk, L"LogicalDisk");
			this->LogicalDisk->Name = L"LogicalDisk";
			this->LogicalDisk->UseVisualStyleBackColor = true;
			this->LogicalDisk->Click += gcnew System::EventHandler(this, &MyForm::LogicalDisk_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Name = L"label2";
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Boolean mouseDown;
		private: int mouseX=0, mouseY=0;
	private: System::Void gioiThieu_Click(System::Object^ sender, System::EventArgs^ e) {
		if (panel1->Controls->Count > 0)
		{
			panel1->Controls->RemoveAt(0);
			//panel1.Controls.Remove(item);
		}
		panel1->Controls->Add(gcnew PageHome());

	}
	private: System::Void hardDisk_Click(System::Object^ sender, System::EventArgs^ e) {
		//panel0->Visible = false;
		 //FormHard^ frm2 = gcnew Form2(this);
		if( panel1->Controls->Count>0)
		{
			panel1->Controls->RemoveAt(0);
			//panel1.Controls.Remove(item);
		}
		panel1->Controls->Add(gcnew PageHard());
		//panel1->Controls["PageHard"]->BringToFront();
		 //frm2->Show();
		
	}
	
		   
	
private: System::Void LogicalDisk_Click(System::Object^ sender, System::EventArgs^ e) {
	if (panel1->Controls->Count > 0)
	{
		panel1->Controls->RemoveAt(0);
		//panel1.Controls.Remove(item);
	}
	panel1->Controls->Add(gcnew PageLogical());
}

private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouseDown = true;
}
private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (mouseDown) {
		mouseX = MousePosition.X -500;
		mouseY = MousePosition.Y -20;
		this->SetDesktopLocation(mouseX, mouseY);
	}
}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouseDown = false;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
