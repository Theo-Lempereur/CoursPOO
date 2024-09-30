#pragma once
#include "Library.h"
#include "Stats.hpp"
#include "Weapons.hpp"



class Players
{
	public:
	Players() = default;
	~Players() = default;
	Players(int id, std::string name, std::vector<Stats> stats, std::vector<Weapons> weapons);

	/// <summary>
	/// this frunction is used to create a player with the given name and id. The static keyword is used to make sure that the function is called on the class itself and not on the object of the class
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	static Players createPlayerWithFile(std::string name);

	void printPlayerInfo() const;

	/// <summary>
	/// Search the value of the stat with the given name. The function returns the value of the stat if the stat is found. If the stat is not found, the function returns -1
	/// </summary>
	/// <param name="statName"></param>
	/// <returns></returns>
	int getIntStatValue(std::string statName) const;

	private:
	int m_id;

	std::string m_name;

	/// <summary>
	/// represents the stats of the player. Using a vector to store the stats of the player and the Stats class to store the individual stats. 
	/// Another way to store the stats would be to creat multiple variables for each stat but that would be a bad idea as the number of stats can increase and it would be difficult to manage them.
	/// Read the Stats class to understand how the stats are stored.
	/// </summary>
	std::vector<Stats> m_stats;

	/// <summary>
	/// represents the weapons of the player. Using the same logic as the stats to store the weapons of the player
	/// </summary>
	std::vector<Weapons> m_weapons;
};



