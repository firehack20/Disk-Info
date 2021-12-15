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
	/// Summary for PageHard
	/// </summary>
	public ref class PageHard : public System::Windows::Forms::UserControl
	{
	public:
		PageHard(void)
		{
			InitializeComponent();
			HardDriveInfo* info = new HardDriveInfo();
			ListHardDrive a = info->getHardDrives();
			for (uint16_t i = 0; i < a.size(); i++)
			{
				this->comboBox->Items->Add(L"PhysicalDrive" + i);
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
		~PageHard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox;
	protected:


	private: System::Windows::Forms::TextBox^ textBox_type;

	private: System::Windows::Forms::Label^ label_diskName;
	private: System::Windows::Forms::TextBox^ textBox_byteSector;


	private: System::Windows::Forms::Label^ label_byteSector;
	private: System::Windows::Forms::TextBox^ textBox_diskName;
	private: System::Windows::Forms::TextBox^ textBox_serial;

	private: System::Windows::Forms::Label^ label_totalSize;
	private: System::Windows::Forms::TextBox^ textBox_size;
	private: System::Windows::Forms::TextBox^ textBox_sectorTrack;



	private: System::Windows::Forms::Label^ label_type;
	private: System::Windows::Forms::Label^ label_serial;
	private: System::Windows::Forms::Label^ label_sectorTrack;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_trackCylinder;
	private: System::Windows::Forms::TextBox^ textBox_trackCylinder;
	private: System::Windows::Forms::Label^ label_cylinder;
	private: System::Windows::Forms::TextBox^ textBox_cylinder;

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
			this->textBox_type = (gcnew System::Windows::Forms::TextBox());
			this->label_diskName = (gcnew System::Windows::Forms::Label());
			this->textBox_byteSector = (gcnew System::Windows::Forms::TextBox());
			this->label_byteSector = (gcnew System::Windows::Forms::Label());
			this->textBox_diskName = (gcnew System::Windows::Forms::TextBox());
			this->textBox_serial = (gcnew System::Windows::Forms::TextBox());
			this->label_totalSize = (gcnew System::Windows::Forms::Label());
			this->textBox_size = (gcnew System::Windows::Forms::TextBox());
			this->textBox_sectorTrack = (gcnew System::Windows::Forms::TextBox());
			this->label_type = (gcnew System::Windows::Forms::Label());
			this->label_serial = (gcnew System::Windows::Forms::Label());
			this->label_sectorTrack = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label_trackCylinder = (gcnew System::Windows::Forms::Label());
			this->textBox_trackCylinder = (gcnew System::Windows::Forms::TextBox());
			this->textBox_cylinder = (gcnew System::Windows::Forms::TextBox());
			this->label_cylinder = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox
			// 
			this->comboBox->BackColor = System::Drawing::Color::White;
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Location = System::Drawing::Point(424, 12);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(167, 28);
			this->comboBox->TabIndex = 16;
			this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &PageHard::comboBox_SelectedIndexChanged);
			// 
			// textBox_type
			// 
			this->textBox_type->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_type->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_type->Location = System::Drawing::Point(135, 136);
			this->textBox_type->Name = L"textBox_type";
			this->textBox_type->ReadOnly = true;
			this->textBox_type->Size = System::Drawing::Size(290, 26);
			this->textBox_type->TabIndex = 0;
			// 
			// label_diskName
			// 
			this->label_diskName->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_diskName->AutoSize = true;
			this->label_diskName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_diskName->ForeColor = System::Drawing::Color::White;
			this->label_diskName->Location = System::Drawing::Point(41, 16);
			this->label_diskName->Name = L"label_diskName";
			this->label_diskName->Size = System::Drawing::Size(88, 20);
			this->label_diskName->TabIndex = 12;
			this->label_diskName->Text = L"Tên ổ đĩa:";
			// 
			// textBox_byteSector
			// 
			this->textBox_byteSector->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_byteSector->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_byteSector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_byteSector->Location = System::Drawing::Point(676, 13);
			this->textBox_byteSector->Name = L"textBox_byteSector";
			this->textBox_byteSector->ReadOnly = true;
			this->textBox_byteSector->Size = System::Drawing::Size(206, 26);
			this->textBox_byteSector->TabIndex = 11;
			// 
			// label_byteSector
			// 
			this->label_byteSector->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_byteSector->AutoSize = true;
			this->label_byteSector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_byteSector->ForeColor = System::Drawing::Color::White;
			this->label_byteSector->Location = System::Drawing::Point(538, 16);
			this->label_byteSector->Name = L"label_byteSector";
			this->label_byteSector->Size = System::Drawing::Size(130, 20);
			this->label_byteSector->TabIndex = 18;
			this->label_byteSector->Text = L"Số byte/sector:";
			// 
			// textBox_diskName
			// 
			this->textBox_diskName->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_diskName->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_diskName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_diskName->Location = System::Drawing::Point(135, 13);
			this->textBox_diskName->Name = L"textBox_diskName";
			this->textBox_diskName->ReadOnly = true;
			this->textBox_diskName->Size = System::Drawing::Size(290, 26);
			this->textBox_diskName->TabIndex = 10;
			// 
			// textBox_serial
			// 
			this->textBox_serial->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_serial->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_serial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_serial->Location = System::Drawing::Point(135, 73);
			this->textBox_serial->Name = L"textBox_serial";
			this->textBox_serial->ReadOnly = true;
			this->textBox_serial->Size = System::Drawing::Size(290, 26);
			this->textBox_serial->TabIndex = 5;
			// 
			// label_totalSize
			// 
			this->label_totalSize->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_totalSize->AutoSize = true;
			this->label_totalSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_totalSize->ForeColor = System::Drawing::Color::White;
			this->label_totalSize->Location = System::Drawing::Point(23, 199);
			this->label_totalSize->Name = L"label_totalSize";
			this->label_totalSize->Size = System::Drawing::Size(106, 20);
			this->label_totalSize->TabIndex = 16;
			this->label_totalSize->Text = L"Dung lượng:";
			// 
			// textBox_size
			// 
			this->textBox_size->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_size->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_size->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_size->Location = System::Drawing::Point(135, 196);
			this->textBox_size->Name = L"textBox_size";
			this->textBox_size->ReadOnly = true;
			this->textBox_size->Size = System::Drawing::Size(290, 26);
			this->textBox_size->TabIndex = 7;
			// 
			// textBox_sectorTrack
			// 
			this->textBox_sectorTrack->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_sectorTrack->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_sectorTrack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox_sectorTrack->Location = System::Drawing::Point(675, 73);
			this->textBox_sectorTrack->Name = L"textBox_sectorTrack";
			this->textBox_sectorTrack->ReadOnly = true;
			this->textBox_sectorTrack->Size = System::Drawing::Size(207, 26);
			this->textBox_sectorTrack->TabIndex = 8;
			// 
			// label_type
			// 
			this->label_type->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_type->AutoSize = true;
			this->label_type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_type->ForeColor = System::Drawing::Color::White;
			this->label_type->Location = System::Drawing::Point(33, 139);
			this->label_type->Name = L"label_type";
			this->label_type->Size = System::Drawing::Size(96, 20);
			this->label_type->TabIndex = 14;
			this->label_type->Text = L"Định dạng:";
			// 
			// label_serial
			// 
			this->label_serial->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_serial->AutoSize = true;
			this->label_serial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_serial->ForeColor = System::Drawing::Color::White;
			this->label_serial->Location = System::Drawing::Point(45, 76);
			this->label_serial->Name = L"label_serial";
			this->label_serial->Size = System::Drawing::Size(84, 20);
			this->label_serial->TabIndex = 13;
			this->label_serial->Text = L"Số serial:";
			// 
			// label_sectorTrack
			// 
			this->label_sectorTrack->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_sectorTrack->AutoSize = true;
			this->label_sectorTrack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_sectorTrack->ForeColor = System::Drawing::Color::White;
			this->label_sectorTrack->Location = System::Drawing::Point(532, 76);
			this->label_sectorTrack->Name = L"label_sectorTrack";
			this->label_sectorTrack->Size = System::Drawing::Size(136, 20);
			this->label_sectorTrack->TabIndex = 15;
			this->label_sectorTrack->Text = L"Số sector/track:";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30.81571F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				69.18429F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				243)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				213)));
			this->tableLayoutPanel1->Controls->Add(this->label_cylinder, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox_trackCylinder, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_trackCylinder, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_diskName, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_diskName, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_serial, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_serial, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_type, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label_totalSize, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_type, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox_size, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_byteSector, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox_byteSector, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_sectorTrack, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_sectorTrack, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox_cylinder, 3, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 67);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.53782F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.46218F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 59)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(885, 239);
			this->tableLayoutPanel1->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(318, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 20);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Chọn ổ đĩa:";
			// 
			// label_trackCylinder
			// 
			this->label_trackCylinder->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_trackCylinder->AutoSize = true;
			this->label_trackCylinder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_trackCylinder->ForeColor = System::Drawing::Color::White;
			this->label_trackCylinder->Location = System::Drawing::Point(521, 139);
			this->label_trackCylinder->Name = L"label_trackCylinder";
			this->label_trackCylinder->Size = System::Drawing::Size(147, 20);
			this->label_trackCylinder->TabIndex = 19;
			this->label_trackCylinder->Text = L"Số track/cylinder:";
			// 
			// textBox_trackCylinder
			// 
			this->textBox_trackCylinder->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_trackCylinder->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_trackCylinder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox_trackCylinder->Location = System::Drawing::Point(675, 136);
			this->textBox_trackCylinder->Name = L"textBox_trackCylinder";
			this->textBox_trackCylinder->ReadOnly = true;
			this->textBox_trackCylinder->Size = System::Drawing::Size(207, 26);
			this->textBox_trackCylinder->TabIndex = 20;
			// 
			// textBox_cylinder
			// 
			this->textBox_cylinder->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->textBox_cylinder->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_cylinder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_cylinder->Location = System::Drawing::Point(675, 196);
			this->textBox_cylinder->Name = L"textBox_cylinder";
			this->textBox_cylinder->ReadOnly = true;
			this->textBox_cylinder->Size = System::Drawing::Size(207, 26);
			this->textBox_cylinder->TabIndex = 21;
			// 
			// label_cylinder
			// 
			this->label_cylinder->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_cylinder->AutoSize = true;
			this->label_cylinder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_cylinder->ForeColor = System::Drawing::Color::White;
			this->label_cylinder->Location = System::Drawing::Point(566, 199);
			this->label_cylinder->Name = L"label_cylinder";
			this->label_cylinder->Size = System::Drawing::Size(102, 20);
			this->label_cylinder->TabIndex = 22;
			this->label_cylinder->Text = L"Số cylinder:";
			// 
			// PageHard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label2);
			this->Name = L"PageHard";
			this->Size = System::Drawing::Size(900, 411);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Double bytesToGB(System::Double bytes) {
			double temp = int(bytes / 1000000000 * 100);
			return temp / 100;
		}
	private: System::Void comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		HardDriveInfo* info = new HardDriveInfo();
		ListHardDrive a = info->getHardDrives();
		int i = comboBox->SelectedIndex;
		textBox_diskName->Text = gcnew System::String(a.at(i)->productId.c_str());
		textBox_serial->Text = gcnew System::String(a.at(i)->serialNumber.c_str());
		textBox_type->Text = gcnew System::String(a.at(i)->driveType.c_str());

		textBox_size->Text = a.at(i)->diskSize.ToString() + " Bytes  " + bytesToGB(a.at(i)->diskSize).ToString()+" GB";
		textBox_byteSector->Text = a.at(i)->bytesPerSector.ToString();
		textBox_sectorTrack->Text = a.at(i)->sectorsPerTrack.ToString();
		textBox_trackCylinder->Text = a.at(i)->tracksPerCylinder.ToString();
		textBox_cylinder->Text = a.at(i)->cylinders.ToString();

		//textBox_sectorCluster->Text = a.at(comboBox->SelectedIndex)->sectorsPerTrack.ToString();
		//MessageBox::Show(comboBox->SelectedIndex.ToString());
	}

};
}
