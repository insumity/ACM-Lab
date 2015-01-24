#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
	int t;
	cin >> t;

	while (t-- > 0) {
		int n, m;
		cin >> n >> m;
	
		vector< pair< int, pair< int, int > > > graph1; 
		vector< pair< int, pair< int, int > > > graph2; 

		vector< int > parent1(n, 0), parent2(n, 0);
		vector< int > rank1(n, 0), rank2(n, 0);

		for (int i = 0; i < n; ++i) {
			parent1[i] = i;
			parent2[i] = i;
		}

		for (int i = 0; i < m; ++i) {
			int a, b, w1, w2;
			cin >> a >> b >> w1 >> w2;
			graph1.push_back(make_pair(w1, make_pair(a, b)));
			graph2.push_back(make_pair(w2, make_pair(a, b)));
		}

		sort(graph1.begin(), graph1.end(), compareW);
		sort(graph2.begin(), graph2.end(), compareW);

		set< pair< int, int > > s; 
		for (unsigned int i = 0; i < graph1.size(); ++i) {
			int x = graph1[i].second.first;
			int y = graph1[i].second.second;
			
			if (!sameSet(x, y, parent1, rank1)) {
				unionSet(x, y, parent1, rank1);
				s.insert(make_pair(x, y));
			}
		}

		bool theSame = true;
		for (unsigned int i = 0; i < graph2.size(); ++i) {
			int x = graph2[i].second.first;
			int y = graph2[i].second.second;
			
			if (!sameSet(x, y, parent2, rank2)) {
				unionSet(x, y, parent2, rank2);
				if (s.find(make_pair(x, y)) == s.end()) {
					theSame = false;
					break;
				}
			}
		}

		cout << ((theSame)? "yes": "no") << endl;

	}

	return 0;
}

