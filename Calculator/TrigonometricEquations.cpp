#include "pch.h"
#include "TrigonometricEquations.h"
#include <Math.h>
using namespace System;

TrigonometricEquations::TrigonometricEquations() : Equations() {}
TrigonometricEquations::TrigonometricEquations(Double** coef) : Equations(coef) {}
TrigonometricEquations::TrigonometricEquations(Double** coef, Double* initX) : Equations(coef, initX) {}

Boolean TrigonometricEquations::checkInitApprox(int i)
{
	W(0, 0) = 0;
	W(1, 1) = 0;
	switch (i) {
	case 1:
		W(0, 1) = Math::Abs(getX2dY(x0[1]));
		W(1, 0) = Math::Abs(getY1dX(x0[0]));
		break;
	case 2:
		W(0, 1) = Math::Abs(getX1dY(x0[1]));
		W(1, 0) = Math::Abs(getY2dX(x0[0]));
		break;
	}
	if (!isfinite(W(0, 1)) || !isfinite(W(1, 0))) return false;

	if (W.getNormM() < 1 && W.getNormL() < 1) {
		return true;
	}
	return false;
}

Int16 TrigonometricEquations::JakobiMethod(List<Double>^ result, Double precis)
{
	if ((a[0][1] == 0 && Math::Abs(a[0][2]) > 1) ||
		(a[1][0] == 0 && Math::Abs(a[1][2]) > 1)) {
		return -2;
	}
	if (a[0][1] == 0 && a[0][2] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0) {
		result->Add(-a[0][0]);
		result->Add(Math::Acos(0));
		return 0;
	}

	Double num1, num2;		// Змінні для тимчасового збереження результатів обчислення коренів.
	Double delta;			// Різниця між значеннями коренів на сусідніх ітераціях.
	Int32 i;				// Лічильник ітерацій.

/* 1 */
	if (a[1][0] != 0 && a[0][1] != 0 && checkInitApprox(1)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		i = 2;
		while (true) {
			iterations++;
			result->Add(getX2(result[i - 1]));
			result->Add(getY1(result[i - 2]));
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}

/* 2 */
	if (checkInitApprox(2)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		i = 2;
		while (true) {
			iterations++;
			num1 = getX1(result[i - 1]);
			num2 = getY2(result[i - 2]);
			if (!isfinite(num1) || !isfinite(num2)) {
				result->Clear();
				return -3;
			}
			result->Add(num1);
			result->Add(num2);
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
	return -1;
}
Int16 TrigonometricEquations::ZeydelMethod(List<Double>^ result, Double precis)
{
	if ((a[0][1] == 0 && Math::Abs(a[0][2]) > 1) ||
		(a[1][0] == 0 && Math::Abs(a[1][2]) > 1)) {
		return -2;
	}
	if (a[0][1] == 0 && a[0][2] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0) {
		result->Add(-a[0][0]);
		result->Add(Math::Acos(0));
		return 0;
	}

	Double num1, num2;		// Змінні для тимчасового збереження результатів обчислення коренів.
	Double delta;			// Різниця між значеннями коренів на сусідніх ітераціях.
	Int32 i;				// Лічильник ітерацій.

/* 1 */
	if (a[1][0] != 0 && a[0][1] != 0 && checkInitApprox(1)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		i = 2;
		while (true) {
			iterations++;
			result->Add(getX2(result[i - 1]));
			result->Add(getY1(result[i]));
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}

/* 2 */
	if (checkInitApprox(2)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		i = 2;
		while (true) {
			iterations++;
			num1 = getX1(result[i - 1]);
			if (!isfinite(num1)) {
				result->Clear();
				return -3;
			}
			result->Add(num1);

			num2 = getY2(result[i]);
			if (!isfinite(num2)) {
				result->Clear();
				return -3;
			}
			result->Add(num2);
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
	return -1;
}

Int16 TrigonometricEquations::getId()
{
	return 2;
}
String^ TrigonometricEquations::getEquations()
{
	String^ eq = ("  sin(x + " + Convert::ToString(a[0][0]) + ") + " + Convert::ToString(a[0][1]) + " * y + " +
		Convert::ToString(a[0][2]) + " = 0\n  " + Convert::ToString(a[1][0]) + " * x + cos(y + " + Convert::ToString(a[1][1]) + 
		") + " + Convert::ToString(a[1][2]) + " = 0");
	return eq;
}

Double TrigonometricEquations::getY1(Double x)
{
	if (a[0][1] == 0) return NAN;
	return -(Math::Sin(x + a[0][0]) + a[0][2]) / a[0][1];
}
Double TrigonometricEquations::getY2(Double x)
{
	return Math::Acos(-a[1][0] * x - a[1][2]) - a[1][1];
}
Double TrigonometricEquations::getX1(Double y)
{
	return Math::Asin(-a[0][1] * y - a[0][2]) - a[0][0];
}
Double TrigonometricEquations::getX2(Double y)
{
	if (a[1][0] == 0) return NAN;
	return -(Math::Cos(y + a[1][1]) + a[1][2]) / a[1][0];
}

Double TrigonometricEquations::getY1dX(Double x)
{
	if (a[0][1] == 0) return NAN;
	return -Math::Cos(x + a[0][0]) / a[0][1];
}
Double TrigonometricEquations::getY2dX(Double x)
{
	Double num = 1 - Math::Pow(a[1][0] * x + a[1][2], 2);
	if (num <= 0) return NAN;
	return a[1][0] / Math::Sqrt(num);
}
Double TrigonometricEquations::getX1dY(Double y)
{
	Double num = 1 - Math::Pow(a[0][1] * y + a[0][2], 2);
	if (num <= 0) return NAN;
	return -a[0][1] / Math::Sqrt(num);
}
Double TrigonometricEquations::getX2dY(Double y)
{
	if (a[1][0] == 0) return NAN;
	return Math::Sin(y + a[1][1]) / a[1][0];
}
