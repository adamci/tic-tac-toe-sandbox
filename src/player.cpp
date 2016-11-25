//
//	player.cpp
//
//

#include "player.hpp"


// player methods
bool player::validMove(int i, std::vector<char> board)
{
	if (board[i] == ' ')
		return true;
	else
		return false;
}