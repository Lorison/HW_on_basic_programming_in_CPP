#include <iostream>
#include <string>
#include <windows.h>
#include <limits> // Для задержки

struct Account
{
    int accountNumber;
    std::string ownerName;
    double balance;
};

void updateBalance(Account &account, double newBalance)
{
    account.balance = newBalance;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    Account myAccount;

    std::cout << "Введите номер счёта: ";
    std::cin >> myAccount.accountNumber;

    std::cin.ignore(); // Очистка буфера после ввода числа

    std::cout << "Введите имя владельца: ";
    std::getline(std::cin, myAccount.ownerName);

    std::cout << "Введите баланс: ";
    std::cin >> myAccount.balance;

    double newBalance;
    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    updateBalance(myAccount, newBalance);

    std::cout << "Ваш счёт: "
              << myAccount.ownerName << ", "
              << myAccount.accountNumber << ", "
              << myAccount.balance << std::endl;

    // Задержка перед закрытием
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
