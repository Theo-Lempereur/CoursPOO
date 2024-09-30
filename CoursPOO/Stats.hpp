#pragma once
#include "Library.h"


/// <summary>
/// Enum for the type of stats, this will prevent to have the possibilility to add a wrong type of stat
/// </summary>
enum TypeStats
{
	Health,
	Mana,
	Strenght,
	Agility,
	Intelligence,
	Armor
};

struct Stats
{
	Stats(std::string name, int defaultValue);
	~Stats() = default;
	void printStats() const;

	/// <summary>
	/// this is the name of the stat (basically not usefull but can be usefull for the debug)
	/// </summary>
	std::string m_name;

	/// <summary>
	/// the default value of the stat
	/// </summary>
	int m_Value;

	/// <summary>
	/// the type of the stat
	/// </summary>
	TypeStats m_type;
};



