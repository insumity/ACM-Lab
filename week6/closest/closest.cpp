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

long long solve(vector< pair<int, int> > &points, int start, int end, vector< pair<int, int> > points_y)
{
	if (start == end || start + 1 == end) {
		return LONG_MAX;
	}
	else if (start + 2 == end) {
		return distance(points[start], points[start + 1]);
	}
	
	int medium = start + (end - start) / 2;
	
	vector< pair<int, int> > points_y_left;
	vector< pair<int, int> > points_y_right;
	
	for (int j = 0; j < points_y.size(); ++j) {
		if (points_y[j].first <= points[medium].first) {
			points_y_left.push_back(points_y[j]);
		}
		else {
			points_y_right.push_back(points_y[j]);
		}
	}
	
	long long r1 = solve(points, start, medium, points_y_left);
	long long r2 = solve(points, medium, end, points_y_right);
	long long r = min(r1, r2);

	long long min = r;
	for (int k = 0; k < points_y.size(); ++k) {
		for (int i = 1; i <= 15 && k + i < points_y.size(); ++i) {
			if (distance(points_y[k], points_y[k + i]) < min) {
				min = distance(points_y[k], points_y[k + i]);
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
		
		vector< pair<int, int> > points, points_y;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			points.push_back(make_pair(a, b));
			points_y.push_back(make_pair(a, b));
		}		

		if (n == 1) {
			cout << "0\n";
			continue;
		}

		sort(points.begin(), points.end(), compare); 
		sort(points_y.begin(), points_y.end(), compare_by_y); 
		long long min = solve(points, 0, n, points_y);
		cout << min << endl;
	}

	return 0;
}


