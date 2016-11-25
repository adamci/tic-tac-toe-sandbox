//
//  game.hpp
//
//


#include <ctime>
#include "include.h"
#include "players/humanPlayer.hpp"
#include "players/randomPlayer.hpp"
#include "players/minimaxPlayer.hpp"

using namespace std;



// ======================================== //
//          Game class definition           //
// ======================================== //
// Note that a board is represented as a vector<char> object that represents a
// tic-tac-toe board if it were read from left to right and top to bottom
template<class playerTypeA, class playerTypeB>
class game
{
private:
    vector<char> board;
    playerTypeA *playerA;
    playerTypeB *playerB;
    bool playerAToMove;
    char mark;

    friend class player;
    friend class humanPlayer;
    friend class randomPlayer;
    friend class minimaxPlayer;

    void print(vector<char> g);

public:
    game(playerTypeA *pA, playerTypeB *pB) : playerA(pA), playerB(pB)
    {
        // Initialize board
        int i;
        for (i = 0; i < BOARD_SIZE; i++) {
            board.push_back(' ');
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
    void test();
};



// ======================================== //
//              Game methods                //
// ======================================== //
template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::print(vector<char> g)
{
    cout << endl;
    cout << "  a b c\n";
    cout <<"1 " << g[0] << "|" << g[1] << "|" << g[2] << endl;
    cout << "-------\n";
    cout <<"2 " << g[3] << "|" << g[4] << "|" << g[5] << endl;
    cout << "-------\n";
    cout <<"3 " << g[6] << "|" << g[7] << "|" << g[8] << endl;
    cout << endl;
}

template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::reset()
{
        // Initialize board
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        board[i] = ' ';
    }

    // Repick first player
    playerAToMove = ((rand() % 2) == 0);
    mark = 'X';
}

template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::move()
{
    if (playerAToMove) {
        auto move = playerA->play(board, mark);
        board[move] = mark;
    }
    else {
        auto move = playerB->play(board, mark);
        board[move] = mark;
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
    print(board);
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
    int i;

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
        if ((board[0] == m && board[1] == m && board[2] == m) ||
            (board[3] == m && board[4] == m && board[5] == m) ||
            (board[6] == m && board[7] == m && board[8] == m) ||
            (board[0] == m && board[3] == m && board[6] == m) ||
            (board[1] == m && board[4] == m && board[7] == m) ||
            (board[2] == m && board[5] == m && board[8] == m) ||
            (board[0] == m && board[4] == m && board[8] == m) ||
            (board[2] == m && board[4] == m && board[6] == m)   )
            winner = i + 1;
    }

    // Check for game not over
    if (winner == 0) {
        for (i = 0; i < BOARD_SIZE; i++) {
            if (board[i] == ' ') {
                winner = -1;
            }
        }
    }

    return winner;
}


template <class playerTypeA, class playerTypeB>
void game<playerTypeA, playerTypeB>::test()
{
    vector<char> test_board = {' ', 'X', ' ',
                              ' ', ' ', 'X',
                              'O', 'O', 'X' };


    cout << "Test run of single move:\n";
    print(test_board);

    auto move = playerA->play(test_board, 'O');
    cout << move << endl;
    test_board[move] = 'O';

    print(test_board);
}