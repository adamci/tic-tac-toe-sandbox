//
//	main.cpp
//
//


#include "game.hpp"
#define RANDGAMES 100000



// Forward declarations
void humanVersusRandom();
void randRandThousandTrialTest();



int main()
{
	//randRandThousandTrialTest();
	humanVersusRandom();

	return 1;
}



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