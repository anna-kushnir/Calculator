#pragma once
#include "JakobiMatrix.h"
using namespace System;
using namespace System::Collections::Generic;
/// <summary>
/// ���� ��� ����������� ������� ������.
/// </summary>
ref class Equations abstract
{
protected:

	/// <summary>
	/// ���������� ����� ����������� ������ �������.
	/// </summary>
	Double** a;
	/// <summary>
	/// ����������� ����� ���������� ��������� ����'���� �������.
	/// </summary>
	Double* x0;
	/// <summary>
	/// ������� ���� ���� �������.
	/// </summary>
	JakobiMatrix W;
	/// <summary>
	/// ʳ������ ��������.
	/// </summary>
	Int16 iterations;

public:

	/// <summary>
	/// ����������� ������� ������ �� �������������.
	/// </summary>
	Equations();
	/// <summary>
	/// ����������� ������� ������ �� ��������� �������������.
	/// </summary>
	/// <param name = 'coef'>���������� ����� ����������� ������.</param>
	Equations(Double** coef);
	/// <summary>
	/// ����������� ������� ������ �� ��������� ������������� �� 
	/// ���������� ����������� ����'����.
	/// </summary>
	/// <param name = 'coef'>���������� ����� ����������� ������.</param>
	/// <param name = 'initX'>����������� ����� ���������� ��������� ����'���� 
	/// �������.</param>
	Equations(Double** coef, Double* initX);
	/// <summary>
	/// ����� �������� ���'��� ������� �� ������ ����������� �� ���������� 
	/// ���������.
	/// </summary>
	~Equations();
	
	/// <summary>
	/// ����'��� ���� ������� ������� ����.
	/// </summary>
	/// <param name="result">����� ��� ������ �������� ����'���� �� �������� 
	/// ���������� ������������ �������.</param>
	/// <param name="precis">�������, � ���� ������������ ���������.</param>
	/// <returns>-3, ���� ����'������ ������� �������� �� ��������� 
	/// ������������ �������; -2, ���� ������� �� �� ����'����; -1, ���� 
	/// ����������� ������ ��������; 0, ���� ������� �� ���������� ���� ����'����; 
	/// 1, ���� ����������� ������ ������; 2, ���� ������� �� ����� ����'����.
	/// </returns>
	virtual Int16 JakobiMethod(List<Double>^ result, Double precis) = 0;
	/// <summary>
	/// ����'��� ���� ������� ������� �����-�������.
	/// </summary>
	/// <param name="result">����� ��� ������ �������� ����'���� �� �������� 
	/// ���������� ������������ �������.</param>
	/// <param name="precis">�������, � ���� ������������ ���������.</param>
	/// <returns>-3, ���� ����'������ ������� �������� �� ��������� 
	/// ������������ �������; -2, ���� ������� �� �� ����'����; -1, ���� 
	/// ����������� ������ ��������; 0, ���� ������� �� ���������� ���� ����'����; 
	/// 1, ���� ����������� ������ ������; 2, ���� ������� �� ����� ����'����.
	/// </returns>
	virtual Int16 ZeydelMethod(List<Double>^ result, Double precis) = 0;

	/// <summary>
	/// ������� �������� Y � ������� ������� ������� � ������� ����� X.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getY1(Double x) = 0;
	/// <summary>
	/// ������� �������� Y � ������� ������� ������� � ������� ����� X.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getY2(Double x) = 0;
	/// <summary>
	///  ������� �������� X � ������� ������� ������� � ������� ����� Y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getX1(Double y) = 0;
	/// <summary>
	///  ������� �������� X � ������� ������� ������� � ������� ����� Y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getX2(Double y) = 0;

	/// <summary>
	/// ������� ����� ������� � ������ ���� ������.
	/// </summary>
	/// <returns>1, ���� ������� �����������; 2, ���� ������� ���������������; 3, 
	/// ���� ������� ��������������.</returns>
	virtual Int16 getId() = 0;
	/// <summary>
	/// ������� ������� ������ � ������ ���� �����, �� ������� ����� ��������� 
	/// ��� �������, ��� � ��������� �������������.
	/// </summary>
	/// <returns>�������� ���� String^</returns>
	virtual String^ getEquations() = 0;
	/// <summary>
	/// ������� ������� ��������, ��������� ��� ��������� ������� ����'����
	/// ���� ������� ������.
	/// </summary>
	/// <returns>�������� ���� Int16.</returns>
	Int16 getIterations();
	/// <summary>
	/// ������� ����� ����������� ������ ���� �������.
	/// </summary>
	/// <returns>���������� ��������� ����� ���� Double.</returns>
	Double** getCoef();

protected:

	/// <summary>
	/// �������� ����������� ������ �� ������� ��� �������� ����������� ���������.
	/// </summary>
	/// <param name="i">���������, ���� �������, �� ���� �������� ������� �����������
	/// �������� ������� ��� ������� ������������ �������.</param>
	/// <returns>false, ���� ����������� ������ ��������; true, ���� ����������� ������ 
	/// ������.</returns>
	virtual Boolean checkInitApprox(int i) = 0;
	/// <summary>
	/// ������� �������� ������� �� X ������� ������� ������� � ����� x.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getY1dX(Double x) = 0;
	/// <summary>
	/// ������� �������� ������� �� X ������� ������� ������� � ����� x.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getY2dX(Double x) = 0;
	/// <summary>
	/// ������� �������� ������� �� Y ������� ������� ������� � ����� y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getX1dY(Double y) = 0;
	/// <summary>
	/// ������� �������� ������� �� Y ������� ������� ������� � ����� y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	virtual Double getX2dY(Double y) = 0;

};
