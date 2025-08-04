#pragma once
#include "Race.h"
#include <string>
#include <map>

class RaceManager {
private:
    std::map<std::string, Transport*> allTransports;
    std::map<std::string, bool> registered;

    void createTransports();
    bool isGroundTransport(Transport* t) const;
    bool isAirTransport(Transport* t) const;
    int countAvailable(RaceType raceType) const;

public:
    RaceManager();
    ~RaceManager();

    void start();
    void resetRegistration();
    void showAvailableTransports(RaceType raceType) const;
    Transport* selectTransport(RaceType raceType);
};