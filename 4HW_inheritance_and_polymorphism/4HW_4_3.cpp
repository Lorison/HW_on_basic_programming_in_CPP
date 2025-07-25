#define NOMINMAX
#include <iostream>
#include <clocale>
#include <windows.h>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

// Константа для сравнения с плавающей точкой (вместо магического 1e-6)
const double EPSILON = 1e-6;

// ========== Пространство имён для геометрических фигур ==========
namespace Geometry {

    // Базовый класс Figure
    class Figure {
    protected:
        const char* name;
        int sides_count;

        virtual void print_sides() const {}
        virtual void print_angles() const {}

    public:
        // Основной конструктор
        Figure(const char* name, int sides) : name(name), sides_count(sides) {}

        // Конструктор по умолчанию
        Figure() : name("Фигура"), sides_count(0) {}

        virtual ~Figure() = default;

        virtual bool check() const {
            return sides_count == 0;
        }

        virtual void print_info() const {
            cout << name << ":\n";
            cout << (check() ? "Правильная\n" : "Неправильная\n");
            cout << "Количество сторон: " << sides_count << "\n";
        }
    };

    // Треугольник
    class Triangle : public Figure {
    protected:
        double a, b, c;
        double A, B, C;

        void print_sides() const override {
            cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        }

        void print_angles() const override {
            cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
        }

    public:
        Triangle(double a, double b, double c, double A, double B, double C)
            : Figure("Треугольник", 3), a(a), b(b), c(c), A(A), B(B), C(C) {}

        bool check() const override {
            return abs(A + B + C - 180.0) < EPSILON;
        }

        void print_info() const override {
            Figure::print_info();
            print_sides();
            print_angles();
            cout << endl;
        }
    };

    // Прямоугольный треугольник
    class RightTriangle : public Triangle {
    public:
        RightTriangle(double a, double b, double c, double A, double B)
            : Triangle(a, b, c, A, B, 90) {
            name = "Прямоугольный треугольник";
        }

        bool check() const override {
            return Triangle::check() && abs(C - 90.0) < EPSILON;
        }
    };

    // Равнобедренный треугольник
    class IsoscelesTriangle : public Triangle {
    public:
        IsoscelesTriangle(double a, double b, double A, double B)
            : Triangle(a, b, a, A, B, A) {
            name = "Равнобедренный треугольник";
        }

        bool check() const override {
            return Triangle::check() &&
                   abs(a - c) < EPSILON &&
                   abs(A - C) < EPSILON;
        }
    };

    // Равносторонний треугольник
    class EquilateralTriangle : public Triangle {
    public:
        EquilateralTriangle(double side)
            : Triangle(side, side, side, 60, 60, 60) {
            name = "Равносторонний треугольник";
        }

        bool check() const override {
            return Triangle::check() &&
                   abs(a - b) < EPSILON &&
                   abs(b - c) < EPSILON;
        }
    };

    // Четырёхугольник
    class Quadrangle : public Figure {
    protected:
        double a, b, c, d;
        double A, B, C, D;

        void print_sides() const override {
            cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        }

        void print_angles() const override {
            cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
        }

    public:
        Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D)
            : Figure("Четырёхугольник", 4),
              a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

        bool check() const override {
            return abs(A + B + C + D - 360.0) < EPSILON;
        }

        void print_info() const override {
            Figure::print_info();
            print_sides();
            print_angles();
            cout << endl;
        }
    };

    // Параллелограмм
    class Parallelogram : public Quadrangle {
    public:
        Parallelogram(double a, double b, double A, double B)
            : Quadrangle(a, b, a, b, A, B, A, B) {
            name = "Параллелограмм";
        }

        bool check() const override {
            return Quadrangle::check() &&
                   abs(a - c) < EPSILON && abs(b - d) < EPSILON &&
                   abs(A - C) < EPSILON && abs(B - D) < EPSILON;
        }
    };

    // Прямоугольник 
    class RectangleShape : public Parallelogram {
    public:
        RectangleShape(double a, double b)
            : Parallelogram(a, b, 90, 90) {
            name = "Прямоугольник";
        }

        bool check() const override {
            return Parallelogram::check() &&
                   abs(A - 90.0) < EPSILON &&
                   abs(B - 90.0) < EPSILON;
        }
    };

    // Квадрат
    class Square : public RectangleShape {
    public:
        Square(double side)
            : RectangleShape(side, side) {
            name = "Квадрат";
        }

        bool check() const override {
            return RectangleShape::check() &&
                   abs(a - b) < EPSILON;
        }
    };

    // Ромб
    class Rhombus : public Parallelogram {
    public:
        Rhombus(double side, double A, double B)
            : Parallelogram(side, side, A, B) {
            name = "Ромб";
        }

        bool check() const override {
            return Parallelogram::check() &&
                   abs(a - b) < EPSILON;
        }
    };
}

// ========== main функция ==========
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    using namespace Geometry;

    // Создаем фигуры
    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 40);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    RectangleShape rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    // Вывод информации
    vector<Figure*> figures = {
        &figure,
        &triangle,
        &right_triangle,
        &isosceles_triangle,
        &equilateral_triangle,

        &quadrangle,
        &rectangle,
        &square,
        &parallelogram,
        &rhombus
    };

    for (auto fig : figures) {
        fig->print_info();
    }

    // Задержка перед закрытием консоли
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}