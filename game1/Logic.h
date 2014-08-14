#pragma once
#include "Draw.h"
#include <list>

class Character;
class Sprite;

enum
{
	tile_route,
	tile_wall
};

enum
{
	sprite_player,
	sprite_enemy,
	sprite_fireball,
	sprite_sword
};

class Logic
{
public:
	Logic(Draw *d, int w = 30, int h = 20);
	~Logic(void);

	void add_player(Character *p);
	void update(void);
	void draw(void);
	bool key_press(char c);

	void add_num_enemy(int num);
	void add_enemies(Sprite *sp);
	std::list<Sprite *> enemy;	//store NPCs
	std::list<Sprite *>::iterator it;	

	friend class Sprite;
protected:
	void create_map(void);

private:
	int screenw;
	int screenh;
	char **map;

	Character *player;
	Draw *newdraw;
};

