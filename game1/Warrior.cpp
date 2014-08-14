#include "StdAfx.h"
#include "Warrior.h"
#include "Sword.h"

Warrior::Warrior(Draw *d, Logic *l, int index, float x, float y, int live, char hack, char left, char down, char right, char up) :
	Character(d, l, index, x , y, live, left, down, right, up)
{
	hack_key = hack;
	class_ID = warrior_ID;
}


Warrior::~Warrior(void)
{
}

bool Warrior::key_press(char c)
{
	bool ispress = Character::key_press(c);
	if(ispress == false)	//not the moving key
	{
		if(c == hack_key)
		{
			hack_sword();
			return true;
		}
	}
	return ispress;
}

void Warrior::hack_sword(void)
{
	if(isvalid_move(int(pos.x + 2*direction.x), int(pos.y + 2*direction.y)) && isvalid_move(int(pos.x + direction.x), int(pos.y + direction.y)) 
		&& ((int)pos.x != 1 || (int)pos.y != 1))		
	{
		Sword *tmp = new Sword(newdraw, newlogic, sprite_sword, pos.x + direction.x, pos.y + direction.y, direction.x, direction.y);
		newlogic->add_enemies((Sprite *)tmp);
	}
}