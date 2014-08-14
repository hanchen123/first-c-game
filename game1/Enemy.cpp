#include "StdAfx.h"
#include "Enemy.h"
#include "Character.h"
#include "Logic.h"

Enemy::Enemy(Draw *d, Logic *l, int index, float x, float y, int live) : Sprite(d, l, index, x, y, live)
{
	target = NULL;
	class_ID = enemy_ID;
}


Enemy::~Enemy(void)
{
}

bool Enemy::move(float x, float y)
{
	int pos_x = int(pos.x + x);
	int pos_y = int(pos.y + y);
	if(isvalid_move(pos_x, pos_y))
	{
		std::list<Sprite *>::iterator it;
		for(it = newlogic->enemy.begin(); it != newlogic->enemy.end(); it++)
		{
			if((*it) != this && int((*it)->getX()) == pos_x && int((*it)->getY()) == pos_y)
				return false;
		}
		erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;

		direction.x = x;
		direction.y = y;

		draw(pos.x, pos.y);

		if((int)target->getX() == pos_x && (int)target->getY() == pos_y)
			target->add_live(-1);
		return true;
	}
	return false;
}

void Enemy::idle_update(void)		//start move
{
	if(target)
		ai();
}

void Enemy::add_target(Character *p)
{
	target = p;
}

void Enemy::ai(void)
{
	vector2D target_pos = target->get_position();
	vector2D direction;

	direction.x = target_pos.x - pos.x;
	direction.y = target_pos.y - pos.y;

	float dis = sqrt(direction.x * direction.x + direction.y * direction.y);

	direction.x /= (dis*enemy_speed);
	direction.y /= (dis*enemy_speed);

	if(!move(direction.x, direction.y))
	{
		while(!move(float(rand()%3 - 1), float(rand()%3 - 1)));
	}
}