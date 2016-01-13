//
//  game.hpp
//
//


#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include "humanPlayer.hpp"
#include "randomPlayer.hpp"

using namespace std;


// ======================================== //
//          Game class definition           //
// ======================================== //
template<class playerTypeA, class playerTypeB>
class game
{
private:
    char grid[3][3];
    playerTypeA *playerA;
    playerTypeB *playerB;
    bool playerAToMove;
    char mark;

    friend class player;
    friend class humanPlayer;
    friend class randomPlayer;

public:
    game(playerTypeA *pA, playerTypeB *pB) : playerA(pA), playerB(pB)
    {
        // Initialize board
        int i, j;
        for (i = 0; i < 3; i++) {
           for (j = 0; j < 3; j++) {
               grid[i][j] = ' ';
           }
        }

        // Pick first move randomly
        srand(time(NULL));
        playerAToMove = ((rand() % 2) == 0);

        mark = 'X';
    }


    void reset();
    void move();
    void print();
    int isOver();
};



// ======================================== //
//              Game methods                //
// ======================================== //
template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::reset()
{
        // Initialize board
    int i, j;
    for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
           grid[i][j] = ' ';
       }
    }

    // Repick first player
    playerAToMove = ((rand() % 2) == 0);
    mark = 'X';
}

template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::move()
{
    if (playerAToMove) {
        auto move = playerA->play(grid, mark);
        grid[move.first][move.second] = mark;
    }
    else {
        auto move = playerB->play(grid, mark);
        grid[move.first][move.second] = mark;
    }

    // switch turns
    playerAToMove = !playerAToMove;
    if (mark == 'X') {
        mark = 'O';
    } else {
        mark = 'X';
    }
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

    char marks[2];
    int i,j;

    // Correctly set marks array
    if (( playerAToMove && mark == 'X') ||
        (!playerAToMove && mark == 'O')   )
    {
        marks[0] = 'X';
        marks[1] = 'O';
    } else {
        marks[0] = 'O';
        marks[1] = 'X';
    }


    for (i = 0; i < 2; i++) {
        char m = marks[i];
        if ((grid[0][0] == m && grid[0][1] == m && grid[0][2] == m) ||
            (grid[1][0] == m && grid[1][1] == m && grid[1][2] == m) ||
            (grid[2][0] == m && grid[2][1] == m && grid[2][2] == m) ||
            (grid[0][0] == m && grid[1][0] == m && grid[2][0] == m) ||
            (grid[0][1] == m && grid[1][1] == m && grid[2][1] == m) ||
            (grid[0][2] == m && grid[1][2] == m && grid[2][2] == m) ||
            (grid[0][0] == m && grid[1][1] == m && grid[2][2] == m) ||
            (grid[0][2] == m && grid[1][1] == m && grid[2][0] == m)   )
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