#include <iostream>

#include "Data.h"
#include "Menu.h"

int main()
{
    Data data("stations.csv","network.csv");
    Menu menu(data.getRailwayGraph());
    return 0;
}

