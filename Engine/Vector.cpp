#include "Vector.h"
#include <cmath>

Vector::Vector( int x_in,int y_in )
	:
	x( x_in ),
	y( y_in )
{
}

Vector Vector::operator+(const Vector& rhs) const
{
	return Vector( x + rhs.x , y + rhs.y );
}

Vector& Vector::operator+=(const Vector& rhs)
{
	return *this = *this + rhs;
}

Vector Vector::operator-( const Vector& rhs ) const
{
	return Vector( x - rhs.x,y - rhs.y );
}

Vector& Vector::operator-=( const Vector& rhs )
{
	return *this = *this - rhs;
}

Vector Vector::operator*( int rhs ) const
{
	return Vector( x * rhs , y * rhs );
}

Vector& Vector::operator*=( int rhs )
{
	return *this = *this * rhs;
}

bool Vector::operator==( const Vector& rhs ) const
{
	return x == rhs.x && y == rhs.y;
}

float Vector::getLength() const
{
	return float( std::sqrt( getLengthSq() ) );
}

float Vector::getLengthSq() const
{
	return float( x * x + y * y );
}

Vector& Vector::Nomalize()
{
	return *this = getNomalize();
}

Vector Vector::getNomalize() const
{
	const float len = getLengthSq();
	if ( len != 0.0f )
	{
		return *this * int( (1.0f / len) );
	}
	return *this;
}

