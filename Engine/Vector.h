#pragma once
class Vector
{
public:
	Vector() = default;
	Vector( int x_in , int y_in );
	Vector operator+( const Vector& rhs ) const;
	Vector& operator+=( const Vector& rhs );
	Vector operator-( const Vector& rhs ) const;
	Vector& operator-=( const Vector& rhs );
	Vector operator*( int rhs ) const;
	Vector& operator*=( int rhs );
	bool operator==( const Vector& rhs ) const;
	float getLength() const;
	float getLengthSq() const;
	Vector& Nomalize();
	Vector getNomalize() const;
public:
	int x;
	int y;
};

