#include "pch.h"
#include "Equations.h"

Equations::Equations()
{
	a = new Double * [2];
	x0 = new Double[2];
	for (Int16 i = 0; i < 2; ++i) {
		a[i] = new Double[3];
	}
}
Equations::Equations(Double** coef)
{
	a = new Double * [2];
	x0 = nullptr;
	for (Int16 i = 0; i < 2; ++i) {
		a[i] = new Double[3];
	}
	for (Int16 i = 0; i < 2; ++i) {
		for (Int16 j = 0; j < 3; ++j) {
			a[i][j] = coef[i][j];
		}
	}
}
Equations::Equations(Double** coef, Double* initX)
{
	a = new Double * [2];
	x0 = new Double[2];
	for (Int16 i = 0; i < 2; ++i) {
		a[i] = new Double[3];
	}
	for (Int16 i = 0; i < 2; ++i) {
		for (Int16 j = 0; j < 3; ++j) {
			a[i][j] = coef[i][j];
		}
		x0[i] = initX[i];
	}
}

Equations::~Equations()
{
	for (Int16 i = 0; i < 2; ++i) {
		delete[] a[i];
	}
	delete[] a, x0;
}

Int16 Equations::getIterations()
{
	return iterations;
}
Double** Equations::getCoef()
{
	return a;
}
