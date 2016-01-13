//
//	minimaxPlayer.hpp
//
//


#include "player.hpp"
#include <iostream>
#include <utility>
#include <vector>

// ======================================== //
//     Minimax player class definition      //
// ======================================== //
class minimaxPlayer : public player
{
private:
	int eval(char grid[3][3]);
	bool tie(char grid[3][3]);
	std::pair<int, std::pair<int,int>> minimax(char grid[3][3], char turn, int depth);

public:
	std::pair<int,int> play(char grid[3][3], char mark);
};