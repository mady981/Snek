#pragma once
#include "Board.h"
#include "Vector.h"
#include <random>
class Objects
{
public:
	class Frute
	{
	public:
		Frute( Board& brd );
		void Respawn( Board& brd );
		void Draw( Board& brd );
	private:
		static constexpr Color FruteColor = { 255,0,0 };
	private:
		std::mt19937 rng;
		Vector FrutePos;
	};
	class Poison
	{
	public:
		Poison() = default;
		void inIn( Board& brd );
		void Draw( Board& brd );
	private:
		static constexpr Color PoisonColor = { 128,0,128 };
	private:
		std::mt19937 rng;
		Vector PoisonPos;
	};
	class Obstical
	{};
private:
};

