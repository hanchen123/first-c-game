#pragma once
#include "Sprite.h"

class Character : public Sprite
{
public:
	Character(Draw *d, Logic *l, int index, float x = 1, float y = 1, int live = 3, char left = 'a', char down = 's', char right = 'd', char up = 'w');
	~Character(void);

	virtual bool key_press(char c);
	virtual void add_live(int num = 1);
protected:
	char left_key;
	char down_key;
	char right_key;
	char up_key;
};

