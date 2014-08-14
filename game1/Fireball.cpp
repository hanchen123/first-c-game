#include "StdAfx.h"
#include "Fireball.h"


Fireball::Fireball(Draw *d, Logic *l,int index, float x, float y, float dir_x, float dir_y, int live) : Sprite(d, l, index, x, y, live)
{
	direction.x = dir_x;
	direction.y = dir_y;

	class_ID = fireball_ID;
}


Fireball::~Fireball(void)
{
}

void Fireball::idle_update(void)
{
	if(move(direction.x, direction.y))
	{
		std::list<Sprite *>::iterator it;
		for(it = newlogic->enemy.begin(); it != newlogic->enemy.end(); it++)
		{
			if((*it)->class_ID != class_ID && (int)(*it)->getX() == (int)pos.x && (int)(*it)->getY() == (int)pos.y)
			{
				(*it)->add_live(-1);
				add_live(-1);
			}
		}
	}
	else
		add_live(-1);
}

bool Fireball::move(float x, float y)
{
	int pos_x = int(pos.x + x);
	int pos_y = int(pos.y + y);

	if(isvalid_move(pos_x, pos_y))
	{
		erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;

		draw(pos.x, pos.y);
		return true;
	}
	return false;
}
