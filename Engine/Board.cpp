#include "Board.h"

Board::Board( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Board::DrawCell( const Vector& pos,Color c )
{
	gfx.DrawRectVecDim( pos * dimasion,dimasion,dimasion,c );
}

void Board::SetContens( const Vector& pos,CellContens )
{
	const 
}

const int Board::getdimsion() const
{
	return dimasion;
}

const int Board::getwidth() const
{
	return width;
}

const int Board::getheight() const
{
	return height;
}
