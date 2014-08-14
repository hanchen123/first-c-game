#include "Draw.h"
#include <windows.h>
#include <iostream>

Draw::Draw(int w, int h)
{
	screenw = w;
	screenh = h;
	cursor_vis(false);

	map = NULL;
}


Draw::~Draw(void)
{
	cursor_vis(true);
}

int Draw::create_sprite(int index, char c)
{
	if(index >= 0 && index < 14)
	{
		sprite_vt[index] = c;
		return index;
	}
	return -1;
}

void Draw::draw_sprite(int index, int x, int y)
{
	//move to the location
	move_xy(x, y);
	//draw image
	std::cout << sprite_vt[index];
}

void Draw::move_xy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output_handle, pos);
}

void Draw::cursor_vis(bool vis)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cci;
	
	cci.dwSize = 1;
	cci.bVisible = vis;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &cci);
}

void Draw::erase_sprite(int x, int y)
{
	move_xy(x, y);
	//erase image
	std::cout << " ";
}

void Draw::draw_background(void)
{
	if(map)
	{
		for(int j = 0; j < screenh; j++)
		{
			move_xy(0, j);
			for(int i = 0; i < screenw; i++)
			{
				std::cout << background_vt[map[i][j]];
			}
		}
	}
}

void Draw::set_map(char **passed_map)
{
	map = passed_map;
}

void Draw::create_background(int index, char c)
{
	if(index >= 0 && index < 14)
	{
		background_vt[index] = c;
	}
}