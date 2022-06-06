#include "pch.h"
#include "Calculator_Form.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CalculatorNamespace::Calculator_Form());
  return 0;
}