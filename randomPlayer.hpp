//
//	randomPlayer.hpp
//
//


#include "player.hpp"
#include "include.h"

// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	int play(std::vector<char> board, char turn);
};