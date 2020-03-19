#pragma once
#include "Vector.h"
class HitBox
{
public:
	HitBox() = default;
	HitBox( float left_in,float right_in,float top_in,float bottem_in );
	HitBox( const Vector& topleft,const Vector& bottemright );
	HitBox( const Vector& topleft,float width,float height );
	bool isOverlappingWith( const HitBox& other ) const;
	bool isOverlappingWith( const Vector& other ) const;
	static HitBox fromCenter( const Vector & center,float width,float height );
public:
	float left;
	float right;
	float top;
	float bottem;
};
