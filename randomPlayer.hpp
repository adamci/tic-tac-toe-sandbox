//
//	randomPlayer.hpp
//
//


#include "player.hpp"
#include <iostream>
#include <tuple>
using namespace std;

// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	tuple<int,int> play(char grid[3][3]);
};