#include "../head/GeneralUser.h"
#include <string>
#include"../head/City.h"
#include"../head/Link.h"
#include "../head/WorldMap.h"



GeneralUser::GeneralUser(std::string n, CityPtr c, WorldMap& m) : User(n, c, m), map(m)
{acceptable_mode = {"road", "boat", "plane", "train"};}


float GeneralUser::evaluateCost(std::string mode, float dist)
{
    if (mode == "road") {
        return dist * 0.7;
    }
    else if (mode == "train") {
        return dist * 0.23;
    }
    else if (mode == "plane") {
        return dist * 0.10;
    }
    else if (mode == "boat") {
        return dist * 2.57;
    }
    else {
        return dist * (-1);
    }
}
