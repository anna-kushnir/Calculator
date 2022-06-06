#pragma once
#include <iostream>
using namespace System;
/// <summary>
/// ����, �� �������� ������� ����.
/// </summary>
ref class JakobiMatrix
{
protected:

	/// <summary>
	/// ������� ����.
	/// </summary>
	Double** W;

public:

	/// <summary>
	/// ����������� ������� ���� �� �������������.
	/// </summary>
	JakobiMatrix();
	/// <summary>
	/// ����������� ������� ���� �� �������� ����������� ������.
	/// </summary>
	/// <param name="matrix">���������� �����, � ����� ���� �������� ������� ����.</param>
	JakobiMatrix(Double** matrix);
	/// <summary>
	/// ����� �������� ���'��� ������� �� �������.
	/// </summary>
	~JakobiMatrix();

	/// <summary>
	/// ����� ������� ���� �� �������� ����������� ������.
	/// </summary>
	/// <param name="matrix">���������� �����, � ����� ���� �������� ������� ����.</param>
	Void setMatrix(Double** matrix);

	/// <summary>
	/// ������� ������ ���� (���� M) ������� ����.
	/// </summary>
	/// <returns>�������� ���� Double.</returns>
	Double getNormM();
	/// <summary>
	/// ������� ������ ���� (���� L) ������� ����.
	/// </summary>
	/// <returns>�������� ���� Double.</returns>
	Double getNormL();

	/// <summary>
	/// ������� ������� ������� ���� � ��������� (row, col).
	/// </summary>
	/// <param name="row">����� �����.</param>
	/// <param name="col">����� �������.</param>
	/// <returns>��������� �� ����� ���� Double.</returns>
	Double& operator()(const Int16 row, const Int16 col);
};
