#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int dfs(vector< vector< pair< int, int > > > &graph, int start, int end, int result, vector< bool > &visited)
{
	if (start == end) {
		return result;
	}
	else {
		if (!visited[start]) {
			int min = 2000000000;
			visited[start] = true;
			for (unsigned i = 0; i < graph[start].size(); ++i) {
				if (!visited[graph[start][i].first]) {
					int weight = graph[start][i].second;
					int newResult = dfs(graph, graph[start][i].first, end, (result > weight? result: weight), visited);
					min = (newResult < min)? newResult: min;
				}
			}
			visited[start] = false;	
			return min;
		}
		return 2000000000;
	}
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0) {
		int n, m, s, t;
		cin >> n >> m;
		cin >> s >> t;
	
		vector< vector< pair< int, int > > > graph(n); 

		for (int i = 0; i < m; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			graph[a].push_back(make_pair(b, w));
		}
		
		vector< bool > visited(n, false);
		int res = dfs(graph, s, t, -1, visited);
		cout << res << endl;
	}

	return 0;
}

