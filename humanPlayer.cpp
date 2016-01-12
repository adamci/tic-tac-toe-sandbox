//
//	humanPlayer.cpp
//
//


#include "humanPlayer.hpp"


tuple<int,int> humanPlayer::play(char grid[3][3])
{
	string move;
	int i, j;

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
			j = move[0] - 'a';
			i = move[1] - '1';

			if (validMove(i, j, grid))
				break;
			else
				cerr << "Invalid move\n";
		}
		else
			cerr << "Invalid syntax\n";
    }

    return make_tuple(i, j);
}