#include "Snake.h"

Snake::Snake( const Vector& pos_in )
{
	segments[0].inHead( pos_in );
}

void Snake::MovBy( const Vector& delta_vel )
{
	for ( int i = nSegments; i > 0; --i )
	{
		segments[i].Follow( segments[i - 1] );
	}
	segments[0].MovBy( delta_vel );
}

void Snake::Grow()
{
	++nSegments;
	segments[nSegments - 1].inBody();
}

void Snake::Draw( Board& brd )
{
	for ( int i = 0; i < nSegments; ++i )
	{
		segments[i].Draw( brd );
	}
}

bool Snake::isinTile( const Vector& target )
{
	for ( int i = 1; i < nSegments; ++i )
	{
		if ( segments[i].getPos() == target )
		{
			return true;
		}
	}
	return false;
}

const Vector Snake::nextHeadPos( const Vector& delta_vel ) const
{
	const Vector next = segments[0].getPos() + delta_vel;
	return Vector( next );
}

void Snake::Segment::inHead( const Vector& pos_in )
{
	pos = pos_in;
	c = HeadColor;
}

void Snake::Segment::inBody()
{
	c = BodyColor;
}

void Snake::Segment::Follow( const Segment& next )
{
	pos = next.pos;
}

void Snake::Segment::MovBy( const Vector& delta_vel )
{
	pos += delta_vel;
}

void Snake::Segment::Draw( Board& brd )
{
	brd.DrawCell( getPos(),c );
}

const Vector Snake::Segment::getPos() const
{
	return Vector( pos );
}
