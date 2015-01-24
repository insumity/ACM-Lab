#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool isCorrect(vector< vector< int > > &sudoku, int row, int col)
{
	int rowNumber[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 9; ++i) {
		if (sudoku[i][col] == 0) {
			continue;
		}
		if (rowNumber[sudoku[i][col] - 1] == 1) {
			return false;
		}
		rowNumber[sudoku[i][col] - 1] = 1; 
	}

	int colNumber[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 9; ++i) {
		if (sudoku[row][i] == 0) {
			continue;
		}
		if (colNumber[sudoku[row][i] - 1] == 1) {
			return false;
		}
		colNumber[sudoku[row][i] - 1] = 1; 
	}


	int boxNumber[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int nRow = 3 * (row / 3);
	int nCol = 3 * (col / 3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
		
			if (sudoku[nRow + i][nCol +j] == 0) {
				continue;
			}
			
			if (boxNumber[sudoku[nRow + i][nCol +j] - 1] == 1) {
				return false;
			}

			boxNumber[sudoku[nRow + i][nCol + j] - 1] = 1; 
		}
	}
	
	return true;
}

void print_sudoku(vector< vector< int > >&sudoku)
{
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---\n";
}

bool isValid(vector< vector< int > > &sudoku)
{
	//print_sudoku(sudoku);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (!isCorrect(sudoku, i, j)) {
				return false;
			}
		}	
	}

	return true;
}

vector< pair< int, pair<int, int> > > get_indexes(vector< vector< int > > &sudoku)
{
	vector< pair< int, pair<int, int > > > result;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (sudoku[i][j] == 0) {
				int times = 0;
				for (int k = 1; k <= 9; ++k) {
					sudoku[i][j] = k;
					if (isCorrect(sudoku, i, j)) {
						times++;
					}
				}
				sudoku[i][j] = 0;
				result.push_back(make_pair(times, make_pair(i, j)));
			}
		}
	}

	return result;
}

bool comparePairs(const pair<int, pair<int, int> > a, const pair<int, pair<int, int> > b)
{
	if (a.first < b.first) {
		return true;
	}
	else {
		return false;
	}
}


bool canSolve(vector< vector< int > > &sudoku, vector< pair<int, pair<int, int> > > &possible_indexes)
{
	bool noZero = true;

	for (unsigned int l = 0; l < possible_indexes.size(); ++l) { 
		if (possible_indexes[l].first == -1) {
			continue;
		}
		noZero = false;
		for (int k = 1; k <= 9; ++k) {
			int i = possible_indexes[l].second.first;
			int j = possible_indexes[l].second.second;
			sudoku[i][j] = k;
			if (!isCorrect(sudoku, i, j)) {
				sudoku[i][j] = 0;
				continue;
			}
			
			int tmp = possible_indexes[l].first;
			possible_indexes[l].first = -1;
			if (canSolve(sudoku, possible_indexes)) {
				return true;
			}
			possible_indexes[l].first = tmp;
			sudoku[i][j] = 0;
		}
		return false;
	}

	if (noZero) {
		if (isValid(sudoku)) {
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t-- > 0) {
		vector< vector< int > > sudoku(9, vector< int > (9, 0));

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char c;
				cin >> c;	
				if (c == '?') {
					sudoku[i][j] = 0;
				}
				else {
					sudoku[i][j] = (int) (c - '0');
				}
			} 
		}
		
		vector< pair<int, pair< int, int > > > possible_indexes = get_indexes(sudoku);
		sort(possible_indexes.begin(), possible_indexes.end(), comparePairs);
		cout << canSolve(sudoku, possible_indexes) << endl;
	}

	return 0;
}

