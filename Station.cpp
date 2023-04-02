#include "Station.h"


#include <string>
using std::string;

void Station::setName(string name)
{
    this->name = name;
}

void Station::setDistrict(string district)
{
    this->district = district;
}

void Station::setMunicipality(string municipality)
{
    this->municipality = municipality;
}

void Station::setTownship(string township)
{
    this->township = township;
}

void Station::setLine(std::string line)
{
    this->line = line;
}

string Station::getName()
{
    return name;
}

string Station::getDistrict()
{
    return district;
}

string Station::getMunicipality() const
{
    return municipality;
}

string Station::getTownship()
{
    return township;
}

string Station::getLine()
{
    return line;
}

