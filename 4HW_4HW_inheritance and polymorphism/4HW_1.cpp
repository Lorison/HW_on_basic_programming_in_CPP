#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Базовый класс "Фигура"
class Figure {
protected:
    int sides_count;
    const char* name;

    // Защищённый конструктор для инициализации дочерних классов
    Figure(int sides, const char* figureName) : sides_count(sides), name(figureName) {}

public:
    // Публичный конструктор по умолчанию
    Figure() : sides_count(0), name("Фигура") {}

    // Метод для получения количества сторон
    int get_sides_count() const {
        return sides_count;
    }

    // Метод для получения названия фигуры
    const char* get_name() const {
        return name;
    }
};

// Производный класс "Треугольник"
class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {}
};

// Производный класс "Четырёхугольник"
class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {}
};

int main() {
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Количество сторон:" << endl;

    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    // Вывод информации о фигурах
    cout << figure.get_name() << ": " << figure.get_sides_count() << endl;
    cout << triangle.get_name() << ": " << triangle.get_sides_count() << endl;
    cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}