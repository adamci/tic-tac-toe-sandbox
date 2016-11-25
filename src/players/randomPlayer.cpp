//
//	randomPlayer.cpp
//
//


#include "randomPlayer.hpp"
using namespace std;


int randomPlayer::play(vector<char> board, char turn)
{
	int i, j, xRan;
	int int_move;

	do {
		xRan = rand() % 9;
		i = xRan / 3;
		j = xRan % 3;
		int_move = 3*i + j;
	} while (!validMove(int_move, board));

	return int_move;
}