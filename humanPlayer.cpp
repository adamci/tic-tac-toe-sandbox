//
//	humanPlayer.cpp
//
//


#include "humanPlayer.hpp"
using namespace std;


int humanPlayer::play(vector<char> board, char turn)
{
	string move;
	int i, j;
	int int_move;

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
			int_move = 3*i + j;

			if (validMove(int_move, board))
				break;
			else
				cerr << "Invalid move\n";
		}
		else
			cerr << "Invalid syntax\n";
    }

    return int_move;
}