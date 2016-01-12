//
//	humanPlayer.hpp
//
//

#include "player.hpp"
#include <iostream>
using namespace std;



// ======================================== //
//       Human player class definition      //
// ======================================== //
class humanPlayer : public player
{
public:
	void play(int *i, int *j, char grid[3][3]);
};