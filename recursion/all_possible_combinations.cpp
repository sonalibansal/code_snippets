#include <iostream>
using namespace std;


void printCombination (int arr[], int data[], int start, int end, int index, int r) {
	if (index == r) {
		for (int j = 0 ; j < r; j++) {
			cout << data[j] << " ";
		}
		cout << endl;
		return;
	}

	if (start >= end) {
		return;
	}

	data[index] = arr[start];
	printCombination (arr, data, start + 1, end, index + 1, r);

	while (arr[i] == arr[i+1])
        i++;

	printCombination (arr, data, start + 1, end , index, r);
}


int main () {

	int arr[] = {1,2,3,4,5};

	int r = 3, n = 5;

	int data[r];

	sort(arr, arr+n); 

	printCombination (arr, data, 0, n, 0, r);
}