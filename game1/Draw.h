#pragma once

class Draw
{
public:
	Draw(int w = 30, int h = 20);
	~Draw(void);
	int create_sprite(int index, char c);
	void erase_sprite(int x, int y);
	void draw_sprite(int index, int x, int y);

	void create_background(int index, char c);
	void draw_background(void);
	void set_map(char **map);

protected:
	char **map;
	int screenw, screenh;
	char sprite_vt[14];
	char background_vt[14];

private:
	void move_xy(int x, int y);
	void cursor_vis(bool vis);
};

