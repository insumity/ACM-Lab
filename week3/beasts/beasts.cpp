#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

using namespace std;

bool canPutBeast(int row, int col, vector< vector< bool > > &board)
{
	for (int i = row - 1, k = 1; i >= 0; --i, ++k) {
		if (board[i][col]) {
			return false;
		}
		if (col - k >= 0) {
			if (board[i][col - k]) {
				return false;
			}
		}
		if (col + k < board.size()) {
			if (board[i][col + k]) {
				return false;
			}
		}
	}

	for (int i = 0; i < col; ++i) {
		if (board[row][i]) {
			return false;
		}
	}

	return true;
}

bool solve(int row, vector< vector< bool > > &board)
{
	int n = board.size();
	if (row == n) {
		return true;
	}
	if (n == 1) {
		board[0][0] = true;
		return true;
	}


	for (int col = 0; col < n; ++col) {

		// can we put a best on current position?
		if (!canPutBeast(row, col, board)) {
			continue;
		}

		board[row][col] = true;
		bool isThere = solve(row + 1, board);
		if (isThere) {
			return true;
		}
		board[row][col] = false;
	}

	return false;
}

string get_result(vector< vector< bool> > &board) {
	int n = board.size();
	vector< int > solution(n);

	for (int col = 0; col < n; ++col) {
		for (int row = 0; row < n; ++row) {
			if (board[row][col]) {
				solution[col] = row + 1;
			}
		}
	} 	

	ostringstream oss;
	string text = "";
	for (int i = 0; i < solution.size() - 1; ++i) {
		oss << solution[i] << " ";
	}

	oss << solution[solution.size() - 1];
	return oss.str();
}

void pre_calculate_results() {
	for (int i = 1; i <= 30; ++i) {
		vector<vector< bool> > board(i, vector< bool > (i, false));
		bool so = solve(0, board);
		cout << "map.insert(pair<int, string>(" << i << ", \"" << (so? get_result(board): "Impossible") << "\")); " << endl;
	}
}

int main()
{

	map<int, string> map;
	map.insert(pair<int, string>(1, "1"));
	map.insert(pair<int, string>(1, "1"));
	map.insert(pair<int, string>(2, "Impossible"));
	map.insert(pair<int, string>(3, "Impossible"));
	map.insert(pair<int, string>(4, "3 1 4 2"));
	map.insert(pair<int, string>(5, "1 4 2 5 3"));
	map.insert(pair<int, string>(6, "4 1 5 2 6 3"));
	map.insert(pair<int, string>(7, "1 5 2 6 3 7 4"));
	map.insert(pair<int, string>(8, "1 7 5 8 2 4 6 3"));
	map.insert(pair<int, string>(9, "1 5 2 6 9 3 8 4 7"));
	map.insert(pair<int, string>(10, "1 8 2 9 6 3 10 4 7 5"));
	map.insert(pair<int, string>(11, "1 7 2 8 3 9 4 10 5 11 6"));
	map.insert(pair<int, string>(12, "1 9 2 12 3 7 10 4 11 5 8 6"));
	map.insert(pair<int, string>(13, "1 4 2 9 3 10 13 11 5 7 12 6 8"));
	map.insert(pair<int, string>(14, "1 11 2 8 3 12 4 13 10 6 14 5 7 9"));
	map.insert(pair<int, string>(15, "1 4 2 8 3 11 13 15 10 5 14 6 9 7 12"));
	map.insert(pair<int, string>(16, "1 4 2 13 3 10 12 15 6 16 14 8 5 7 9 11"));
	map.insert(pair<int, string>(17, "1 4 2 12 3 13 8 5 14 16 6 15 17 10 7 9 11"));
	map.insert(pair<int, string>(18, "1 4 2 14 3 11 13 5 16 18 15 7 9 17 6 8 10 12"));
	map.insert(pair<int, string>(19, "1 4 2 5 3 15 11 16 6 17 14 18 7 19 8 12 9 13 10"));
	map.insert(pair<int, string>(20, "1 4 2 5 3 19 17 15 12 16 20 8 6 18 7 13 11 9 14 10"));
	map.insert(pair<int, string>(21, "1 4 2 5 3 18 14 17 6 16 7 15 21 19 8 20 12 10 13 11 9"));
	map.insert(pair<int, string>(22, "1 4 2 5 3 18 20 14 17 6 21 16 10 7 22 19 8 13 11 9 15 12"));
	map.insert(pair<int, string>(23, "1 4 2 5 3 16 18 15 6 14 7 20 8 23 21 19 22 9 12 10 13 11 17"));
	map.insert(pair<int, string>(24, "1 4 2 5 3 17 22 18 6 15 7 19 21 8 24 20 23 9 11 13 16 10 12 14"));
	map.insert(pair<int, string>(25, "1 4 2 5 3 16 19 17 6 18 7 23 8 20 9 21 24 22 10 13 11 25 15 12 14"));
	map.insert(pair<int, string>(26, "1 4 2 5 3 22 18 21 6 17 7 20 8 24 9 19 26 23 25 13 10 14 11 15 12 16"));
	map.insert(pair<int, string>(27, "1 4 2 5 3 17 19 21 6 18 7 22 8 23 9 20 10 25 11 26 24 27 12 15 13 16 14"));
	map.insert(pair<int, string>(28, "1 4 2 5 3 26 18 22 6 23 7 19 8 24 9 20 10 21 28 25 27 13 11 16 12 15 17 14"));
	map.insert(pair<int, string>(29, "1 4 2 5 3 10 21 19 6 23 7 20 8 26 9 22 24 27 29 11 14 25 28 12 17 13 16 18 15"));
	map.insert(pair<int, string>(30, "1 4 2 5 3 24 10 23 6 22 7 21 8 28 9 20 27 25 30 26 29 15 11 16 14 12 18 13 19 17"));
	
	
	int t;
	cin >> t;

	while (t-- > 0) {
		int n;
		cin >> n;
		
		cout << map.find(n)->second << endl;
	}


	return 0;
}

