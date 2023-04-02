#include "Network.h"
#include "Station.h"

void Network::setStationA(Station* station_A)
{
    this->station_A = station_A;
}

void Network::setStationB(Station* station_B)
{
    this->station_B = station_B;
}

void Network::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void Network::setService(const string& service)
{
    this->service = service;
}

Station* Network::getStationA()
{
    return station_A;
}

Station* Network::getStationB() const
{
    return station_B;
}

int Network::getCapacity() const
{
    return capacity;
}

string Network::getService()
{
    return service;
}
