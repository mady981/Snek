#include "HitBox.h"

HitBox::HitBox( int left_in,int right_in,int top_in,int bottem_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottem( bottem_in )
{
}

HitBox::HitBox( const Vector& topleft,const Vector& bottemright )
	:
	HitBox( topleft.x,bottemright.x,topleft.y,bottemright.y )
{
}

HitBox::HitBox( const Vector& topleft,int width,int height )
	:
	HitBox( topleft,topleft + Vector( width,height ) )
{
}

bool HitBox::isOverlappingWith( const HitBox& other ) const
{
	return right > other.left && left < other.right
		&& bottem > other.top && top < other.bottem;
}

bool HitBox::isOverlappingWith( const Vector& other ) const
{
	return right > other.x && left < other.x
		&& bottem > other.y && top < other.y;
}

HitBox HitBox::fromCenter( const Vector& center,int width,int height )
{
	const Vector half( width / 2,height / 2 );
	return HitBox( center - half,center + half );
}
