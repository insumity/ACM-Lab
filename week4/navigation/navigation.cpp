#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dfs(vector< vector< pair< int, bool> > > &edges, vector< bool > &visited, int start, int end)
{
	visited[start] = true;
	cout << "dfs(" << start << ", " << end << ")" << endl;
	if (start == ende {
nstall zsh		cout << start << " FOUND END!" << endl;
		return 1;
	}

	bool finished = false;
	for (int i = 0; i < edges[start].size(); ++i) {
		cout << "looping ...";
		if (!visited[edges[start][i].first] && !edges[start][i].second) {

			cout << "getting ...";
			cout << start << " : ";
			edges[start][i].second = true;
			edges[i][start].second = true;
			int res = dfs(edges, visited, edges[start][i].first, end);
			finished = (res == 1);
		}
	}

	return finished? 1: 0;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;		
		
		vector< vector< pair< int, bool> > > edges(n, vector< pair< int, bool> > ());
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(make_pair(b, false));
			edges[b].push_back(make_pair(a, false));
		}

		cout << "!!!" << endl;
		for (int k = 0; k < n; ++k) {
			cout << k << ": ";
			for (int i = 0; i < edges[k].size(); ++i) {
				cout << edges[k][i].first << " ";
			}
			cout << endl;
		}
		cout << "!!!" << endl;

		cout << "\t\tSTARTING\n";
		while (true) {
			vector< bool > visited(n, false);
			int res = dfs(edges, visited, s, t);
			if (res == 0) {
				break;
			}
		}
		cout << "\t\tENDING\n";
	}	

	return 0;
}

