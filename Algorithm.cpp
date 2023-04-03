#include "data_structures/Graph.h"
#include "data_structures/VertexEdge.h"
#include "data_structures/MutablePriorityQueue.h"
#include "Network.h"
#include "Station.h"

#include "Algorithm.h"
#include <queue>
#include <limits>

using namespace std;

Algorithm::Algorithm(Data* data) : data(data) {}

bool bfs(Graph *residualGraph, vector<int> &parent, int src, int dest_id) {
    vector<bool> visited(parent.size(), false);

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge *e : residualGraph->findVertex(u)->getAdj()) {
            int v = e->getDest()->getId();
            if (!visited[v] && e->getFlow() > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;

                if (v == dest_id) {
                    return true;
                }
            }
        }
    }

    return false;
}

int fordFulkerson(Graph *graph, const string &src, const string &dest) {
    int dest_id = graph->findVertex(dest)->getId();
    Graph *residualGraph = new Graph(graph->getNumVertex());

    for (Vertex *v : graph->getVertexSet()) {
        for (Edge *e : v->getAdj()) {
            residualGraph->addEdge(v->getId(), e->getDest()->getId(), e->getWeight());
        }
    }

    vector<int> parentNode(residualGraph->getNumVertex(), -1);
    int max_flow = 0;

    while (bfs(residualGraph, parentNode, graph->findVertex(src)->getId(), dest_id)) {
        int path_flow = INT_MAX;

        for (int v = dest_id; v != graph->findVertex(src)->getId(); v = parentNode[v]) {
            int u = parentNode[v];
            path_flow = min(path_flow, static_cast<int>(residualGraph->findVertex(u)->getAdj()[0]->getWeight() - residualGraph->findVertex(u)->getAdj()[0]->getFlow()));
        }

        for (int v = dest_id; v != graph->findVertex(src)->getId(); v = parentNode[v]) {
            int u = parentNode[v];
            Edge *edge = residualGraph->findVertex(u)->getAdj()[0];
            edge->setFlow(edge->getFlow() + path_flow);
            Edge *reverse_edge = residualGraph->findVertex(v)->getAdj()[0];
            reverse_edge->setFlow(reverse_edge->getFlow() - path_flow);
        }

        max_flow += path_flow;
    }

    delete residualGraph;
    return max_flow;
}

int Algorithm::maxTrainsBetweenStations(const string &source, const string &dest) {
    return fordFulkerson(data->getRailwayGraph(), source, dest);
}

void Algorithm::mostTrainsRequired() {
    int maxTrains = 0;
    string stationA, stationB;
    Graph *graph = data->getRailwayGraph();

    for (Vertex *source : graph->getVertexSet()) {
        for (Vertex *dest : graph->getVertexSet()) {
            if (source->getId() != dest->getId()) {
                int trains = maxTrainsBetweenStations(source->getName(), dest->getName());
                if (trains > maxTrains) {
                    maxTrains = trains;
                    stationA = source->getName();
                    stationB = dest->getName();
                }
            }
        }
    }

    std::cout << "The most trains required between stations are: " << maxTrains << std::endl;
    std::cout << "These stations are: " << stationA << " and " << stationB << std::endl;
}
