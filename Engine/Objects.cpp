#include "Objects.h"

Objects::Frute::Frute( Board& brd )
{
	Respawn( brd );
}

void Objects::Frute::Respawn( Board& brd )
{
	std::uniform_int_distribution<int> xDist( 0,brd.getwidth() );
	std::uniform_int_distribution<int> yDist( 0,brd.getheight() );
	FrutePos = { xDist( rng ),yDist( rng ) };
}

void Objects::Frute::Draw( Board& brd)
{
	brd.SetContens( FrutePos,Board::CellContens::Frute );
}

void Objects::Poison::inIn( Board& brd )
{
	std::uniform_int_distribution<int> xDist( 0,brd.getwidth() );
	std::uniform_int_distribution<int> yDist( 0,brd.getheight() );
	PoisonPos = { xDist( rng ),yDist( rng ) };
}

void Objects::Poison::Draw( Board& brd )
{
	brd.DrawCell( PoisonPos,PoisonColor );
}
