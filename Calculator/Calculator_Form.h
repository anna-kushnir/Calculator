#pragma once
#include <string>
#include "Equations.h"
#include "Question_Form.h"
using namespace System::Collections::Generic;

namespace CalculatorNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Клас для відображення форми, що містить засоби для розв'язання системи нелінійних рівнянь.
	/// </summary>
	public ref class Calculator_Form : public System::Windows::Forms::Form
	{
		/// <summary>
		/// Створює форму Calculator_Form та ініціалізує її компоненти.
		/// </summary>
	public: Calculator_Form(void);
		/// <summary>
		/// Видаляє всі використовувані формою Calculator_Form компоненти.
		/// </summary>
	protected: ~Calculator_Form();

	/// <summary>
	/// Шлях до файлу, куди користувач зберігає отриманий результат розв'язку системи.
	/// </summary>
	private: String^ path;
	/// <summary>
	/// Система нелінійних рівнянь обраного виду з уведеними коефіцієнтами, а також, 
	/// можливо, з вказаними початковими наближеннями розв'язку.
	/// </summary>
	private: Equations^ equations;
	/// <summary>
	/// Масив, що складається з отриманих результатів (x;y) на кожній ітерації 
	/// (якщо вдалося застосувати для розв'язання ітераційні методи), або з одного
	/// розв'язку (x;y) (якщо не вдалося застосувати ітераційні методи або розв'язок 
	/// знайшовся аналітично). 
	/// </summary>
	private: System::Collections::Generic::List<Double>^ result;

	/// <summary>
	/// Група, яка містить функціонал для вибору виду системи рівнянь.
	/// </summary>
	private: System::Windows::Forms::GroupBox^ boxEqType;
	/// <summary>
	/// Кнопка для вибору системи арифметичних рівнянь.
	/// </summary>
	private: System::Windows::Forms::RadioButton^ btnArithmEq;
	/// <summary>
	/// Кнопка для вибору системи тригонометричних рівнянь.
	/// </summary>
	private: System::Windows::Forms::RadioButton^ btnTrigonomEq;
	/// <summary>
	/// Кнопка для вибору системи трансцендентних рівнянь.
	/// </summary>
	private: System::Windows::Forms::RadioButton^ btnTranscEq;

	/// <summary>
	/// Група, яка містить таблицю для введення коефіцієнтів рівнянь.
	/// </summary>
	private: System::Windows::Forms::GroupBox^ boxCoeff;
	/// <summary>
	/// Таблиця коефіцієнтів рівнянь системи.
	/// </summary>
	private: System::Windows::Forms::DataGridView^ tblCoeff;

	/// <summary>
	/// Група, яка містить функціонал для вибору методу розв'язання системи рівнянь.
	/// </summary>
	private: System::Windows::Forms::GroupBox^ boxSolMethod;
	/// <summary>
	/// Рядок меню для вибору методу розв'язання системи рівнянь.
	/// </summary>
	private: System::Windows::Forms::MenuStrip^ menuMethod;
	/// <summary>
	/// Меню для вибору методу розв'язання системи рівнянь.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ btnMethod;
	/// <summary>
	/// Елемент меню для вибору методу Якобі.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ btnJakobiMethod;
	/// <summary>
	/// Елемент меню для вибору методу Гауса-Зейделя.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ btnZeydelMethod;

	/// <summary>
	/// Група, яка містить таблицю для введення початкових наближень.
	/// </summary>
	private: System::Windows::Forms::GroupBox^ boxInitApprox;
	/// <summary>
	/// Таблиця початкових наближень розв'язку системи рівнянь.
	/// </summary>
	private: System::Windows::Forms::DataGridView^ tblInitApprox;

	/// <summary>
	/// Група, яка містить поле для введення точності обчислень.
	/// </summary>
	private: System::Windows::Forms::GroupBox^ boxPrecision;
	/// <summary>
	/// Текстове поле для введення точності обчислень.
	/// </summary>
	private: System::Windows::Forms::TextBox^ tblPrecision;
	/// <summary>
	/// Знак "=".
	/// </summary>
	private: System::Windows::Forms::Label^ labelEqual;
	/// <summary>
	/// Знак "Епсилон".
	/// </summary>
	private: System::Windows::Forms::Label^ labelEps;

	/// <summary>
	/// Кнопка для початку розв'язування системи рівнянь.
	/// </summary>
	private: System::Windows::Forms::Button^ btnStart;
	/// <summary>
	/// Кнопка для побудови графіків рівнянь системи.
	/// </summary>
	private: System::Windows::Forms::Button^ btnDrawGraph;
	/// <summary>
	/// Кнопка для очищення форми.
	/// </summary>
	private: System::Windows::Forms::Button^ btnClear;

	/// <summary>
	/// Напис "Розв'язання".
	/// </summary>
	private: System::Windows::Forms::Label^ labelSolution;
	/// <summary>
	/// Текстове поле для виведення результату розв'язання системи.
	/// </summary>
	private: System::Windows::Forms::RichTextBox^ ResultBox;
	/// <summary>
	/// Текстове поле для виведення обраного рівняння з введеними коефіцієнтами.
	/// </summary>
	private: System::Windows::Forms::RichTextBox^ tblYourEquation;
	/// <summary>
	/// Графіки рівнянь системи.
	/// </summary>
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ graphEquations;

	/// <summary>
	/// Рядок меню головного вікна.
	/// </summary>
	private: System::Windows::Forms::MenuStrip^ menu;
	/// <summary>
	/// Головне меню.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ menuMain;
	/// <summary>
	/// Елемент головного меню для очищення форми.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ menuClear;
	/// <summary>
	/// Елемент головного меню для збереження результату у раніше створений або 
	/// новий файл.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ menuSaveResult;
	/// <summary>
	/// Елемент головного меню для збереження результату у новий файл.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ menuSaveResultAs;
	/// <summary>
	/// Елемент головного меню для відкриття останнього збереженого результату.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ menuSeeLast;
	/// <summary>
	/// Меню для виведення інформації.
	/// </summary>
	private: System::Windows::Forms::ToolStripMenuItem^ menuInfo;

	/// <summary>
	/// Необхідна змінна для зберігання компонентів графічного дизайну.
	/// </summary>
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Ініціалізує всі графічні компоненти форми.
	/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->boxEqType = (gcnew System::Windows::Forms::GroupBox());
			this->btnTranscEq = (gcnew System::Windows::Forms::RadioButton());
			this->btnTrigonomEq = (gcnew System::Windows::Forms::RadioButton());
			this->btnArithmEq = (gcnew System::Windows::Forms::RadioButton());
			this->boxCoeff = (gcnew System::Windows::Forms::GroupBox());
			this->tblCoeff = (gcnew System::Windows::Forms::DataGridView());
			this->boxInitApprox = (gcnew System::Windows::Forms::GroupBox());
			this->tblInitApprox = (gcnew System::Windows::Forms::DataGridView());
			this->boxSolMethod = (gcnew System::Windows::Forms::GroupBox());
			this->menuMethod = (gcnew System::Windows::Forms::MenuStrip());
			this->btnMethod = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnJakobiMethod = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnZeydelMethod = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boxPrecision = (gcnew System::Windows::Forms::GroupBox());
			this->tblPrecision = (gcnew System::Windows::Forms::TextBox());
			this->labelEqual = (gcnew System::Windows::Forms::Label());
			this->labelEps = (gcnew System::Windows::Forms::Label());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->ResultBox = (gcnew System::Windows::Forms::RichTextBox());
			this->labelSolution = (gcnew System::Windows::Forms::Label());
			this->menuMain = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuClear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSaveResult = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSaveResultAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSeeLast = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->graphEquations = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tblYourEquation = (gcnew System::Windows::Forms::RichTextBox());
			this->btnDrawGraph = (gcnew System::Windows::Forms::Button());
			this->boxEqType->SuspendLayout();
			this->boxCoeff->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblCoeff))->BeginInit();
			this->boxInitApprox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblInitApprox))->BeginInit();
			this->boxSolMethod->SuspendLayout();
			this->menuMethod->SuspendLayout();
			this->boxPrecision->SuspendLayout();
			this->menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphEquations))->BeginInit();
			this->SuspendLayout();
			// 
			// boxEqType
			// 
			this->boxEqType->AutoSize = true;
			this->boxEqType->Controls->Add(this->btnTranscEq);
			this->boxEqType->Controls->Add(this->btnTrigonomEq);
			this->boxEqType->Controls->Add(this->btnArithmEq);
			this->boxEqType->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->boxEqType->Location = System::Drawing::Point(12, 28);
			this->boxEqType->Name = L"boxEqType";
			this->boxEqType->Size = System::Drawing::Size(384, 270);
			this->boxEqType->TabIndex = 0;
			this->boxEqType->TabStop = false;
			this->boxEqType->Text = L"Вид системи:";
			// 
			// btnTranscEq
			// 
			this->btnTranscEq->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnTranscEq->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnTranscEq->Location = System::Drawing::Point(38, 187);
			this->btnTranscEq->Name = L"btnTranscEq";
			this->btnTranscEq->Size = System::Drawing::Size(269, 46);
			this->btnTranscEq->TabIndex = 2;
			this->btnTranscEq->Text = L"  e^(a11*x) + e^(a12*y) + a13 = 0\r\n  e^(a21*x) + e^(a22*y) + a23 = 0";
			this->btnTranscEq->UseVisualStyleBackColor = true;
			// 
			// btnTrigonomEq
			// 
			this->btnTrigonomEq->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnTrigonomEq->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnTrigonomEq->Location = System::Drawing::Point(38, 113);
			this->btnTrigonomEq->Name = L"btnTrigonomEq";
			this->btnTrigonomEq->Size = System::Drawing::Size(269, 43);
			this->btnTrigonomEq->TabIndex = 1;
			this->btnTrigonomEq->Text = L"  sin(x + a11) + a12 * y  + a13 = 0\r\n  a21 * x + cos(y + a22) + a23 = 0";
			this->btnTrigonomEq->UseVisualStyleBackColor = true;
			// 
			// btnArithmEq
			// 
			this->btnArithmEq->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnArithmEq->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnArithmEq->Location = System::Drawing::Point(38, 33);
			this->btnArithmEq->Name = L"btnArithmEq";
			this->btnArithmEq->Size = System::Drawing::Size(269, 46);
			this->btnArithmEq->TabIndex = 0;
			this->btnArithmEq->Text = L"  a11 * x^2 + a12 * y^2 + a13 = 0\r\n  a21 * x^2 + a22 * y^2 + a23 = 0";
			this->btnArithmEq->UseVisualStyleBackColor = true;
			// 
			// boxCoeff
			// 
			this->boxCoeff->AutoSize = true;
			this->boxCoeff->Controls->Add(this->tblCoeff);
			this->boxCoeff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->boxCoeff->Location = System::Drawing::Point(402, 28);
			this->boxCoeff->Name = L"boxCoeff";
			this->boxCoeff->Size = System::Drawing::Size(419, 138);
			this->boxCoeff->TabIndex = 1;
			this->boxCoeff->TabStop = false;
			this->boxCoeff->Text = L"Коефіцієнти рівнянь:";
			// 
			// tblCoeff
			// 
			this->tblCoeff->AllowUserToAddRows = false;
			this->tblCoeff->AllowUserToDeleteRows = false;
			this->tblCoeff->AllowUserToResizeColumns = false;
			this->tblCoeff->AllowUserToResizeRows = false;
			this->tblCoeff->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblCoeff->BackgroundColor = System::Drawing::SystemColors::Window;
			this->tblCoeff->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tblCoeff->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->tblCoeff->ColumnHeadersVisible = false;
			this->tblCoeff->Cursor = System::Windows::Forms::Cursors::IBeam;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->NullValue = L"0";
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->tblCoeff->DefaultCellStyle = dataGridViewCellStyle1;
			this->tblCoeff->Location = System::Drawing::Point(23, 33);
			this->tblCoeff->Name = L"tblCoeff";
			this->tblCoeff->RowHeadersVisible = false;
			this->tblCoeff->RowTemplate->Height = 39;
			this->tblCoeff->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tblCoeff->Size = System::Drawing::Size(360, 80);
			this->tblCoeff->TabIndex = 0;
			// 
			// boxInitApprox
			// 
			this->boxInitApprox->AutoSize = true;
			this->boxInitApprox->Controls->Add(this->tblInitApprox);
			this->boxInitApprox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->boxInitApprox->Location = System::Drawing::Point(827, 28);
			this->boxInitApprox->Name = L"boxInitApprox";
			this->boxInitApprox->Size = System::Drawing::Size(272, 137);
			this->boxInitApprox->TabIndex = 9;
			this->boxInitApprox->TabStop = false;
			this->boxInitApprox->Text = L"Початкові наближення:";
			// 
			// tblInitApprox
			// 
			this->tblInitApprox->AllowUserToAddRows = false;
			this->tblInitApprox->AllowUserToDeleteRows = false;
			this->tblInitApprox->AllowUserToResizeColumns = false;
			this->tblInitApprox->AllowUserToResizeRows = false;
			this->tblInitApprox->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->tblInitApprox->BackgroundColor = System::Drawing::SystemColors::Window;
			this->tblInitApprox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tblInitApprox->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->tblInitApprox->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tblInitApprox->ColumnHeadersVisible = false;
			this->tblInitApprox->Cursor = System::Windows::Forms::Cursors::IBeam;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->NullValue = L"0";
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->tblInitApprox->DefaultCellStyle = dataGridViewCellStyle2;
			this->tblInitApprox->Location = System::Drawing::Point(28, 32);
			this->tblInitApprox->Name = L"tblInitApprox";
			this->tblInitApprox->RowHeadersVisible = false;
			this->tblInitApprox->RowHeadersWidth = 100;
			this->tblInitApprox->RowTemplate->Height = 39;
			this->tblInitApprox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->tblInitApprox->Size = System::Drawing::Size(200, 80);
			this->tblInitApprox->TabIndex = 0;
			// 
			// boxSolMethod
			// 
			this->boxSolMethod->AutoSize = true;
			this->boxSolMethod->Controls->Add(this->menuMethod);
			this->boxSolMethod->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->boxSolMethod->Location = System::Drawing::Point(401, 171);
			this->boxSolMethod->Name = L"boxSolMethod";
			this->boxSolMethod->Size = System::Drawing::Size(419, 127);
			this->boxSolMethod->TabIndex = 3;
			this->boxSolMethod->TabStop = false;
			this->boxSolMethod->Text = L"Метод розв\'язання системи:";
			// 
			// menuMethod
			// 
			this->menuMethod->AutoSize = false;
			this->menuMethod->BackColor = System::Drawing::SystemColors::MenuBar;
			this->menuMethod->Dock = System::Windows::Forms::DockStyle::None;
			this->menuMethod->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuMethod->GripMargin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->menuMethod->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->menuMethod->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->btnMethod });
			this->menuMethod->Location = System::Drawing::Point(24, 56);
			this->menuMethod->Name = L"menuMethod";
			this->menuMethod->Size = System::Drawing::Size(275, 30);
			this->menuMethod->TabIndex = 2;
			this->menuMethod->Text = L"menuMethod";
			// 
			// btnMethod
			// 
			this->btnMethod->AutoSize = false;
			this->btnMethod->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->btnJakobiMethod,
					this->btnZeydelMethod
			});
			this->btnMethod->Name = L"btnMethod";
			this->btnMethod->Size = System::Drawing::Size(260, 25);
			this->btnMethod->Text = L"Оберіть метод розв\'язання";
			// 
			// btnJakobiMethod
			// 
			this->btnJakobiMethod->AutoSize = false;
			this->btnJakobiMethod->BackColor = System::Drawing::SystemColors::MenuBar;
			this->btnJakobiMethod->Name = L"btnJakobiMethod";
			this->btnJakobiMethod->Size = System::Drawing::Size(273, 24);
			this->btnJakobiMethod->Text = L"Метод простої ітерації (Якобі)";
			this->btnJakobiMethod->Click += gcnew System::EventHandler(this, &Calculator_Form::btnJakobiMethod_Click);
			// 
			// btnZeydelMethod
			// 
			this->btnZeydelMethod->AutoSize = false;
			this->btnZeydelMethod->BackColor = System::Drawing::SystemColors::MenuBar;
			this->btnZeydelMethod->Name = L"btnZeydelMethod";
			this->btnZeydelMethod->Size = System::Drawing::Size(273, 24);
			this->btnZeydelMethod->Text = L"Метод Гауса-Зейделя";
			this->btnZeydelMethod->Click += gcnew System::EventHandler(this, &Calculator_Form::btnZeydelMethod_Click);
			// 
			// boxPrecision
			// 
			this->boxPrecision->AutoSize = true;
			this->boxPrecision->Controls->Add(this->tblPrecision);
			this->boxPrecision->Controls->Add(this->labelEqual);
			this->boxPrecision->Controls->Add(this->labelEps);
			this->boxPrecision->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->boxPrecision->Location = System::Drawing::Point(826, 171);
			this->boxPrecision->Name = L"boxPrecision";
			this->boxPrecision->Size = System::Drawing::Size(273, 127);
			this->boxPrecision->TabIndex = 10;
			this->boxPrecision->TabStop = false;
			this->boxPrecision->Text = L"Точність:";
			// 
			// tblPrecision
			// 
			this->tblPrecision->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->tblPrecision->Location = System::Drawing::Point(86, 56);
			this->tblPrecision->Name = L"tblPrecision";
			this->tblPrecision->Size = System::Drawing::Size(142, 26);
			this->tblPrecision->TabIndex = 2;
			this->tblPrecision->Text = L"0,0001";
			// 
			// labelEqual
			// 
			this->labelEqual->AutoSize = true;
			this->labelEqual->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->labelEqual->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->labelEqual->Location = System::Drawing::Point(58, 58);
			this->labelEqual->Name = L"labelEqual";
			this->labelEqual->Size = System::Drawing::Size(18, 19);
			this->labelEqual->TabIndex = 1;
			this->labelEqual->Text = L"=";
			// 
			// labelEps
			// 
			this->labelEps->AutoSize = true;
			this->labelEps->Font = (gcnew System::Drawing::Font(L"Vladimir Script", 12, System::Drawing::FontStyle::Bold));
			this->labelEps->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->labelEps->Location = System::Drawing::Point(30, 59);
			this->labelEps->Name = L"labelEps";
			this->labelEps->Size = System::Drawing::Size(19, 19);
			this->labelEps->TabIndex = 0;
			this->labelEps->Text = L"E";
			// 
			// btnStart
			// 
			this->btnStart->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 14));
			this->btnStart->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnStart->Location = System::Drawing::Point(447, 307);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(209, 72);
			this->btnStart->TabIndex = 5;
			this->btnStart->Text = L"Розв\'язати";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Calculator_Form::btnStart_Click);
			// 
			// btnClear
			// 
			this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnClear->Location = System::Drawing::Point(985, 322);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(114, 40);
			this->btnClear->TabIndex = 11;
			this->btnClear->Text = L"Очистити";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Calculator_Form::btnClear_Click);
			// 
			// ResultBox
			// 
			this->ResultBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultBox->Location = System::Drawing::Point(12, 451);
			this->ResultBox->Name = L"ResultBox";
			this->ResultBox->ReadOnly = true;
			this->ResultBox->Size = System::Drawing::Size(657, 288);
			this->ResultBox->TabIndex = 7;
			this->ResultBox->Text = L"";
			this->ResultBox->Visible = false;
			// 
			// labelSolution
			// 
			this->labelSolution->AutoSize = true;
			this->labelSolution->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13));
			this->labelSolution->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->labelSolution->Location = System::Drawing::Point(12, 425);
			this->labelSolution->Name = L"labelSolution";
			this->labelSolution->Size = System::Drawing::Size(104, 20);
			this->labelSolution->TabIndex = 8;
			this->labelSolution->Text = L"Розв\'язання:";
			this->labelSolution->Visible = false;
			// 
			// menuMain
			// 
			this->menuMain->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->menuClear,
					this->menuSaveResult, this->menuSaveResultAs, this->menuSeeLast
			});
			this->menuMain->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuMain->Name = L"menuMain";
			this->menuMain->Size = System::Drawing::Size(58, 21);
			this->menuMain->Text = L"Меню";
			// 
			// menuClear
			// 
			this->menuClear->Name = L"menuClear";
			this->menuClear->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D0));
			this->menuClear->Size = System::Drawing::Size(378, 22);
			this->menuClear->Text = L"Очистити";
			this->menuClear->Click += gcnew System::EventHandler(this, &Calculator_Form::menuClear_Click);
			// 
			// menuSaveResult
			// 
			this->menuSaveResult->Enabled = false;
			this->menuSaveResult->Name = L"menuSaveResult";
			this->menuSaveResult->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->menuSaveResult->Size = System::Drawing::Size(378, 22);
			this->menuSaveResult->Text = L"Зберегти результат";
			this->menuSaveResult->Click += gcnew System::EventHandler(this, &Calculator_Form::menuSaveResult_Click);
			// 
			// menuSaveResultAs
			// 
			this->menuSaveResultAs->Enabled = false;
			this->menuSaveResultAs->Name = L"menuSaveResultAs";
			this->menuSaveResultAs->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->menuSaveResultAs->Size = System::Drawing::Size(378, 22);
			this->menuSaveResultAs->Text = L"Зберегти результат як...";
			this->menuSaveResultAs->Click += gcnew System::EventHandler(this, &Calculator_Form::menuSaveResultAs_Click);
			// 
			// menuSeeLast
			// 
			this->menuSeeLast->Enabled = false;
			this->menuSeeLast->Name = L"menuSeeLast";
			this->menuSeeLast->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->menuSeeLast->Size = System::Drawing::Size(378, 22);
			this->menuSeeLast->Text = L"Відкрити останній збережений результат";
			this->menuSeeLast->Click += gcnew System::EventHandler(this, &Calculator_Form::menuSeeLast_Click);
			// 
			// menuInfo
			// 
			this->menuInfo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuInfo->Name = L"menuInfo";
			this->menuInfo->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
			this->menuInfo->Size = System::Drawing::Size(89, 21);
			this->menuInfo->Text = L"Інформація";
			this->menuInfo->Click += gcnew System::EventHandler(this, &Calculator_Form::menuInfo_Click);
			// 
			// menu
			// 
			this->menu->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->menuMain, this->menuInfo });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(1114, 25);
			this->menu->TabIndex = 13;
			this->menu->Text = L"Menu";
			// 
			// graphEquations
			// 
			this->graphEquations->BackColor = System::Drawing::SystemColors::Window;
			chartArea1->AxisX->ScaleBreakStyle->Enabled = true;
			chartArea1->AxisX->ScaleView->SizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->CursorX->Interval = 0.01;
			chartArea1->CursorX->IsUserEnabled = true;
			chartArea1->CursorX->IsUserSelectionEnabled = true;
			chartArea1->CursorX->LineColor = System::Drawing::Color::LimeGreen;
			chartArea1->CursorY->Interval = 0.01;
			chartArea1->CursorY->IsUserEnabled = true;
			chartArea1->CursorY->IsUserSelectionEnabled = true;
			chartArea1->CursorY->LineColor = System::Drawing::Color::LimeGreen;
			chartArea1->Name = L"ChartArea1";
			this->graphEquations->ChartAreas->Add(chartArea1);
			this->graphEquations->Cursor = System::Windows::Forms::Cursors::Cross;
			this->graphEquations->Location = System::Drawing::Point(676, 389);
			this->graphEquations->Name = L"graphEquations";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Fuchsia;
			series1->CustomProperties = L"IsXAxisQuantitative=False";
			series1->Legend = L"Legend1";
			series1->Name = L"First";
			series1->YValuesPerPoint = 2;
			series2->BorderWidth = 2;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::DarkOrange;
			series2->Legend = L"Legend1";
			series2->Name = L"Second";
			series2->YValuesPerPoint = 2;
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Fuchsia;
			series3->Name = L"First2";
			series4->BorderWidth = 2;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::DarkOrange;
			series4->Name = L"Second2";
			this->graphEquations->Series->Add(series1);
			this->graphEquations->Series->Add(series2);
			this->graphEquations->Series->Add(series3);
			this->graphEquations->Series->Add(series4);
			this->graphEquations->Size = System::Drawing::Size(423, 350);
			this->graphEquations->TabIndex = 14;
			this->graphEquations->Visible = false;
			// 
			// tblYourEquation
			// 
			this->tblYourEquation->BackColor = System::Drawing::SystemColors::Window;
			this->tblYourEquation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tblYourEquation->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tblYourEquation->Location = System::Drawing::Point(50, 324);
			this->tblYourEquation->Name = L"tblYourEquation";
			this->tblYourEquation->ReadOnly = true;
			this->tblYourEquation->Size = System::Drawing::Size(346, 75);
			this->tblYourEquation->TabIndex = 15;
			this->tblYourEquation->Text = L"";
			this->tblYourEquation->Visible = false;
			// 
			// btnDrawGraph
			// 
			this->btnDrawGraph->Location = System::Drawing::Point(691, 319);
			this->btnDrawGraph->Name = L"btnDrawGraph";
			this->btnDrawGraph->Size = System::Drawing::Size(256, 46);
			this->btnDrawGraph->TabIndex = 16;
			this->btnDrawGraph->Text = L"Побудувати графік для визначення початкових наближень";
			this->btnDrawGraph->UseVisualStyleBackColor = true;
			this->btnDrawGraph->Click += gcnew System::EventHandler(this, &Calculator_Form::btnDrawGraph_Click);
			// 
			// Calculator_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1114, 761);
			this->Controls->Add(this->btnDrawGraph);
			this->Controls->Add(this->tblYourEquation);
			this->Controls->Add(this->graphEquations);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->boxEqType);
			this->Controls->Add(this->boxCoeff);
			this->Controls->Add(this->boxInitApprox);
			this->Controls->Add(this->boxSolMethod);
			this->Controls->Add(this->boxPrecision);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->ResultBox);
			this->Controls->Add(this->labelSolution);
			this->Controls->Add(this->menu);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HelpButton = true;
			this->KeyPreview = true;
			this->MainMenuStrip = this->menu;
			this->MaximumSize = System::Drawing::Size(1130, 1100);
			this->MinimumSize = System::Drawing::Size(1130, 800);
			this->Name = L"Calculator_Form";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор \"Системи нелінійних рівнянь\"";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Calculator_Form::Calculator_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Calculator_Form::Calculator_Load);
			this->boxEqType->ResumeLayout(false);
			this->boxCoeff->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblCoeff))->EndInit();
			this->boxInitApprox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tblInitApprox))->EndInit();
			this->boxSolMethod->ResumeLayout(false);
			this->menuMethod->ResumeLayout(false);
			this->menuMethod->PerformLayout();
			this->boxPrecision->ResumeLayout(false);
			this->boxPrecision->PerformLayout();
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphEquations))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/// <summary>
	/// Викликається при завантаженні форми. Ініціалізує таблиці та користувацькі 
	/// компоненти форми.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void Calculator_Load(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається, коли користувач намагається закрити форму. Запитує у користувача, 
	/// чи дійсно він бажає вийти, і якщо так - закриває форму.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу FormClosingEventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void Calculator_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на кнопку btnStart. Опрацьовує введені користувачем 
	/// дані та, якщо не виявлено помилок, розв'язує обрану систему рівнянь обраним методом.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на кнопку btnDrawGraph. Опрацьовує введені користувачем 
	/// дані та викликає дочірню форму для введення меж для побудови графіків, і на основі 
	/// цих даних будує графіки.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void btnDrawGraph_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на кнопку btnClear. Викликає функцію для очищення форми.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню menuClear. Викликає функцію для очищення 
	/// форми.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void menuClear_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню menuSaveResult. Викликає функцію для 
	/// збереження результату у новий файл, якщо користувач зберігає результат вперше; 
	/// інакше - оновлює вже створений файл.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void menuSaveResult_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню menuSaveResultAs. Викликає функцію для 
	/// збереження результату у новий файл.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void menuSaveResultAs_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню menuSeeLast. Відкриває останній збережений результат.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void menuSeeLast_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню menuInfo. Відкриває вікно повідомлення, 
	/// яке відображає інформацію про програмне забезпечення.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void menuInfo_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню btnJakobiMethod. Знімає мітку з методу 
	/// Зейделя і встановлює її на метод Якобі.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void btnJakobiMethod_Click(System::Object^ sender, System::EventArgs^ e);
	/// <summary>
	/// Викликається при натисканні на елемент меню btnZeydelMethod. Знімає мітку з методу 
	/// Якобі і встановлює її на метод Зейделя.
	/// </summary>
	/// <param name = 'sender'>Об’єкт класу Object^</param>
	/// <param name = 'e'>Об'єкт класу EventArgs^</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void btnZeydelMethod_Click(System::Object^ sender, System::EventArgs^ e);

	/// <summary>
	/// Сканує коефіцієнти рівнянь системи з форми Calculator_Form та записує їх у 
	/// двовимірний масив coef.
	/// </summary>
	/// <param name = 'coef'>Двовимірний динамічний масив з елементами типу Double, 
	/// у який зчитуються коефіцієнти, введені користувачем.</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void scanCoefficients(Double** coef);
	/// <summary>
	/// Сканує початкові наближення з форми Calculator_Form та записує їх у одновимірний 
	/// масив initX.
	/// </summary>
	/// <param name = 'initX'>Одновимірний динамічний масив з елементами типу Double, 
	/// у який зчитуються початкові наближення, введені користувачем.</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void scanInitApprox(Double* initX);
	/// <summary>
	/// Очищує форму та відновлює її до початкового стану.
	/// </summary>
	/// <returns>Значення типу Void.</returns>
	private: System::Void clear();
	/// <summary>
	/// Зберігає результат розв'язання системи рівнянь у текстовий файл за допомогою 
	/// діалогового вікна SaveFileDialog.
	/// </summary>
	/// <returns>Значення типу Void.</returns>
	private: System::Void saveNewResult();
	/// <summary>
	/// Будує графіки заданої в класі Calculator_Form системи нелінійних рівнянь на 
	/// заданому проміжку.
	/// </summary>
	/// <param name = 'a'>Початок проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'b'>Кінець проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'flag'>Прапорець, який визначає, потрібно побудувати графіки 
	/// з ймовірно відомою точкою їх перетину (flag == 2) чи ні (flag == 1).</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void drawGraph(Double a, Double b, Int16 flag);
	/// <summary>
	/// Будує графіки заданої в формі Calculator_Form системи арифметичних рівнянь 
	/// на вказаному проміжку з вказаною точністю побудови.
	/// </summary>
	/// <param name = 'a'>Початок проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'b'>Кінець проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'step'>Крок побудови графіків.</param>
	/// <returns>Повертає -3, якщо не вдалося побудувати графік жодного з рівнянь системи; 
	/// -1, якщо не вдалося побудувати лише перше рівняння системи; 
	/// -2, якщо не вдалося побудувати лише друге рівняння системи;
	/// інакше - повертає 2.</returns>
	private: System::Int16 drawGraphArithmetic(Double a, Double b, Double step);
	/// <summary>
	/// Будує графіки заданої в формі Calculator_Form системи тригонометричних рівнянь 
	/// на вказаному проміжку з вказаною точністю побудови.
	/// </summary>
	/// <param name = 'a'>Початок проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'b'>Кінець проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'step'>Крок побудови графіків.</param>
	/// <returns>Повертає -3, якщо не вдалося побудувати графік жодного з рівнянь системи; 
	/// -1, якщо не вдалося побудувати лише перше рівняння системи; 
	/// -2, якщо не вдалося побудувати лише друге рівняння системи;
	/// інакше - повертає 2.</returns>
	private: System::Int16 drawGraphTrigonometric(Double a, Double b, Double step);
	/// <summary>
	/// Будує графіки заданої в формі Calculator_Form системи трансцендентних рівнянь 
	/// на вказаному проміжку з вказаною точністю побудови.
	/// </summary>
	/// <param name = 'a'>Початок проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'b'>Кінець проміжку, на якому потрібно побудувати графіки.</param>
	/// <param name = 'step'>Крок побудови графіків.</param>
	/// <returns>Повертає -3, якщо не вдалося побудувати графік жодного з рівнянь системи; 
	/// -1, якщо не вдалося побудувати лише перше рівняння системи; 
	/// -2, якщо не вдалося побудувати лише друге рівняння системи;
	/// інакше - повертає 2.</returns>
	private: System::Int16 drawGraphTranscendental(Double a, Double b, Double step);
	/// <summary>
	/// "Готує" форму для виведення та подальшої обробки результату. Робить видимими поля 
	/// розв'язку, графік, а також відкриває можливість зберегти подальший результат у файл. 
	/// Виводить введене користувачем рівняння у форму.
	/// </summary>
	/// <returns>Значення типу Void</returns>
	private: System::Void solvingBegin();
	/// <summary>
	/// На основі отриманого параметра flag виводить результат розв'язання системи у форму, 
	/// у тому числі викликає функцію для виведення результатів ітераційного процесу.
	/// </summary>
	/// <param name = 'flag'>Прапорець, який визначає, вдалося розв'язати систему чи ні.</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void outputResult(Int16 flag);
	/// <summary>
	/// Виводить у текстове поле форми результати, отримані на кожній з ітерацій процесу 
	/// розв'язання введеної системи обраним методом, а також виводить кількість цих ітерацій.
	/// </summary>
	/// <returns>Значення типу Void.</returns>
	private: System::Void outputIterations();
	/// <summary>
	/// Ініціалізує об'єкт системи рівнянь обраного виду уведеними користувачем коефіцієнтами 
	/// та початковим наближенням розв'язку.
	/// </summary>
	/// <returns>Значення типу Boolean, яке визначає, чи сталися якісь помилки при ініціалізації 
	/// (повертає false), чи все пройшло успішно (повертає true).</returns>
	private: System::Boolean initializeEquationsToSolve();
	/// <summary>
	/// Ініціалізує об'єкт системи рівнянь обраного виду уведеними користувачем коефіцієнтами.
	/// </summary>
	/// <returns>Значення типу Boolean, яке визначає, чи сталися якісь помилки при ініціалізації. 
	/// (повертає false), чи все пройшло успішно (повертає true).</returns>
	private: System::Boolean initializeEquationsToDrawGraph();
	/// <summary>
	/// У залежності від обраного методу розв'язання, викликає відповідні функції методів, або ж виводить 
	/// повідомлення про помилку, якщо не було обрано жодного методу.
	/// </summary>
	/// <param name = 'precis'>Точність, з якою потрібно обчислити розв'язок системи.</param>
	/// <returns>Значення типу Void.</returns>
	private: System::Void solve(Double precis);
	};
}
