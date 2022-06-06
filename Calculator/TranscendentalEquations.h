#pragma once
#include "Equations.h"
/// <summary>
/// ���� ��� ����������� ������� ��������������� ������:
/// e^(a11*x)+e^(a12*y)+a13=0
/// e^(a21*x)+e^(a22*y)+a23=0
/// </summary>
ref class TranscendentalEquations : public Equations
{
public:

	/// <summary>
	/// ����������� ������� ��������������� ������ �� �������������.
	/// </summary>
	TranscendentalEquations();
	/// <summary>
	/// ����������� ������� ��������������� ������ � ��������� �������������.
	/// </summary>
	/// <param name = 'coef'>���������� ����� ����������� ������.</param>
	TranscendentalEquations(Double** coef);
	/// <summary>
	/// ����������� ������� ��������������� ������ � ��������� ������������� 
	/// �� ���������� ����������� ����'����.
	/// </summary>
	/// <param name = 'coef'>���������� ����� ����������� ������.</param>
	/// <param name = 'initX'>����������� ����� ���������� ��������� ����'���� 
	/// �������.</param>
	TranscendentalEquations(Double** coef, Double* initX);

	/// <summary>
	/// ����'��� ���� �������������� ������� ������� ����.
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
	/// ����'��� ���� �������������� ������� ������� �����-�������.
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
