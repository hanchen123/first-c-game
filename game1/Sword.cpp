#include "StdAfx.h"
#include "Sword.h"


Sword::Sword(Draw *d, Logic *l,int index, float x, float y, float dir_x, float dir_y, int live) : Sprite(d, l, index, x, y, live)
{
	direction.x = dir_x;
	direction.y = dir_y;
	first = true;

	class_ID = sword_ID;
}


Sword::~Sword(void)
{
}

void Sword::idle_update(void)
{
	move(direction.x, direction.y);
	if(first)	//sword exists one frame time.
	{
		first = false;
		return;
	}

	std::list<Sprite *>::iterator it;
	for(it = newlogic->enemy.begin(); it != newlogic->enemy.end(); it++)
	{
		if((*it)->class_ID != class_ID && (((int)(*it)->getX() == (int)pos.x && (int)(*it)->getY() == (int)pos.y) 
			|| ((int)(*it)->getX() == ((int)pos.x + direction.x) && (int)(*it)->getY() == ((int)pos.y + direction.y))))
		{
			(*it)->add_live(-2);
		}
	}
	add_live(-1);
}

bool Sword::move(float x, float y)
{
	int pos_x = int(pos.x + x);
	int pos_y = int(pos.y + y);

	if(isvalid_move(pos_x, pos_y) && isvalid_move(pos.x, pos.y))
	{
		draw(pos.x, pos.y);
		draw(pos_x, pos_y);
		return true;
	}
	return false;
}