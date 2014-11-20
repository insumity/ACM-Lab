#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
	int MAX_VALUE = 10001;
	int c;
	cin >> c;
	while (c--) {
		int ci, mi;
		cin >> ci >> mi;

		vector<int> coins(ci);
		vector<int> results(MAX_VALUE, -1);
		for (int j = 0; j < ci; ++j) {
			cin >> coins[j];
			if (coins[j] > 10000) {
				continue;
			}
			results[coins[j]] = 1;
		}
		results[0] = 0;		
		
		for (int l = 1; l < MAX_VALUE; ++l) {
			
			if (results[l] != -1) {
				continue;
			}
	
			int min = INT_MAX;
			for (int k = 0; k < ci; ++k) {
				if (l - coins[k] >= 0 && results[l - coins[k]] != -1) {
					if (1 + results[l - coins[k]] < min) {
						min = 1 + results[l - coins[k]];
					}
				}
			}
						
			if (min != INT_MAX) {
				results[l] = min; 
			}	
		}

		for (int j = 0; j < mi; ++j) {
			int value;
			cin >> value;
			if (results[value] == -1) {
				cout << "not possible\n";
				continue;
			}
			cout << results[value] << endl;
		}	
	}

	return 0;
}

