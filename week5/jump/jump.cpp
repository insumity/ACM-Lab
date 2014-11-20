#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;

	
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		vector<long long> g(n, 0); 
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
			
		long long min, min_index;
		min = min_index = -1;
		g[0] = 0;
		for (int p = 1; p < n; ++p) {
		
			if (min != -1 && g[p - 1] > min && min_index >= (p - k)) {
			}
			else if (g[p - 1] < min) {
				min = g[p - 1];
				min_index = p - 1;
			}
			else {
					min = g[p - 1];
					min_index = p - 1;
					for (int j = 2; j <= k; ++j) {
				}
						if (p - j >= 0 && g[p - j] < min) {
							min = g[p - j];
							min_index = p - j;
						}
					}
			}
			
			g[p] = a[p] + min;
		}

		if (n != 0) {
			cout << g[n - 1 ] << endl;
		}
		else {
			cout << "0\n";
		}
	}

	return 0;
}

