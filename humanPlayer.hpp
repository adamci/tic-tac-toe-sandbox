//
//	humanPlayer.hpp
//
//

#include "player.hpp"
#include <iostream>
#include <tuple>


// ======================================== //
//       Human player class definition      //
// ======================================== //
class humanPlayer : public player
{
public:
	std::tuple<int,int> play(char grid[3][3]);
};