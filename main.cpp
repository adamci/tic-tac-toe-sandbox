// Tic-Tac-Toe Engine
//
//     Adam Cimpeanu
//


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "game.h"
#include "players.h"
#include "moveset.h"
#define RANDGAMES 100000
using namespace std;





// Game methods
template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::move()
{
    int i, j;

    if (playerAToMove) {
        playerA->play(&i, &j, this->grid);
        grid[i][j] = 'X';
    }
    else {
        playerB->play(&i, &j, this->grid);
        grid[i][j] = 'O';
    }

    // switch turns
    playerAToMove = !playerAToMove;
}

template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::print()
{
    cout << endl;
    cout << "  a b c\n";
    cout <<"1 " << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << endl;
    cout << "-------\n";
    cout <<"2 " << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << endl;
    cout << "-------\n";
    cout <<"3 " << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;
    cout << endl;
}

template <class playerTypeA, class playerTypeB>
int game<playerTypeA, playerTypeB>::isOver()
{
    // 0 --> tie
    // -1--> no winner yet
    // 1 --> player A won
    // 2 --> player B won
    int winner = 0;

    char mark[2] = {'X', 'O'};
    int i,j;

    for (i = 0; i < 2; i++) {
        char m = mark[i];
        if ((grid[0][0] == m && grid[0][1] == m && grid[0][2] == m) ||
            (grid[1][0] == m && grid[1][1] == m && grid[1][2] == m) ||
            (grid[2][0] == m && grid[2][1] == m && grid[2][2] == m) ||
            (grid[0][0] == m && grid[1][0] == m && grid[2][0] == m) ||
            (grid[0][1] == m && grid[1][1] == m && grid[2][1] == m) ||
            (grid[0][2] == m && grid[1][2] == m && grid[2][2] == m) ||
            (grid[0][0] == m && grid[1][1] == m && grid[2][2] == m) ||
            (grid[0][2] == m && grid[1][1] == m && grid[2][0] == m))
            winner = i + 1;
    }

    // Check for game not over
    if (winner == 0) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid[i][j] == ' ') {
                    winner = -1;
                }
            }
        }
    }

    return winner;
}



// player methods
bool player::validMove(int i, int j, char grid[3][3])
{
	if (grid[i][j] == ' ')
		return true;
	else
		return false;
}

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


// ======================================== //
//          Moveset Implementation          //
// ======================================== //
// movesetTree::movesetTree()
// {
// 	// Initialize root
// 	root = new node();

// 	// Initialize value and grid
// 	root->value = 0;
// 	int i, j;
// 	for (i = 0; i < 3; i++)
// 	{
// 		for (j = 0; j < 3; j++)
// 		{
// 			root->(grid[i][j]) = ' ';
// 		}
// 	}

//     // Initialize branches of 
// }




// ======================================== //
//               Main Functions             //
// ======================================== //
void humanVersusRandom()
{
	randomPlayer bot;
	humanPlayer human;

    game<randomPlayer, humanPlayer> ttt(&bot, &human);

    while (ttt.isOver() == -1)
    {
    	ttt.print();
    	ttt.move();
    }

    // Announce end game
    if (ttt.isOver() == 0)
        cout << "It's a tie!\n";
    else if (ttt.isOver() == 1)
        cout << "Bot won!\n";
    else
        cout << "You won!\n";

    ttt.print();
}


void randRandThousandTrialTest()
{
	randomPlayer rand1;
	randomPlayer rand2;
	game<randomPlayer, randomPlayer> ttt(&rand1, &rand2);
	int rand1Wins = 0;
	int rand2Wins = 0;

	int i;
	for (i = 0; i < RANDGAMES; i++)
	{
		ttt.reset();

		while (ttt.isOver() == -1)
		{
			ttt.move();
		}

		// Announce end game
		if (ttt.isOver() == 0)
			continue;
		else if (ttt.isOver() == 1)
			++rand1Wins;
		else
			++rand2Wins;
	}

	cout << "Rand1 won " << rand1Wins << " times." << endl;
	cout << "Rand2 won " << rand2Wins << " times." << endl;
	cout << "There were " << RANDGAMES - rand1Wins - rand2Wins << " ties." << endl;
}


int main()
{
	randRandThousandTrialTest();

	return 1;
}