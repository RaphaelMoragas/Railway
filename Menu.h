#ifndef RAILNETWORK_MENU_H
#define RAILNETWORK_MENU_H

#include "data_structures/Graph.h"
#include "BasicServiceMetrics.h"

#include <iostream>

class Menu {
public:
    Menu(Graph *railwayGraph);

private:
    Graph *railwayGraph;
    BasicServiceMetrics metrics;
    int option;
    bool quit = false;

    void menu();
    void principal();
    void submenu1();
    void submenu2();
    void submenu3();
    void submenu4();


};

#endif //RAILNETWORK_MENU_H
