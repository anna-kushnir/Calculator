#pragma once
#include "JakobiMatrix.h"
using namespace System;
using namespace System::Collections::Generic;
/// <summary>
/// Клас для відображення системи рівнянь.
/// </summary>
ref class Equations abstract
{
protected:

	/// <summary>
	/// Двовимірний масив коефіцієнтів рівнянь системи.
	/// </summary>
	Double** a;
	/// <summary>
	/// Одновимірний масив початкових наближень розв'язку системи.
	/// </summary>
	Double* x0;
	/// <summary>
	/// Матриця Якобі даної системи.
	/// </summary>
	JakobiMatrix W;
	/// <summary>
	/// Кількість ітерацій.
	/// </summary>
	Int16 iterations;

public:

	/// <summary>
	/// Конструктор системи рівнянь за замовчуванням.
	/// </summary>
	Equations();
	/// <summary>
	/// Конструктор системи рівнянь із вказаними коефіцієнтами.
	/// </summary>
	/// <param name = 'coef'>Двовимірний масив коефіцієнтів рівнянь.</param>
	Equations(Double** coef);
	/// <summary>
	/// Конструктор системи рівнянь із вказаними коефіцієнтами та 
	/// початковим наближенням розв'язку.
	/// </summary>
	/// <param name = 'coef'>Двовимірний масив коефіцієнтів рівнянь.</param>
	/// <param name = 'initX'>Одновимірний масив початкових наближень розв'язку 
	/// системи.</param>
	Equations(Double** coef, Double* initX);
	/// <summary>
	/// Очищує динамічну пам'ять виділену на масиви коефіцієнтів та початкових 
	/// наближень.
	/// </summary>
	~Equations();
	
	/// <summary>
	/// Розв'язує дану систему методом Якобі.
	/// </summary>
	/// <param name="result">Масив для запису кінцевого розв'язку та проміжних 
	/// результатів ітераційного процесу.</param>
	/// <param name="precis">Точність, з якою обчислюється результат.</param>
	/// <returns>-3, якщо розв'язання системи призвело до розбіжного 
	/// ітераційного процесу; -2, якщо система не має розв'язків; -1, якщо 
	/// ітераційний процес розбіжний; 0, якщо система має щонайменше один розв'язок; 
	/// 1, якщо ітераційний процес збіжний; 2, якщо система має безліч розв'язків.
	/// </returns>
	virtual Int16 JakobiMethod(List<Double>^ result, Double precis) = 0;
	/// <summary>
	/// Розв'язує дану систему методом Гауса-Зейделя.
	/// </summary>
	/// <param name="result">Масив для запису кінцевого розв'язку та проміжних 
	/// результатів ітераційного процесу.</param>
	/// <param name="precis">Точність, з якою обчислюється результат.</param>
	/// <returns>-3, якщо розв'язання системи призвело до розбіжного 
	/// ітераційного процесу; -2, якщо система не має розв'язків; -1, якщо 
	/// ітераційний процес розбіжний; 0, якщо система має щонайменше один розв'язок; 
	/// 1, якщо ітераційний процес збіжний; 2, якщо система має безліч розв'язків.
	/// </returns>
	virtual Int16 ZeydelMethod(List<Double>^ result, Double precis) = 0;

	/// <summary>
	/// Повертає значення Y з першого рівняння системи у вказаній точці X.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getY1(Double x) = 0;
	/// <summary>
	/// Повертає значення Y з другого рівняння системи у вказаній точці X.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getY2(Double x) = 0;
	/// <summary>
	///  Повертає значення X з першого рівняння системи у вказаній точці Y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getX1(Double y) = 0;
	/// <summary>
	///  Повертає значення X з другого рівняння системи у вказаній точці Y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getX2(Double y) = 0;

	/// <summary>
	/// Повертає номер системи у списку видів систем.
	/// </summary>
	/// <returns>1, якщо система арифметична; 2, якщо система тригонометрична; 3, 
	/// якщо система трансцендентна.</returns>
	virtual Int16 getId() = 0;
	/// <summary>
	/// Повертає систему рівнянь у вигляді двох рядків, які являють собою загальний 
	/// вид системи, але з вказаними коефіцієнтами.
	/// </summary>
	/// <returns>Значення типу String^</returns>
	virtual String^ getEquations() = 0;
	/// <summary>
	/// Повертає кількість ітерацій, зроблених при обчисленні точного розв'язку
	/// даної системи рівнянь.
	/// </summary>
	/// <returns>Значення типу Int16.</returns>
	Int16 getIterations();
	/// <summary>
	/// Повертає масив коефіцієнтів рівнянь даної системи.
	/// </summary>
	/// <returns>Двовимірний динамічний масив типу Double.</returns>
	Double** getCoef();

protected:

	/// <summary>
	/// Перевіряє ітераційний процес на збіжність при заданому початковому наближенні.
	/// </summary>
	/// <param name="i">Прапорець, який визначає, за якою формулою потрібно перетворити
	/// початкові рівняння для початку ітераційного процесу.</param>
	/// <returns>false, якщо ітераційний процес розбіжний; true, якщо ітераційний процес 
	/// збіжний.</returns>
	virtual Boolean checkInitApprox(int i) = 0;
	/// <summary>
	/// Повертає значення похідної по X першого рівняння системи у точці x.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getY1dX(Double x) = 0;
	/// <summary>
	/// Повертає значення похідної по X другого рівняння системи у точці x.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getY2dX(Double x) = 0;
	/// <summary>
	/// Повертає значення похідної по Y першого рівняння системи у точці y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getX1dY(Double y) = 0;
	/// <summary>
	/// Повертає значення похідної по Y другого рівняння системи у точці y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	virtual Double getX2dY(Double y) = 0;

};
