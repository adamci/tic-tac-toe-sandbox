class player;

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
    // friend bool player::validMove(int i, int j);
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
    }

    void reset()
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
    }

    void move();
    int isOver();
    void print();
};