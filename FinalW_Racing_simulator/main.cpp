#define NOMINMAX

#include <iostream>
#include <clocale>
#include <windows.h>
#include <limits>
#include "RaceManager.h"

// Настройка русской кодировки для Windows
void setupConsole()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
}

int main()
{
    setupConsole();

    RaceManager manager;
    manager.start();

    // Задержка перед закрытием консоли
    std::cout << "\nНажмите Enter для выхода...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}