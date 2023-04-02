#include "Data.h"
#include "Menu.h"

int main()
{
    Data data("stations.csv","network.csv");
    Menu menu = Menu(data.getRailwayGraph());
    menu.start();
    return 0;
}
