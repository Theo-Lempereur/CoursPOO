#include "Library.h"
#include "CsvReader.hpp"
#include "Players.hpp"


int main()
{
	//affiche les accents 

	setlocale(LC_ALL, "fr_FR");

	std::vector<std::string> testReader = CsvReader::ReadLine("PlayerTable.csv", 1);

	for (int i = 0; i < testReader.size(); i++)
	{
		std::cout << testReader[i] << std::endl;
	}

	Players player = Players::createPlayerWithFile("Jules");
	player.printPlayerInfo();

	return 0;
}
