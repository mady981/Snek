#pragma once
#include "Graphics.h"
#include "Vector.h"
#include "Board.h"
class Snake
{
private:
	class Segment
	{
	public:
		void inHead( const Vector& pos_in );
		void inBody();
		void Follow( const Segment& next );
		void MovBy( const Vector& delta_vel );
		void Draw( Board& brd );
		const Vector getPos() const;
	private:
		Vector pos;
		Color c;
	};
public:
	Snake( const Vector& pos_in );
	void MovBy( const Vector& delta_vel );
	void Grow();
	void Draw( Board& brd );
	bool isinTile( const Vector& target );
	const Vector nextHeadPos( const Vector& delta_vel ) const;
private:
	static constexpr Color HeadColor = { 255,255,0 };
	static constexpr Color BodyColor = { 0,255,0 };
	static constexpr int maxSegments = 100;
	int nSegments = 1;
	Segment segments[maxSegments];
};

