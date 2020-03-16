#include "HitBox.h"

HitBox::HitBox( float x0_in,float y0_in,float x1_in,float y1_in )
	:
	x0( x0 ),
	y0( y0 ),
	x1( x1 ),
	y1( y1 )
{
}

bool HitBox::operator==( const HitBox& rhs ) const
{
	return x0 == rhs.x0 && y0 == rhs.y0 && x1 == rhs.x1 && y1 == rhs.y1;
}
