#include "Stats.hpp"



Stats::Stats(std::string name, int Value)
{
	m_name = name;
	m_Value = Value;
}

void Stats::printStats() const
{
	std::cout << m_name << ": " << m_Value << std::endl;
}