#ifndef RAILNETWORK_BASICSERVICEMETRICS_H
#define RAILNETWORK_BASICSERVICEMETRICS_H

#include <string>
#include <list>
#include <map>
#include "data_structures/Graph.h"

class BasicServiceMetrics {
private:
    Graph *railwayGraph;

    int findMaxFlow(Vertex *source, Vertex *target);

public:
    explicit BasicServiceMetrics(Graph *railwayGraph);

    int maxTrainsBetweenStations(const std::string &source, const std::string &dest);
    std::list<std::pair<Vertex*, Vertex*>> pairsMaxFlow();
    std::list<std::pair<std::string, std::string>> topKMunicipalitiesAndDistricts(int k);
    int maxTrainsArrivingAtStation(const std::string &station);
};
#endif //RAILNETWORK_BASICSERVICEMETRICS_H
