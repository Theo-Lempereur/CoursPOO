#include "Weapons.hpp"


void Weapons::printWeapons() const{
	std::cout << m_name << ": ";
	m_stats.printStats();
}

Stats Weapons::getStats() const
{
	return m_stats;
}

