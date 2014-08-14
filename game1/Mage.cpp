#include "StdAfx.h"
#include "Mage.h"
#include "Fireball.h"

Mage::Mage(Draw *d, Logic *l, int index, float x, float y, int live, char spell, char left, char down, char right, char up) : 
	Character(d, l, index, x , y, live, left, down, right, up)
{
	spell_key = spell;
	class_ID = mage_ID;
}


Mage::~Mage(void)
{
}

bool Mage::key_press(char c)
{
	bool ispress = Character::key_press(c);
	if(ispress == false)	//not the moving key
	{
		if(c == spell_key)
		{
			cast_fireball();
			return true;
		}
	}
	return ispress;
}

void Mage::cast_fireball(void)
{
	if(isvalid_move(int(pos.x + direction.x), int(pos.y + direction.y)) && ((int)pos.x != 1 || (int)pos.y != 1))		
	{
		Fireball *tmp = new Fireball(newdraw, newlogic, sprite_fireball, pos.x + direction.x, pos.y + direction.y, direction.x, direction.y);
		newlogic->add_enemies((Sprite *)tmp);
	}
}