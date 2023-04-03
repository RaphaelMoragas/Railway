#ifndef RAILNETWORK_ALGORITHM_H
#define RAILNETWORK_ALGORITHM_H

#include "Data.h"

class Algorithm {
public:
    Algorithm(Data* data);

    int maxTrainsBetweenStations(const std::string &source, const std::string &dest);
    void mostTrainsRequired();

private:
    Data* data;
};

#endif //RAILNETWORK_ALGORITHM_H
