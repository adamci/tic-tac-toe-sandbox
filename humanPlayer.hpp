//
//	humanPlayer.hpp
//
//

#include "player.hpp"
#include <iostream>
#include <utility>
#include <vector>


// ======================================== //
//       Human player class definition      //
// ======================================== //
class humanPlayer : public player
{
public:
	int play(std::vector<char> board, char turn);
};