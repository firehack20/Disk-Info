#pragma once
#include "Disk_Manager.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Project1 {

	/// <summary>
	/// Summary for PageLogical
	/// </summary>
	public ref class PageLogical : public System::Windows::Forms::UserControl
	{
	public:
		PageLogical(void)
		{
			InitializeComponent();
			LogicalDriveInfo* info = new LogicalDriveInfo();
			ListLogicalDrive logic = info->getLogicalDrives();
			for (uint16_t i = 0; i < logic.size(); i++)
			{
				this->comboBox->Items->Add( gcnew String(logic.at(i)->pathName.c_str() ) );
			}
			this->comboBox->SelectedIndex = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PageLogical()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label_size;
	private: System::Windows::Forms::TextBox^ textBox_size;
	private: System::Windows::Forms::Label^ label_Name;
	private: System::Windows::Forms::TextBox^ textBox_name;

	private: System::Windows::Forms::Label^ label_type;
	private: System::Windows::Forms::TextBox^ textBox_type;
	private: System::Windows::Forms::Label^ label_system;
	private: System::Windows::Forms::TextBox^ textBox_system;
	private: System::Windows::Forms::Label^ label_byteSector;
	private: System::Windows::Forms::TextBox^ textBox_sectorCluster;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label_root;
	private: System::Windows::Forms::TextBox^ textBox_root;
	private: System::Windows::Forms::Label^ label_used;
	private: System::Windows::Forms::TextBox^ textBox_used;
	private: System::Windows::Forms::Label^ label_free;
	private: System::Windows::Forms::TextBox^ textBox_free;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox;
	private: System::Windows::Forms::TextBox^ textBox_GBsize;
	private: System::Windows::Forms::TextBox^ textBox_GBfree;

	private: System::Windows::Forms::TextBox^ textBox_GBused;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ percentage;
	private: System::Windows::Forms::TextBox^ textBox_byteSector;
	private: System::Windows::Forms::Label^ label1;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label_size = (gcnew System::Windows::Forms::Label());
			this->textBox_size = (gcnew System::Windows::Forms::TextBox());
			this->label_Name = (gcnew System::Windows::Forms::Label());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->label_type = (gcnew System::Windows::Forms::Label());
			this->textBox_type = (gcnew System::Windows::Forms::TextBox());
			this->label_system = (gcnew System::Windows::Forms::Label());
			this->textBox_system = (gcnew System::Windows::Forms::TextBox());
			this->label_byteSector = (gcnew System::Windows::Forms::Label());
			this->textBox_sectorCluster = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label_root = (gcnew System::Windows::Forms::Label());
			this->textBox_root = (gcnew System::Windows::Forms::TextBox());
			this->textBox_GBsize = (gcnew System::Windows::Forms::TextBox());
			this->textBox_GBused = (gcnew System::Windows::Forms::TextBox());
			this->textBox_GBfree = (gcnew System::Windows::Forms::TextBox());
			this->textBox_free = (gcnew System::Windows::Forms::TextBox());
			this->textBox_used = (gcnew System::Windows::Forms::TextBox());
			this->label_used = (gcnew System::Windows::Forms::Label());
			this->label_free = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->percentage = (gcnew System::Windows::Forms::Label());
			this->textBox_byteSector = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox
			// 
			this->comboBox->BackColor = System::Drawing::Color::White;
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Location = System::Drawing::Point(424, 12);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(167, 28);
			this->comboBox->TabIndex = 19;
			this->comboBox->Tag = L"";
			this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &PageLogical::comboBox_SelectedIndexChanged);
			// 
			// label_size
			// 
			this->label_size->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_size->AutoSize = true;
			this->label_size->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_size->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_size->Location = System::Drawing::Point(446, 10);
			this->label_size->Name = L"label_size";
			this->label_size->Size = System::Drawing::Size(106, 20);
			this->label_size->TabIndex = 16;
			this->label_size->Text = L"Dung lượng:";
			this->label_size->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_size
			// 
			this->textBox_size->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_size->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_size->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_size->Location = System::Drawing::Point(566, 7);
			this->textBox_size->Name = L"textBox_size";
			this->textBox_size->ReadOnly = true;
			this->textBox_size->Size = System::Drawing::Size(202, 26);
			this->textBox_size->TabIndex = 7;
			// 
			// label_Name
			// 
			this->label_Name->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_Name->AutoSize = true;
			this->label_Name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Name->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_Name->Location = System::Drawing::Point(3, 10);
			this->label_Name->Name = L"label_Name";
			this->label_Name->Size = System::Drawing::Size(88, 20);
			this->label_Name->TabIndex = 12;
			this->label_Name->Text = L"Tên ổ đĩa:";
			this->label_Name->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_name
			// 
			this->textBox_name->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_name->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_name->Location = System::Drawing::Point(172, 7);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->ReadOnly = true;
			this->textBox_name->Size = System::Drawing::Size(173, 26);
			this->textBox_name->TabIndex = 10;
			// 
			// label_type
			// 
			this->label_type->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_type->AutoSize = true;
			this->label_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_type->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_type->Location = System::Drawing::Point(3, 131);
			this->label_type->Name = L"label_type";
			this->label_type->Size = System::Drawing::Size(48, 20);
			this->label_type->TabIndex = 15;
			this->label_type->Text = L"Loại:";
			this->label_type->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_type
			// 
			this->textBox_type->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_type->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_type->Location = System::Drawing::Point(172, 128);
			this->textBox_type->Name = L"textBox_type";
			this->textBox_type->ReadOnly = true;
			this->textBox_type->Size = System::Drawing::Size(173, 26);
			this->textBox_type->TabIndex = 8;
			// 
			// label_system
			// 
			this->label_system->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_system->AutoSize = true;
			this->label_system->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_system->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_system->Location = System::Drawing::Point(3, 92);
			this->label_system->Name = L"label_system";
			this->label_system->Size = System::Drawing::Size(96, 20);
			this->label_system->TabIndex = 14;
			this->label_system->Text = L"Định dạng:";
			this->label_system->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_system
			// 
			this->textBox_system->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_system->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_system->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_system->Location = System::Drawing::Point(172, 89);
			this->textBox_system->Name = L"textBox_system";
			this->textBox_system->ReadOnly = true;
			this->textBox_system->Size = System::Drawing::Size(173, 26);
			this->textBox_system->TabIndex = 0;
			// 
			// label_byteSector
			// 
			this->label_byteSector->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_byteSector->AutoSize = true;
			this->label_byteSector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_byteSector->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_byteSector->Location = System::Drawing::Point(3, 207);
			this->label_byteSector->Name = L"label_byteSector";
			this->label_byteSector->Size = System::Drawing::Size(159, 20);
			this->label_byteSector->TabIndex = 18;
			this->label_byteSector->Text = L"Số sectors/cluster:";
			this->label_byteSector->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_sectorCluster
			// 
			this->textBox_sectorCluster->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_sectorCluster->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_sectorCluster->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox_sectorCluster->Location = System::Drawing::Point(172, 204);
			this->textBox_sectorCluster->Name = L"textBox_sectorCluster";
			this->textBox_sectorCluster->ReadOnly = true;
			this->textBox_sectorCluster->Size = System::Drawing::Size(173, 26);
			this->textBox_sectorCluster->TabIndex = 11;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.68035F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.31965F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				95)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				120)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				208)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				113)));
			this->tableLayoutPanel1->Controls->Add(this->panel4, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_root, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_root, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_Name, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_name, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_type, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_type, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_system, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_system, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_GBsize, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_GBused, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_GBfree, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_free, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_used, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_size, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_size, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_used, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_free, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_sectorCluster, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox_byteSector, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label_byteSector, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 4);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 71);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.19277F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.80723F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(885, 237);
			this->tableLayoutPanel1->TabIndex = 18;
			// 
			// panel4
			// 
			this->panel4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(410, 87);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(30, 30);
			this->panel4->TabIndex = 26;
			// 
			// panel3
			// 
			this->panel3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->panel3->BackColor = System::Drawing::Color::Navy;
			this->panel3->Location = System::Drawing::Point(410, 46);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(30, 30);
			this->panel3->TabIndex = 25;
			// 
			// label_root
			// 
			this->label_root->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_root->AutoSize = true;
			this->label_root->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_root->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_root->Location = System::Drawing::Point(3, 51);
			this->label_root->Name = L"label_root";
			this->label_root->Size = System::Drawing::Size(82, 20);
			this->label_root->TabIndex = 21;
			this->label_root->Text = L"Thư mục:";
			this->label_root->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox_root
			// 
			this->textBox_root->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_root->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_root->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_root->Location = System::Drawing::Point(172, 48);
			this->textBox_root->Name = L"textBox_root";
			this->textBox_root->ReadOnly = true;
			this->textBox_root->Size = System::Drawing::Size(173, 26);
			this->textBox_root->TabIndex = 21;
			// 
			// textBox_GBsize
			// 
			this->textBox_GBsize->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_GBsize->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_GBsize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_GBsize->Location = System::Drawing::Point(780, 7);
			this->textBox_GBsize->Name = L"textBox_GBsize";
			this->textBox_GBsize->ReadOnly = true;
			this->textBox_GBsize->Size = System::Drawing::Size(102, 26);
			this->textBox_GBsize->TabIndex = 23;
			// 
			// textBox_GBused
			// 
			this->textBox_GBused->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_GBused->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_GBused->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_GBused->Location = System::Drawing::Point(780, 48);
			this->textBox_GBused->Name = L"textBox_GBused";
			this->textBox_GBused->ReadOnly = true;
			this->textBox_GBused->Size = System::Drawing::Size(102, 26);
			this->textBox_GBused->TabIndex = 21;
			// 
			// textBox_GBfree
			// 
			this->textBox_GBfree->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_GBfree->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_GBfree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_GBfree->Location = System::Drawing::Point(780, 89);
			this->textBox_GBfree->Name = L"textBox_GBfree";
			this->textBox_GBfree->ReadOnly = true;
			this->textBox_GBfree->Size = System::Drawing::Size(102, 26);
			this->textBox_GBfree->TabIndex = 21;
			// 
			// textBox_free
			// 
			this->textBox_free->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_free->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_free->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_free->Location = System::Drawing::Point(566, 89);
			this->textBox_free->Name = L"textBox_free";
			this->textBox_free->ReadOnly = true;
			this->textBox_free->Size = System::Drawing::Size(202, 26);
			this->textBox_free->TabIndex = 22;
			// 
			// textBox_used
			// 
			this->textBox_used->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_used->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_used->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_used->Location = System::Drawing::Point(566, 48);
			this->textBox_used->Name = L"textBox_used";
			this->textBox_used->ReadOnly = true;
			this->textBox_used->Size = System::Drawing::Size(202, 26);
			this->textBox_used->TabIndex = 20;
			// 
			// label_used
			// 
			this->label_used->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_used->AutoSize = true;
			this->label_used->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_used->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_used->Location = System::Drawing::Point(446, 51);
			this->label_used->Name = L"label_used";
			this->label_used->Size = System::Drawing::Size(82, 20);
			this->label_used->TabIndex = 19;
			this->label_used->Text = L"Đã dùng:";
			this->label_used->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_free
			// 
			this->label_free->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label_free->AutoSize = true;
			this->label_free->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_free->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_free->Location = System::Drawing::Point(446, 92);
			this->label_free->Name = L"label_free";
			this->label_free->Size = System::Drawing::Size(93, 20);
			this->label_free->TabIndex = 21;
			this->label_free->Text = L"Còn trống:";
			this->label_free->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(274, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 20);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Chọn phân vùng:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::SlateGray;
			this->panel1->Controls->Add(this->percentage);
			this->panel1->Location = System::Drawing::Point(584, 194);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(214, 214);
			this->panel1->TabIndex = 21;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PageLogical::panel1_Paint);
			// 
			// percentage
			// 
			this->percentage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->percentage->AutoSize = true;
			this->percentage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->percentage->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->percentage->Location = System::Drawing::Point(87, 99);
			this->percentage->Name = L"percentage";
			this->percentage->Size = System::Drawing::Size(47, 15);
			this->percentage->TabIndex = 0;
			this->percentage->Text = L"label1";
			this->percentage->Visible = false;
			// 
			// textBox_byteSector
			// 
			this->textBox_byteSector->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_byteSector->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_byteSector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_byteSector->Location = System::Drawing::Point(172, 165);
			this->textBox_byteSector->Name = L"textBox_byteSector";
			this->textBox_byteSector->ReadOnly = true;
			this->textBox_byteSector->Size = System::Drawing::Size(173, 26);
			this->textBox_byteSector->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(3, 168);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 20);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Số bytes/sector:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PageLogical
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label2);
			this->Name = L"PageLogical";
			this->Size = System::Drawing::Size(900, 411);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Double alpha=0;
