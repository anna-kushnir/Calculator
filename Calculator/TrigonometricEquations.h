#pragma once
#include "Equations.h"
/// <summary>
/// Клас для відображення системи тригонометричних рівнянь:
/// sin(x+a11)+a12*y+a13=0
/// a21*x+cos(y+a22)+a23=0
/// </summary>
ref class TrigonometricEquations : public Equations
{
public:

	/// <summary>
	/// Конструктор системи тригонометричних рівнянь за замовчуванням.
	/// </summary>
	TrigonometricEquations();
	/// <summary>
	/// Конструктор системи тригонометричних рівнянь з вказаними коефіцієнтами.
	/// </summary>
	/// <param name = 'coef'>Двовимірний масив коефіцієнтів рівнянь.</param>
	TrigonometricEquations(Double** coef);
	/// <summary>
	/// Конструктор системи тригонометричних рівнянь з вказаними коефіцієнтами 
	/// та початковим наближенням розв'язку.
	/// </summary>
	/// <param name = 'coef'>Двовимірний масив коефіцієнтів рівнянь.</param>
	/// <param name = 'initX'>Одновимірний масив початкових наближень розв'язку 
	/// системи.</param>
	TrigonometricEquations(Double** coef, Double* initX);
	
	/// <summary>
	/// Розв'язує дану тригонометричну систему методом Якобі.
	/// </summary>
	/// <param name="result">Масив для запису кінцевого розв'язку та проміжних 
	/// результатів ітераційного процесу.</param>
	/// <param name="precis">Точність, з якою обчислюється результат.</param>
	/// <returns>-3, якщо обраний метод не застосовний для розв'язання введеної системи; 
	/// -2, якщо система не має розв'язків; -1, якщо ітераційний процес розбіжний; 0, 
	/// якщо система має щонайменше один розв'язок; 1, якщо ітераційний процес збіжний; 
	/// 2, якщо система має безліч розв'язків.</returns>
	Int16 JakobiMethod(List<Double>^ result, Double precis) override;
	/// <summary>
	/// Розв'язує дану тригонометричну систему методом Гауса-Зейделя.
	/// </summary>
	/// <param name="result">Масив для запису кінцевого розв'язку та проміжних 
	/// результатів ітераційного процесу.</param>
	/// <param name="precis">Точність, з якою обчислюється результат.</param>
	/// <returns>-3, якщо обраний метод не застосовний для розв'язання введеної системи; 
	/// -2, якщо система не має розв'язків; -1, якщо ітераційний процес розбіжний; 0, 
	/// якщо система має щонайменше один розв'язок; 1, якщо ітераційний процес збіжний; 
	/// 2, якщо система має безліч розв'язків.</returns>
	Int16 ZeydelMethod(List<Double>^ result, Double precis) override;

	/// <summary>
	/// Повертає "номер" системи у списку видів систем.
	/// </summary>
	/// <returns>1, якщо система арифметична; 2, якщо система тригонометрична; 3, якщо система трансцендентна.</returns>
	Int16 getId() override;
	/// <summary>
	/// Повертає систему рівнянь у вигляді двох рядків, які являють собою загальний 
	/// вид системи, але з вказаними коефіцієнтами.
	/// </summary>
	/// <returns>Значення типу String^</returns>
	String^ getEquations() override;

	/// <summary>
	/// Повертає значення Y з першого рівняння системи у вказаній точці X.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getY1(Double x) override;
	/// <summary>
	/// Повертає значення Y з другого рівняння системи у вказаній точці X.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getY2(Double x) override;
	/// <summary>
	///  Повертає значення X з першого рівняння системи у вказаній точці Y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getX1(Double y) override;
	/// <summary>
	///  Повертає значення X з другого рівняння системи у вказаній точці Y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getX2(Double y) override;

protected:

	/// <summary>
	/// Перевіряє ітераційний процес на збіжність при заданому початковому наближенні.
	/// </summary>
	/// <param name="i">Прапорець, який визначає, за якою формулою потрібно перетворити
	/// початкові рівняння для початку ітераційного процесу.</param>
	/// <returns>false, якщо ітераційний процес розбіжний; true, якщо ітераційний процес 
	/// збіжний.</returns>
	Boolean checkInitApprox(int i) override;
	/// <summary>
	/// Повертає значення похідної по X першого рівняння системи у точці x.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getY1dX(Double x) override;
	/// <summary>
	/// Повертає значення похідної по X другого рівняння системи у точці x.
	/// </summary>
	/// <param name="x">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getY2dX(Double x) override;
	/// <summary>
	/// Повертає значення похідної по Y першого рівняння системи у точці y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getX1dY(Double y) override;
	/// <summary>
	/// Повертає значення похідної по Y другого рівняння системи у точці y.
	/// </summary>
	/// <param name="y">Аргумент функції.</param>
	/// <returns>Значення типу Double.</returns>
	Double getX2dY(Double y) override;
};
