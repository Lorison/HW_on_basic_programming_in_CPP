#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits> // Для numeric_limits

using namespace std;

// Класс Calculator
class Calculator
{
private:
    double num1;
    double num2;

public:
    // Методы установки значений
    bool set_num1(double number)
    {
        if (number != 0)
        {
            num1 = number;
            return true;
        }
        return false;
    }

    bool set_num2(double number)
    {
        if (number != 0)
        {
            num2 = number;
            return true;
        }
        return false;
    }

    // Методы арифметических операций
    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }
};

int main()
{
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Calculator calc;
    double input;

    while (true)
    {
        // Ввод num1
        cout << "Введите num1: ";
        cin >> input;
        while (cin.fail() || !calc.set_num1(input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод или num1 равен 0! Повторите ввод num1: ";
            cin >> input;
        }

        // Ввод num2
        cout << "Введите num2: ";
        cin >> input;
        while (cin.fail() || !calc.set_num2(input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод или num2 равен 0! Повторите ввод num2: ";
            cin >> input;
        }

        // Вывод результатов
        cout << "num1 + num2 = " << calc.add() << endl;
        cout << "num1 - num2 = " << calc.subtract_1_2() << endl;
        cout << "num2 - num1 = " << calc.subtract_2_1() << endl;
        cout << "num1 * num2 = " << calc.multiply() << endl;
        cout << "num1 / num2 = " << calc.divide_1_2() << endl;
        cout << "num2 / num1 = " << calc.divide_2_1() << endl;
        cout << "-----------------------------------" << endl;
    }

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}