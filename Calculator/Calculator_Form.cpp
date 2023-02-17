#include "pch.h"
#include "Calculator_Form.h"
#include "ArithmeticEquations.h"
#include "TrigonometricEquations.h"
#include "TranscendentalEquations.h"

CalculatorNamespace::Calculator_Form::Calculator_Form(void)
{
	InitializeComponent();
	String^ output = ("Щоб розв'язати систему двох нелінійних рівнянь, оберіть вид системи та метод її розв'язання, " +
		"введіть коефіцієнти, початкові наближення та точність обчислення розв'язку системи.\nДалі натисніть \"Розв'язати\"." +
		"\n\nЯкщо ви не знаєте початкові наближення розв'язку, оберіть вид системи та введіть коефіцієнти рівнянь." +
		"\nДалі натисніть \"Побудувати графік для визначення початкових наближень\" і у вікні, що з'явиться, введіть інтервал по X, " +
		"на якому бажаєте побудувати графік.\nЗа побудованим графіком ви зможете самостійно визначити орієнтовний наближений розв'язок.");
	MessageBox::Show(output, "Вітання!", MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1);
}
CalculatorNamespace::Calculator_Form::~Calculator_Form()
{
	if (components)
	{
		delete components;
	}
}
System::Void CalculatorNamespace::Calculator_Form::Calculator_Load(System::Object^ sender, System::EventArgs^ e)
{
	tblCoeff->ColumnCount = 3;
	tblCoeff->RowCount = 2;
	tblInitApprox->ColumnCount = 1;
	tblInitApprox->RowCount = 2;
	result = gcnew List<Double>();
	path = "";
}
System::Void CalculatorNamespace::Calculator_Form::Calculator_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	String^ output = "Ви дійсно бажаєте вийти?\nПрограма втратить шлях до останнього збереженого результату.";
	if (MessageBox::Show(output, "Вихід", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::No) {
		e->Cancel = true;
	}
}
System::Void CalculatorNamespace::Calculator_Form::btnStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	result->Clear();
	ResultBox->Text = "";
	Double precis;		// Змінна для зчитування точності.
	try {
		precis = Convert::ToDouble(tblPrecision->Text);
		if (precis <= 0) throw "Uncorrect";
	}
	catch (const char*) {
		MessageBox::Show("Точність має бути додатнім числом!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	catch (...) {
		if (MessageBox::Show("Не коректний ввід числових даних!\nОчистити форму?", "Помилка!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
		{
			clear();
		}
		return;
	}

	if (!initializeEquationsToSolve()) return;

	solve(precis);
}
System::Void CalculatorNamespace::Calculator_Form::btnDrawGraph_Click(System::Object^ sender, System::EventArgs^ e)
{
	ResultBox->Text = "";
	tblYourEquation->Visible = true;
	graphEquations->Visible = true;
	menuSaveResult->Enabled = false;
	menuSaveResultAs->Enabled = false;
	ResultBox->Visible = false;
	labelSolution->Visible = false;
	
	if (!initializeEquationsToDrawGraph()) return;

	tblYourEquation->Text = "Введена система рівнянь:\n" + equations->getEquations();

	Question_FormNamespace::Question_Form^ childForm = gcnew Question_FormNamespace::Question_Form;		// Форма для введення меж побудови графіків.
	childForm->ShowDialog();
	Double from = childForm->getXFrom();	// Ліва межа побудови графіків.
	Double to = childForm->getXTo();		// Права межа побудови графіків.
	drawGraph(from, to, 1);	
}
System::Void CalculatorNamespace::Calculator_Form::btnClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	clear();
}

System::Void CalculatorNamespace::Calculator_Form::menuClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	clear();
}
System::Void CalculatorNamespace::Calculator_Form::menuSaveResult_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (path == "") {
		saveNewResult();
	}
	else {
		try {
			System::IO::File::WriteAllText(path, tblYourEquation->Text + "\n\n" + ResultBox->Text);
			menuSeeLast->Enabled = true;
		}
		catch (...) {
			MessageBox::Show("Не вдалося зберегти результат!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
}
System::Void CalculatorNamespace::Calculator_Form::menuSaveResultAs_Click(System::Object^ sender, System::EventArgs^ e)
{
	saveNewResult();
}
System::Void CalculatorNamespace::Calculator_Form::menuSeeLast_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		System::Diagnostics::Process::Start("notepad.exe", path);
	}
	catch (...) {
		MessageBox::Show("Не вдалося відкрити файл!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
}
System::Void CalculatorNamespace::Calculator_Form::menuInfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ output = ("Щоб розв'язати систему двох нелінійних рівнянь, оберіть вид системи та метод її розв'язання, " +
		"введіть коефіцієнти, початкові наближення та точність обчислення розв'язку системи.\nДалі натисніть \"Розв'язати\"." +
		"\n\nЯкщо ви не знаєте початкові наближення розв'язку, оберіть вид системи та введіть коефіцієнти рівнянь." +
		"\nДалі натисніть \"Побудувати графік для визначення початкових наближень\" і у вікні, що з'явиться, введіть інтервал по X, " +
		"на якому бажаєте побудувати графік.\nЗа побудованим графіком ви зможете самостійно визначити орієнтовний наближений розв'язок." +
		"\n\nEnvironment:\n              Microsoft Visual Studio Community 2022\n              Version 17.2.1\n" +
		"\nDeveloped by: \n              Hanna Kushnir");
	MessageBox::Show(output, "Інформація", MessageBoxButtons::OK, MessageBoxIcon::None, MessageBoxDefaultButton::Button1);
}
System::Void CalculatorNamespace::Calculator_Form::btnJakobiMethod_Click(System::Object^ sender, System::EventArgs^ e)
{
	btnJakobiMethod->Checked = true;
	btnZeydelMethod->Checked = false;
	btnMethod->Text = btnJakobiMethod->Text;
}
System::Void CalculatorNamespace::Calculator_Form::btnZeydelMethod_Click(System::Object^ sender, System::EventArgs^ e)
{
	btnZeydelMethod->Checked = true;
	btnJakobiMethod->Checked = false;
	btnMethod->Text = btnZeydelMethod->Text;
}

System::Void CalculatorNamespace::Calculator_Form::scanCoefficients(Double** coef)
{
	for (Int16 i = 0; i < 2; ++i) {
		for (Int16 j = 0; j < 3; ++j) {
			coef[i][j] = Convert::ToDouble(tblCoeff->Rows[i]->Cells[j]->Value);
		}
	}
}
System::Void CalculatorNamespace::Calculator_Form::scanInitApprox(Double* initX)
{
	for (Int16 i = 0; i < 2; ++i) {
		initX[i] = Convert::ToDouble(tblInitApprox->Rows[i]->Cells[0]->Value);
	}
}
System::Void CalculatorNamespace::Calculator_Form::clear()
{
	btnArithmEq->Checked = false;
	btnTrigonomEq->Checked = false;
	btnTranscEq->Checked = false;
	btnMethod->Text = "Оберіть метод розв'язання";
	btnJakobiMethod->Checked = false;
	btnZeydelMethod->Checked = false;
	for (Int16 i = 0; i < 2; ++i) {
		for (Int16 j = 0; j < 3; ++j) {
			tblCoeff->Rows[i]->Cells[j]->Value = nullptr;
		}
		tblInitApprox->Rows[i]->Cells[0]->Value = nullptr;
	}
	tblPrecision->Text = "0,0001";
	ResultBox->Text = "";
	tblYourEquation->Text = "";
	graphEquations->Series[0]->Points->Clear();
	graphEquations->Series[1]->Points->Clear();
	graphEquations->Series[2]->Points->Clear();
	graphEquations->Series[3]->Points->Clear();
	menuSaveResult->Enabled = false;
	menuSaveResultAs->Enabled = false;
	ResultBox->Visible = false;
	labelSolution->Visible = false;
	tblYourEquation->Visible = false;
	graphEquations->Visible = false;
}
System::Void CalculatorNamespace::Calculator_Form::saveNewResult()
{
	try {
		SaveFileDialog^ saveResultDialog = gcnew SaveFileDialog();		// Вікно збереження результату.
		saveResultDialog->Filter = "Text file (.txt)|*.txt";
		saveResultDialog->Title = "Збереження результату";
		if (saveResultDialog->ShowDialog() == Windows::Forms::DialogResult::Cancel) {
			return;
		}
		else {
			path = saveResultDialog->FileName;
			System::IO::File::WriteAllText(path, tblYourEquation->Text + "\n\n" + ResultBox->Text);
		}
	}
	catch (...) {
		MessageBox::Show("Не вдалося зберегти результат!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	MessageBox::Show("Ваш результат успішно збережено!", "Успішно!", MessageBoxButtons::OK, MessageBoxIcon::None); 
	menuSeeLast->Enabled = true;
}
System::Void CalculatorNamespace::Calculator_Form::drawGraph(Double a, Double b, Int16 flag)
{
	if (flag == 2 && result->Count != 0) {
		a = Math::Floor(result[result->Count - 2] * 10) / 10 - 10;
		b = a + 20;
	}
	graphEquations->Series[0]->Points->Clear();
	graphEquations->Series[1]->Points->Clear();
	graphEquations->Series[2]->Points->Clear();
	graphEquations->Series[3]->Points->Clear();

	Int16 flagGraph;		// Прапорець, який визначає чи вдалося побудувати графіки.
	Double step = 0.01;		// Крок побудови графіків.
	switch (equations->getId()) {
	case 1:
		flagGraph = drawGraphArithmetic(a, b, step);
		break;
	case 2:
		flagGraph = drawGraphTrigonometric(a, b, step);
		break;
	case 3:
		flagGraph = drawGraphTranscendental(a, b, step);
		break;
	}
	
	switch (flagGraph) {
	case -3:
		MessageBox::Show("Не вдалося побудувати графіки для рівнянь системи.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::None);
		graphEquations->Visible = false;
		break;
	case -1:
		MessageBox::Show("Не вдалося побудувати графік для першого рівняння системи.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::None);
		break;
	case -2:
		MessageBox::Show("Не вдалося побудувати графік для другого рівняння системи.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::None);
		break;	
	}
}
System::Int16 CalculatorNamespace::Calculator_Form::drawGraphArithmetic(Double a, Double b, Double step)
{
	Double x, y1, y2;			// Змінні для збереження координат.
	Boolean flag1 = false,		// Прапорець, який визначає чи вдалося побудувати графік першого рівняння системи.
		flag2 = false;			// Прапорець, який визначає чи вдалося побудувати графік другого рівняння системи.
	if ((equations->getCoef()[0][0] > 0 && equations->getCoef()[0][1] < 0 && equations->getCoef()[0][2] < 0) ||
		(equations->getCoef()[0][0] < 0 && equations->getCoef()[0][1] > 0 && equations->getCoef()[0][2] > 0)) {
		x = a;
		while (x <= 0) {
			y1 = equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[0]->Points->AddXY(x, y1);
				flag1 = true;
			}
			x += step;
		}
		while (x >= a) {
			y1 = -equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[0]->Points->AddXY(x, y1);
				flag1 = true;
			}
			x -= step;
		}
		x = b;
		while (x >= 0) {
			y1 = equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[2]->Points->AddXY(x, y1);
				flag1 = true;
			}
			x -= step;
		}
		while (x <= b) {
			y1 = -equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[2]->Points->AddXY(x, y1);
				flag1 = true;
			}
			x += step;
		}
	}
	else {
		x = a;
		while (x <= b) {
			y1 = equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[0]->Points->AddXY(x, y1);
				flag1 = true;
			}
			x += step;
		}
		while (x >= a) {
			y1 = -equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[2]->Points->AddXY(x, y1);
				flag1 = true;
			}
			x -= step;
		}
	}
	if ((equations->getCoef()[1][0] > 0 && equations->getCoef()[1][1] < 0 && equations->getCoef()[1][2] < 0) ||
		(equations->getCoef()[1][0] < 0 && equations->getCoef()[1][1] > 0 && equations->getCoef()[1][2] > 0)) {
		x = a;
		while (x <= 0) {
			y2 = equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[1]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x += step;
		}
		while (x >= a) {
			y2 = -equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[1]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x -= step;
		}
		x = b;
		while (x >= 0) {
			y2 = equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[3]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x -= step;
		}
		while (x <= b) {
			y2 = -equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[3]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x += step;
		}
	}
	else {
		x = a;
		while (x <= b) {
			y2 = equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[1]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x += step;
		}
		while (x >= a) {
			y2 = -equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[3]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x -= step;
		}
	}
	if (!flag1 && !flag2) return -3;
	if (!flag1) return -1;
	if (!flag2) return -2;
	return 2;
}
System::Int16 CalculatorNamespace::Calculator_Form::drawGraphTrigonometric(Double a, Double b, Double step)
{
	Double x, y1, y2, x1;		// Змінні для збереження координат.
	Boolean flag1 = false,		// Прапорець, який визначає чи вдалося побудувати графік першого рівняння системи.
		flag2 = false;			// Прапорець, який визначає чи вдалося побудувати графік другого рівняння системи.
	x = a;
	y1 = equations->getY1(x);
	if (isfinite(y1)) {
		while (x <= b) {
			y1 = equations->getY1(x);
			if (isfinite(y1)) {
				graphEquations->Series[0]->Points->AddXY(x, y1);
				flag1 = true;
			}
			y2 = equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[1]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x += step;
		}
		flag1 = true;
	}
	else {
		x1 = equations->getX1(0);
		if (isfinite(x1)) {
			y2 = equations->getY2(x1);
			if (isfinite(y2)) {
				graphEquations->Series[0]->Points->AddXY(x1, y2 - 5);
				graphEquations->Series[0]->Points->AddXY(x1, y2 + 5);
				flag1 = true;
			}
			else {
				graphEquations->Series[0]->Points->AddXY(x1, -5);
				graphEquations->Series[0]->Points->AddXY(x1, 5);
				flag1 = true;
			}
			x = x1 - 10;
			b = x1 + 10;
		}
		while (x <= b) {
			y2 = equations->getY2(x);
			if (isfinite(y2)) {
				graphEquations->Series[1]->Points->AddXY(x, y2);
				flag2 = true;
			}
			x += step;
		}
	}
	if (!flag1 && !flag2) return -3;
	if (!flag1) return -1;
	if (!flag2) return -2;
	return 2;
}
System::Int16 CalculatorNamespace::Calculator_Form::drawGraphTranscendental(Double a, Double b, Double step)
{
	Double x, y1, y2;			// Змінні для збереження координат.
	Boolean flag1 = false,		// Прапорець, який визначає чи вдалося побудувати графік першого рівняння системи.
		flag2 = false;			// Прапорець, який визначає чи вдалося побудувати графік другого рівняння системи.
	x = a;
	while (x <= b) {
		y1 = equations->getY1(x);
		if (isfinite(y1)) {
			graphEquations->Series[0]->Points->AddXY(x, y1);
			flag1 = true;
		}
		y2 = equations->getY2(x);
		if (isfinite(y2)) {
			graphEquations->Series[1]->Points->AddXY(x, y2);
			flag2 = true;
		}
		x += step;
	}
	if (!flag1 && !flag2) return -3;
	if (!flag1) return -1;
	if (!flag2) return -2;
	return 2;
}
System::Void CalculatorNamespace::Calculator_Form::solvingBegin()
{
	ResultBox->Visible = true;
	labelSolution->Visible = true;
	tblYourEquation->Visible = true;
	menuSaveResult->Enabled = true;
	menuSaveResultAs->Enabled = true;
	graphEquations->Visible = true;
	tblYourEquation->Text = "Введена система рівнянь:\n" + equations->getEquations();
}
System::Void CalculatorNamespace::Calculator_Form::outputResult(Int16 flag)
{
	switch (flag)
	{
	case -3:
		ResultBox->Text = ("Обраний метод не застосовний для розв'язання введеної системи.");
		return;
	case -2:
		ResultBox->Text = "Дана система рівнянь не має розв'язків на множині дійсних чисел.";
		return;
	case -1:
		ResultBox->Text = ("Введені вами початкові наближення призводять до розбіжного ітераційного процесу, або обраний метод " +
			"не застосовний до введеної системи.");
		return;
	case 0:
		ResultBox->Text = "Дана система рівнянь має такий можливий розв'язок:\n       x = " + result[0] + "\n       y = " + result[1];
		return;
	case 2:
		ResultBox->Text = "Дана система рівнянь визначена на всій множині дійсних чисел.";
		return;
	default:
		outputIterations();
	}
}
System::Void CalculatorNamespace::Calculator_Form::outputIterations()
{
	ResultBox->Text = "Результати ітераційного процесу:";
	Int16 i = 1;		// Лічильник циклу.
	for each (Double iter in result)
	{
		if (i % 2 == 1) {
			ResultBox->Text += "\nІтерація " + Math::Floor((Double)i / 2) + " :\n               x = " + iter;
		}
		else {
			ResultBox->Text += "\n               y = " + iter;
		}
		i++;
	}
	if (result->Count != 0) {
		ResultBox->Text += "\n\nОтриманий розв'язок:\n   x = " 
			+ result[result->Count - 2] + "\n   y = " + result[result->Count - 1] +
			"\nКількість ітерацій: " + equations->getIterations();
	}
}
System::Boolean CalculatorNamespace::Calculator_Form::initializeEquationsToSolve()
{
	Double** coef = new Double * [2];	// Масив коефіцієнтів.
	Double* initX = new Double[2];		// Масив початкових наближень.
	for (Int16 i = 0; i < 2; ++i) {
		coef[i] = new Double[3];
	}
	try {
		scanCoefficients(coef);
		scanInitApprox(initX);
	}
	catch (...) {
		if (MessageBox::Show("Не коректний ввід числових даних!\nОчистити форму?", "Помилка!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
		{
			clear();
		}
		return false;
	}
	if (btnArithmEq->Checked) {
		equations = (gcnew ArithmeticEquations(coef, initX));
	}
	else if (btnTrigonomEq->Checked) {
		equations = (gcnew TrigonometricEquations(coef, initX));
	}
	else if (btnTranscEq->Checked) {
		equations = (gcnew TranscendentalEquations(coef, initX));
	}
	else {
		MessageBox::Show("Оберіть вид системи!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		for (Int16 i = 0; i < 2; ++i) {
			delete[] coef[i];
		}
		delete[] coef, initX;
		return false;
	}
	for (Int16 i = 0; i < 2; ++i) {
		delete[] coef[i];
	}
	delete[] coef, initX;
	return true;
}
System::Boolean CalculatorNamespace::Calculator_Form::initializeEquationsToDrawGraph()
{
	Double** coef = new Double * [2];	// Масив коефіцієнтів.
	for (Int16 i = 0; i < 2; ++i) {
		coef[i] = new Double[3];
	}
	try {
		scanCoefficients(coef);
	}
	catch (...) {
		if (MessageBox::Show("Не коректний ввід числових даних!\nОчистити форму?", "Помилка!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
		{
			clear();
		}
		return false;
	}
	if (btnArithmEq->Checked) {
		equations = gcnew ArithmeticEquations(coef);
	}
	else if (btnTrigonomEq->Checked) {
		equations = gcnew TrigonometricEquations(coef);
	}
	else if (btnTranscEq->Checked) {
		equations = gcnew TranscendentalEquations(coef);
	}
	else {
		MessageBox::Show("Оберіть вид системи!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		for (Int16 i = 0; i < 2; ++i) {
			delete[] coef[i];
		}
		delete[] coef;
		return false;
	}
	for (Int16 i = 0; i < 2; ++i) {
		delete[] coef[i];
	}
	delete[] coef;
	return true;
}
System::Void CalculatorNamespace::Calculator_Form::solve(Double precis)
{
	Int16 flag;		// Прапорець, який визначає, чи вдалося розв’язати систему рівнянь.
	if (btnJakobiMethod->Checked) {
		solvingBegin();
		try {
			flag = equations->JakobiMethod(result, precis);
		}
		catch (...) {
			MessageBox::Show("Не вдалося розв'язати вказану систему!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		outputResult(flag);
		drawGraph(-10, 10, 2);
	}
	else if (btnZeydelMethod->Checked) {
		solvingBegin();
		try {
			flag = equations->ZeydelMethod(result, precis);
		}
		catch (...) {
			MessageBox::Show("Не вдалося розв'язати вказану систему!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		outputResult(flag);
		drawGraph(-10, 10, 2);
	}
	else {
		MessageBox::Show("Оберіть метод розв'язання!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
}


System::Void CalculatorNamespace::Calculator_Form::saveInput_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "Text file (.txt)|*.txt";
		saveFileDialog->Title = "Збереження введених даних";
		if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::Cancel) {
			return;
		}
		else {
			String^ newPath = saveFileDialog->FileName;

			System::IO::File::WriteAllText(newPath, "");

			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (tblCoeff->Rows[i]->Cells[j]->Value == nullptr)
						System::IO::File::AppendAllText(newPath, "0 ");
					else
						System::IO::File::AppendAllText(newPath, Convert::ToString(tblCoeff->Rows[i]->Cells[j]->Value) + " ");
				}
			}
			System::IO::File::AppendAllText(newPath, "\n");
			for (int i = 0; i < 2; ++i) {
				if (tblInitApprox->Rows[i]->Cells[0]->Value == nullptr)
					System::IO::File::AppendAllText(newPath, "0 ");
				else
					System::IO::File::AppendAllText(newPath, Convert::ToString(tblInitApprox->Rows[i]->Cells[0]->Value) + " ");
			}
			System::IO::File::AppendAllText(newPath, "\n" + Convert::ToString(tblPrecision->Text + " \n"));

			if (btnArithmEq->Checked) {
				System::IO::File::AppendAllText(newPath, "1\n");
			}
			else if (btnTrigonomEq->Checked) {
				System::IO::File::AppendAllText(newPath, "2\n");
			}
			else if (btnTranscEq->Checked) {
				System::IO::File::AppendAllText(newPath, "3\n");
			}
			else {
				System::IO::File::AppendAllText(newPath, "0\n");
			}

			if (btnJakobiMethod->Checked) {
				System::IO::File::AppendAllText(newPath, "1");
			}
			else if (btnZeydelMethod->Checked) {
				System::IO::File::AppendAllText(newPath, "2");
			}
			else {
				System::IO::File::AppendAllText(newPath, "0");
			}
		}
	}
	catch (...) {
		MessageBox::Show("Не вдалося зберегти введені дані задачі!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	MessageBox::Show("Ваші дані успішно збережено!", "Успішно!", MessageBoxButtons::OK, MessageBoxIcon::None);
}

System::Void CalculatorNamespace::Calculator_Form::openInput_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Text file (.txt)|*.txt";
		openFileDialog->Title = "Відкриття файлу з вхідними даними";
		if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::Cancel) {
			return;
		}
		else {
			String^ newPath = openFileDialog->FileName;

			array<String^>^ arr = System::IO::File::ReadAllLines(newPath);

			int k = 0, m;
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					m = arr[0]->IndexOf(" ", k);
					tblCoeff->Rows[i]->Cells[j]->Value = Convert::ToDouble(arr[0]->Substring(k, m - k));
					k = m + 1;
				}
			}
			k = 0;
			for (int i = 0; i < 2; ++i) {
				m = arr[1]->IndexOf(" ", k);
				tblInitApprox->Rows[i]->Cells[0]->Value = Convert::ToDouble(arr[1]->Substring(k, m - k));
				k = m + 1;
			}
			tblPrecision->Text = arr[2];

			if (arr[3] == "1") {
				btnArithmEq->Checked = true;
			}
			else if (arr[3] == "2") {
				btnTrigonomEq->Checked = true;
			}
			else if (arr[3] == "3") {
				btnTranscEq->Checked = true;
			}

			if (arr[4] == "1") {
				btnJakobiMethod_Click(sender, e);
			}
			if (arr[4] == "2") {
				btnZeydelMethod_Click(sender, e);
			}
		}
	}
	catch (...) {
		MessageBox::Show("Не вдалося відкрити файл або вхідні дані некоректні!", "Помилка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}
