//https://www.geeksforgeeks.org/maximum-product-increasing-subsequence/
#include <iostream>
using namespace std;
//int arr[] = { 3, 100, 4, 5, 150, 6 };
int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
int n = 8;
int dp[8][8];

int maxProduct(int index, int last) {
	if(index >= n) {
		return 1;
	}
	if(arr[index] > arr[last] || index == last) {
		return max(arr[index]* maxProduct(index+1, index), maxProduct(index+1, last));
	}
	return maxProduct(index+1, last);
}

int main() {
	// your code goes here
	int curr = 0, max = 0;
	for(int i = 0 ; i < n ; i++) {
		curr = maxProduct(i, i);
		if(max < curr) {
			max = curr;
		}
	}
	cout << "Max product = " << max << endl;
	return 0;
}