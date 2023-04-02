//
// Created by rapha on 02/04/2023.
//

#ifndef RAILNETWORK_GRAFO_H
#define RAILNETWORK_GRAFO_H



#include "Station.h"
#include "Network.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

using std::string;
using std::unordered_map;
using std::vector;
using std::pair;


class Grafo {

public:

    int getMaxTrainsBetweenStations(const string& source, const string& target);
    vector<pair<string, string>> getStationsWithMaxTrains();
    vector<string> getTopKMunicipalitiesAndDistricts(int k);
    int getMaxTrainsArrivingAtStation(const string& station_name);

private:

    unordered_map<string, Station> stations;
    unordered_map<string, vector<Network>> station_edges;
    unordered_map<string, int> max_trains_to_station;

};

#endif //RAILNETWORK_GRAFO_H
