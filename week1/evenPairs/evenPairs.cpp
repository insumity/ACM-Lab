#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> numbers(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	} 

	int totalEvenPairs = 0;	
	int lastOneIndex = -1;

	// evenPairs[i] contains number of evenPairs starting from i-th number
	vector<int> evenPairs(n, 0);		

	for (int i = n - 1; i >= 0; --i) {
		int evenPairsStarting = 0;
		if (numbers[i] == 0) {
			evenPairsStarting++;
			if (i < n - 1) {
				evenPairsStarting += evenPairs[i + 1];
			}
			evenPairs[i] = evenPairsStarting;
		}
		else {
			if (lastOneIndex != -1) {
				evenPairsStarting++;

				if (lastOneIndex != n - 1) {
					evenPairsStarting += evenPairs[lastOneIndex + 1];
				} 
			}
			lastOneIndex = i;
			evenPairs[i] = evenPairsStarting;
		}

		totalEvenPairs += evenPairsStarting;
	}

	/*for (int i = 0; i < n; ++i) {
		cout << "(" << i << "): " << evenPairs[i] << endl;
	}*/
	cout << totalEvenPairs << endl;

 	
	return 0;
}

