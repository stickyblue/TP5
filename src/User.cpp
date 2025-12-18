#include "../head/WorldMap.h"
#include "../head/Parser.h"
#include "../head/User.h"
#include <memory>
#include <iostream>
#include <queue>


User::User(std::string name, CityPtr city, WorldMap& map) : name(name), city(city), map(map) 
{acceptable_mode = {};}

std::vector<std::string> User::getAcessibleFromBy(const std::string& c, const std::vector<std::string> modes) const
{
    std::vector<std::string> modesAcceptables = modes;
    if (modes.empty())
    {  
        std::cout << "Using acceptable modes" << std::endl;
        modesAcceptables = this->acceptable_mode;
    }

    std::deque<std::string> villeavoir = {c};

    std::vector<std::string> villevisitable;

    while (!villeavoir.empty())
    {  
        for (const auto& ville : map.getNeighbourgsFromBy(villeavoir.front(), modesAcceptables))
        {
            if (std::find(villevisitable.begin(), villevisitable.end(), ville) == villevisitable.end())
            {
                villeavoir.push_back(ville);
                villevisitable.push_back(ville);
            }
        }
        villeavoir.pop_front();
    }
    return villevisitable;
}

