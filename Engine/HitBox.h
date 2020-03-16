#pragma once
class HitBox
{
public:
	HitBox() = default;
	HitBox( float x0_in,float y0_in,float x1_in,float y1_in );
	bool operator==( const HitBox & rhs ) const;
private:
	float x0;
	float y0;
	float x1;
	float y1;
};
