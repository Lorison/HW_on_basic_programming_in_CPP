#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
#include <windows.h>
#include <limits>
using namespace std;

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

    string get_output_address() const
    {
        return city + ", " + street + ", " + to_string(houseNumber) + ", " + to_string(apartmentNumber);
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin.is_open())
    {
        cerr << "Не удалось открыть файл in.txt!" << endl;
        return 1;
    }

    if (!fout.is_open())
    {
        cerr << "Не удалось открыть файл out.txt!" << endl;
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

        addresses.push_back(Address(city, street, house, apartment)); // Добавляем в вектор
    }

    fout << N << endl;

    // Выводим в обратном порядке
    for (int i = N - 1; i >= 0; --i)
    {
        fout << addresses[i].get_output_address() << endl;
    }

    cout << "Адреса успешно обработаны и сохранены в out.txt" << endl;

    // Задержка перед закрытием консоли
    cout << "\nНажмите Enter для выхода...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}