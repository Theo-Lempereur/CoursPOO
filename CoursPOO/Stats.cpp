#include "Stats.hpp"



Stats::Stats(std::string name, int defaultValue)
{
	m_name = name;
	m_defaultValue = defaultValue;
	m_type = TypeStats::Agility;
}

void Stats::printStats() const
{
	std::cout << m_name << ": " << m_defaultValue << std::endl;
}