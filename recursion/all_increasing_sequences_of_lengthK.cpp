<<<<<<< HEAD
//https://www.geeksforgeeks.org/print-increasing-sequences-length-k-first-n-natural-numbers/
=======
>>>>>>> bc18f19a23bf2e42af152dd0c98741de7d41a334
#include <iostream>
using namespace std;


void printAllIncreasingSequences (int data[], int start, int end, int index, int k) {
	if (index == k) {
		for (int i = 0 ; i < k; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		return;
	}

	if (start > end) {
		return;
	}

	data[index] = start;
	printAllIncreasingSequences (data, start + 1, end, index + 1, k);
	printAllIncreasingSequences (data, start + 1, end, index, k);

}

int main () {
	int n = 5, k = 3;

	int data[k];

	printAllIncreasingSequences (data, 1, n, 0, k);
}