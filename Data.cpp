#include "Data.h"

Data::Data(std::string stations, std::string network) {
    std::ifstream stationsFile;
    std::ifstream networkFile;
    std::string line;
    int id = 1;

    stationsFile.open(stations, std::ifstream::in);
    networkFile.open(network, std::ifstream::in);

    if (stationsFile.is_open() && networkFile.is_open()) {
        getline(stationsFile, line);
        getline(networkFile, line);

        while (!stationsFile.eof()) {
            getline(stationsFile, line);

            if (line == "") {
                continue;
            }

            std::stringstream sstream(line);
            std::vector<std::string> tokens;
            std::string token;

            while (getline(sstream, token, ',')) {
                size_t first_quote = token.find('"');
                if (first_quote != std::string::npos) {
                    size_t second_quote = token.find('"', first_quote + 1);
                    while (second_quote == std::string::npos) {
                        std::string next_part;
                        getline(sstream, next_part, ',');
                        token += "," + next_part;
                        second_quote = next_part.find('"');
                    }
                    token = token.substr(first_quote + 1, second_quote - first_quote - 1);
                }
                tokens.push_back(token);
            }

            if (railwayGraph.addVertex(id, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4])) {
                id++;
            }
        }

        while (!networkFile.eof()) {
            getline(networkFile, line);

            if (line == "") {
                continue;
            }

            std::stringstream sstream(line);
            std::string nameA, nameB, tmpCapacity, service;
            int capacity;

            getline(sstream, nameA, ',');
            getline(sstream, nameB, ',');
            getline(sstream, tmpCapacity, ',');
            capacity = std::stoi(tmpCapacity);
            getline(sstream, service);

            Vertex *vSource = railwayGraph.findVertex(nameA);
            Vertex *vDest = railwayGraph.findVertex(nameB);

            if (vSource != nullptr && vDest != nullptr) {
                vSource->addEdge(vDest, service, capacity);
            }
        }
    } else {
        std::cout << "Arquivo não pode ser aberto" << std::endl;
    }
}

Graph *Data::getRailwayGraph() {
    return &railwayGraph;
}


