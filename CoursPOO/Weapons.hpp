#pragma once
#include "Library.h"
#include "Stats.hpp"


class Weapons
{
	public:
	Weapons() = default;
	~Weapons() = default;
	void printWeapons() const;

	/// <summary>
	/// Here just to return the stats of the weapon.
	/// </summary>
	/// <returns></returns>
	Stats getStats() const;

	private:
	int m_id;
	std::string m_name;

	/// <summary>
	/// The stats of the weapon. We whill suppose here that the weapon only has 1 stat at a time.
	///  If we want to add more stats, we can use a vector of Stats.
	/// </summary>
	Stats m_stats;
	
};

