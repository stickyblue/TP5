#include "../head/EcoUser.h"
#include <string>
#include"../head/City.h"
#include"../head/Link.h"
#include "../head/WorldMap.h"
#include <iostream>


EcoUser::EcoUser(std::string n, CityPtr c, WorldMap& m) : User(n, c, m), map(m)
{acceptable_mode  = {"road", "train"};}




float EcoUser::evaluateCost(std::string mode, float dist)
{
    if (mode == "road") {
        return dist * 180;
    }
    else if (mode == "train") {
        return dist * 2;
    }
    else if (mode == "plane") {
        return dist * 270;
    }
    else if (mode == "boat") {
        return dist * 220;
    }
    else {
        return dist * (99999999);
    }
}
