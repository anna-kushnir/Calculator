#pragma once
#include <iostream>
using namespace System;
/// <summary>
///  лас, що в≥дображаЇ матрицю якоб≥.
/// </summary>
ref class JakobiMatrix
{
protected:

	/// <summary>
	/// ћатриц€ якоб≥.
	/// </summary>
	Double** W;

public:

	/// <summary>
	///  онструктор матриц≥ якоб≥ за замовчуванн€м.
	/// </summary>
	JakobiMatrix();
	/// <summary>
	///  онструктор матриц≥ якоб≥ ≥з заданого двовим≥рного масиву.
	/// </summary>
	/// <param name="matrix">ƒвовим≥рний масив, з €кого буде створена матриц€ якоб≥.</param>
	JakobiMatrix(Double** matrix);
	/// <summary>
	/// ќчищуЇ динам≥чну пам'€ть вид≥лену на матрицю.
	/// </summary>
	~JakobiMatrix();

	/// <summary>
	/// ‘ормуЇ матрицю якоб≥ ≥з заданого двовим≥рного масиву.
	/// </summary>
	/// <param name="matrix">ƒвовим≥рний масив, з €кого буде створена матриц€ якоб≥.</param>
	Void setMatrix(Double** matrix);

	/// <summary>
	/// ѕовертаЇ перший норм (норм M) матриц≥ якоб≥.
	/// </summary>
	/// <returns>«наченн€ типу Double.</returns>
	Double getNormM();
	/// <summary>
	/// ѕовертаЇ другий норм (норм L) матриц≥ якоб≥.
	/// </summary>
	/// <returns>«наченн€ типу Double.</returns>
	Double getNormL();

	/// <summary>
	/// ѕовертаЇ елемент матриц≥ якоб≥ з ≥ндексами (row, col).
	/// </summary>
	/// <param name="row">Ќомер р€дка.</param>
	/// <param name="col">Ќомер стовпц€.</param>
	/// <returns>ѕосиланн€ на зм≥нну типу Double.</returns>
	Double& operator()(const Int16 row, const Int16 col);
};
