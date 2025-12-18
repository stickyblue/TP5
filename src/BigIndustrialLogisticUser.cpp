#include "../head/BigIndustrialLogisticUser.h"
#include <string>
#include"../head/City.h"
#include"../head/Link.h"
#include "../head/WorldMap.h"



BigIndustrialLogisticUser::BigIndustrialLogisticUser(std::string n, CityPtr c, WorldMap& m) : User(n, c, m), map(m)
{acceptable_mode = {"road"};}



float BigIndustrialLogisticUser::evaluateCost(std::string mode, float dist)
{
    if (mode == "road") {
        return dist / 42;
    }
    else if (mode == "train") {
        return dist / 52;
    }
    else if (mode == "plane") {
        return dist / 750;
    }
    else if (mode == "boat") {
        return dist / 27;
    }
    else {
        return dist * (9999999);
    }
}
