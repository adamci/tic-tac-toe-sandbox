//
//	randomPlayer.cpp
//
//


#include "randomPlayer.hpp"

void randomPlayer::play(int *i, int *j, char grid[3][3])
{
	int i_temp, j_temp, xRan;

	do {
		xRan = rand() % 9;
		i_temp = xRan / 3;
		j_temp = xRan % 3;
	} while (!validMove(i_temp, j_temp, grid));

	*i = i_temp;
	*j = j_temp;
}