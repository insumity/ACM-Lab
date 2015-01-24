#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector< vector< int > > &graph, int v, vector< bool > &visited, vector< int > &result);
vector< int > top_sort(vector< vector< int > > &graph)
{
	vector< int > result;
	vector< bool > visited(graph.size(), false);

	int n = graph.size();
	for (int i = n - 1; i >= 0; i--) {
		dfs(graph, i, visited, result); 
	}

	return result;
}

void dfs(vector< vector< int > > &graph, int v, vector< bool > &visited, vector< int > &result)
{
	if (!visited[v]) {
		visited[v] = true;
		for (unsigned int i = 0; i < graph[v].size(); ++i) {
			if (!visited[graph[v][i]]) {
				dfs(graph, graph[v][i], visited, result);
			}
		}

		result.push_back(v);
	}
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0) {
		int n, m;
		cin >> n >> m;

		vector< vector< int > > graph(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
		}

		for (int i = 0; i < n; ++i) {
			sort(graph[i].begin(), graph[i].end(), std::greater<int>());
		}

		vector< int > solution = top_sort(graph);
		for (unsigned int i = 0; i < solution.size(); ++i) {
			cout << (solution[i] + 1) << endl;
		}
	}

	return 0;
}

