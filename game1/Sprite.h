#pragma once
#include "Draw.h"
#include "Logic.h"

enum
{
	sprite_ID,
	character_ID,
	enemy_ID,
	fireball_ID,
	mage_ID,
	sword_ID,
	warrior_ID
};

struct vector2D
{
	float x;
	float y;
};

class Sprite
{
public:
	Sprite(Draw *d, Logic *l, int index, float x = 1, float y = 1, int live = 1);
	~Sprite(void);

	vector2D get_direction(void);
	vector2D get_position(void);
	float getX(void);
	float getY(void);

	int class_ID;

	int getlive(void);
	bool isdead(void);
	virtual void add_live(int num = 1);
	virtual void idle_update(void);
	virtual bool move(float x, float y);

protected:
	Draw *newdraw;
	Logic *newlogic;

	vector2D pos;
	vector2D direction;
	int sprite_index;
	int live;

	void draw(float x, float y);
	void erase(float x, float y);

	bool isvalid_move(int x, int y);
};

