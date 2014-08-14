#include "StdAfx.h"
#include "Sprite.h"


Sprite::Sprite(Draw *d, Logic *l, int index, float x, float y, int passed_live)
{
	newdraw = d;
	newlogic = l;

	pos.x = x;
	pos.y = y;

	direction.x = 1;
	direction.y = 0;

	sprite_index = index;
	live = passed_live;

	class_ID = sprite_ID;
}


Sprite::~Sprite(void)
{
	erase(pos.x, pos.y);
}

vector2D Sprite::get_direction(void)
{
	return direction;
}

vector2D Sprite::get_position(void)
{
	return pos;
}

float Sprite::getX(void)
{
	return pos.x;
}

float Sprite::getY(void)
{
	return pos.y;
}

void Sprite::add_live(int num)
{
	live += num;
}

int Sprite::getlive(void)
{
	return live;
}

bool Sprite::isdead(void)
{
	return (live <= 0);
}

bool Sprite::move(float x, float y)
{
	int pos_x = int(pos.x + x);
	int pos_y = int(pos.y + y);
	direction.x = x;
	direction.y = y;

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

void Sprite::draw(float x, float y)
{
	newdraw->draw_sprite(sprite_index, (int)x, (int)y);
}


void Sprite::erase(float x, float y)
{
	newdraw->erase_sprite((int)x, (int)y);
}

bool Sprite::isvalid_move(int x, int y)
{
	if(newlogic->map[x][y] != tile_wall)
		return true;
	return false;
}

void Sprite::idle_update(void)
{

}

