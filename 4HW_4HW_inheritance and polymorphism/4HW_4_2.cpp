#include <iostream>
#include <clocale>
#include <windows.h>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// ========== Базовый класс Figure ==========
class Figure
{
protected:
    const char *name;

public:
    Figure(const char *name) : name(name) {}
    virtual ~Figure() = default;
    virtual void print() const = 0;
    const char *get_name() const { return name; }
};

// ========== Треугольник ==========
class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print() const override
    {
        cout << get_name() << ":\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

// ========== Прямоугольный треугольник ==========
class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник";
    }
};

// ========== Равнобедренный треугольник ==========
class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A)
    {
        name = "Равнобедренный треугольник";
    }
};

// ========== Равносторонний треугольник ==========
class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
};

// ========== Четырёхугольник ==========
class Quadrangle : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure("Четырёхугольник"), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print() const override
    {
        cout << get_name() << ":\n";
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

// ========== Параллелограмм ==========
class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name = "Параллелограмм";
    }
};

// ========== Прямоугольник ==========
class RectangleShape : public Parallelogram
{
public:
    RectangleShape(double a, double b)
        : Parallelogram(a, b, 90, 90)
    {
        name = "Прямоугольник";
    }
};

// ========== Квадрат ==========
class Square : public RectangleShape
{
public:
    Square(double side)
        : RectangleShape(side, side)
    {
        name = "Квадрат";
    }
};

// ========== Ромб ==========
class Rhombus : public Parallelogram
{
public:
    Rhombus(double side, double A, double B)
        : Parallelogram(side, side, A, B)
    {
        name = "Ромб";
    }
};

// ========== Функция вывода информации ==========
void print_info(Figure *figure)
{
    figure->print();
}

// ========== Основная функция ==========
int main()
{
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
    vector<Figure *> figures = {
        &triangle, &right_triangle, &isosceles_triangle, &equilateral_triangle,
        &quadrangle, &rectangle, &square, &parallelogram, &rhombus};

    for (auto fig : figures)
    {
        print_info(fig);
    }

    // Задержка перед закрытием консоли
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}