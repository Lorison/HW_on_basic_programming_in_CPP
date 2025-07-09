#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

enum class Month {
    None = 0,
    Январь,
    Февраль,
    Март,
    Апрель,
    Май,
    Июнь,
    Июль,
    Август,
    Сентябрь,
    Октябрь,
    Ноябрь,
    Декабрь
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int number;
    do {
        cout << "Введите номер месяца: ";
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неправильный номер!\n";
            continue;
        }

        if (number == 0) {
            cout << "До свидания\n";
            break;
        }

        if (number < 1 || number > 12) {
            cout << "Неправильный номер!\n";
            continue;
        }

        Month month = static_cast<Month>(number);

        switch (month) {
            case Month::Январь:   cout << "Январь\n";   break;
            case Month::Февраль:  cout << "Февраль\n";  break;
            case Month::Март:     cout << "Март\n";     break;
            case Month::Апрель:   cout << "Апрель\n";   break;
            case Month::Май:      cout << "Май\n";      break;
            case Month::Июнь:     cout << "Июнь\n";     break;
            case Month::Июль:     cout << "Июль\n";     break;
            case Month::Август:   cout << "Август\n";   break;
            case Month::Сентябрь: cout << "Сентябрь\n"; break;
            case Month::Октябрь:  cout << "Октябрь\n";  break;
            case Month::Ноябрь:   cout << "Ноябрь\n";   break;
            case Month::Декабрь:  cout << "Декабрь\n";  break;
            default:              cout << "Ошибка\n";   break;
        }

    } while (true);

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}