#pragma once

class Mage : public Character
{
public:
	Mage(Draw *d, Logic *l, int index, float x = 1, float y = 1, int live = 3, char spell = 'j', char left = 'a', char down = 's', char right = 'd', char up = 'w');
	~Mage(void);
	bool key_press(char c);

protected:
	void cast_fireball(void);

private: 
	char spell_key;
};

