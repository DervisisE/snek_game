#pragma once
#include "Location.h"
#include "Board.h"
#include "Colors.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void initBody();
		void Move(const Location& delta);
		void Follow(const Segment& next);
		void Draw(Board& brd) const;

	private:
		Location loc;
		Color c;
	};
public:	
	Snake(const Location& loc);
	void MoveBy(const Location& delta);
	void Grow();
	void Draw(Board& brd) const;
private:

	static constexpr int nSegmentsMax{ 1000 };
	Segment segments[nSegmentsMax];
	int nSegment{ 1 };
	static constexpr Color headColor = Colors::Red;
	static constexpr Color bodyColor = Colors::Yellow;
};

