#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Класс Counter
class Counter
{
private:
    int value; // Приватное поле

public:
    // Конструктор по умолчанию: значение = 1
    Counter()
    {
        value = 1;
    }

    // Конструктор с начальным значением
    Counter(int initialValue)
    {
        value = initialValue;
    }

    // Увеличение счётчика на 1
    void increment()
    {
        value++;
    }

    // Уменьшение счётчика на 1
    void decrement()
    {
        value--;
    }

    // Получение текущего значения
    int getValue() const
    {
        return value;
    }
};

int main()
{
    // Настройка русской кодировки для Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Переменная для ответа
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

    // Создание счётчика
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