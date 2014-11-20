#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		vector<int> values(n);
		vector<int> sum_values(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> values[i];
			sum_values[i] = (i > 0)? values[i] + sum_values[i - 1]: 0;
		}

		vector< vector< long long > > results(n + 1, vector< long long > (n + 1, 0));
		
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= n - i; ++j) {
	
				int start = j;
				int end = j  + i;

				long long sum = sum_values[end - 1] - sum_values[start] + values[start];

				long long v1 = values[start] + (sum - values[start] - results[start + 1][end]);
				long long v2 = values[end - 1] + (sum - values[end - 1] - results[start][end - 1]);
				results[start][end] = max(v1, v2);	
			}
		}
		
		cout << results[0][n] << endl;				
	}

	return 0;
}

