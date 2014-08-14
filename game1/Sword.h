#pragma once
#include"Sprite.h"

class Sword : public Sprite
{
public:
	Sword(Draw *d, Logic *l,int index, float x = 1, float y =1, float dir_x = 0, float dir_y = 0, int live = 1);
	~Sword(void);
	void idle_update(void);
	bool move(float x, float y);

private:
	bool first;
};

