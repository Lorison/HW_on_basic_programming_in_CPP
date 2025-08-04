#pragma once
#include <vector>
#include "Transport.h"

enum class RaceType
{
    GROUND,
    AIR,
    MIXED
};

class Race
{
private:
    RaceType type;
    double distance;
    std::vector<Transport *> participants;

public:
    Race(RaceType type, double distance);

    void addParticipant(Transport *t);
    void run() const;

    RaceType getType() const;
    double getDistance() const;
    size_t getParticipantCount() const;
};