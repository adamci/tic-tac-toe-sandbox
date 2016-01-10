template<class playerTypeA, class playerTypeB>
class game;


// ======================================== //
//        Player class definition           //
// ======================================== //
class player
{
public:
    bool validMove(int i, int j, char grid[3][3]);
};


// ======================================== //
//       Human player class definition      //
// ======================================== //
class humanPlayer : public player
{
public:
	void play(int *i, int *j, char grid[3][3]);
};


// ======================================== //
//      Random player class definition      //
// ======================================== //
class randomPlayer : public player
{
public:
	void play(int *i, int *j, char grid[3][3]);
};