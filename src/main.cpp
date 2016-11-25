//
//	main.cpp
//
//


#include "game.hpp"
#define RANDGAMES 100



// Forward declarations
void humanVersusRandom();
void humanVersusMinimax();
void randRandTrialTest();
void randMinimaxTrialTest();
void minimaxMinimaxTrialTest();
void testPlayer();



int main()
{
	//randRandTrialTest();
	randMinimaxTrialTest();
	//humanVersusRandom();
	//humanVersusMinimax();
	//testPlayer();
	//minimaxMinimaxTrialTest();

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

void humanVersusMinimax()
{
	minimaxPlayer minimax;
	humanPlayer human;

	game<minimaxPlayer, humanPlayer> ttt(&minimax, &human);

    while (ttt.isOver() == -1)
    {
    	ttt.print();
    	ttt.move();
    }

    // Announce end game
    if (ttt.isOver() == 0)
        cout << "It's a tie!\n";
    else if (ttt.isOver() == 1)
        cout << "Minimax won!\n";
    else
        cout << "You won!\n";

    ttt.print();
}

void randRandTrialTest()
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

void randMinimaxTrialTest()
{
	randomPlayer rando;
	minimaxPlayer minimax;
	game<randomPlayer, minimaxPlayer> ttt(&rando, &minimax);
	int randoWins = 0;
	int minimaxWins = 0;

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
			++randoWins;
		else
			++minimaxWins;
	}

	cout << "Rando won " << randoWins << " times." << endl;
	cout << "Minimax won " << minimaxWins << " times." << endl;
	cout << "There were " << RANDGAMES - randoWins - minimaxWins << " ties." << endl;
}

void minimaxMinimaxTrialTest()
{
	minimaxPlayer max1;
	minimaxPlayer max2;
	game<minimaxPlayer, minimaxPlayer> ttt(&max1, &max2);
	int max1Wins = 0;
	int max2Wins = 0;

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
			++max1Wins;
		else
			++max2Wins;
	}

	cout << "Max1 won " << max1Wins << " times." << endl;
	cout << "Max2 won " << max2Wins << " times." << endl;
	cout << "There were " << RANDGAMES - max1Wins - max2Wins << " ties." << endl;
}

void testPlayer()
{
	//randomPlayer random;
	humanPlayer human;
	minimaxPlayer minimax;

	game<minimaxPlayer, humanPlayer> ttt(&minimax, &human);

	ttt.test();	
}