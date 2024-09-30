#include "Players.hpp"
#include "Library.h"
#include "CsvReader.hpp"

Players::Players(int id, std::string name, std::vector<Stats> stats, std::vector<Weapons> weapons) : m_id(id), m_name(name), m_stats(stats), m_weapons(weapons) 
{}

Players Players::createPlayerWithFile(std::string name) {

	std::vector<Stats> stats;
	std::vector<Weapons> weapons;

	//read the column of names from the csv file
	std::vector<std::string> column = CsvReader::ReadColumn("PlayerTable.csv", 0);

	std::vector<std::string> infoPerso;
	std::vector<std::string> NameInfo = CsvReader::ReadLine("PlayerTable.csv", 0);

	int id = 1;
	//search for the name in the vector
	for (int i = 0; i < column.size(); i++) {
		if (column[i] == name) {
			//if the name is found, read the stats and weapons from the csv file
			infoPerso = CsvReader::ReadLine("PlayerTable.csv", i);
			id = i;
		}
	}

	//create the stats vector
	for (int i = 1; i < NameInfo.size(); i++) {
		Stats stat = Stats(NameInfo[i], std::stoi(infoPerso[i]));
		stats.push_back(stat);
	}

	//weapons instantiation is not implemented yet but you can do it the same way as stats

	//create the player
	Players player = Players(id, name, stats, weapons);

	return player;
}

void Players::printPlayerInfo() const{
	std::cout << "Player name: " << m_name << std::endl;

	for (int i = 0; i < m_stats.size(); i++) {
		m_stats[i].printStats();
	}

	if (m_weapons.empty())
	{
		std::cout << "No weapons" << std::endl;
	}
	else
	{
		for (int i = 0; i < m_weapons.size(); i++) {
			m_weapons[i].printWeapons();
		}
	}
}

int Players::getIntStatValue(std::string statName) const {
	for (int i = 0; i < m_stats.size(); i++) {
		if (m_stats[i].m_name == statName) {
			return m_stats[i].m_Value;
		}
	}
}