private: System::Double bytesToGB(System::Double bytes) {
	double temp= int( bytes / 1073741824 * 100);
	return temp / 100;
}
private: System::Void comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	LogicalDriveInfo* info = new LogicalDriveInfo();
	ListLogicalDrive logic = info->getLogicalDrives();
	int i=comboBox->SelectedIndex;
	textBox_name->Text = gcnew System::String(logic.at(i)->volumeName.c_str());
	textBox_root->Text = gcnew System::String(logic.at(i)->pathName.c_str());
	textBox_system->Text = gcnew System::String(logic.at(i)->fileSystemName.c_str());
	textBox_type->Text = gcnew System::String(logic.at(i)->type.c_str());
	textBox_byteSector->Text = logic.at(i)->bytesPerSector.ToString();
	textBox_sectorCluster->Text = logic.at(i)->sectorsPerCluster.ToString();
	textBox_size->Text = logic.at(i)->size.ToString()+" bytes";
	textBox_free->Text = logic.at(i)->sizeFree.ToString() + " bytes";
	textBox_used->Text = logic.at(i)->sizeUsed.ToString() + " bytes";
	textBox_GBsize->Text= bytesToGB(logic.at(i)->size).ToString() + " GB";
	textBox_GBfree->Text = bytesToGB(logic.at(i)->sizeFree).ToString() + " GB";
	textBox_GBused->Text = bytesToGB(logic.at(i)->sizeUsed).ToString() + " GB";
	double pe = bytesToGB(logic.at(i)->sizeUsed) / bytesToGB(logic.at(i)->size);
	alpha =pe *360;
	percentage->Text = (roundf(pe*1000)/10).ToString()+"%";
	percentage->Visible = true;
	this->Refresh();
}

private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;
	g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBilinear;
	g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::HighQuality;
	g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;
	//g->Clear(Color::SlateGray);

	Rectangle rect = ClientRectangle;
	Rectangle smallRect;
	smallRect.X = panel1->Height/4;//rect.X + rect.Width / 4;
	smallRect.Y = panel1->Height /4;//rect.Y + rect.Height / 4;
	smallRect.Width = panel1->Height / 2;//rect.Width / 2;
	smallRect.Height = panel1->Height / 2;//rect.Height / 2;

	Pen^ whitePen = gcnew Pen(Color::White);
	whitePen->Width = 10;
	//g->DrawLine(redPen, 0, 0, rect.Width, rect.Height);
	g->DrawEllipse(whitePen, smallRect);
	Pen^ bluePen = gcnew Pen(Color::Navy);
	bluePen->Width = 11;
	g->DrawArc(bluePen, smallRect, 180, alpha);
	
}
};//class
}
