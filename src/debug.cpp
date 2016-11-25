//
//	debug.cpp
//
//

#include "debug.hpp"

using namespace std;

void print_grid(vector<char> board)
{
    cout << endl;
    cout << "  a b c\n";
    cout <<"1 " << board[0] << "|" << board[1] << "|" << board[2] << endl;
    cout << "-------\n";
    cout <<"2 " << board[3] << "|" << board[4] << "|" << board[5] << endl;
    cout << "-------\n";
    cout <<"3 " << board[6] << "|" << board[7] << "|" << board[8] << endl;
    cout << endl;
}

void print_int_vec(vector<int> vec)
{
	int i;

	cout << "{";
	for (i = 0; i < vec.size(); i++) {
		auto score = vec[i];
		cout << score;

		if (i < vec.size() - 1)
			cout << ", ";
	 }
	 cout << "}" << endl;
}