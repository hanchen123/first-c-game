#include "StdAfx.h"
#include "Character.h"


Character::Character(Draw *d, Logic *l, int index, float x , float y, int live, char left, char down, char right, char up) : Sprite(d, l, index, x , y, live)
{
	left_key = left;
	down_key = down;
	right_key = right;
	up_key = up;

	class_ID = character_ID;
}


Character::~Character(void)
{
}

bool Character::key_press(char c)
{
	if(c == left_key)
	{
		return move(-1, 0);
	}
	if(c == down_key)
	{
		return move(0, 1);
	}
	if(c == right_key)
	{
		return move(1, 0);
	}
	if(c == up_key)
	{
		return move(0, -1);
	}
	return false;
}

void Character::add_live(int num)
{
	Sprite::add_live(num);
	if(!Sprite::isdead())
	{
		pos.x = 1;
		pos.y = 1;
		move(0, 0);
	}
}