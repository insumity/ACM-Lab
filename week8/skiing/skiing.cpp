#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int findSet(int i, vector< int > &parent, vector< int > &rank)
{
	return parent[i] == i ? i : (parent[i] = findSet(parent[i], parent, rank));
}

bool sameSet(int i, int j, vector< int > &parent, vector< int > &rank) {
	return findSet(i, parent, rank) == findSet(j, parent, rank);
}

void unionSet(int i, int j, vector< int > &parent, vector< int > &rank) {
	if (!sameSet(i, j, parent, rank)) {
		int x = findSet(i, parent, rank);
		int y = findSet(j, parent, rank);
		if (rank[x] > rank[y]) {
			parent[y] = x;
		} else {
			parent[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
}

bool compareW(const pair<int, pair<int, int > > a, const pair<int, pair<int, int > > b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t-- > 0) {
		int n, m, s, t;
		cin >> n >> m;
		cin >> s >> t;
	
		vector< pair< int, pair< int, int > > > graph; 

		vector< int > father(n, -1);
		vector< int > parent(n, 0);
		vector< int > rank(n, 0);

		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			parent[i] = i;
		}

		for (int i = 0; i < m; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			graph.push_back(make_pair(w, make_pair(a, b)));
		}

		sort(graph.begin(), graph.end(), compareW);

		for (unsigned int i = 0; i < graph.size(); ++i) {
			int x = graph[i].second.first;
			int y = graph[i].second.second;
	
			if (!sameSet(x, y, parent, rank)) {
				unionSet(x, y, parent, rank);
				if (sameSet(s, t, parent, rank)) {
					cout << graph[i].first << endl;
					break;
				}
			}
		}

	}

	return 0;
}

