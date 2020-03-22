#include "Board.h"

Board::Board( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Board::DrawCell( const Vector& pos,Color c )
{
	gfx.DrawRectVecDim( pos * dimansion + Vector( 1,1 ),dimansion - 2,dimansion - 2,c );
}

void Board::SetCells( const CellContens& con )
{
	do
	{
	std::uniform_int_distribution<int> xDist( 0,width );
	std::uniform_int_distribution<int> yDist( 0,height );
	pos = { xDist( rng ),yDist( rng ) };
	contens[pos.y * width + pos.x] = { con };
	} while ( contens[pos.y * width + pos.x] == Board::CellContens::Empty );
}

void Board::Draw()
{
	for ( int y = 0; y < height; ++y )
	{
		for ( int x = 0; x < width; ++x )
		{
			if ( contens[y * width + x] == CellContens::Food )
			{
				gfx.DrawRectVecDim( Vector( { x,y } ) * dimansion + Vector( 1,1 ),dimansion - 2,dimansion - 2,FoodColor );
			}
			else if ( contens[y * width + x] == CellContens::Poison )
			{
				gfx.DrawRectVecDim( Vector( { x,y } ) * dimansion + Vector( 1,1 ),dimansion - 2,dimansion - 2,PoisonColor );
			}
			else if ( contens[y * width + x] == CellContens::Death )
			{
				gfx.DrawRectVecDim( Vector( { x,y } ) * dimansion + Vector( 1,1 ),dimansion - 2,dimansion - 2,DeathColor );
			}
		}
	}
}

bool Board::isColliding( const Vector& snek_pos,const CellContens con )
{
	if ( con == CellContens::Food )
	{
		if ( contens[snek_pos.y * width + snek_pos.x] == CellContens::Food )
		{
			contens[snek_pos.y * width + snek_pos.x] = { CellContens::Empty };
			return true;
		}
	}
	else if ( con == CellContens::Poison )
	{
		if ( contens[snek_pos.y * width + snek_pos.x] == CellContens::Poison )
		{
			contens[snek_pos.y * width + snek_pos.x] = { CellContens::Empty };
			return true;
		}
	}
	else if ( con == CellContens::Death )
	{
		if ( contens[snek_pos.y * width + snek_pos.x] == CellContens::Death )
		{
			return true;
		}
	}
	return false;
}
