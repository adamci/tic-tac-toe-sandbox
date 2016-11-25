//
//	humanPlayer.hpp
//
//

#include "player.hpp"
#include "include.h"


// ======================================== //
//       Human player class definition      //
// ======================================== //
class humanPlayer : public player
{
public:
	int play(std::vector<char> board, char turn);
};