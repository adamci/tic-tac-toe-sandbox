//
//	minimaxPlayer.hpp
//
//


#include "player.hpp"
#include "../include.h"

// Note that DEPTH must be set to a positive value
#define DEPTH 2

// ======================================== //
//     Minimax player class definition      //
// ======================================== //
class minimaxPlayer : public player
{
private:
	int eval(std::vector<char> board);
	bool tie(std::vector<char> board);
	std::pair<int, int> minimax(std::vector<char> grid, char turn, int depth);

public:
	int play(std::vector<char> board, char mark);
};