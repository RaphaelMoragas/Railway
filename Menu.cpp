#include "Menu.h"

Menu::Menu(Graph *railwayGraph) {
    this->railwayGraph = railwayGraph;
}

void Menu::start() {
    std::cout << railwayGraph->getNumVertex() << '\n';

}
