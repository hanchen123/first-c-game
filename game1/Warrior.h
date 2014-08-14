#pragma once
class Warrior : public Character
{
public:
	Warrior(Draw *d, Logic *l, int index, float x = 1, float y = 1, int live = 4, char hack = 'j', char left = 'a', char down = 's', char right = 'd', char up = 'w');
	~Warrior(void);
	bool key_press(char c);

protected:
	void hack_sword(void);

private: 
	char hack_key;
};

