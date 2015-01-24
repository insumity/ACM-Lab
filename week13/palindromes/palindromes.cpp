#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solve(string& s, int start, int end, vector< vector< int > > &solutions)
{
	if (start == end) {
		solutions[start][end] = 0;
		return 0;
	}
	else if (start > end) {
		return 0;
	}
	else {
		if (solutions[start][end] != -1) {
			return solutions[start][end];
		}
		
		int result = (end - start) + 1;
		result = min(solve(s, start + 1, end, solutions) + 1, result);
		result = min(solve(s, start, end - 1, solutions) + 1, result);
		if (s[start] == s[end]) {
			result = min(solve(s, start + 1, end - 1, solutions), result);
		}
		solutions[start][end] = result;
		return result;
	}
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0) {
		string s;
		cin >> s;

		vector< vector< int > > map(s.size(), vector< int > (s.size(), - 1));
		cout << solve(s, 0, s.size() - 1, map) << endl;
	}

	return 0;
}

