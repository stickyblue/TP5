#pragma once

#include"City.h"
#include"Link.h"

#include<unordered_set>
#include<unordered_map>
#include<vector>

using CityPtr = std::shared_ptr<City>;
using LinkPtr = std::shared_ptr<Link>;

class WorldMap{

    

    protected:

        std::unordered_map<std::string, CityPtr> cities; //Ensemble des villes de la carte


        //Adjacency List Representation of the map
        std::unordered_map<std::string,std::vector<LinkPtr>> adj; // Dictionnaire liant les villes et les liens sortant partant de cette ville. 

    private: 
        //Ajout d'une ville aux villes de la carte
        //@param: le nom de la ville à ajouter
        //@return: Un shared_ptr sur la ville créée.
        void addCity(const std::string& name);

        //Ajout d'un liens entre deux villes à la carte
        //@param: Le nom de la première ville a, le nom de la seconde ville b, la distance entre les deux villes dist et le mode de transport utilisable sur la liaison mode
        void addLink(const std::string& a, const std::string& b, float dist, const std::string& mode);

    public:

        
        // Constructeur en utilisant la classe Parser
        //@param: filePath - Chemin vers le fichier de nom fileName contenant la description texte de la carte
        WorldMap( const std::string& fileName, const std::string& filePath = "./");

        // Vérifie que la ville est présente sur la carte
        //@param: Le nom de la ville recherchée
        //@return: true si la ville est contenue dans la carte, false otherwise
        bool contains(const std::string& c) const;

        // Renvoie la liste des liens sortant d'une ville de la carte
        // @param: Le nom de la ville recherchée
        // @return: Un std::vector<LinkPtr> contenant la liste des liens sortant
        std::vector<LinkPtr> getExitLinkFrom(const std::string& c);

        // Renvoie la liste des villes diretement voisines d'une ville donnée accessible par un moyen de transport donné 
        //(Absence de précision <=> Toutes les villes voisines)
        // @param: Le nom de la ville recherchée, la liste des transports autorisés.
        // @return: Un std::vector<std::string> contenant la liste des noms des villes adjacentes accessibles
        std::vector<std::string> getNeighbourgsFromBy(const std::string& c, const std::vector<std::string> modes = {"train", "road", "boat", "plane"});


    //////////// UTILITIES /////////////

        // Affiche les villes contenues dans la carte et les liaisons adjacentes de chaque sommet
        void printWorldMap() const;

        // Return a reference to the set of cities of the map
        std::unordered_map<std::string, CityPtr> getCities() const{ return cities;}

        // Return the adjacency list representation of our maps:
        std::unordered_map<std::string,std::vector<LinkPtr>> getAdj() const  {return adj;}


};
