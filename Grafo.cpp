#include "Grafo.h"
#include <limits>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include<iostream>


using std::priority_queue;
using std::numeric_limits;
using std::vector;
using std::string;
using std::pair;
using std::greater;
using std::set;
using std::map;


int Grafo::getMaxTrainsBetweenStations(const string& source, const string& target) {
    if (stations.find(source) == stations.end() || stations.find(target) == stations.end()) {
        std::cout << "Error: Uma ou ambas as estações especificadas não existem." << std::endl;
        return -1;
    }

    map<string, int> max_trains;
    for (const auto& station : stations) {
        max_trains[station.first] = numeric_limits<int>::min();
    }
    max_trains[source] = numeric_limits<int>::max();

    set<string> unvisited;
    for (const auto& station : stations) {
        unvisited.insert(station.first);
    }

    while (!unvisited.empty()) {
        string current_station;
        int max_capacity = numeric_limits<int>::min();
        for (const auto& station : unvisited) {
            if (max_trains[station] > max_capacity) {
                max_capacity = max_trains[station];
                current_station = station;
            }
        }

        if (current_station == target) {
            break;
        }

        unvisited.erase(current_station);

        for (const auto& network : station_edges[current_station]) {
            string next_station = network.getStationB()->getName();
            int capacity = std::min(max_trains[current_station], network.getCapacity());
            max_trains[next_station] = std::max(max_trains[next_station], capacity);
        }
    }

    return max_trains[target];
}

vector<pair<string, string>> Grafo::getStationsWithMaxTrains() {
    vector<pair<string, string>> station_pairs;
    int max_trains = numeric_limits<int>::min();

    for (const auto& src : stations) {
        for (const auto& dest : stations) {
            if (src.first != dest.first) {
                int trains = getMaxTrainsBetweenStations(src.first, dest.first);
                if (trains > max_trains) {
                    max_trains = trains;
                    station_pairs.clear();
                    station_pairs.push_back({src.first, dest.first});
                } else if (trains == max_trains) {
                    station_pairs.push_back({src.first, dest.first});
                }
            }
        }
    }

    return station_pairs;
}


vector<string> Grafo::getTopKMunicipalitiesAndDistricts(int k) {
    map<string, int> municipality_counts;
    for (const auto& station : stations) {
        municipality_counts[station.second.getMunicipality()]++;
    }

    vector<pair<int, string>> count_municipality_pairs;
    for (const auto& entry : municipality_counts) {
        count_municipality_pairs.push_back({entry.second, entry.first});
    }
    std::sort(count_municipality_pairs.rbegin(), count_municipality_pairs.rend());

    vector<string> top_municipalities;
    for (int i = 0; i < k && i < count_municipality_pairs.size(); ++i) {
        top_municipalities.push_back(count_municipality_pairs[i].second);
    }

    return top_municipalities;
}

int Grafo::getMaxTrainsArrivingAtStation(const string& station_name) {
    if (stations.find(station_name) == stations.end()) {
        std::cout << "Error: A estação especificada não existe." << std::endl;
        return -1;
    }

    int max_trains = 0;
    for (const auto& entry : station_edges) {
        for (const auto& network : entry.second) {
            if (network.getStationB()->getName() == station_name) {
                max_trains = std::max(max_trains, network.getCapacity());
            }
        }
    }

    return max_trains;
}
