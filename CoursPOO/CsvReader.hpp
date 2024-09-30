#pragma once
#include "Library.h"

/// <summary>
/// Little library to read csv files. And understand the reading of the csv file with fstream. 
/// </summary>
class CsvReader
{
public:
	CsvReader() = default;
	~CsvReader() = default;

	
	static std::vector<std::string> ReadColumn(std::string chemin_fichier, int colonne);
	static std::vector<std::string> ReadLine(const std::string chemin_fichier, int ligne); 
};

