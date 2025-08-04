#include "RaceManager.h"
#include "Race.h"
#include <iostream>
#include <limits>

void RaceManager::createTransports()
{
    allTransports["Верблюд"] = new Verblyud();
    allTransports["Верблюд-Быстроход"] = new VerblyudBistrohod();
    allTransports["Кентавр"] = new Kentavr();
    allTransports["Ботинки-Вездеходы"] = new BotnikiVezdehody();
    allTransports["Ковер-Самолёт"] = new KovorSamolyot();
    allTransports["Орёл"] = new Orel();
    allTransports["Метла"] = new Metla();

    for (const auto &pair : allTransports)
    {
        registered[pair.first] = false;
    }
}

RaceManager::RaceManager()
{
    createTransports();
}

RaceManager::~RaceManager()
{
    for (auto &pair : allTransports)
    {
        delete pair.second;
    }
}

bool RaceManager::isGroundTransport(Transport *t) const
{
    return dynamic_cast<GroundTransport *>(t) != nullptr;
}

bool RaceManager::isAirTransport(Transport *t) const
{
    return dynamic_cast<AirTransport *>(t) != nullptr;
}

void RaceManager::resetRegistration()
{
    for (auto &pair : registered)
    {
        pair.second = false;
    }
}

void RaceManager::showAvailableTransports(RaceType raceType) const
{
    std::cout << "\nДоступные транспортные средства:\n";
    int index = 1;
    for (const auto &pair : allTransports)
    {
        const std::string &name = pair.first;
        Transport *t = pair.second;

        bool canUse = false;
        if (raceType == RaceType::GROUND && isGroundTransport(t))
        {
            canUse = true;
        }
        else if (raceType == RaceType::AIR && isAirTransport(t))
        {
            canUse = true;
        }
        else if (raceType == RaceType::MIXED)
        {
            canUse = true;
        }

        if (canUse && !registered.at(name))
        {
            std::cout << index++ << ". " << name << "\n";
        }
    }
    if (index == 1)
    {
        std::cout << "Нет доступных ТС для выбора.\n";
    }
}

int RaceManager::countAvailable(RaceType raceType) const
{
    int count = 0;
    for (const auto &pair : allTransports)
    {
        const std::string &name = pair.first;
        Transport *t = pair.second;

        bool canUse = false;
        if (raceType == RaceType::GROUND && isGroundTransport(t))
        {
            canUse = true;
        }
        else if (raceType == RaceType::AIR && isAirTransport(t))
        {
            canUse = true;
        }
        else if (raceType == RaceType::MIXED)
        {
            canUse = true;
        }

        if (canUse && !registered.at(name))
        {
            count++;
        }
    }
    return count;
}

Transport *RaceManager::selectTransport(RaceType raceType)
{
    showAvailableTransports(raceType);

    if (countAvailable(raceType) == 0)
    {
        std::cout << "Нет доступных транспортных средств.\n";
        return nullptr;
    }

    int choice;
    std::cout << "Введите номер ТС (0 для отмены): ";

    while (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Введите число: ";
    }

    if (choice == 0)
        return nullptr;

    int index = 1;
    for (const auto &pair : allTransports)
    {
        const std::string &name = pair.first;
        Transport *t = pair.second;

        bool canUse = false;
        if (raceType == RaceType::GROUND && isGroundTransport(t))
        {
            canUse = true;
        }
        else if (raceType == RaceType::AIR && isAirTransport(t))
        {
            canUse = true;
        }
        else if (raceType == RaceType::MIXED)
        {
            canUse = true;
        }

        if (canUse && !registered.at(name))
        {
            if (index == choice)
            {
                registered[name] = true;
                std::cout << name << " успешно зарегистрирован!\n";
                return t;
            }
            index++;
        }
    }

    std::cout << "Неверный выбор.\n";
    return nullptr;
}

void RaceManager::start()
{
    while (true)
    {
        std::cout << "\n=== Добро пожаловать в Гоночный Симулятор! ===\n";
        std::cout << "1. Гонка для наземного транспорта\n";
        std::cout << "2. Гонка для воздушного транспорта\n";
        std::cout << "3. Гонка для наземного и воздушного транспорта\n";
        std::cout << "Выберите тип гонки: ";

        int raceChoice;
        while (!(std::cin >> raceChoice) || raceChoice < 1 || raceChoice > 3)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите число от 1 до 3: ";
        }

        RaceType raceType = static_cast<RaceType>(raceChoice - 1);

        double distance;
        std::cout << "Укажите длину дистанции (должна быть положительной): ";
        while (!(std::cin >> distance) || distance <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите положительное число: ";
        }

        Race race(raceType, distance);
        resetRegistration();

        std::cout << "\nГонка: ";
        if (raceType == RaceType::GROUND)
        {
            std::cout << "Наземного транспорта";
        }
        else if (raceType == RaceType::AIR)
        {
            std::cout << "Воздушного транспорта";
        }
        else
        {
            std::cout << "Смешанная";
        }
        std::cout << ". Дистанция: " << distance << " км\n";

        std::cout << "Зарегистрированные ТС:\n";

        while (true)
        {
            std::cout << "\n1. Зарегистрировать транспорт\n";
            std::cout << "2. Начать гонку\n";
            std::cout << "Выберите действие: ";

            int action;
            while (!(std::cin >> action) || (action != 1 && action != 2))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Введите 1 или 2: ";
            }

            if (action == 1)
            {
                Transport *t = selectTransport(raceType);
                if (t)
                {
                    race.addParticipant(t);
                }
            }
            else if (action == 2)
            {
                if (race.getParticipantCount() < 2)
                {
                    std::cout << "Должно быть зарегистрировано хотя бы 2 ТС!\n";
                    continue;
                }
                break;
            }
        }

        race.run();

        std::cout << "\n1. Провести ещё одну гонку\n";
        std::cout << "2. Выйти\n";
        std::cout << "Выберите действие: ";

        int finalAction;
        while (!(std::cin >> finalAction) || (finalAction != 1 && finalAction != 2))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите 1 или 2: ";
        }

        if (finalAction != 1)
        {
            break;
        }
    }
}