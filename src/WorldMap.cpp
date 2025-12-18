#include "../head/WorldMap.h"
#include "../head/Parser.h"
#include <memory>
#include <iostream>
#include <cassert>
//
using CityPtr = std::shared_ptr<City>;
using LinkPtr = std::shared_ptr<Link>;

// Ajoute une ville de nom name à la liste des cartes
void WorldMap::addCity(const std::string& name) {

    CityPtr newCity = std::make_shared<City>(name);
    cities[name] = newCity;

}

// Ajoute un lien entre la ville a et la ville b
void WorldMap::addLink(const std::string& a, const std::string& b, float dist, const std::string& mode) {
    addCity(a);
    addCity(b);
    assert(mode == "train" || mode == "road" || mode == "plane" || mode == "boat");
    LinkPtr newLink = std::make_shared<Link>(cities[a], cities[b], dist, mode);

    adj[a].push_back(newLink);

}

//Constructeur de carte depuis un fichier
WorldMap::WorldMap(const std::string& fileName, const std::string& filePath) {
    std::string fullPath = filePath.empty() ? fileName : (filePath + "/" + fileName);

    // Objet Parser permettant d'extraire les donnéees nécessaires à la construction d'un graphe décrit dans un fichier texte stocké à Path
    Parser parser(fullPath);

    //LinkDesc est un tuple <string from, string to, int distance, string mode>
    //cityNames est un Vector contenant les noms des villes à instancier dans le graphe
    // VOIR "utils/Parser.h" pour plus de détail.
    auto [linksDesc, cityNames] = parser.parse();
    

    // Ajout des villes (optionnel si addLink réalise déjà l'opération d'ajout des villes).
    for (const auto& name : cityNames) {
            
            addCity(name);

    }

    // Ajout des liaisons à la liste d'adjacence
    for (const auto& ld : linksDesc) {
        addLink(std::get<0>(ld), std::get<1>(ld), std::get<2>(ld), std::get<3>(ld));
    }
}

bool WorldMap::contains(const std::string& c) const
{
    if (cities.find(c) == cities.end())
        return false;
    return true;
}

std::vector<LinkPtr> WorldMap::getExitLinkFrom(const std::string& c)
{
    return adj[c];
}

std::vector<std::string> WorldMap::getNeighbourgsFromBy(const std::string& c, const std::vector<std::string> modes)
{
    std::vector<std::string> neighbours;
    
    for (const auto& j : modes)
    {
        for (const auto& ld : getExitLinkFrom(c))
        {
            if (ld->mode == j)
            {
                neighbours.push_back(ld->to->name);
            }
        }
    }

    return neighbours;
}


/////////////////////////////// NE PAS MODIFIER ////////////////////////////////

void WorldMap::printWorldMap() const {
    std::cout << "=== Villes ===\n";
    for (const auto& [name, ptr] : cities) {
        std::cout << name << "\n";
    }

    std::cout << "\n=== Liens ===\n";
    for (const auto& [from, linksList] : adj) {
        for (const auto& l : linksList) {
            std::cout << l->from->name << " --> " 
                      << l->to->name << " | "
                      << l->distance << " km | "
                      << l->mode << "\n";
        }
    }
}


