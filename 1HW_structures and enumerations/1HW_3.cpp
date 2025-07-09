#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>
#include <limits>

using namespace std;

// Определение структуры Address
struct Address {
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
    int postalCode;
};

// Функция для вывода информации об адресе
void printAddress(const Address& address) {
    cout << "Город: " << address.city << "\n";
    cout << "Улица: " << address.street << "\n";
    cout << "Номер дома: " << address.houseNumber << "\n";
    cout << "Номер квартиры: " << address.apartmentNumber << "\n";
    cout << "Индекс: " << address.postalCode << "\n\n";
}

int main() {
    // Настройка русской кодировки
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Создание первого экземпляра структуры
    Address address1;
    address1.city = "Москва";
    address1.street = "Арбат";
    address1.houseNumber = 12;
    address1.apartmentNumber = 8;
    address1.postalCode = 123456;

    // Создание второго экземпляра структуры
    Address address2;
    address2.city = "Ижевск";
    address2.street = "Пушкина";
    address2.houseNumber = 59;
    address2.apartmentNumber = 143;
    address2.postalCode = 953769;

    // Вызов функции вывода
    printAddress(address1);
    printAddress(address2);

    // Задержка перед закрытием консоли
    cout << "Нажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}