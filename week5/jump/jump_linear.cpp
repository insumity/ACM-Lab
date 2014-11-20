#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n), res(n), lmin(k + 1), lmin2(k + 1), rmin(k + 1);
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
		}

		for (int j = 0; j <= k; ++j) {
			res[j] = a[j];
			if (j == 0) {
				lmin[k] = a[k];
			}
			else {
				lmin[k - j] = min(a[k - j], lmin[k - j + 1]);
			} 
		}

		for (int j = k + 1; j < n; j += k) {
			if (j > k + 1) {
				rmin[j - (j / k) * k] = min(a[j],  rmin[j - 1]); 
			}
			
			// find lmin index
			for (int p = 0i; p <= k; ++p) {
				
			res[j] = min	
		}
		
	}

	return 0;
}

