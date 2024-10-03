#include "Library.h"
#include "CsvReader.hpp"
#include "Players.hpp"
#include "Stats.hpp"
#include "Weapons.hpp"

using namespace std;

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
	cout << endl;
	Players player2 = Players::createPlayerWithFile("Remy");
	player2.printPlayerInfo();
	cout << endl;

	player.attack(player2);

	player2.printPlayerInfo();

	
	vector<Stats> statsList;
	
	vector<Weapons> weaponsList;

	Players players = Players();
	SorcierSylvestre sorcier = SorcierSylvestre(1, "Soso", statsList, weaponsList);
	ExpertExplosifs expert = ExpertExplosifs(2, "Boober", statsList, weaponsList);



	return 0;
}
