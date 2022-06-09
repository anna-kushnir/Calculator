#pragma once
#include "Equations.h"
/// <summary>
/// ���� ��� ����������� ������� ������������ ������:
/// a11*x^2+a12*y^2+a13=0
///  a21*x^2+a22*y^2+a23=0
/// </summary>
ref class ArithmeticEquations : public Equations
{
public:

	/// <summary>
	/// ����������� ������� ������������ ������ �� �������������.
	/// </summary>
	ArithmeticEquations();
	/// <summary>
	/// ����������� ������� ������������ ������ � ��������� �������������.
	/// </summary>
	/// <param name = 'coef'>���������� ����� ����������� ������.</param>
	ArithmeticEquations(Double** coef);
	/// <summary>
	/// ����������� ������� ������������ ������ � ��������� ������������� 
	/// �� ���������� ����������� ����'����.
	/// </summary>
	/// <param name = 'coef'>���������� ����� ����������� ������.</param>
	/// <param name = 'initX'>����������� ����� ���������� ��������� ����'���� 
	/// �������.</param>
	ArithmeticEquations(Double** coef, Double* initX);

	/// <summary>
	/// ����'��� ���� ����������� ������� ������� ����.
	/// </summary>
	/// <param name="result">����� ��� ������ �������� ����'���� �� �������� 
	/// ���������� ������������ �������.</param>
	/// <param name="precis">�������, � ���� ������������ ���������.</param>
	/// <returns>-3, ���� ������� ����� �� ����������� ��� ����'������ ������� �������; 
	/// -2, ���� ������� �� �� ����'����; -1, ���� ����������� ������ ��������; 0, 
	/// ���� ������� �� ���������� ���� ����'����; 1, ���� ����������� ������ ������; 
	/// 2, ���� ������� �� ����� ����'����.</returns>
	Int16 JakobiMethod(List<Double>^ result, Double precis) override;
	/// <summary>
	/// ����'��� ���� ����������� ������� ������� �����-�������.
	/// </summary>
	/// <param name="result">����� ��� ������ �������� ����'���� �� �������� 
	/// ���������� ������������ �������.</param>
	/// <param name="precis">�������, � ���� ������������ ���������.</param>
	/// <returns>-3, ���� ������� ����� �� ����������� ��� ����'������ ������� �������; 
	/// -2, ���� ������� �� �� ����'����; -1, ���� ����������� ������ ��������; 0, 
	/// ���� ������� �� ���������� ���� ����'����; 1, ���� ����������� ������ ������; 
	/// 2, ���� ������� �� ����� ����'����.</returns>
	Int16 ZeydelMethod(List<Double>^ result, Double precis) override;

	/// <summary>
	/// ������� "�����" ������� � ������ ���� ������.
	/// </summary>
	/// <returns>1, ���� ������� �����������; 2, ���� ������� ���������������; 3, ���� ������� ��������������.</returns>
	Int16 getId() override;
	/// <summary>
	/// ������� ������� ������ � ������ ���� �����, �� ������� ����� ��������� 
	/// ��� �������, ��� � ��������� �������������.
	/// </summary>
	/// <returns>�������� ���� String^</returns>
	String^ getEquations() override;

	/// <summary>
	/// ������� �������� Y � ������� ������� ������� � ������� ����� X.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getY1(Double x) override;
	/// <summary>
	/// ������� �������� Y � ������� ������� ������� � ������� ����� X.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getY2(Double x) override;
	/// <summary>
	///  ������� �������� X � ������� ������� ������� � ������� ����� Y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getX1(Double y) override;
	/// <summary>
	///  ������� �������� X � ������� ������� ������� � ������� ����� Y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getX2(Double y) override;

protected:

	/// <summary>
	/// �������� ����������� ������ �� ������� ��� �������� ����������� ���������.
	/// </summary>
	/// <param name="i">���������, ���� �������, �� ���� �������� ������� �����������
	/// �������� ������� ��� ������� ������������ �������.</param>
	/// <returns>false, ���� ����������� ������ ��������; true, ���� ����������� ������ 
	/// ������.</returns>
	Boolean checkInitApprox(int i) override;
	/// <summary>
	/// ������� �������� ������� �� X ������� ������� ������� � ����� x.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getY1dX(Double x) override;
	/// <summary>
	/// ������� �������� ������� �� X ������� ������� ������� � ����� x.
	/// </summary>
	/// <param name="x">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getY2dX(Double x) override;
	/// <summary>
	/// ������� �������� ������� �� Y ������� ������� ������� � ����� y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getX1dY(Double y) override;
	/// <summary>
	/// ������� �������� ������� �� Y ������� ������� ������� � ����� y.
	/// </summary>
	/// <param name="y">�������� �������.</param>
	/// <returns>�������� ���� Double.</returns>
	Double getX2dY(Double y) override;
};
