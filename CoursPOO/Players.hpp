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

	/// <summary>
	/// the const keyword is used to make sure that the function does not modify the object
	/// </summary>
	void printPlayerInfo() const;

	private:

	int m_id;
	std::string m_name;

	/// <summary>
	/// represents the stats of the player. Using a vector to store the stats of the player and the Stats class to store the individual stats. 
	/// Another way to store the stats would be to creat multiple variables for each stat but that would be a bad idea as the number of stats can increase and it would be difficult to manage them
	/// </summary>
	std::vector<Stats> m_stats;

	/// <summary>
	/// represents the weapons of the player. Using the same logic as the stats to store the weapons of the player
	/// </summary>
	std::vector<Weapons> m_weapons;
};



