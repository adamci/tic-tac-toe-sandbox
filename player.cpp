//
//	player.cpp
//
//

#include "player.hpp"


// player methods
bool player::validMove(int i, int j, char grid[3][3])
{
	if (grid[i][j] == ' ')
		return true;
	else
		return false;
}