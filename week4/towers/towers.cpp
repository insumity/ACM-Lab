#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0) {
		int n, m;
		cin >> n >> m;
		
		vector<int> maidens(n);
		vector<int> princes(m);
		
		for (int i = 0; i < n; ++i) {
			cin >> maidens[i];
		}
		
		for (int j = 0; j < m; ++j) {
			cin >> princes[j];
		}

		if (m < n) {
			cout << "Impossible!\n";
			continue;
		}

		sort(maidens.begin(), maidens.end());
		sort(princes.begin(), princes.end(), std::greater<int>());
		
		bool hasSolution = true;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (maidens[i] + princes[i] < 5000) {
				hasSolution = false;
				break;
			}
			sum += princes[i];
		}

		if (hasSolution) {
			cout << sum << endl;
		}
		else {
			cout << "Impossible!\n";
			continue;
		}
	}

	return 0;
}

