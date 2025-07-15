#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
#include <windows.h>
#include <limits>

using namespace std;

// Класс Address
class Address
{
private:
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;

public:
    // Конструктор с параметрами
    Address(string c, string s, int hn, int an)
        : city(c), street(s), houseNumber(hn), apartmentNumber(an) {}

    // Получение названия города (для сортировки)
    string get_city() const
    {
        return city;
    }

    // Формат вывода
    string get_output_address() const
    {
        return city + ", " + street + ", " + to_string(houseNumber) + ", " + to_string(apartmentNumber);
    }
};

// Сортировка пузырьком
void sort(Address *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j].get_city() > arr[j + 1].get_city())
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    ifstream fin("in_2.txt");
    ofstream fout("out_2.txt");

    if (!fin.is_open())
    {
        cerr << "Не удалось открыть файл in_2.txt!" << endl;
        return 1;
    }

    if (!fout.is_open())
    {
        cerr << "Не удалось открыть файл out_2.txt!" << endl;
        return 1;
    }

    int N;
    fin >> N;

    vector<Address> addresses; // Вектор для хранения адресов

    for (int i = 0; i < N; ++i)
    {
        string city, street;
        int house, apartment;

        fin.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(fin, city);
        getline(fin, street);
        fin >> house;
        fin >> apartment;

        addresses.push_back(Address(city, street, house, apartment));
    }

    // Сортировка по названию города
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (addresses[j].get_city() > addresses[j + 1].get_city())
            {
                swap(addresses[j], addresses[j + 1]);
            }
        }
    }

    // Запись результата в файл
    fout << N << endl;
    for (int i = 0; i < N; ++i)
    {
        fout << addresses[i].get_output_address() << endl;
    }

    cout << "Адреса успешно отсортированы и сохранены в out_2.txt" << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}