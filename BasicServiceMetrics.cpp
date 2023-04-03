#include "data_structures/Graph.h"
#include "data_structures/VertexEdge.h"
#include "data_structures/MutablePriorityQueue.h"

#include "BasicServiceMetrics.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <limits>

using namespace std;

BasicServiceMetrics::BasicServiceMetrics(Graph *railwayGraph): railwayGraph(railwayGraph) {}

int BasicServiceMetrics::findMaxFlow(Vertex *source, Vertex *target) {
    return railwayGraph->edmondsKarp(source,target);
}

int BasicServiceMetrics::maxTrainsBetweenStations(const std::string &source, const std::string &dest) {
    Vertex *sourceVertex = railwayGraph->getVertex(source);
    Vertex *destVertex = railwayGraph->getVertex(dest);
    return findMaxFlow(sourceVertex, destVertex);
}

std::list<std::pair<Vertex*, Vertex*>> BasicServiceMetrics::pairsMaxFlow() {
    std::list<std::pair<Vertex*, Vertex*>> pairs;
    int max = -1;
    int flow;
    auto vertexSet = railwayGraph->getVertexSet();

    for (int i = 0; i < vertexSet.size(); i++) {
        for (int j = i + 1; j < vertexSet.size(); j++) {
            flow = railwayGraph->edmondsKarp(vertexSet[i], vertexSet[j]);
            if (max < flow) {
                pairs.clear();
                max = flow;
                pairs.push_back(std::make_pair(vertexSet[i],vertexSet[j]));
            } else if (max == flow) {
                pairs.push_back(std::make_pair(vertexSet[i],vertexSet[j]));
            }
        }
    }

    return pairs;
}

std::list<std::pair<std::string, std::string>> BasicServiceMetrics::topKMunicipalitiesAndDistricts(int k) {
    std::map<std::pair<std::string, std::string>, int> edgeUsage;

    for (const auto &vertexPair : railwayGraph->getVertexSet()) {
        for (const auto &edge : vertexPair->getEdges()) {
            std::string source = vertexPair->getName();
            std::string dest = edge->getDest()->getName();
            int capacity = edge->getCapacity();
            edgeUsage[std::make_pair(source, dest)] += capacity;
        }
    }

    using EdgePair = std::pair<std::pair<std::string, std::string>, int>;
    auto comp = [](const EdgePair &a, const EdgePair &b) { return a.second > b.second; };
    std::priority_queue<EdgePair, std::vector<EdgePair>, decltype(comp)> pq(comp);

    for (const auto &edgeUsagePair : edgeUsage) {
        pq.push(edgeUsagePair);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    std::list<std::pair<std::string, std::string>> result;
    while (!pq.empty()) {
        result.push_front(pq.top().first);
        pq.pop();
    }

    return result;
}

int BasicServiceMetrics::maxTrainsArrivingAtStation(const std::string &station) {
    Vertex *stationVertex = railwayGraph->getVertex(station);
    if (stationVertex == nullptr) {
        return 0;
    }

    int maxTrains = 0;
    for (const auto &edge : stationVertex->getEdges()) {
        maxTrains += edge->getCapacity();
    }

    return maxTrains;
}