//https://www.geeksforgeeks.org/sum-triangle-from-array/
#include <iostream> 
using namespace std;

void sumTriangle (int arr[], int level, int n) {
	if (level == n) {
		return;
	}

	int j;
	int res[n-level];
	for (j = 0 ; j < n-level; j++) {
		res[j] = arr[j] + arr[j+1];
	}

	for (int k = 0 ; k < j ; k++) {
		cout << res[k] << " ";
	}

	cout << endl;

	sumTriangle (res, level+1, n);
}

int main () {
	int arr[] = {1,2,3,4,5};
	int level = 1, n = 5;
	sumTriangle (arr, level, n);
}