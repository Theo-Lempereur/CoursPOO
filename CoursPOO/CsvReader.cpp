#include "CsvReader.hpp"
#include "library.h"

using namespace std;


vector<string> CsvReader::ReadLine(const string chemin_fichier, int ligne) {
    std::vector<std::string> ligne_values;
    std::ifstream fichier(chemin_fichier);
    if (fichier.is_open()) {
        std::string l;
        int count = 0;
        while (std::getline(fichier, l) && count < ligne) {
            ++count;
        }
        if (count == ligne) {
            std::stringstream ss(l);
            std::string element;
            while (std::getline(ss, element, ';')) {
                ligne_values.push_back(element);
            }
        }
        else {
            std::cout << "La ligne specifiee n'existe pas dans le fichier." << std::endl;
        }
        fichier.close();
    }
    else {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
    }
    return ligne_values;
}

vector<string> CsvReader::ReadColumn(string chemin_fichier, int colonne) {
    std::vector<std::string> colonne_values;
    std::ifstream fichier(chemin_fichier);
    if (fichier.is_open()) {
        std::string l;
        while (std::getline(fichier, l)) { // On lit chaque ligne
            std::stringstream ss(l); // On transforme la ligne en flux
            std::string element; // On stocke chaque élément de la ligne
            int count = 0;
            while (std::getline(ss, element, ';') && count < colonne) { // On lit chaque élément de la ligne
                ++count;
            }
            if (count == colonne) {
                colonne_values.push_back(element);
            }
            else {
                std::cout << "La colonne specifiee n'existe pas dans le fichier." << std::endl;
            }
        }
        fichier.close();
    }
    else {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
    }
    return colonne_values;
}