#include "StdAfx.h"
#include "Logic.h"
#include "Character.h"
#include "Enemy.h"
#include <time.h>

Logic::Logic(Draw *d, int w, int h)
{
	newdraw = d;
	screenw = w;
	screenh = h;

	player = NULL;

	map = new char *[w];
	for(int i = 0; i < w; i++)
		map[i] = new char[h];

	create_map();
	newdraw->set_map(map);

	//initial the list head will do nothing itself
	Enemy *tmp = new Enemy(newdraw, this, sprite_enemy, float(screenw), float(screenh));
	add_enemies((Sprite *)tmp);
}


Logic::~Logic(void)
{
	for(int i = 0; i < screenw; i++)
		delete [] map[i];
	delete [] map;
	for(it = enemy.begin(); it != enemy.end(); it++)
	{
		delete (*it);
	}
}

void Logic::create_map(void)
{
	srand((unsigned)time(NULL));	//random seed
	for(int i = 0; i < screenw; i++)
		for(int j = 0; j < screenh; j++)
		{
			int random = rand() % 100;
			if(j == 0 || j == screenh - 1 || i == 0 || i == screenw - 1)	//border
				map[i][j] = tile_wall;
			else
			{
				if(random < 90 || (i < 3 && j < 3))
					map[i][j] = tile_route;
				else
					map[i][j] = tile_wall;
			}
		}
}

void Logic::draw(void)
{
	newdraw->draw_background();
}

void Logic::add_player(Character *pass_player)
{
	player = pass_player;
}

bool Logic::key_press(char c)
{
	if(player)
		if(player->key_press(c))
			return true;
	return false;
}

void Logic::update(void)
{
	for(it = enemy.begin(); it != enemy.end(); it++)
	{
		(*it)->idle_update();

		if((*it)->isdead() == true)
		{
			Sprite *tmp = *it;
			if((*it)->class_ID == sword_ID)
				newdraw->erase_sprite((*it)->getX()+(*it)->get_direction().x, (*it)->getY()+(*it)->get_direction().y);
			it--;
			delete tmp;
			enemy.remove(tmp);
		}
	}
}

void Logic::add_num_enemy(int num)
{
	int i = num;
	while(i > 0)
	{
		int pos_x = int((float(rand() % 100) / 100) * (screenw - 2) + 1);
		int pos_y = int((float(rand() % 100) / 100) * (screenh - 2) + 1);

		if(map[pos_x][pos_y] != tile_wall)
		{
			Enemy *tmp = new Enemy(newdraw, this, sprite_enemy, float(pos_x), float(pos_y));
			tmp->add_target(player);
			add_enemies((Sprite *)tmp);
			i--;
		}
	}
}

void Logic::add_enemies(Sprite *sp)
{
	enemy.push_back(sp);
}