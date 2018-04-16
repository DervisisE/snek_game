#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Colors.h"

class Board 
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const { return width; };
	int GetGridHeight() const { return height; };
private:
	int width{ 80 }, height{ 60 };			//in grid/cell coordinates
	static constexpr int dimension{ 10 };	//in pixels
	Graphics& gfx;
	Color c;
};