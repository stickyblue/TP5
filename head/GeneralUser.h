#pragma once

#include <string>
#include"City.h"
#include"Link.h"
#include "WorldMap.h"
#include "User.h"

#include<unordered_set>
#include<unordered_map>
#include<vector>

using CityPtr = std::shared_ptr<City>;
using LinkPtr = std::shared_ptr<Link>;

// Class describing a General User, 
// A General User as no preference about its transportation mode
// An General User evaluate the cost of its travel by considering the cost per kilometer of its transportation mode.
class GeneralUser: public User{

    protected:

        std::string name;

        CityPtr city;

        WorldMap& map;

     
        // Fonction évaluant le cout d'une mode de transport en fonction de la distance.
        float evaluateCost(std::string mode, float dist);

        // Liste des modes transports que l'utilisateur souhaite utiliser en priorité.
        std::vector<std::string> acceptable_mode = {"road", "boat", "plane", "train"};

    public:

        // Constructor of User
        // @param n the user name, c a shared_ptr onto a City, m a reference onto a WorldMap
        // Initialize the acceptable_mode to ["road","train","plane","boat"]
        GeneralUser(std::string n, CityPtr c, WorldMap& m);

        // // Renvoie la liste des villes de la carte acessibles en partant d'une ville donnée en utilisant un moyen de transport parmis une liste de transport donné en entrée.
        // // Si aucun mode de transport n'est donnée en entrée, considérer que l'utilisateur utilise ses modes de transport acceptables.
        // // @param: Le nom de la ville de départ sur la ville de départ c, la liste des transports autorisés modes
        // // @return: Un std::vector<std::string> contenant les nom des villes villes accessibles.
        // std::vector<std::string> getAcessibleFromBy(const std::string& c, const std::vector<std::string> modes = {}) const;


        // // Renvoie le chemin le plus court et le cout total du trajet pour l'utilisateur pour accéder à une ville donnée depuis une ville de départ donnée.
        // // Si aucun mode de transport n'est donnée en entrée, considérer que l'utilisateur souhaite utiliser ses modes de transport acceptables.
        // // Si aucune ville de départ n'est donnée en entrée, considérer que lutilisateur souhaite partir de la ville où il habite.
        // // @param: le nom de la ville de départ from_c, de la ville d'arrivée to_c, la liste des transports autorisés modes
        // // @return: Un tuple contenant un Vector contenant les Links à emprunter dans l'ordre de passage pour partir de la ville de départ et arriver à la ville d'arrivée à un cout minimal, et le cout total associé au trajet.
        // std::tuple<std::vector<LinkPtr>,float> getAccessibleFromBy(const std::string& to_c, const std::string& from_c = "", const std::vector<std::string> modes = {} ) const;

};
