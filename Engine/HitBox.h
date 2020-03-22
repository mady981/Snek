#pragma once
#include "Vector.h"
class HitBox
{
public:
	HitBox() = default;
	HitBox( int left_in,int right_in,int top_in,int bottem_in );
	HitBox( const Vector& topleft,const Vector& bottemright );
	HitBox( const Vector& topleft,int width,int height );
	bool isOverlappingWith( const HitBox& other ) const;
	bool isOverlappingWith( const Vector& other ) const;
	static HitBox fromCenter( const Vector & center,int width,int height );
public:
	int left;
	int right;
	int top;
	int bottem;
};
