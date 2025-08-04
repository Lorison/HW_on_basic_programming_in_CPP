#include "Transport.h"
#include <iostream>

// === Transport ===
Transport::Transport(const std::string &n, double s)
    : name(n), speed(s) {}

std::string Transport::getName() const
{
    return name;
}

double Transport::getSpeed() const
{
    return speed;
}

// === GroundTransport ===
GroundTransport::GroundTransport(const std::string &n, double s, int mt,
                                 const std::vector<double> &rd)
    : Transport(n, s), moveTime(mt), restDurations(rd) {}

double GroundTransport::getRestDuration(int restCount) const
{
    if (restCount == 1 && restDurations.size() >= 1)
    {
        return restDurations[0];
    }
    else if (restCount == 2 && restDurations.size() >= 2)
    {
        return restDurations[1];
    }
    else if (restDurations.size() > 2)
    {
        return restDurations[2];
    }
    return 0.0;
}

double GroundTransport::calculateTime(double distance) const
{
    double totalTime = 0.0;
    double timeDriven = 0.0;
    int restCount = 0;

    double totalTimeDriving = distance / speed;

    while (timeDriven + moveTime < totalTimeDriving)
    {
        timeDriven += moveTime;
        restCount++;
        totalTime += getRestDuration(restCount);
    }

    return totalTimeDriving + totalTime;
}

// === AirTransport ===
AirTransport::AirTransport(const std::string &n, double s)
    : Transport(n, s) {}

double AirTransport::calculateTime(double distance) const
{
    double coeff = getReductionCoefficient(distance);
    double reducedDistance = distance * (1.0 - coeff);
    return reducedDistance / speed;
}

// === Конкретные реализации ===

// Наземные
Verblyud::Verblyud()
    : GroundTransport("Верблюд", 10, 30, {5, 8}) {}

VerblyudBistrohod::VerblyudBistrohod()
    : GroundTransport("Верблюд-Быстроход", 40, 10, {5, 6.5, 8}) {}

Kentavr::Kentavr()
    : GroundTransport("Кентавр", 15, 8, {2}) {}

BotnikiVezdehody::BotnikiVezdehody()
    : GroundTransport("Ботинки-Вездеходы", 6, 60, {10, 5}) {}

// Воздушные
KovorSamolyot::KovorSamolyot()
    : AirTransport("Ковер-Самолёт", 10) {}

double KovorSamolyot::getReductionCoefficient(double distance) const
{
    if (distance < 1000)
    {
        return 0.0;
    }
    else if (distance < 5000)
    {
        return 0.03;
    }
    else if (distance < 10000)
    {
        return 0.10;
    }
    else
    {
        return 0.05;
    }
}

Orel::Orel()
    : AirTransport("Орёл", 8) {}

double Orel::getReductionCoefficient(double distance) const
{
    (void)distance; // Параметр не используется — намеренно
    return 0.06;
}

Metla::Metla()
    : AirTransport("Метла", 20) {}

double Metla::getReductionCoefficient(double distance) const
{
    int thousands = static_cast<int>(distance / 1000);
    double coeff = 0.01 * thousands;
    if (coeff > 1.0)
        coeff = 1.0; // Максимум 100%
    return coeff;
}