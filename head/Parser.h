#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>  // pour std::all_of

using LinkDescription = std::tuple<std::string, std::string, float, std::string>;

class Parser {
private:
    std::string filePath;

    // Fonction pour supprimer \r (retour chariot Windows)
    static std::string removeCarriageReturn(const std::string& s) {
        std::string result = s;
        result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());
        return result;
    }

    // Fonction pour supprimer espaces début/fin
    static std::string trim(const std::string& s) {
        size_t start = s.find_first_not_of(" \t");
        if (start == std::string::npos) return "";
        size_t end = s.find_last_not_of(" \t");
        return s.substr(start, end - start + 1);
    }

public:
    Parser(const std::string& path) : filePath(path) {}

    std::pair<std::vector<LinkDescription>, std::vector<std::string>> parse() {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir le fichier : " + filePath);
        }

        std::vector<LinkDescription> links;
        std::vector<std::string> cities;
        std::string line;
        std::string currentCity;

        while (std::getline(file, line)) {
            // Supprimer \r et trim
            line = trim(removeCarriageReturn(line));
            
            // Ignorer lignes vides
            if (line.empty()) continue;

            // Détecter ligne ville(se termine par
            if (!line.empty() && line.back() == ':') {
                currentCity = line.substr(0, line.size() - 1);
                // Nettoyer nom ville aussi
                currentCity = trim(currentCity);
                if (!currentCity.empty()) {
                    cities.push_back(currentCity);
                }
                continue;  // IMPORTANT : skip cette ligne
            }

            // Ligne de liaison (seulement si on a une ville courante)
            if (currentCity.empty()) {
                throw std::runtime_error("Liaison trouvée sans ville courante : " + line);
            }

            // Parser la liaison : DEST DISTANCE MODE
            std::stringstream ss(line);
            std::string dest, mode;
            float dist;

            ss >> dest >> dist >> mode;

            if (dest.empty() || mode.empty() || ss.fail()) {
                throw std::runtime_error("Format invalide : '" + line + "' (attendu: DEST DIST MODE)");
            }

            links.emplace_back(currentCity, dest, dist, mode);
        }

        if (cities.empty()) {
            throw std::runtime_error("Aucune ville trouvée dans le fichier");
        }

        return {links, cities};
    }
};