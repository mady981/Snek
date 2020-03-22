#pragma once
#include "Graphics.h"
#include "Vector.h"
class Board
{
public:
	enum class CellContens
	{
		Empty,
		Frute,
		Poison,
		Obstical
	};
public:
	Board( Graphics& gfx );
	void DrawCell( const Vector& pos,Color c );
	void SetContens( const Vector& pos,CellContens );
	const int getdimsion() const;
	const int getwidth() const;
	const int getheight() const;
private:
	static constexpr int dimasion = 20;
	static constexpr int width = Graphics::ScreenWidth / dimasion;
	static constexpr int height = Graphics::ScreenHeight / dimasion;
	CellContens contens[width * height] = { CellContens::Empty };
private:
	Graphics& gfx;
};

