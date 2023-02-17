#include "pch.h"
#include "Question_Form.h"
using namespace System;

Question_FormNamespace::Question_Form::Question_Form(void)
{
	InitializeComponent();
	x1 = -10;
	x2 = 10;
}
Question_FormNamespace::Question_Form::~Question_Form()
{
	if (components)
	{
		delete components;
	}
}

System::Void Question_FormNamespace::Question_Form::btnAccept_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		x1 = Convert::ToDouble(tblFrom->Text);
		x2 = Convert::ToDouble(tblTo->Text);
	}
	catch (...) {
		MessageBox::Show("Не коректний ввід числових даних!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	Close();
}

Double Question_FormNamespace::Question_Form::getXFrom()
{
	return x1;
}
Double Question_FormNamespace::Question_Form::getXTo()
{
	return x2;
}
