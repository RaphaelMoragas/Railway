#include "Menu.h"

Menu::Menu(Graph *railwayGraph): railwayGraph(railwayGraph), metrics(railwayGraph) {
    principal();
}

void Menu::menu() {
    std::cout << "\n=================================================================================================\n";
    std::cout << " \t\t\t\t\t\t\t\t\t\t\t\tMENU \n";
    std::cout << "=================================================================================================\n\n";

    std::cout << "Selecione uma das seguintes opções (0-6):" << std::endl;
    std::cout << "1- Número máximo de trens que podem viajar simultaneamente entre duas estações específicas" << std::endl;
    std::cout << "2- Pares de estação com a maior quantidade de trens" << std::endl;
    std::cout << "3- Top k municípios e distritos em relação às necessidades de transporte" << std::endl;
    std::cout << "4- Número máximo de trens que podem chegar simultaneamente a uma estação" << std::endl;
    std::cout << "0- Sair" << "\n";
}

void Menu::principal() {
    do {
        menu();
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 0:
                quit = true;
                break;
            case 1:
                submenu1();
                break;
            case 2:
                submenu2();
                break;
            case 3:
                submenu3();
                break;
            case 4:
                submenu4();
                break;

            default:
                std::cout << "Opção inválida. Favor selecionar uma opção válida";
                break;
        }
    } while (!quit);
}

void Menu::submenu1() {
    std::string nameA, nameB;
    Vertex *s, *t;
    int maxFlow;

    while (true) {
        std::cout << "Escolha a estação de origem:" << std::endl;
        getline(std::cin, nameA);
        s = railwayGraph->findVertex(nameA);
        if (s == nullptr) {
            std::cout << "Estação inválida. Tente novamente" << "\n\n";
            continue;
        }

        std::cout << "Escolha a estação de destino:" << std::endl;
        getline(std::cin, nameB);
        t = railwayGraph->findVertex(nameB);
        if (t == nullptr) {
            std::cout << "Estação inválida. Tente novamente" << "\n\n";
            continue;
        }

        maxFlow = metrics.findMaxFlow(s, t);
        std::cout << "\nO número máximo de trens será: ";
        std::cout << maxFlow << std::endl;

        break;
    }

}

void Menu::submenu2() {
    std::list<std::pair<Vertex*, Vertex*>> pairs = metrics.pairsMaxFlow();

    for (auto pair : pairs) {
        std::cout << pair.first->getName() << ' ' << pair.second->getName() << std::endl;
    }

}


void Menu::submenu3() {
    int k;
    std::cout << "Informe o valor de k:" << std::endl;
    std::cin >> k;
    std::cin.ignore();

    std::list<std::pair<std::string, std::string>> topK = metrics.topKMunicipalitiesAndDistricts(k);

    std::cout << "Top " << k << " municípios e distritos em relação às necessidades de transporte:" << std::endl;
    for (const auto &pair : topK) {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }
}

void Menu::submenu4() {
    std::string station;
    std::cout << "Informe o nome da estação:" << std::endl;
    std::cin.ignore();
    getline(std::cin, station);

    int maxTrains = metrics.maxTrainsArrivingAtStation(station);

    std::cout << "O número máximo de trens que podem chegar simultaneamente à estação " << station << " é " << maxTrains << std::endl;
}