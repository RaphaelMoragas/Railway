#ifndef RAILNETWORK_MENU_H
#define RAILNETWORK_MENU_H


#include "data_structures/Graph.h"

class Menu {
public:
    Menu(Graph *railwayGraph);
    void start();


private:
    Graph *railwayGraph;

};

#endif //RAILNETWORK_MENU_H
