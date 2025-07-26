#define NOMINMAX

#include <iostream>
#include <clocale>
#include <windows.h>
#include <vector>
#include <limits>

#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Parallelogram.h"
#include "RectangleShape.h"
#include "Square.h"
#include "Rhombus.h"

using namespace std;

// Функция вывода информации
void print_info(const Figure *figure)
{
    figure->print();
}

// Основная функция
int main()
{
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создаем фигуры
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    RectangleShape rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    // Вывод информации
    vector<const Figure *> figures = {
        &triangle, &right_triangle, &isosceles_triangle, &equilateral_triangle,
        &quadrangle, &rectangle, &square, &parallelogram, &rhombus};

    for (const auto fig : figures)
    {
        print_info(fig);
    }

    // Задержка перед закрытием консоли
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}