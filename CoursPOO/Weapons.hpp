#pragma once
#include "Library.h"
#include "Stats.hpp"

class Weapons
{
	public:
	Weapons() = default;
	~Weapons() = default;
	void printWeapons() const;

	private:
	int m_id;
	std::string m_name;
	Stats m_stats;
};

