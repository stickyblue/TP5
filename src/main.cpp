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
#include <vector>


int main()
{
    WorldMap maWorldMap("worldmap.txt");

    std::cout << "Test constructeur à partir du fichier txt fourni" << std::endl;
    std::cout << "\n Test printMap" << std::endl;
    maWorldMap.printWorldMap();
    std::cout << "Test contains" << std::endl;
    std::cout << "contains B ? " << maWorldMap.contains("B") << std::endl;
    std::cout << "Test getExitLinkFrom" << std::endl;
    std::cout << "\n getExitLinkFrom B: " << std::endl;
    for (const auto& ld : maWorldMap.getExitLinkFrom("B")) {
        std::cout << "Lien vers: " << ld->to->name << std::endl;
    }
    std::cout << "getExitLinkFromBy B, road: " << std::endl;
    for (const auto& ld : maWorldMap.getNeighbourgsFromBy("B", {"road"})) {
        std::cout << "Lien vers: " << ld << std::endl;
    }

    std::cout << "\n test getAcessibleFromBy" << std::endl;


    GeneralUser user1("User1", maWorldMap.getCities()["E"], maWorldMap);
    std::cout << "getAcessibleFromBy E, GenaralUser,  road and train: " << std::endl;
    std::vector<std::string> accessible_mode_list_1 = user1.getAcessibleFromBy("E", {"road", "train"});

    for (const auto& city_name : accessible_mode_list_1) {
        std::cout << "Ville accessible: " << city_name << std::endl;
    }

    EcoUser user2("User2", maWorldMap.getCities()["E"], maWorldMap);
    std::cout << "getAcessibleFromBy E, EcoUser, no arguments given: " << std::endl;
    std::vector<std::string> accessible_mode_list_2 = user2.getAcessibleFromBy("E");

    for (const auto& city_name : accessible_mode_list_2) {
        std::cout << "Ville accessible: " << city_name << std::endl;
    }

    BigIndustrialLogisticUser user3("User3", maWorldMap.getCities()["E"], maWorldMap);
    std::cout << "getAcessibleFromBy E, BigIndustrialLogisticUser, no arguments given: " << std::endl;
    std::vector<std::string> accessible_mode_list_3 = user3.getAcessibleFromBy("E");
    for (const auto& city_name : accessible_mode_list_3) {
        std::cout << "Ville accessible: " << city_name << std::endl;
    }
    







    return 0;
}
