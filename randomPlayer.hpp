//
//	randomPlayer.hpp
//
//


#include "player.hpp"
#include <iostream>
#include <tuple>

// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	std::tuple<int,int> play(char grid[3][3]);
};