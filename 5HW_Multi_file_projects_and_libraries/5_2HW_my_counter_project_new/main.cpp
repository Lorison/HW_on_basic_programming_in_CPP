#define NOMINMAX

#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>
#include "Counter.h"

using namespace std;

int main()
{
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    string userChoice;
    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> userChoice;

    int initialValue = 1;

    if (userChoice == "да" || userChoice == "Да" || userChoice == "ДА")
    {
        cout << "Введите начальное значение счётчика: ";
        while (!(cin >> initialValue))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод! Введите число: ";
        }
    }

    Counter counter(initialValue);

    char command;
    cout << "Введите команду ('+', '-', '=' или 'x'): ";
    while (cin >> command && command != 'x')
    {
        switch (command)
        {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            cout << counter.getValue() << endl;
            break;
        default:
            cout << "Неизвестная команда! Используйте '+', '-', '=', 'x': ";
            break;
        }
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
    }

    cout << "До свидания!" << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}