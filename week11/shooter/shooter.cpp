#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
	int x, y;
	Point(int x, int y): x(x), y(y) {}

	bool operator<(Point other) const {
		if (x == other.x) {
			return y < other.y;
		}
		else {
			return x < other.x;
		}
	}
};

double dist(Point a, Point b)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}

struct Vec {
	int x, y;
	
	Vec(Point p, Point q) {
		x = q.x - p.x;
		y = q.y - p.y;
	}
};

double dot(Vec v, Vec u) {
	return v.x * u.x + v.y * u.y;
}

double norm(Vec v) {
	return sqrt(dot(v, v));
}

double angle(Vec v, Vec u) {
	return acos(dot(v, u) / (norm(v) * norm(u)));
}

int cross(Vec v, Vec u) {
	return v.x * u.y - v.y * u.x;
}

int ccw(Point p, Point q, Point r) {
	return cross(Vec(p, q), Vec(p, r));
}

double area(vector< Point > &p)
{
	int result = 0;
	for (int i = 0; i < p.size() - 1; ++i) {
		result += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
	}
	return ((double) result) / 2.0;
}

bool contains(vector< Point > &p, Point q)
{
	double sum = 0.0;
	for (int i = 0; i < p.size() - 1; ++i) {
		if (ccw(q, p[i], p[i + 1]) >= 0) {
			sum += angle(Vec(q, p[i]), Vec(q, p[i + 1]));
		}
		else {
			sum -= angle(Vec(q, p[i]), Vec(q, p[i + 1]));
		}
	}

	return sum > 3;
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0) {
		int n, m;
		cin >> n >> m;
		vector< Point > points;
	
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			points.push_back(Point(a, b));
		}

		double result = -1;
		for (int k = 0; k < m; ++k) {
			int num;
			cin >> num;

			vector< Point > spaceship;

			for (int j = 0; j < num; ++j) {
				int a, b;
				cin >> a >> b;
				spaceship.push_back(Point(a, b));
			}
			spaceship.push_back(spaceship[0]);

			for (int i = 0; i < n; ++i) {
				if (contains(spaceship, points[i])) {
					result = (result == -1)? area(spaceship): area(spaceship) < result? area(spaceship): result;
				}
			}
		}

		if (result == -1) {
			cout << "fail\n";
		}
		else {
			cout << result << endl;
		}
	}
	
	return 0;
}

