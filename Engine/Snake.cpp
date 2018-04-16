#include "Snake.h"
#include <assert.h>
#include <math.h>


Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);

}

void Snake::MoveBy(const Location & delta)
{
	for (int i = nSegment-1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].Move(delta);
}

void Snake::Grow()
{
	if (nSegment < nSegmentsMax)
	{
		nSegment++;
		segments[nSegment - 1].initBody();
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegment; i++)
	{
		segments[i].Draw(brd);
	}
}

void Snake::Segment::InitHead(const Location & loc)
{
	this->loc = loc;
	c = headColor;
	
}
void Snake::Segment::initBody()
{
	c = bodyColor;
}
void Snake::Segment::Move(const Location & delta)
{
	assert(abs(delta.x) + abs(delta.y) == 1);
	loc.Add(delta);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

