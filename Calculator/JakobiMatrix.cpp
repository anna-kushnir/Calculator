#include "pch.h"
#include "JakobiMatrix.h"

JakobiMatrix::JakobiMatrix()
{
	W = new Double * [2];
	for (Int16 i = 0; i < 2; ++i) {
		W[i] = new Double[2];
	}
}
JakobiMatrix::JakobiMatrix(Double** matrix)
{
	W = new Double * [2];
	for (Int16 i = 0; i < 2; ++i) {
		W[i] = new Double[2];
	}
	for (Int16 i = 0; i < 2; ++i) {
		for (Int16 j = 0; j < 2; ++j) {
			W[i][j] = matrix[i][j];
		}
	}
}
JakobiMatrix::~JakobiMatrix()
{
	for (Int16 i = 0; i < 2; ++i) {
		delete[] W[i];
	}
	delete[] W;
}

Void JakobiMatrix::setMatrix(Double** matrix)
{
	for (Int16 i = 0; i < 2; ++i) {
		for (Int16 j = 0; j < 2; ++j) {
			W[i][j] = matrix[i][j];
		}
	}
}

Double JakobiMatrix::getNormM()
{
	return Math::Max(W[0][0] + W[0][1], W[1][0] + W[1][1]);
}
Double JakobiMatrix::getNormL()
{
	return Math::Max(W[0][0] + W[1][0], W[0][1] + W[1][1]);
}

Double& JakobiMatrix::operator()(const Int16 row, const Int16 col)
{
	return W[row][col];
}
