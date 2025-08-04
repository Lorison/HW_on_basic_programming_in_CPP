#include "Race.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

Race::Race(RaceType t, double d) : type(t), distance(d) {}

void Race::addParticipant(Transport *t)
{
    participants.push_back(t);
}

void Race::run() const
{
    std::cout << "\n=== РЕЗУЛЬТАТЫ ГОНКИ ===\n";

    std::vector<std::pair<double, std::string>> results;
    for (const auto &participant : participants)
    {
        double time = participant->calculateTime(distance);
        results.emplace_back(time, participant->getName());
    }

    std::sort(results.begin(), results.end());

    for (size_t i = 0; i < results.size(); ++i)
    {
        std::cout << i + 1 << ". " << results[i].second
                  << ". Время: " << std::fixed << std::setprecision(2)
                  << results[i].first << " ч\n";
    }
}

RaceType Race::getType() const
{
    return type;
}

double Race::getDistance() const
{
    return distance;
}

size_t Race::getParticipantCount() const
{
    return participants.size();
}