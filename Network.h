#ifndef RAILNETWORK_NETWORK_H
#define RAILNETWORK_NETWORK_H

#pragma once
#include <string>

class Station; // Forward declaration

using std::string;

class Network {

private:
    Station* station_A; /// Estação de saída
    Station* station_B; /// Estação de destino
    int capacity;
    string service;

public:
    Network(Station* station_A = nullptr, Station* station_B = nullptr, int capacity = 0, const string& service = "")
            : station_A(station_A), station_B(station_B), capacity(capacity), service(service) {}

    void setStationA(Station* station_A);
    void setStationB(Station* station_B);
    void setCapacity(int capacity);
    void setService(const string& service);

    Station* getStationA();
    Station* getStationB() const;
    int getCapacity() const;
    string getService();

};



#endif //RAILNETWORK_NETWORK_H
