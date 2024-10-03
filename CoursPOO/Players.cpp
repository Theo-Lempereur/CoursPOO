#include "Players.hpp"
#include "Library.h"
#include "CsvReader.hpp"

Players::Players()
{
	m_id = 0;
	m_name = "Default";
	m_persoType = other;
}

Players::~Players()
{
}

Players::Players(int id, std::string name, std::vector<Stats> stats, std::vector<Weapons> weapons) : m_id(id), m_name(name), m_stats(stats), m_weapons(weapons)
{
	m_persoType = other;
}

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

/// <summary>
/// Here is a function that return the value of a stat from the stats vector
/// </summary>
/// <param name="statName">: Name of the stats you want the value</param>
/// <returns></returns>
int Players::getIntStatValue(std::string statName) const {
	for (int i = 0; i < m_stats.size(); i++) {
		//we can search by directly comparing the name of the stat with the statName because stats are a struct
		if (m_stats[i].m_name == statName) {
			return m_stats[i].m_Value;
		}
	}
	return -1;
}

void Players::takeDamage(int damage) {
	int health = getIntStatValue("Health");
	int defense = getIntStatValue("Armor");
	int damageTaken = damage - defense;
	if (damageTaken < 0) {
		damageTaken = 0;
	}
	std::cout << "Damage taken: " << damageTaken << std::endl;
	health -= damageTaken;
	for (int i = 0; i < m_stats.size(); i++) {
		if (m_stats[i].m_name == "Health") {
			m_stats[i].m_Value = health;
		}
	}
}
//BE CARFULL TO IMPLEMENT TAKE DAMAGE FUNCTION BEFOR ATTACK FUNCTION

void Players::attack(Players& target) {
	int damage = getIntStatValue("Strenght");
	
	//add 10 dammage if the target is a sorcer in enum type
	if (target.m_persoType == Sorcerer) {
		damage += 10;
	}

	target.takeDamage(damage);
}

void Players::launchSpell()  
{
	std::cout << "Spell launched" << std::endl;
}

/// <summary>
/// Add a weapon to the player and update the stats by adding the stats of the weapon
/// </summary>
/// <param name="weapon">: The weapon to add</param>
void Players::addWeapon(Weapons weapon) 
{
	//add the weapon to the vector
	m_weapons.push_back(weapon);
	//get the stats of the weapon
	Stats weaponStats = weapon.getStats();
	
	//add the stats of the weapon to the player stats
	for (int i = 0; i < m_stats.size(); i++)
	{
		if (weaponStats.m_name == m_stats[i].m_name)
		{
			m_stats[i].m_Value += weaponStats.m_Value;
		}
	}

	
}

/// <summary>
/// Add a weapon to the player and update the stats by substracting the stats of the weapon
/// </summary>
/// <param name="weaponName"></param>
void Players::unequipWeapon(std::string weaponName)
{
	//search for the weapon in the vector
	for (int i = 0; i < m_weapons.size(); i++)
	{
		//if the weapon is found
		if (m_weapons[i].getStats().m_name == weaponName)
		{
			//substract the stats of the weapon from the player stats
			Stats weaponStats = m_weapons[i].getStats();
			for (int j = 0; j < m_stats.size(); j++)
			{
				if (weaponStats.m_name == m_stats[j].m_name)
				{
					m_stats[j].m_Value -= weaponStats.m_Value;
				}
			}
			//remove the weapon from the vector
			m_weapons.erase(m_weapons.begin() + i);
		}
	}
}



SorcierSylvestre::SorcierSylvestre(int id, std::string name, std::vector<Stats> stats, std::vector<Weapons> weapons) : Players(id, name, stats, weapons) 
{
	m_sylvanAffinity = 0;
	m_persoType = Sorcerer;
}

void SorcierSylvestre::launchSpell() 
{
	std::cout << "Sylvan spell launched" << std::endl;
	m_sylvanAffinity += 10;
	std::cout << "Sylvan affinity: " << m_sylvanAffinity << std::endl;
}


ExpertExplosifs::ExpertExplosifs(int id, std::string name, std::vector<Stats> stats, std::vector<Weapons> weapons) : Players(id, name, stats, weapons)
{
	m_explosifCount = 10;
	m_persoType = Bomber;
}


void ExpertExplosifs::launchSpell() 
{
	std::cout << "Explosive spell launched" << std::endl;
	m_explosifCount -= 1;
	std::cout << "Explosive count: " << m_explosifCount << std::endl;
}
