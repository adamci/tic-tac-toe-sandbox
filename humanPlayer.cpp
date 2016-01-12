//
//	humanPlayer.cpp
//
//


#include "humanPlayer.hpp"




void humanPlayer::play(int *i, int *j, char grid[3][3])
{
	string move;
	int i_temp, j_temp;

    while (true)
    {
		cout << "Make a move: ";
		cin >> move;
		

		if (!move.empty()       &&
			move.length() == 2  &&
			'a' <= move[0]      &&
			move[0] <= 'c'      &&
			'1' <= move[1]      &&
			move[1] <= '3'        )
		{
			j_temp = move[0] - 'a';
			i_temp = move[1] - '1';

			if (validMove(i_temp, j_temp, grid))
			{
				*i = i_temp;
				*j = j_temp;
				break;
			}
			else
				cerr << "Invalid move\n";
		}
		else
			cerr << "Invalid syntax\n";
    }
}