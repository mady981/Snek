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
	if ( nSegments < maxSegments )
	{
		++nSegments;
		segments[nSegments - 1].inBody();
	}
}

void Snake::Draw( Graphics& gfx )
{
	for ( int i = 0; i < nSegments; ++i )
	{
		segments[i].Draw( gfx );
	}
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

void Snake::Segment::Draw( Graphics& gfx )
{
	gfx.DrawRectHB( getHitBox(),c );
}

HitBox Snake::Segment::getHitBox() const
{
	return HitBox( pos * dimansion + Vector( 1.0f,1.0f ),dimansion - 2.0f,dimansion - 2.0f );
}
