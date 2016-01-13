//
//	randomPlayer.cpp
//
//


#include "randomPlayer.hpp"
using namespace std;


pair<int,int> randomPlayer::play(char grid[3][3], char turn)
{
	int i, j, xRan;

	do {
		xRan = rand() % 9;
		i = xRan / 3;
		j = xRan % 3;
	} while (!validMove(i, j, grid));

	return make_pair(i, j);
}