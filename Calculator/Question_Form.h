#pragma once
using namespace System::Collections::Generic;

namespace Question_FormNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;

	/// <summary>
	/// ���� ��� ����������� �����, �������� ��� �������� ��� �������� �������.
	/// </summary>
	public ref class Question_Form : public System::Windows::Forms::Form
	{
		/// <summary>
		/// ������� ����� Question_Form �� �������� �� ����������.
		/// </summary>
	public: Question_Form(void);

		/// <summary>
		/// ������� �� �������������� ������ Question_Form ����������.
		/// </summary>
	protected: ~Question_Form();

	/// <summary>
	/// ˳�� ���� �������� ������� (�� ����� �������� ���������� x ������� �������� ������).
	/// </summary>
	private: Double x1;
	/// <summary>
	/// ����� ���� �������� ������� (�� ����� �������� ���������� x ������� �������� ������).
	/// </summary>
	private: Double x2;
	/// <summary>
	/// �����, ��� ������ �� �������� ����� Question_Form.
	/// </summary>
	private: System::Windows::Forms::GroupBox^ boxQuestion;
	/// <summary>
	/// ���� ��� �������� ��� ��� �������� �������.
	/// </summary>
	private: System::Windows::Forms::TextBox^ tblFrom;
	/// <summary>
	/// ���� ��� �������� ����� ��� �������� �������.
	/// </summary>
	private: System::Windows::Forms::TextBox^ tblTo;
	/// <summary>
	/// ������ ��� ������������ �������� ����� �� ���������� �� �������� (����������) �����.
	/// </summary>
	private: System::Windows::Forms::Button^ btnAccept;
	/// <summary>
	/// ����� "³�".
	/// </summary>
	private: System::Windows::Forms::Label^ labelFrom;
	/// <summary>
	/// ����� "��".
	/// </summary>
	private: System::Windows::Forms::Label^ labelTo;

	/// <summary>
	/// ��������� ����� ��� ��������� ���������� ���������� �������.
	/// </summary>
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �������� �� ������� ���������� �����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->boxQuestion = (gcnew System::Windows::Forms::GroupBox());
			this->tblFrom = (gcnew System::Windows::Forms::TextBox());
			this->tblTo = (gcnew System::Windows::Forms::TextBox());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->labelFrom = (gcnew System::Windows::Forms::Label());
			this->labelTo = (gcnew System::Windows::Forms::Label());
			this->boxQuestion->SuspendLayout();
			this->SuspendLayout();
			// 
			// boxQuestion
			// 
			this->boxQuestion->AutoSize = true;
			this->boxQuestion->Controls->Add(this->tblFrom);
			this->boxQuestion->Controls->Add(this->tblTo);
			this->boxQuestion->Controls->Add(this->btnAccept);
			this->boxQuestion->Controls->Add(this->labelFrom);
			this->boxQuestion->Controls->Add(this->labelTo);
			this->boxQuestion->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->boxQuestion->Location = System::Drawing::Point(12, 12);
			this->boxQuestion->Name = L"boxQuestion";
			this->boxQuestion->Size = System::Drawing::Size(350, 197);
			this->boxQuestion->TabIndex = 10;
			this->boxQuestion->TabStop = false;
			this->boxQuestion->Text = L"������ ��� ��� �������� �������:";
			// 
			// tblFrom
			// 
			this->tblFrom->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->tblFrom->Location = System::Drawing::Point(14, 66);
			this->tblFrom->Name = L"tblFrom";
			this->tblFrom->Size = System::Drawing::Size(120, 26);
			this->tblFrom->TabIndex = 2;
			this->tblFrom->Text = L"-10";
			// 
			// tblTo
			// 
			this->tblTo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->tblTo->Location = System::Drawing::Point(194, 66);
			this->tblTo->Name = L"tblTo";
			this->tblTo->Size = System::Drawing::Size(120, 26);
			this->tblTo->TabIndex = 2;
			this->tblTo->Text = L"10";
			// 
			// btnAccept
			// 
			this->btnAccept->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAccept->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13));
			this->btnAccept->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnAccept->Location = System::Drawing::Point(78, 119);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(170, 49);
			this->btnAccept->TabIndex = 5;
			this->btnAccept->Text = L"ϳ���������";
			this->btnAccept->UseVisualStyleBackColor = true;
			this->btnAccept->Click += gcnew System::EventHandler(this, &Question_Form::btnAccept_Click);
			// 
			// labelFrom
			// 
			this->labelFrom->AutoSize = true;
			this->labelFrom->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->labelFrom->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->labelFrom->Location = System::Drawing::Point(10, 35);
			this->labelFrom->Name = L"labelFrom";
			this->labelFrom->Size = System::Drawing::Size(33, 19);
			this->labelFrom->TabIndex = 8;
			this->labelFrom->Text = L"³�:";
			// 
			// labelTo
			// 
			this->labelTo->AutoSize = true;
			this->labelTo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->labelTo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->labelTo->Location = System::Drawing::Point(190, 35);
			this->labelTo->Name = L"labelTo";
			this->labelTo->Size = System::Drawing::Size(31, 19);
			this->labelTo->TabIndex = 8;
			this->labelTo->Text = L"��:";
			// 
			// Question_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(374, 221);
			this->Controls->Add(this->boxQuestion);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MaximumSize = System::Drawing::Size(390, 260);
			this->MinimumSize = System::Drawing::Size(390, 260);
			this->Name = L"Question_Form";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��� ��������";
			this->boxQuestion->ResumeLayout(false);
			this->boxQuestion->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/// <summary>
	/// ����� ������ ������������ ��� ��� �������� ������� � ������� ���� �����.
	/// </summary>
	/// <param name = 'sender'>�ᒺ�� ����� Object^</param>
	/// <param name = 'e'>��'��� ����� EventArgs^</param>
	/// <returns>�������� ���� Void.</returns>
    private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// ������� �������� ��� ��� �������� �������.
	/// </summary>
	/// <returns>�������� ���� Double.</returns>
    public: Double getXFrom();
	/// <summary>
	/// ������� �������� ����� ��� �������� �������.
	/// </summary>
	/// <returns>�������� ���� Double.</returns>
	public: Double getXTo();
	};
}
