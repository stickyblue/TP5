#include <iostream>
#include <string>
#include "../head/City.h"
#include "../head/Link.h"
#include "../head/Parser.h"
#include "../head/WorldMap.h"
#include "../head/User.h"
#include "../head/GeneralUser.h"
#include "../head/EcoUser.h"
#include "../head/BigIndustrialLogisticUser.h"


int main()
{
    WorldMap maWorldMap("worldmap.txt");

    std::cout << "Test constructeur à partir du fichier txt fourni" << std::endl;
    std::cout << "Test printMap" << std::endl;
    maWorldMap.printWorldMap();
    std::cout << "Test contains" << std::endl;
    std::cout << "contains B ? " << maWorldMap.contains("B") << std::endl;
    std::cout << "Test getExitLinkFrom" << std::endl;
    std::cout << "getExitLinkFrom B: " << std::endl;
    for (const auto& ld : maWorldMap.getExitLinkFrom("B")) {
        std::cout << "Lien vers: " << ld->to->name << std::endl;
    }
    std::cout << "getExitLinkFromBy B, road: " << std::endl;
    for (const auto& ld : maWorldMap.getNeighbourgsFromBy("B", {"road"})) {
        std::cout << "Lien vers: " << ld << std::endl;
    }

    std::cout << "test getAcessibleFromBy" << std::endl;


    GeneralUser user1("User1", maWorldMap.getCities()["E"], maWorldMap);
    std::cout << "getAcessibleFromBy E, road and train: " << std::endl;
    for (const auto& city_name : user1.getAcessibleFromBy("E", {"road", "train"})) {
        std::cout << "Ville accessible: " << city_name << std::endl;
    }

    EcoUser user2("User2", maWorldMap.getCities()["E"], maWorldMap);
    std::cout << "getAcessibleFromBy E, no arguments given: " << std::endl;
    for (const auto& city_name : user1.getAcessibleFromBy("E", {})) {
        std::cout << "Ville accessible: " << city_name << std::endl;
    }







    return 0;
}
