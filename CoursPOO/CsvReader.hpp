#pragma once
#include "Library.h"
//Librairy qui permet de lire un fichier CSV et de l'utiliser pour le programme (donc de plusieur manières différentes)
class CsvReader
{
public:
	CsvReader() = default;
	~CsvReader() = default;
	static std::vector<std::string> ReadColumn(std::string chemin_fichier, int colonne);
	static std::vector<std::string> ReadLine(const std::string chemin_fichier, int ligne); //Permet de lire une ligne du fichier et stock les informations dans un tableau de string
	

};

