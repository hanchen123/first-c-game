#include "stdafx.h"
#include <iostream>

void pre_game(void);
int num = 1, w = 30, h = 20, type = 0;

int main(int argc, char argv[])
{
	pre_game();
	system("cls");

	Game newgame(num, w ,h, type);
	newgame.run();

	system("pause"); 
	return 0;
}

void pre_game(void)
{
	std::cout << "Game Start" << std::endl << "Your mission is to kill all the enemies. You can be a mage or a warrior:" << std::endl <<
		"Mage has 3 lives and use fireball(need 2 hits to kill the enemy)." << std::endl << "Warrior has 4 lives and use sword (only 1 hit can kill the enemy)." 
		<< std::endl << "'a, s, d, w' for moving, 'j' for attacking" << std::endl;
	std::cout << "Please enter the number of enemy:" << std::endl;
	std::cin >> num;
	std::cout << "Please enter the width of map (more than 10):" << std::endl;
	std::cin >> w;
	std::cout << "Please enter the height of map (more than 10):" << std::endl;
	std::cin >> h;
	std::cout << "Please select your class (0 for mage, 1 for warrior):" << std::endl;
	std::cin >> type;
}