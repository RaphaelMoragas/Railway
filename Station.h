#ifndef RAILNETWORK_STATION_H
#define RAILNETWORK_STATION_H


#include "Network.h"

#include <string>

using std::string;

class Station {

private:
    string name;
    string district;
    string municipality;
    string township;
    string line;

public:
    void setName(string name);
    void setDistrict(string district);
    void setMunicipality(string municipality);
    void setTownship(string township);
    void setLine(string line);

    string getName();
    string getDistrict();
    string getMunicipality() const;
    string getTownship();
    string getLine();
};

#endif //RAILNETWORK_STATION_H
