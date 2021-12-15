//#include "stdafx.h"
//#include "DiskInfor.h"
#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	Application::Run(%form);
	//DiskInfo dI;
	
	//form.get_ComBoBox1_Value();
}
