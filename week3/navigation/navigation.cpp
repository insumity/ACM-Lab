#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canReach(vector< vector< int> > &graph, int start, int end, vector< bool > &visited, vector< bool > &visited2)
{
	if (start == end) {
		return true;
	}
	else {
	
		visited2[start] = true;
		for (unsigned int i = 0; i < graph[start].size(); ++i) {
			if (visited2[graph[start][i]] || visited[graph[start][i]]) {
				continue;
			}
			
			if (canReach(graph, graph[start][i], end, visited, visited2)) {
				visited2[start] = false;
				return true;
			} 
		}
		visited2[start] = false;
		return false;
	}
}

vector< vector< int> > findPath(vector< vector< int > > &graph, int start, int end, vector< bool > &visited, vector< bool > &visited2) {
	
	if (!canReach(graph, start, end, visited, visited2)) {
		return vector< vector< int > >();
	}
	
	if (start == end) {
		if (visited[end]) {
			return vector< vector< int > >();
		}
		vector< int > data (1);
		data[0] = start;
		
		vector< vector< int > > result(1);
		result[0] = data;
		return result;
	}
	else {
		vector< vector< int > > toReturn;

		visited[start] = true;
		for (unsigned int i = 0; i < graph[start].size(); ++i) {
			
			if (visited[graph[start][i]]) {
				continue;
			}
			
			vector< vector< int > > result = findPath(graph, graph[start][i], end, visited, visited2);

			for (unsigned int k = 0; k < result.size(); ++k) {
				vector< int > data;
				data.push_back(start);
				data.insert(data.end(), result[k].begin(), result[k].end());
				toReturn.push_back(data);
			}
		}
		visited[start] = false;
	
		return toReturn;
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

		vector< vector< int > > graph(n);

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<bool> visited(n, false), visited2(n, false);
		vector< vector< int > > paths = findPath(graph, s, t, visited, visited2);
		for (unsigned int i = 0; i < paths.size(); ++i) {
			for (unsigned int j = 0; j < paths[i].size() - 1; ++j) {
				cout << paths[i][j] << " ";
			}
			if (paths[i].size() >= 1) {
				cout << paths[i][paths[i].size() - 1];
			}
			cout << endl;
		}
		cout << paths.size() << endl;
	}

	return 0;
}



