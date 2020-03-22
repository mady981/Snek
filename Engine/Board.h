#pragma once
#include "Graphics.h"
#include "Vector.h"
#include <random>
class Board
{
public:
	enum class CellContens
	{
		Empty,
		Food,
		Poison,
		Death
	};
public:
	Board( Graphics& gfx );
	void DrawCell( const Vector& pos,Color c );
	void SetCells( const CellContens& con );
	void Draw();
	bool isColliding( const Vector& snek_pos,const CellContens con );
private:
	static constexpr int dimansion = 20;
	static constexpr int height = Graphics::ScreenHeight / dimansion;
	static constexpr int width = Graphics::ScreenWidth / dimansion;
	static constexpr Color FoodColor = { 255,0,0 };
	static constexpr Color PoisonColor = { 128,0,128 };
	static constexpr Color DeathColor = { 128,128,128 };
	CellContens contens[width * height] = { CellContens::Empty };
	std::mt19937 rng;
	Vector pos;
private:
	Graphics& gfx;
};

