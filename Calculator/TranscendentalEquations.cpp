#include "pch.h"
#include "TranscendentalEquations.h"
#include <Math.h>
using namespace System;

TranscendentalEquations::TranscendentalEquations() : Equations() {}
TranscendentalEquations::TranscendentalEquations(Double** coef) : Equations(coef) {}
TranscendentalEquations::TranscendentalEquations(Double** coef, Double* initX) : Equations(coef, initX) {}

Boolean TranscendentalEquations::checkInitApprox(int i)
{
	W(0, 0) = 0;
	W(1, 1) = 0;
	switch (i) {
	case 1:
		W(0, 1) = Math::Abs(getX1dY(x0[1]));
		W(1, 0) = Math::Abs(getY2dX(x0[0]));
		break;
	case 2:
		W(0, 1) = Math::Abs(getX2dY(x0[1]));
		W(1, 0) = Math::Abs(getY1dX(x0[0]));
		break;
	}
	if (!isfinite(W(0, 1)) || !isfinite(W(1, 0))) return false;

	if (W.getNormM() < 1 && W.getNormL() < 1) {
		return true;
	}
	return false;
}

Int16 TranscendentalEquations::JakobiMethod(List<Double>^ result, Double precis)
{
	if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[0][2] == -2 && a[1][2] == -2) {
		return 2;
	}
	if ((a[0][2] >= 0 || a[1][2] >= 0) ||
	(a[0][0] == 0 && a[0][1] == 0 && a[0][2] != -2) ||
	(a[1][0] == 0 && a[1][1] == 0 && a[1][2] != -2) ||
	(a[0][2] == -1 && (a[0][0] == 0 || a[0][1] == 0)) ||
	(a[1][2] == -1 && (a[1][0] == 0 || a[1][1] == 0))) {
		return -2;
	}
	Double num1, num2;
	Boolean flag = true;
/* 1 */
	if (a[0][0] != 0 && a[1][1] != 0 && checkInitApprox(1)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		Int32 i = 2;
		while (true) {
			iterations++;
			num1 = getX1(result[i - 1]);
			num2 = getY2(result[i - 2]);
			if (!isfinite(num1) || !isfinite(num2)) {
				result->Clear();
				flag = false;
				break;
			}
			result->Add(num1);
			result->Add(num2);
			Double delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
/* 2 */
	if (a[1][0] != 0 && a[0][1] != 0 && checkInitApprox(2)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		Int32 i = 2;
		while (true) {
			iterations++;
			num1 = getX2(result[i - 1]);
			num2 = getY1(result[i - 2]);
			if (!isfinite(num1) || !isfinite(num2)) {
				result->Clear();
				return -3;
			}
			result->Add(num1);
			result->Add(num2);
			Double delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
	if (flag) return -1;
	return -3;
}
Int16 TranscendentalEquations::ZeydelMethod(List<Double>^ result, Double precis)
{
	if (a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[0][2] == -2 && a[1][2] == -2) {
		return 2;
	}
	if ((a[0][2] >= 0 || a[1][2] >= 0) ||
		(a[0][0] == 0 && a[0][1] == 0 && a[0][2] != -2) ||
		(a[1][0] == 0 && a[1][1] == 0 && a[1][2] != -2) ||
		(a[0][2] == -1 && (a[0][0] == 0 || a[0][1] == 0)) ||
		(a[1][2] == -1 && (a[1][0] == 0 || a[1][1] == 0))) {
		return -2;
	}
	Double num1, num2;
	Boolean flag = true;
/* 1 */
	if (a[0][0] != 0 && a[1][1] != 0 && checkInitApprox(1)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		Int32 i = 2;
		while (true) {
			iterations++;
			num1 = getX1(result[i - 1]);
			if (!isfinite(num1)) {
				result->Clear();
				flag = false;
				break;
			}
			result->Add(num1);

			num2 = getY2(result[i]);
			if (!isfinite(num2)) {
				result->Clear();
				flag = false;
				break;
			}
			result->Add(num2);
			Double delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
/* 2 */
	if (a[1][0] != 0 && a[0][1] != 0 && checkInitApprox(2)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		Int32 i = 2;
		while (true) {
			iterations++;
			num1 = getX2(result[i - 1]);
			if (!isfinite(num1)) {
				result->Clear();
				return -3;
			}
			result->Add(num1);

			num2 = getY1(result[i]);
			if (!isfinite(num2)) {
				result->Clear();
				return -3;
			}
			result->Add(num2);
			Double delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
	if (flag) return -1;
	return -3;
}

Int16 TranscendentalEquations::getId()
{
	return 3;
}
String^ TranscendentalEquations::getEquations()
{
	String^ eq = ("  e^(" + Convert::ToString(a[0][0]) + " * x) + e^(" + Convert::ToString(a[0][1]) + " * y) + " +
		Convert::ToString(a[0][2]) + " = 0\n  e^(" + Convert::ToString(a[1][0]) + " * x) + e^(" + Convert::ToString(a[1][1]) +
		" * y) + " + Convert::ToString(a[1][2]) + " = 0");
	return eq;
}

Double TranscendentalEquations::getY1(Double x)
{
	Double num = -Math::Pow(Math::E, a[0][0] * x) - a[0][2];
	if (num <= 0) return NAN;
	return Math::Log(num) / a[0][1];
}
Double TranscendentalEquations::getY2(Double x)
{
	Double num = -Math::Pow(Math::E, a[1][0] * x) - a[1][2];
	if (num <= 0) return NAN;
	return Math::Log(num) / a[1][1];
}
Double TranscendentalEquations::getX1(Double y)
{
	Double num = -Math::Pow(Math::E, a[0][1] * y) - a[0][2];
	if (num <= 0) return NAN;
	return Math::Log(num) / a[0][0];
}
Double TranscendentalEquations::getX2(Double y)
{
	Double num = -Math::Pow(Math::E, a[1][1] * y) - a[1][2];
	if (num <= 0) return NAN;
	return Math::Log(num) / a[1][0];
}

Double TranscendentalEquations::getY1dX(Double x)
{
	Double num = a[0][1] * (Math::Pow(Math::E, a[0][0] * x) + a[0][2]);
	if (num == 0) return NAN;
	return a[0][0] * Math::Pow(Math::E, a[0][0] * x) / num;
}
Double TranscendentalEquations::getY2dX(Double x)
{
	Double num = a[1][1] * (Math::Pow(Math::E, a[1][0] * x) + a[1][2]);
	if (num == 0) return NAN;
	return a[1][0] * Math::Pow(Math::E, a[1][0] * x) / num;
}
Double TranscendentalEquations::getX1dY(Double y)
{
	Double num = a[0][0] * (Math::Pow(Math::E, a[0][1] * y) + a[0][2]);
	if (num == 0) return NAN;
	return a[0][1] * Math::Pow(Math::E, a[0][1] * y) / num;
}
Double TranscendentalEquations::getX2dY(Double y)
{
	Double num = a[1][0] * (Math::Pow(Math::E, a[1][1] * y) + a[1][2]);
	if (num == 0) return NAN;
	return a[1][1] * Math::Pow(Math::E, a[1][1] * y) / num;
}
