//
// Created by rapha on 02/04/2023.
//

#ifndef RAILNETWORK_DATA_H
#define RAILNETWORK_DATA_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "data_structures/Graph.h"


class Data {
public:
    Data(std::string stations, std::string network);
    Graph *getRailwayGraph();

private:
    Graph railwayGraph;

};


#endif //RAILNETWORK_DATA_H
