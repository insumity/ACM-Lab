#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void findCombination(int l, int m, int n, int *remaining, int *fromM, int *fromN)
{
	int startingN = floor(l / n);
	int minRemaining = INT_MAX;

	for (int i = startingN; i >= 0; --i) {
		int timesN = i * n;

		if (l - timesN == 0) {
			*remaining = 0;
			*fromM = 0;
			*fromN = i;
			return;
		}
		int startingM = floor((l - timesN) / m);
		
		for (int j = startingM; j >= 0; --j) {
			int timesM = j * m;
			if (l - timesN - timesM == 0) {
				*remaining = 0;
				*fromM = j;
				*fromN = i;
				return;
			}
			
			int rem = l - timesN - timesM;
			if (rem < minRemaining) {
				minRemaining = rem;
				*remaining = rem;
				*fromM = j;
				*fromN = i;
			}
		}
	}	
}

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int l, m, n;
		cin >> l >> m >> n;
		int remaining, resultM, resultN;
		findCombination(l, m, n, &remaining, &resultM, &resultN);
		cout << resultM << " " << resultN << " " << remaining << endl;

	}		
	
	return 0;
}

