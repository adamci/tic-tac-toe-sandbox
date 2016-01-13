//
//	minimaxPlayer.cpp
//
//

#include "minimaxPlayer.hpp"
using namespace std;

// Note that DEPTH must be set to a positive value
#define DEPTH 2



pair<int,int> minimaxPlayer::play(char grid[3][3], char turn)
{
	auto ret = minimax(grid, turn, DEPTH);

    if (ret.second.first == -1)
    	cout << "minimaxPlayer::play: DEPTH must be set to a positive value\n";

	return ret.second;
}



pair<int, pair<int,int>> minimaxPlayer::minimax(char grid[3][3], char turn, int depth)
{
	int score;
	int i, j;
	int best_value, best_index;
	char next_turn;
	vector<int> score_vec;
	vector<pair<int,int>> move_vec;

	// Base case: return if tie or score is non-zero
	score = eval(grid);
	if (score != 0 || tie(grid) || depth == 0) {
		return make_pair(score, make_pair(-1,-1));
	}

	// Set next_turn
	if (turn == 'X') {
		next_turn = 'O';
	} else {
		next_turn = 'X';
	}

	// Recursive case: iterate through all possible moves and
	// populate score_vec and move_vec
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (grid[i][j] != ' ')
				continue;

			// Set hypothetical move
			grid[i][j] = turn;

			// Get score for this possible move
			auto ret = minimax(grid, next_turn, depth-1);
			score = ret.first;

			// Push move and its corresponding score
			score_vec.push_back(score);
			move_vec.push_back(make_pair(i,j));

			// Undo hypothetical move
			grid[i][j] = ' ';
		}
	}

	// Maximize for X
	if (turn == 'X') {
		best_value = -10;

		for (i = 0; i < score_vec.size(); i++) {
			if (score_vec[i] >= best_value) {
				best_value = score_vec[i];
				best_index = i;
			}
		}

	}
	// Minimize for O
	else {
		best_value = 10;

		for (i = 0; i < score_vec.size(); i++) {
			if (score_vec[i] <= best_value) {
				best_value = score_vec[i];
				best_index = i;
			}
		}
	}

	return make_pair(score_vec[best_index], move_vec[best_index]);
}



// Returns +10 if X wins, -10 if O wins, 0 otherwise
int minimaxPlayer::eval(char grid[3][3])
{
	int i;
	char marks[2] = {'X', 'O'};

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
        {
        	if (marks[i] == 'X') {
        		return 10;
        	} else {
        		return -10;
        	}
        }
    }

    return 0;
}



bool minimaxPlayer::tie(char grid[3][3])
{
	int i, j;
    bool tie = true;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (grid[i][j] == ' ')
				tie = false;
		}
	}

	return tie;
}