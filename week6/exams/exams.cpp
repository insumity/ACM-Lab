#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double average(vector< double > &ar)
{
	double sum = 0;
	for (int i = 0; i < ar.size(); ++i) {
		sum += ar[i];
	}
	return sum / ar.size();
}

vector< double > solve(vector< double > &exams, vector< pair<int, double> > &changes, vector< pair<int, int> > &available, int start, int end)
{
	vector< double > results;
	if (start == end) {
		return exams;
	}

	int medium = start + (end - start) / 2;
	vector< double> res1 = solve(exams, changes, available, start, medium); 
	vector< double> res2 = solve(exams, changes, available, medium, end); 

	for  
	
	for (int i = 0; i <= changes.size(); ++i) {
		
		vector< double > grades;
		for (int j = 0; j < available.size(); ++j) {
			double max = 0;
			for (int k = available[j].first; k <= available[j].second; ++k) {
				if (exams[k] > max) {
					max = exams[k];
				}		
			}
			grades.push_back(max);
		}

		double avg = average(grades);
		int i_avg = (int (avg * 100.0));
		results.push_back(i_avg / 100.0);
	
		if (i == changes.size()) {
			break;
		}		
		exams[changes[i].first] = changes[i].second;
	}
	return results;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n, m, l;
		cin >> n >> m >> l;
		
		vector< double > g(m);
		for (int i = 0; i < m; ++i) {
			cin >> g[i];
		}

		vector< pair<int, int> > available(n);
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			available[i] = make_pair(a, b);
		}

		vector< pair<int, double > > proposed(l);
		for (int i = 0; i < l; ++i) {
			int a;
			double b;
			cin >> a >> b;
			proposed[i] = make_pair(a, b);
		}

		vector< double > result = solve(g, proposed, available);
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i] << endl;
		}
	}

	return 0;
}

