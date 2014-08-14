#pragma once
#include "Draw.h"
#include "Character.h"
#include "Mage.h"
#include "Warrior.h"
#include "Logic.h"

class Game
{
public:
	Game(int enemies = 1, int x = 30, int y = 20, int type = 0);
	~Game(void);
	bool run(void);

protected:
	bool get_input(char *c);
	void time_update(void);

private:
	double frame;
	double start_time;
	double end_time;
	
	int enemy_num;
	int	posx;
	int screenx;
	int screeny;
	int over;
	int player_class;

	Draw *newdraw;
	Character *player;
	Logic *newlogic;
};