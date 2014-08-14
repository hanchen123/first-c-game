#include "Game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>

#define Game_Speed 50 //20 frame per second

Game::Game(int enemies, int x, int y, int type)
{
	enemy_num = enemies;
	screenx = x;
	screeny = y;
	player_class = type;
	over = 0;
}


Game::~Game(void)
{
}

bool Game::run(void)
{
	newdraw = new Draw(screenx, screeny);
	newlogic = new Logic(newdraw, screenx, screeny);

	newdraw->create_background(tile_route, ' ');
	newdraw->create_background(tile_wall, '#');
	newdraw->create_sprite(sprite_player, 1);
	newdraw->create_sprite(sprite_enemy, 2);
	newdraw->create_sprite(sprite_fireball, '*');
	newdraw->create_sprite(sprite_sword, '%');

	if(player_class == 0)
		player = new Mage(newdraw, newlogic, 0);
	else if(player_class == 1)
		player = new Warrior(newdraw, newlogic, 0);
	newlogic->draw();	//draw the map
	newlogic->add_player(player);
	newlogic->add_num_enemy(enemy_num);

	player->move(0,0);

	posx = 0;
	char key = ' ';

	start_time = timeGetTime();
	end_time = 0;
	frame = 0;

	while(key != 'q'  && !over)
	{
		while(!get_input(&key) && !over)	
		{
			time_update();
			if(newlogic->enemy.size() == 1)		//win
				over = 1;
			else if(player->getlive() == 0)		//lose
				over = 2;			
		}
		player->key_press(key);
	}

	delete player;
	delete newlogic;
	delete newdraw;

	system("cls");
//	std::cout << 1000*frame/(timeGetTime() - start_time) << " fps" << std::endl;
	if(over == 1)
		std::cout << "You Win" << std::endl;
	else if(over == 2)
		std::cout << "Game End" << std::endl;
	return true;
}

bool Game::get_input(char *c)
{
	if(kbhit())
	{
		*c = getch();
		return true;
	}
	return false;
}

void Game::time_update(void)
{
	double cur_time = timeGetTime() - end_time;
	if(cur_time < Game_Speed)
		return;
	newlogic->update();
	frame++;
	end_time = timeGetTime();
}