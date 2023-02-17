#pragma once
#include <iostream>
using namespace System;
/// <summary>
/// Клас, що відображає матрицю Якобі.
/// </summary>
ref class JakobiMatrix
{
protected:

	/// <summary>
	/// Матриця Якобі.
	/// </summary>
	Double** W;

public:

	/// <summary>
	/// Конструктор матриці Якобі за замовчуванням.
	/// </summary>
	JakobiMatrix();
	/// <summary>
	/// Конструктор матриці Якобі із заданого двовимірного масиву.
	/// </summary>
	/// <param name="matrix">Двовимірний масив, з якого буде створена матриця Якобі.</param>
	JakobiMatrix(Double** matrix);
	/// <summary>
	/// Очищує динамічну пам'ять виділену на матрицю.
	/// </summary>
	~JakobiMatrix();

	/// <summary>
	/// Формує матрицю Якобі із заданого двовимірного масиву.
	/// </summary>
	/// <param name="matrix">Двовимірний масив, з якого буде створена матриця Якобі.</param>
	Void setMatrix(Double** matrix);

	/// <summary>
	/// Повертає перший норм (норм M) матриці Якобі.
	/// </summary>
	/// <returns>Значення типу Double.</returns>
	Double getNormM();
	/// <summary>
	/// Повертає другий норм (норм L) матриці Якобі.
	/// </summary>
	/// <returns>Значення типу Double.</returns>
	Double getNormL();

	/// <summary>
	/// Повертає елемент матриці Якобі з індексами (row, col).
	/// </summary>
	/// <param name="row">Номер рядка.</param>
	/// <param name="col">Номер стовпця.</param>
	/// <returns>Посилання на змінну типу Double.</returns>
	Double& operator()(const Int16 row, const Int16 col);
};
