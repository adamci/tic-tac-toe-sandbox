//
//	humanPlayer.hpp
//
//

#include "player.hpp"
#include <iostream>
#include <utility>


// ======================================== //
//       Human player class definition      //
// ======================================== //
class humanPlayer : public player
{
public:
	std::pair<int,int> play(char grid[3][3], char turn);
};