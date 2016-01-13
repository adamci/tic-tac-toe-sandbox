//
//	debug.cpp
//
//


void print_grid(char grid[3][3])
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

void print_move_vec(vector<pair<int,int>> vec)
{
	int i;

	cout << "{";
	for (i = 0; i < vec.size(); i++) {
		auto move = vec[i];
		cout << "(" << move.first << ", " << move.second << "), ";
	 }
	 cout << "}" << endl;
}

void print_score_vec(vector<int> vec)
{
	int i;

	cout << "{";
	for (i = 0; i < vec.size(); i++) {
		auto score = vec[i];
		cout << score << ", ";
	 }
	 cout << "}" << endl;
}