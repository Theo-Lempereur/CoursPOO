#pragma once
#include "Library.h"


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
};



