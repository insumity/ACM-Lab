#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

long long distance(pair<int, int> a, pair<int, int> b)
{
	long long first = (a.first - b.first) * ((long long) a.first - b.first);
	long long second = (a.second - b.second) * ((long long) a.second - b.second);
	return first + second; 
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}
		
bool compare_by_y(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

long long solve(vector< pair<int, int> > &points, int start, int end)
{
	if (start == end || start + 1 == end) {
		return LONG_MAX;
	}
	else if (start + 2 == end) {
		return distance(points[start], points[start + 1]);
	}
	
	int medium = start + (end - start) / 2;
	long long r1 = solve(points, start, medium);
	long long r2 = solve(points, medium, end);
	long long r = min(r1, r2);

	vector< pair<int, int> > points_in_range;
	points_in_range.push_back(points[medium]);
	for (int i = start; i < medium; ++i) {
		if (abs(points[i].first - points[medium].first) <= r) { 
			points_in_range.push_back(points[i]);
		}
	}

	sort(points_in_range.begin(), points_in_range.end(), compare_by_y);
	long long min = r;
	for (int k = 0; k < points_in_range.size(); ++k) {
		for (int i = 1; i <= 15 && k + i < points_in_range.size(); ++i) {
			if (distance(points_in_range[k], points_in_range[k + i]) < min) {
				min = distance(points_in_range[k], points_in_range[k + i]);
			}
		}
	}

	return min;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		vector< pair<int, int> > points; 
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			points.push_back(make_pair(a, b));
		}		

		if (n == 1) {
			cout << "0\n";
			continue;
		}

		sort(points.begin(), points.end(), compare); 
		long long min = solve(points, 0, n);
		cout << min << endl;
	}

	return 0;
}


