#include "pch.h"
#include "ArithmeticEquations.h"
#include <Math.h>
using namespace System;

ArithmeticEquations::ArithmeticEquations() : Equations() {}
ArithmeticEquations::ArithmeticEquations(Double** coef) : Equations(coef) {}
ArithmeticEquations::ArithmeticEquations(Double** coef, Double* initX) : Equations(coef, initX) {}

Boolean ArithmeticEquations::checkInitApprox(int i)
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

Int16 ArithmeticEquations::JakobiMethod(List<Double>^ result, Double precis)
{
	iterations = 0;
	result->Clear();
	if (a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0) {
		return 2;
	}
	if ((a[0][0] * a[0][1] > 0 && a[0][0] * a[0][2] > 0 && a[0][1] * a[0][2] > 0) ||
		(a[1][0] * a[1][1] > 0 && a[1][0] * a[1][2] > 0 && a[1][1] * a[1][2] > 0) ||
		(a[0][0] == 0 && a[0][1] == 0 && a[0][2] != 0) || 
		(a[1][0] == 0 && a[1][1] == 0 && a[1][2] != 0) ||
		(a[0][0] * a[0][1] > 0 && a[0][2] == 0 && a[1][2] != 0) ||
		(a[1][0] * a[1][1] > 0 && a[1][2] == 0 && a[0][2] != 0) ||
		(a[0][0] * a[0][2] > 0 && a[0][1] == 0) ||
		(a[0][1] * a[0][2] > 0 && a[0][0] == 0) ||
		(a[1][0] * a[1][2] > 0 && a[1][1] == 0) ||
		(a[1][1] * a[1][2] > 0 && a[1][0] == 0)) {
		return -2;
	}
	if (a[0][2] == 0 && a[1][2] == 0 && (a[0][0] * a[0][1] > 0 || a[1][0] * a[1][1] > 0)) {
		result->Add(0);
		result->Add(0);
		return 0;
	}
	if (-(a[0][0] + a[0][1]) == a[0][2] && -(a[1][0] + a[1][1]) == a[1][2]) {
		if (x0[0] >= 0) result->Add(1);
		else result->Add(-1);
		if (x0[1] >= 0) result->Add(1);
		else result->Add(-1);
		return 0;
	}

	Double num1, num2;		// Змінні для тимчасового збереження результатів обчислення коренів.
	Boolean flag = true;	// Прапорець, який визначає, чи вдалося розв’язати систему рівнянь.
	Double delta;			// Різниця між значеннями коренів на сусідніх ітераціях.
	Int32 i;				// Лічильник ітерацій.

/* 1 */
	if (a[0][0] != 0 && a[1][1] != 0 && checkInitApprox(1)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		i = 2;
		while (true) {
			iterations++;
			num1 = getX1(result[i - 1]);
			num2 = getY2(result[i - 2]);
			if (!isfinite(num1) || !isfinite(num2)) {
				result->Clear();
				flag = false;
				break;
			}
			if (x0[0] >= 0) result->Add(num1);
			else result->Add(-num1);
			if (x0[1] >= 0) result->Add(num2);
			else result->Add(-num2);
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
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
		i = 2;
		while (true) {
			iterations++;
			num1 = getX2(result[i - 1]);
			num2 = getY1(result[i - 2]);
			if (!isfinite(num1) || !isfinite(num2)) {
				result->Clear();
				return -3;
			}
			if (x0[0] >= 0) result->Add(num1);
			else result->Add(-num1);
			if (x0[1] >= 0) result->Add(num2);
			else result->Add(-num2);
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
	if (flag) return -1;
	return -3;
}
Int16 ArithmeticEquations::ZeydelMethod(List<Double>^ result, Double precis)
{
	iterations = 0;
	result->Clear();
	if (a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0 && a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0) {
		return 2;
	}
	if ((a[0][0] * a[0][1] > 0 && a[0][0] * a[0][2] > 0 && a[0][1] * a[0][2] > 0) ||
		(a[1][0] * a[1][1] > 0 && a[1][0] * a[1][2] > 0 && a[1][1] * a[1][2] > 0) ||
		(a[0][0] == 0 && a[0][1] == 0 && a[0][2] != 0) ||
		(a[1][0] == 0 && a[1][1] == 0 && a[1][2] != 0) ||
		(a[0][0] * a[0][1] > 0 && a[0][2] == 0 && a[1][2] != 0) ||
		(a[1][0] * a[1][1] > 0 && a[1][2] == 0 && a[0][2] != 0) ||
		(a[0][0] * a[0][2] > 0 && a[0][1] == 0) ||
		(a[0][1] * a[0][2] > 0 && a[0][0] == 0) ||
		(a[1][0] * a[1][2] > 0 && a[1][1] == 0) ||
		(a[1][1] * a[1][2] > 0 && a[1][0] == 0)) {
		return -2;
	}
	if (a[0][2] == 0 && a[1][2] == 0 && (a[0][0] * a[0][1] > 0 || a[1][0] * a[1][1] > 0)) {
		result->Add(0);
		result->Add(0); 
		return 0;
	}
	if (-(a[0][0] + a[0][1]) == a[0][2] && -(a[1][0] + a[1][1]) == a[1][2]) {
		if (x0[0] >= 0) result->Add(1);
		else result->Add(-1);
		if (x0[1] >= 0) result->Add(1);
		else result->Add(-1);
		return 0;
	}

	Double num1, num2;		// Змінні для тимчасового збереження результатів обчислення коренів.
	Boolean flag = true;	// Прапорець, який визначає, чи вдалося розв’язати систему рівнянь.
	Double delta;			// Різниця між значеннями коренів на сусідніх ітераціях.
	Int32 i; 				// Лічильник ітерацій.

/* 1 */
	if (a[0][0] != 0 && a[1][1] != 0 && checkInitApprox(1)) {
		result->Add(x0[0]);
		result->Add(x0[1]);
		i = 2;
		while (true) {
			iterations++;
			num1 = getX1(result[i - 1]);
			if (!isfinite(num1)) {
				result->Clear();
				flag = false;
				break;
			}
			if (x0[0] >= 0) result->Add(num1);
			else result->Add(-num1);

			num2 = getY2(result[i]);
			if (!isfinite(num2)) {
				result->Clear();
				flag = false;
				break;
			}
			if (x0[1] >= 0) result->Add(num2);
			else result->Add(-num2);
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
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
		i = 2;
		while (true) {
			iterations++;
			num1 = getX2(result[i - 1]);
			if (!isfinite(num1)) {
				result->Clear();
				return -3;
			}
			if (x0[0] >= 0) result->Add(num1);
			else result->Add(-num1);

			num2 = getY1(result[i]);
			if (!isfinite(num2)) {
				result->Clear();
				return -3;
			}
			if (x0[1] >= 0) result->Add(num2);
			else result->Add(-num2);
			delta = Math::Max(Math::Abs(result[i] - result[i - 2]), Math::Abs(result[i + 1] - result[i - 1]));
			if (delta <= precis) {
				return 1;
			}
			i += 2;
		}
	}
	if (flag) return -1;
	return -3;
}

Int16 ArithmeticEquations::getId()
{
	return 1;
}
String^ ArithmeticEquations::getEquations()
{
	String^ eq = ("  " + Convert::ToString(a[0][0]) + " * x ^ 2 + " + Convert::ToString(a[0][1]) + " * y ^ 2 + " +
		Convert::ToString(a[0][2]) + " = 0\n  " + Convert::ToString(a[1][0]) + " * x ^ 2 + " + Convert::ToString(a[1][1]) +
		" * y ^ 2 + " + Convert::ToString(a[1][2]) + " = 0");
	return eq;
}

Double ArithmeticEquations::getY1(Double x)
{
	if (a[0][1] == 0) return NAN;
	Double num = (-a[0][0] * Math::Pow(x, 2) - a[0][2]) / a[0][1];
	if (num < 0) return NAN;
	return Math::Sqrt(num);
}
Double ArithmeticEquations::getY2(Double x)
{
	if (a[1][1] == 0) return NAN;
	Double num = (-a[1][0] * Math::Pow(x, 2) - a[1][2]) / a[1][1];
	if (num < 0) return NAN;
	return Math::Sqrt(num);
}
Double ArithmeticEquations::getX1(Double y)
{
	if (a[0][0] == 0) return NAN;
	Double num = (-a[0][1] * Math::Pow(y, 2) - a[0][2]) / a[0][0];
	if (num < 0) return NAN;
	return Math::Sqrt(num);
}
Double ArithmeticEquations::getX2(Double y)
{
	if (a[1][0] == 0) return NAN;
	Double num = (-a[1][1] * Math::Pow(y, 2) - a[1][2]) / a[1][0];
	if (num < 0) return NAN;
	return Math::Sqrt(num);
}

Double ArithmeticEquations::getY1dX(Double x)
{
	Double num = a[0][1] * (-a[0][0] * Math::Pow(x, 2) - a[0][2]);
	if (num <= 0) return NAN;
	return -a[0][0] * x / Math::Sqrt(num);
}
Double ArithmeticEquations::getY2dX(Double x)
{
	Double num = a[1][1] * (-a[1][0] * Math::Pow(x, 2) - a[1][2]);
	if (num <= 0) return NAN;
	return -a[1][0] * x / Math::Sqrt(num);
}
Double ArithmeticEquations::getX1dY(Double y)
{
	Double num = a[0][0] * (-a[0][1] * Math::Pow(y, 2) - a[0][2]);
	if (num <= 0) return NAN;
	return -a[0][1] * y / Math::Sqrt(num);
}
Double ArithmeticEquations::getX2dY(Double y)
{
	Double num = a[1][0] * (-a[1][1] * Math::Pow(y, 2) - a[1][2]);
	if (num <= 0) return NAN;
	return -a[1][1] * y / Math::Sqrt(num);
}
