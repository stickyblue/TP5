#pragma once


#include "City.h"
#include <memory>




using CityPtr = std::shared_ptr<City>;


struct Link{


    // Pointeur sur la ville de départ
    CityPtr from;


    // Pointeur sur la ville d'arrivée
    CityPtr to;
   
    // Distance à parcourir
    float distance;
   
    // Mode de transport autorisé
    std::string mode;


    // Constructor
    Link(CityPtr f, CityPtr t, float dd, std::string m): from(f), to(t), distance(dd), mode(m){};


    // Destructor
    ~Link() = default;


};
