#pragma once
#include<string>


struct City{

    // Name of the city
    std::string name;


    // Constructor
    City(const std::string& s): name(s) {};


    // Default Destructor
    ~City() = default;
};
