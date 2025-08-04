#pragma once
#include <string>
#include <vector>

// Абстрактный базовый класс
class Transport
{
protected:
    std::string name;
    double speed; // км/ч

public:
    Transport(const std::string &name, double speed);
    virtual ~Transport() = default;

    std::string getName() const;
    double getSpeed() const;

    // Чисто виртуальная функция: расчёт времени прохождения дистанции
    virtual double calculateTime(double distance) const = 0;
};

// === НАЗЕМНЫЙ ТРАНСПОРТ ===
class GroundTransport : public Transport
{
protected:
    int moveTime;                      // время движения до отдыха (в часах)
    std::vector<double> restDurations; // длительности отдыха в часах

    // Возвращает длительность отдыха по номеру остановки (1, 2, 3...)
    double getRestDuration(int restCount) const;

public:
    GroundTransport(const std::string &name, double speed, int moveTime,
                    const std::vector<double> &restDurations);
    double calculateTime(double distance) const override;
};

// === ВОЗДУШНЫЙ ТРАНСПОРТ ===
class AirTransport : public Transport
{
protected:
    // Чисто виртуальная функция: коэффициент сокращения дистанции
    virtual double getReductionCoefficient(double distance) const = 0;

public:
    AirTransport(const std::string &name, double speed);
    double calculateTime(double distance) const override;
};

// === КОНКРЕТНЫЕ КЛАССЫ ТРАНСПОРТА ===

// Наземные
class Verblyud : public GroundTransport
{
public:
    Verblyud();
};

class VerblyudBistrohod : public GroundTransport
{
public:
    VerblyudBistrohod();
};

class Kentavr : public GroundTransport
{
public:
    Kentavr();
};

class BotnikiVezdehody : public GroundTransport
{
public:
    BotnikiVezdehody();
};

// Воздушные
class KovorSamolyot : public AirTransport
{
public:
    KovorSamolyot();

protected:
    double getReductionCoefficient(double distance) const override;
};

class Orel : public AirTransport
{
public:
    Orel();

protected:
    double getReductionCoefficient(double distance) const override;
};

class Metla : public AirTransport
{
public:
    Metla();

protected:
    double getReductionCoefficient(double distance) const override;
};