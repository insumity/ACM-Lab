#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(vector<int> &a, int start, int end)
{
	if (start == end || start  + 1 == end) {
		return 0;
	}
	else {
		int middle = start + (end - start) / 2;
		int left = solve(a, start, middle);
		int right = solve(a, middle, end);

		sort(a.begin() + start, a.begin() + middle);
		sort(a.begin() + middle, a.begin() + end);
		
		int sum = 0, last_j = middle;
		for (int i = start; i < middle; ++i) {
			int elem = a[i];
			for (int j = last_j; j < end; ++j, ++last_j) {
				if (elem > a[j]) {
					sum += (middle - i);
					sum = sum % (100 * 100);
				}
				else {
					break;
				}
			}
		}

		return (sum + left + right) % (100 * 100);
	}
}

int main()
{
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;	
		
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		
		cout <<  solve(a, 0, n) << endl;
	}

	return 0;
}

