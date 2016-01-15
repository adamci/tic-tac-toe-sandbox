//
//	randomPlayer.hpp
//
//


#include "player.hpp"
#include <iostream>
#include <utility>
#include <vector>

// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	int play(std::vector<char> board, char turn);
};