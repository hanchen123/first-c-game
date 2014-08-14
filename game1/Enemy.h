#pragma once
#include "Sprite.h"

#define enemy_speed 5

class Logic;
class Character;

class Enemy : public Sprite
{
public:
	Enemy(Draw *d, Logic *l, int index, float x = 1, float y = 1, int live = 2);
	~Enemy(void);

	void add_target(Character *p);
	bool move(float x, float y);
	void idle_update(void);

protected:
	void ai(void);
	Character *target;
	int class_ID;
};

