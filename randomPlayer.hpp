//
//	randomPlayer.hpp
//
//


#include "player.hpp"
#include <iostream>
#include <utility>

// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	std::pair<int,int> play(char grid[3][3], char turn);
};