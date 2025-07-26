#define NOMINMAX

#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits> // Для numeric_limits
#include "math_functions.h"

using namespace std;

int main()
{
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double num1, num2;
    int choice;

    cout << "Введите первое число: ";
    cin >> num1;

    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> choice;

    double result = 0;

    switch (choice)
    {
    case 1:
        result = add(num1, num2);
        cout << num1 << " + " << num2 << " = " << result << endl;
        break;
    case 2:
        result = subtract(num1, num2);
        cout << num1 << " - " << num2 << " = " << result << endl;
        break;
    case 3:
        result = multiply(num1, num2);
        cout << num1 << " * " << num2 << " = " << result << endl;
        break;
    case 4:
        result = divide(num1, num2);
        if (num2 == 0)
        {
            cout << "Ошибка: деление на ноль!" << endl;
        }
        else
        {
            cout << num1 << " / " << num2 << " = " << result << endl;
        }
        break;
    case 5:
        result = power(num1, num2);
        cout << num1 << " в степени " << num2 << " = " << result << endl;
        break;
    default:
        cout << "Неверный выбор операции." << endl;
    }

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}