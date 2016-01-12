//
//	randomPlayer.hpp
//
//


#include "player.hpp"
#include <iostream>
using namespace std;


// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	void play(int *i, int *j, char grid[3][3]);
};