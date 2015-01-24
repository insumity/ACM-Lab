#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<int, int> map;
	
	map.insert(pair<int, int>(1, 0));
map.insert(pair<int, int>(2, 60));
map.insert(pair<int, int>(3, 8));
map.insert(pair<int, int>(4, 12));
map.insert(pair<int, int>(5, 24));
map.insert(pair<int, int>(6, 3));
map.insert(pair<int, int>(7, 8));
map.insert(pair<int, int>(8, 62));
map.insert(pair<int, int>(9, 6));
map.insert(pair<int, int>(10, 0));
map.insert(pair<int, int>(11, 0));
map.insert(pair<int, int>(12, 4));
map.insert(pair<int, int>(13, 3));
map.insert(pair<int, int>(14, 8));
map.insert(pair<int, int>(15, 2));
map.insert(pair<int, int>(16, 3));
map.insert(pair<int, int>(17, 27));
map.insert(pair<int, int>(18, 1));
map.insert(pair<int, int>(19, 2));
map.insert(pair<int, int>(20, 0));
map.insert(pair<int, int>(21, 0));
map.insert(pair<int, int>(22, 1));
map.insert(pair<int, int>(23, 3));
map.insert(pair<int, int>(24, 2));
map.insert(pair<int, int>(25, 0));
map.insert(pair<int, int>(26, 9));
map.insert(pair<int, int>(27, 4));
map.insert(pair<int, int>(28, 1));
map.insert(pair<int, int>(29, 2));
map.insert(pair<int, int>(30, 0));
map.insert(pair<int, int>(31, 0));
map.insert(pair<int, int>(32, 1));
map.insert(pair<int, int>(33, 0));
map.insert(pair<int, int>(34, 0));
map.insert(pair<int, int>(35, 5));
map.insert(pair<int, int>(36, 0));
map.insert(pair<int, int>(37, 1));
map.insert(pair<int, int>(38, 2));
map.insert(pair<int, int>(39, 0));
map.insert(pair<int, int>(40, 0));
map.insert(pair<int, int>(41, 0));
map.insert(pair<int, int>(42, 0));
map.insert(pair<int, int>(43, 1));
map.insert(pair<int, int>(44, 5));
map.insert(pair<int, int>(45, 0));
map.insert(pair<int, int>(46, 1));
map.insert(pair<int, int>(47, 0));
map.insert(pair<int, int>(48, 0));
map.insert(pair<int, int>(49, 0));
map.insert(pair<int, int>(50, 0));
map.insert(pair<int, int>(51, 0));
map.insert(pair<int, int>(52, 1));
map.insert(pair<int, int>(53, 4));
map.insert(pair<int, int>(54, 0));
map.insert(pair<int, int>(55, 0));
map.insert(pair<int, int>(56, 0));
map.insert(pair<int, int>(57, 0));
map.insert(pair<int, int>(58, 0));
map.insert(pair<int, int>(59, 1));
map.insert(pair<int, int>(60, 0));
map.insert(pair<int, int>(61, 0));
map.insert(pair<int, int>(62, 2));
map.insert(pair<int, int>(63, 0));
map.insert(pair<int, int>(64, 0));
map.insert(pair<int, int>(65, 0));
map.insert(pair<int, int>(66, 1));
map.insert(pair<int, int>(67, 0));
map.insert(pair<int, int>(68, 1));
map.insert(pair<int, int>(69, 0));
map.insert(pair<int, int>(70, 0));
map.insert(pair<int, int>(71, 0));
map.insert(pair<int, int>(72, 0));
map.insert(pair<int, int>(73, 0));
map.insert(pair<int, int>(74, 0));
map.insert(pair<int, int>(75, 0));
map.insert(pair<int, int>(76, 0));
map.insert(pair<int, int>(77, 0));
map.insert(pair<int, int>(78, 0));
map.insert(pair<int, int>(79, 0));
map.insert(pair<int, int>(80, 0));
	
	int t;
	cin >> t;

	while (t-- > 0) {
		int n;
		cin >> n;
	
		pair<int, int> maxy = pair<int, int>(-1, -1);
		for (int i = 0; i < n; ++i) {
			int data;
			cin >> data;
						
			if (maxy.first == -1) {
				maxy =  pair<int, int>(data, map.find(data)->second);
			}
			else if (map.find(data)->second > maxy.second || (map.find(data)->second == maxy.second && map.find(data)->first < maxy.first)) {
				maxy = *map.find(data);
			}
		}

		cout << maxy.first << " " << maxy.second << endl;
	}


	return 0;
}

