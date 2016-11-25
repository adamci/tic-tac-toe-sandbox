//
//	minimaxPlayer.cpp
//
//

#include "minimaxPlayer.hpp"
using namespace std;





int minimaxPlayer::play(vector<char> board, char turn)
{
	auto ret = minimax(board, turn, DEPTH);

    if (ret.second == -1)
    	cout << "minimaxPlayer::play: DEPTH must be set to a positive value\n";

	return ret.second;
}



pair<int, int> minimaxPlayer::minimax(vector<char> board, char turn, int depth)
{
	int score;
	int i;
	int best_value, best_index;
	char next_turn;
	vector<int> score_vec;
	vector<int> move_vec;

	// Base case: return if tie or score is non-zero
	score = eval(board);
	if (score != 0 || tie(board) || depth == 0) {
		return make_pair(score, -1);
	}

	// Set next_turn
	if (turn == 'X') {
		next_turn = 'O';
	} else {
		next_turn = 'X';
	}

	// Recursive case: iterate through all possible moves and
	// populate score_vec and move_vec
	for (i = 0; i < BOARD_SIZE; i++) {
		if (board[i] != ' ')
			continue;

		// Set hypothetical move
		board[i] = turn;

		// Get score for this possible move
		auto ret = minimax(board, next_turn, depth-1);
		score = ret.first;

		// Push move and its corresponding score
		score_vec.push_back(score);
		move_vec.push_back(i);

		// Undo hypothetical move
		board[i] = ' ';
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
int minimaxPlayer::eval(vector<char> board)
{
	int i;
	char marks[2] = {'X', 'O'};

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



bool minimaxPlayer::tie(vector<char> board)
{
	int i;
    bool tie = true;

	for (i = 0; i < BOARD_SIZE; i++) {
		if (board[i] == ' ')
			tie = false;
	}

	return tie;
}